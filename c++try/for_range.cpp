/*
 * =====================================================================================
 *
 *       Filename:  for_range.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月15日 14时54分50秒
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
#include <vector>
#include <iostream>

int main(int argc, char *argv[])
{
    std::vector<int>ivec = {1,2,3,4,5,6,7,8,9,0};
    for(auto i : ivec){
        i = 100;
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for(auto i : ivec){
        std::cout << i << std::endl;
    }

	return EXIT_SUCCESS;
}


