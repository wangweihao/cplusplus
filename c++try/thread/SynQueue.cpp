/*
 * =====================================================================================
 *
 *       Filename:  SynQueue.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月16日 17时05分52秒
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
#include <mutex>
#include <thread>
#include <condition_variable>
#include <iostream>
#include <list>
#include <vector>
#include <memory>
#include <unistd.h>

template<typename T>
class SynQueue
{
    public:
        SynQueue(int MaxSize):
            m_maxsize(MaxSize) { }

        void Put(const T&x)
        {
            std::lock_guard<std::mutex> locker(m_mutex);
            while(isFull())
            {
                m_notFull.wait(m_mutex);
            }
            m_queue.push_back(x);
            m_notEmpty.notify_one();
        }
        
        void Take(T&x)
        {
            std::lock_guard<std::mutex> locker(m_mutex);
            while(isEmpty())
            {
                std::cout << "no resource... please wait" << std::endl;
                m_notEmpty.wait(m_mutex);
            }
            x = m_queue.front();
            m_queue.pop_front();
            m_notFull.notify_one();
        }

        bool Empty()
        {
            std::lock_guard<std::mutex> locker(m_mutex);
            return m_queue.empty();
        }

        bool Full()
        {
            std::lock_guard<std::mutex> locker(m_mutex);
            return m_queue.size() == m_maxsize;
        }

        size_t Size()
        {
            std::lock_guard<std::mutex> locker(m_mutex);
            return m_queue.size();
        }

    private:
        bool isFull() const
        {
            return m_queue.size() == m_maxsize;
        }
        bool isEmpty() const
        {
            return m_queue.empty();
        }

    private:
        std::list<T>m_queue;
        std::mutex m_mutex;
        std::condition_variable_any m_notEmpty;
        std::condition_variable_any m_notFull;
        int m_maxsize;
};

void func(SynQueue<int> *sq)
{
    int ret;
    sq->Take(ret);
    std::cout << ret << std::endl;
}

int main(int argc, char *argv[])
{
    SynQueue<int>syn(20);
    for(int i = 0; i < 10; i++)
    {
        syn.Put(i);
    }
    std::cout << syn.Size() << std::endl;

    std::vector<std::shared_ptr<std::thread>> tvec;
    for(int i = 0; i < 11; i++)
    {
        tvec.push_back(std::make_shared<std::thread>(func, &syn));
        tvec[i]->detach();
    }
    sleep(10);
    syn.Put(11);
    sleep(10);
    // std::thread t1(func, &syn);
    // t1.join();
    // tvec.push_back()


	return EXIT_SUCCESS;
}


