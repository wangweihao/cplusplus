/*
 * =====================================================================================
 *
 *       Filename:  future.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月19日 23时45分29秒
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
#include <functional>
#include <future>
#include <chrono>

void print_int(std::future<int>& fut)
{
    //如果没设置值会阻塞
    int x = fut.get();
    std::cout << x << std::endl;
}

int main(int argc, char *argv[])
{
    std::promise<int> prom;
    //未来某时获取状态
    std::future<int> fut = prom.get_future();
    std::thread tid(print_int, std::ref(fut));
    std::this_thread::sleep_for(std::chrono::seconds(2));
    prom.set_value(10);
    tid.join();

	return EXIT_SUCCESS;
}


