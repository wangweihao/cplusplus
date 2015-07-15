/*
 * =====================================================================================
 *
 *       Filename:  bind.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月15日 17时04分03秒
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

void func(int x, int y)
{
    std::cout << x << " " << y << std::endl;
}

int main(int argc, char *argv[])
{
    using namespace std::placeholders;
    std::bind(func, 1, 2)();
    std::bind(func, _1, 2)(1);
    std::bind(func, 1, _2)(3, 100);

	return EXIT_SUCCESS;
}


