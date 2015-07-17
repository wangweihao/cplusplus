/*
 * =====================================================================================
 *
 *       Filename:  object_pool.cpp
 *
 *    Description:  
 *
 *
 *        Version:  1.0
 *        Created:  2015年07月17日 17时35分22秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (wangweihao), 578867817@qq.com
 *        Company:  xiyoulinuxgroup
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string>
#include <functional>
#include <memory>
#include <map>
#include <iostream>
#include <list>
#include <type_traits>


class NonCopyable
{
    protected:
        NonCopyable() = default;
        ~NonCopyable() = default;
        NonCopyable(const NonCopyable&) = delete;
        NonCopyable& operator= (const NonCopyable &) = delete;
};

const int MaxObjectNum = 10;

template<typename T>
class ObjectPool : NonCopyable
{
    template<typename... Args>
    using Constructor = std::function<std::shared_ptr<T>(Args...)>;

    public:
        //object num
        template<typename ...Args>
        void Init(size_t num, Args&& ...args)
        {
            if(num < 0 || num > MaxObjectNum)
            {
                throw std::logic_error("object num out of range.");
            }
            auto constructName = typeid(Constructor<Args...>).name();
            for(size_t i = 0; i < num; i++)
            {
                m_object_map.emplace(constructName, std::shared_ptr<T>(new T(std::forward<Args>(args)...), 
                            [this, constructName](T* p)
                            {
                                //not delete object, collect object pool
                                m_object_map.emplace(std::move(constructName), std::shared_ptr<T>(p));
                            }));
            }
        }

        template<typename... Args>
        std::shared_ptr<T>Get()
        {
            //obtain the object type, according to type obtain object
            std::string constructName = typeid(Constructor<Args...>).name();

            auto range = m_object_map.equal_range(constructName);
            for(auto it = range.first; it != range.second; ++it)
            {
                auto ptr = it->second;
                m_object_map.erase(it);
                return ptr;
            }
            return nullptr;
        }
    private:
        std::multimap<std::string, std::shared_ptr<T>>m_object_map;
};


int main(int argc, char *argv[])
{
    ObjectPool<std::list<int>> pool;
    pool.Init(5);
    {
        auto p = pool.Get();
        std::cout << typeid(p).name() << std::endl;
    }
	

	return EXIT_SUCCESS;
}


