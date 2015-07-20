/*
 * =====================================================================================
 *
 *       Filename:  packaged_task2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月20日 08时25分28秒
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
#include <future>
#include <thread>

std::future<int> launcher(std::packaged_task<int(int)>& task, int arg)
{
    if(task.valid())
    {
        std::future<int> ret = task.get_future();
        std::thread (std::move(task), arg).detach();
        return ret;
    }else
    {
        return std::future<int>();
    }
}

int main(int argc, char *argv[])
{
    std::packaged_task<int(int)> tsk([](int x){
            return x*2;
            });
    std::future<int> fut = launcher(tsk, 25);

    std::cout << "............." << fut.get() << std::endl;

	return EXIT_SUCCESS;
}


