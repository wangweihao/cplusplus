/*
 * =====================================================================================
 *
 *       Filename:  lambda.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月15日 19时48分30秒
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

int main(int argc, char *argv[])
{
	int a = 10;
    auto f = [=]() mutable { return ++a; };
    std::cout << f() << std::endl;
    std::function<int(int)> f1 = [&](int b) { return b; };
    std::cout << f1(100) << std::endl;
    std::function<int(void)> f2 = std::bind([](int a) { return a; }, 100);
    std::cout << f2() << std::endl;

	return EXIT_SUCCESS;
}


