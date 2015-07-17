/*
 * =====================================================================================
 *
 *       Filename:  wrap.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月17日 11时19分05秒
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

//thrid argument
template<class F, class... Args, typename std::enable_if<
        !std::is_member_function_pointer<F>::value>::type>
void wrap(F &&f, Args &&... args)
{
    return f(std::forward<Args>(args)...);
}

template<class R, class C, class... DArgs, class P, class... Args>
void wrap(R(C::*f)(DArgs...), P&&p, Args &&...args)
{
    return (*p.*f)(std::forward<Args>(args)...);
}

void func(int i)
{

}

int main(int argc, char *argv[])
{
	

	return EXIT_SUCCESS;
}


