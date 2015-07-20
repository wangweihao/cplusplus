/*
 * =====================================================================================
 *
 *       Filename:  packahed_task.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月20日 07时56分17秒
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
#include <future>
#include <iostream>
#include <thread>
#include <chrono>

int func(int a)
{
    for(int i = 0;i < a; i++)
    {
        std::cout << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return a;

}

int main(int argc, char *argv[])
{
    //package task 
    std::packaged_task<int(int)> task(func);
    //future get some result
    std::future<int> ret = task.get_future();

    //create thread execute task, this must use std::move, because packaged_task 
    std::thread tid(std::move(task), 10);
    std::cout << "sorry...no block?" << std::endl;
    int value = ret.get();
    std::cout << "the future value is:" << value << std::endl;

    tid.join();

	return EXIT_SUCCESS;
}


