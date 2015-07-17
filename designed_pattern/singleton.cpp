/*
 * =====================================================================================
 *
 *       Filename:  singleton.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月17日 08时48分40秒
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
#include <iostream>
#include <memory>

template<typename T>
class Singleton
{
    public:
        template<typename ...Args>
        static T* Instance(Args&&... args)
        {
            if(m_pInstance == nullptr)
            {
                //perfect transmit
                m_pInstance = new T(std::forward<Args>(args)...);
            }
        }

        static T* GetInstance()
        {
            if(m_pInstance == nullptr)
            {
                std::logic_error("the instance is not init, please initialize the instance");
            }
            return m_pInstance;
        }

        static void DestroyInstance()
        {
            delete m_pInstance;
            m_pInstance = nullptr;
        }

    private:
        static T* m_pInstance;

    private:
        Singleton(void);
        virtual ~Singleton(void);
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
};

int main(int argc, char *argv[])
{
	

	return EXIT_SUCCESS;
}


