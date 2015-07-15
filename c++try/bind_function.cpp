/*
 * =====================================================================================
 *
 *       Filename:  bind_function.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月15日 18时20分17秒
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

class A
{
    public:
        int i_ = 0;

        void output(int x, int y)
        {
            std::cout << x << " " << y << std::endl;
        }
};

int main(int argc, char *argv[])
{
    using namespace std::placeholders;
	A a;
    std::function<void(int,int)>fr = std::bind(&A::output, &a,  _1, _2);
    fr(1,2);

	return EXIT_SUCCESS;
}


