/*
 * =====================================================================================
 *
 *       Filename:  type_traits.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月16日 00时17分08秒
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
#include <type_traits>

template<typename T>
void func(T t)
{
    std::cout << std::is_array<T>::value << std::endl;
    std::cout << std::is_fundamental<T>::value << std::endl;
}

int main(int argc, char *argv[])
{
    int a[10] = {1,2,3,4,5,6,7,8,9,0};
	func<int*>(a);
	func<int>(20);

	return EXIT_SUCCESS;
}


