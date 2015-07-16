/*
 * =====================================================================================
 *
 *       Filename:  condiction_variable.cpp
 *
 *    Description:  
 *
 *
 *        Version:  1.0
 *        Created:  2015年07月16日 23时32分21秒
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
#include <condition_variable>
#include <mutex>
#include <iostream>

std::mutex m_mutex;
std::condition_variable m_cond;
int i_glob = 0;

void func()
{
    m_mutex.try_lock();
    i_glob++;


}

int main(int argc, char *argv[])
{
	

	return EXIT_SUCCESS;
}


