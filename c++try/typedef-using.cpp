/*
 * =====================================================================================
 *
 *       Filename:  typedef-using.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月15日 14时08分55秒
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
#include <map>
#include <string>
#include <iostream>

typedef std::map<std::string, int> map_int_t;
typedef std::map<std::string, std::string> map_str_t;

template<typename Val>
using map_t = std::map<std::string, Val>;

//template<typename Val>
//typedef std::map<std::string, Val> map_t;

int main(int argc, char *argv[])
{
	map_t<int>mp;

	return EXIT_SUCCESS;
}


