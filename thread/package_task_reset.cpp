/*
 * =====================================================================================
 *
 *       Filename:  package_task_reset.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月20日 08时48分13秒
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

int func(int x) { return x*x; }

int main(int argc, char *argv[])
{
    std::packaged_task<int(int)> tsk(func);

    std::future<int>fut = tsk.get_future();
    tsk(1000);
    std::cout << fut.get() << std::endl;

    tsk.reset();
    fut = tsk.get_future();
    std::thread(std::move(tsk), 1000).detach();
    std::cout << fut.get() << std::endl;

	return EXIT_SUCCESS;
}


