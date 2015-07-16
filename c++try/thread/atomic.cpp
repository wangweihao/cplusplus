/*
 * =====================================================================================
 *
 *       Filename:  atomic.cpp
 *
 *    Description:  
 *
 *
 *        Version:  1.0
 *        Created:  2015年07月17日 00时06分23秒
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
#include <atomic>
#include <thread>
#include <vector>
#include <iostream>

std::atomic<int>atc(0);

void func()
{
    std::cout << atc << std::endl;
    atc++;
}

int main(int argc, char *argv[])
{
    std::vector<std::thread>tvec;
    for(int i = 0; i < 10; i++)
    {
        std::thread t(func);
        tvec.push_back(std::move(t));
        tvec[i].join();
    }

	return EXIT_SUCCESS;
}


