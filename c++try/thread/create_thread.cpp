/*
 * =====================================================================================
 *
 *       Filename:  create_thread.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月16日 15时36分35秒
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
#include <thread>
#include <iostream>

int k = 0;

void fun(void)
{
    std::this_thread::sleep_for(std::chrono::seconds(3));
    for(int i = 0; i < 10; ++i)
    {
        std::cout << "hello world" << std::endl;
        k++;
    }
}

int main(int argc, char *argv[])
{
    std::thread t1(fun);
    std::cout << "ID:" << t1.get_id() << std::endl;
    std::cout << "CPU:" << std::thread::hardware_concurrency() << std::endl;
    t1.join();
    //t1.detach();

    std::cout << k << std::endl;

	return EXIT_SUCCESS;
}


