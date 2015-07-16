/*
 * =====================================================================================
 *
 *       Filename:  mutex.cpp
 *
 *    Description:  
 *
 *
 *        Version:  1.0
 *        Created:  2015年07月16日 16时10分26秒
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
#include <thread>
#include <mutex>

std::mutex g_lock;
int i = 0;

void func(void)
{
    std::lock_guard<std::mutex>locker(g_lock);
    //g_lock.lock();
    i++;
    std::cout << i << std::endl;
    //g_lock.unlock();
}

int main(int argc, char *argv[])
{
    std::thread t1(func);
	std::thread t2(func);
	std::thread t3(func);
    t1.join();
    t2.join();
    t3.join();

	return EXIT_SUCCESS;
}


