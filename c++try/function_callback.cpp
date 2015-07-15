/*
 * =====================================================================================
 *
 *       Filename:  function_callback.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月15日 16时37分48秒
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
#include <functional>

class A
{
    std::function<void()> callback_;

    public:
        A(const std::function<void()>&f):
            callback_(f)
        {}

        void notify(void)
        {
            callback_();
        }
};

class Foo
{
    public:
        void operator()(void)
        {
            std::cout << __FUNCTION__ << std::endl;
        }
};

int main(int argc, char *argv[])
{
	Foo foo;
    foo();
    A aa(foo);
    A bb = foo();
    aa.notify();

	return EXIT_SUCCESS;
}


