/*
 * =====================================================================================
 *
 *       Filename:  mulbind.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月15日 18时43分39秒
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
#include <vector>
#include <typeinfo>
#include <algorithm>

void func(int i){
    std::cout << "haha" << " " << i << std::endl;
}


int main(int argc, char *argv[])
{
	using namespace std::placeholders;
    std::vector<int>ivec = {12,3,3245,2,34,55,4,2,1, 7,8};
    auto f = std::bind(std::logical_and<bool>(),
            std::bind(std::greater<int>(), _1, 5),
            std::bind(std::less_equal<int>(), _1, 10));
    int count = std::count_if(ivec.begin(), ivec.end(), f);
    std::cout << count << std::endl;
    std::cout << typeid(f).name() << std::endl;

    auto f2 = std::bind(func, 100);
    std::cout << typeid(f2).name() << std::endl;

	return EXIT_SUCCESS;
}


