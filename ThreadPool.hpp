//
//  ThreadPool.hpp
//  Thread
//
//  Created by 仙女 on 2017/4/30.
//  Copyright © 2017年 仙女. All rights reserved.
//

#ifndef ThreadPool_hpp
#define ThreadPool_hpp

#include <stdio.h>
#include "Thread.hpp"
#include <queue>
class ThreadPool
{
public:
    ThreadPool();
    ~ThreadPool();
    void addThreadToPool(Thread* th);
    const Thread* GetOneThread();
    ssize_t PoolSize(){return threadpool_.size();};
private:
    std::queue<Thread*> threadpool_;
};

#endif /* ThreadPool_hpp */
