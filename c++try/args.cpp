/*
 * =====================================================================================
 *
 *       Filename:  args.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月16日 09时17分07秒
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
#include <string>

template<class... T>
void f(T... args)
{
    std::cout << sizeof...(args) << std::endl;
}

int main(int argc, char *argv[])
{
    std::string s("123");
	f();
    f(123);
    f(s);

	return EXIT_SUCCESS;
}


