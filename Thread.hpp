//
//  Thread.hpp
//  Thread
//
//  Created by 仙女 on 2017/4/29.
//  Copyright © 2017年 仙女. All rights reserved.
//

#ifndef Thread_hpp
#define Thread_hpp

#include <stdio.h>
#include <unistd.h>
#include "noncopy.h"
#include <pthread.h>

#include <functional>
#include <sys/types.h>
#include <sys/syscall.h>

typedef std::function<void ()> ThreadFunction;


class Thread:noncopy
{
public:
    Thread(ThreadFunction& fun);
    ~Thread();
    void Start();
    void Run();
    int Join();
    pid_t getThreadId(){return static_cast<pid_t>(syscall(SYS_gettid));};
    //static void* runIntheThread(void* arg);
private:
    
    ThreadFunction threadfun_;
    pthread_t  ThreadId_;
    bool  isrun;
};

#endif /* Thread_hpp */
