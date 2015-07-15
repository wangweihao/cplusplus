/*
 * =====================================================================================
 *
 *       Filename:  initial_list.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月15日 14时33分00秒
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

class A{
    public:
    int a;
    double b;
    char c;
}d = {1,2.2, 'a'};

int main(int argc, char *argv[])
{
    A aa;
    aa.a = 1;
    aa.b = 2.2;
    aa.c = 'c';
    std::cout << d.a << " " << d.b << " " << d.c << std::endl;
    std::cout << aa.a << " " << aa.b << " " << aa.c << std::endl;

	return EXIT_SUCCESS;
}


