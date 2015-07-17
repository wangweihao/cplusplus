/*
 * =====================================================================================
 *
 *       Filename:  command.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月17日 16时22分04秒
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
#include <functional>
#include <type_traits>

template<typename R = void>
struct CommCommand
{
    private:
        std::function<R()>m_f;

    public:
        //function wrap
        template<class F, class... Args, class = typename std::enable_if<
            !std::is_member_function_pointer<F>::value>::type>
        void Wrap(F &&f, Args &&... args)
        {
            m_f = [&] { return f(args...); };
        }

        template<class C, class... DArgs, class P, class... Args>
        void Wrap(R(C::*f)(DArgs...)const, P &&p, Args && ...args)
        {
            m_f = [&,f]{ return (*p.*f)(args...); };
        }

        template<class C, class... DArgs, class P, class... Args>
        void Wrap(R(C::*f)(DArgs...), P &&p, Args &&...args)
        {
            m_f = [&,f]{ return (*p.*f)(args...); };
        }

        R Excecute()
        {
            return m_f();
        }
};

struct STA
{
    int m_a;
    int operator() () { return m_a; }
    int operator() (int n ) { return m_a + n; }

}

int main(int argc, char *argv[])
{
	

	return EXIT_SUCCESS;
}


