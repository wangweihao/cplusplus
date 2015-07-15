/*
 * =====================================================================================
 *
 *       Filename:  algorithm_lambda.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月15日 20时11分28秒
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
#include <algorithm>
#include <vector>
#include <typeinfo>

int main(int argc, char *argv[])
{
    std::vector<int>ivec = {1,2,3,4,5,6,7,8,9,0};
    int count = 0;
    std::for_each(ivec.begin(), ivec.end(), [&count](int val)
    {
        if(!(val & 1))
        {
            std::cout << val << std::endl;
            ++count;
        }
    });
    std::cout << "count:" << count << std::endl; 
    auto f =  for_each(ivec.begin(), ivec.end(), [](int val) {
            if(val > 5 && val < 10)
            {
                std::cout << val << std::endl;
            }
        });
    std::cout << typeid(f).name() << std::endl;
 
    f(8);

    return EXIT_SUCCESS;
}


