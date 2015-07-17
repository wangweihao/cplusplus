/*
 * =====================================================================================
 *
 *       Filename:  observe.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月17日 09时34分44秒
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
#include <memory>
#include <map>
#include <iostream>

class NonCopyable
{
    protected:
        NonCopyable() = default;
        ~NonCopyable() = default;
        NonCopyable(const NonCopyable&) = delete;
        NonCopyable& operator=(const NonCopyable&) = delete;
};

template<typename Func>
class Events : NonCopyable
{
    public:
        Events() { }
        ~Events() { }

        int Connect(const Func &f)
        {
            return Assgin(f);
        }

        int Connect(Func &&f)
        {
            return Assgin(f);
        }

        void Disconnect(int key)
        {
            m_connections.erase(key);
        }

        //notiify all
        template<typename ...Args>
        void Notify(Args&&... args)
        {
            for(auto it : m_connections)
            {
                it.second(std::forward<Args>(args)...);
            }
        }

    private:
        template<typename F>
        int Assgin(F &&f)
        {
            int k = m_observerId++;
            m_connections.emplace(k, std::forward<F>(f));
            return k;
        }

    private:
        int m_observerId = 0;
        std::map<int, Func>m_connections;
};

void print(int a, int b)
{
    std::cout << "print:" << a << "," << b << std::endl;
}

int main(int argc, char *argv[])
{
    using namespace std::placeholders;
    Events<std::function<void(int, int)>>myevent;

    auto funcion_key = myevent.Connect(print); 
    auto lambda_key = myevent.Connect([](int a, int b) { std::cout << "lambda:" << a << "," << b << std::endl; });
    std::function<void(int,int)>f = std::bind(print, 1000, 2);
    auto bind_key = myevent.Connect(f);
    int a = 1, b = 2;
    myevent.Notify(a,b);
    myevent.Disconnect(1);
    std::cout << "----" << std::endl;
    myevent.Notify(a,b);

	return EXIT_SUCCESS;
}


