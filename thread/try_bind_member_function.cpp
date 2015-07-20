/*
 * =====================================================================================
 *
 *       Filename:  try_bind_member_function.cpp
 *
 *    Description:  
 *
 *
 *        Version:  1.0
 *        Created:  2015年07月20日 08时37分18秒
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

class Foo
{
    public:
        Foo() = default;
        
        void func(int c)
        {
            std::cout << a << std::endl;
            std::cout << c << std::endl;
        }
        static void func2(int a)
        {
            std::cout << " static function:" << a << std::endl; 
        }

    private:
        int a = 1000;
};

int main(int argc, char *argv[])
{
    Foo f;
    auto fun = std::bind(&Foo::func, f, 2000);	
    auto fun2 = std::bind(&Foo::func2, 2000);	
    fun();
    fun2();

	return EXIT_SUCCESS;
}


