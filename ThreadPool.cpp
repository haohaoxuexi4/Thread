//
//  ThreadPool.cpp
//  Thread
//
//  Created by 仙女 on 2017/4/30.
//  Copyright © 2017年 仙女. All rights reserved.
//

#include "ThreadPool.hpp"
#include <assert.h>
ThreadPool::ThreadPool()
{

}
ThreadPool::~ThreadPool()
{
    assert(!threadpool_.empty());
    ssize_t size=threadpool_.size();
    for (int i=0;i<size; i++) {
        Thread* th=threadpool_.front();
        delete th;
        threadpool_.pop();
    }
    
}

void ThreadPool::addThreadToPool(Thread *th)
{
    assert(th!=nullptr);
    threadpool_.push(th);
}

const Thread* ThreadPool::GetOneThread()
{

    Thread* th=threadpool_.front();
    threadpool_.pop();
    return th;
}
