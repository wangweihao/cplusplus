/*
 * =====================================================================================
 *
 *       Filename:  shared_ptr_lambda.cpp
 *
 *    Description:  
 *
 *
 *        Version:  1.0
 *        Created:  2015年07月21日 15时09分55秒
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
#include <memory>

using f = std::function<void(int)>;

int main(int argc, char *argv[])
{
    int a = 10;
    std::shared_ptr<f> ptr = std::make_shared<f>([=](int b) { 
            std::cout << a << std::endl;
            std::cout << b << std::endl;
            std::cout << 10 << std::endl;
            });
    (*ptr)(2);

	return EXIT_SUCCESS;
}


