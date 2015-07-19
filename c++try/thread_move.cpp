/*
 * =====================================================================================
 *
 *       Filename:  thread_move.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月19日 19时19分30秒
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
#include <thread>

void func(int &a)
{
    a = 100;
}

int main(int argc, char *argv[])
{
    int i = 10;
    int j = 10;
    //std::thread tid(func, std::ref(i));
    //std::thread tid(func, i);
    //tid.join();
    auto f1 = std::bind(func, i);
    auto f2 = std::bind(func, std::ref(j));
    f1();
    f2();
    std::cout << "i:" << i << " j:" << j << std::endl;

	return EXIT_SUCCESS;
}


