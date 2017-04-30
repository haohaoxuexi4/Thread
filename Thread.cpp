//
//  Thread.cpp
//  Thread
//
//  Created by 仙女 on 2017/4/29.
//  Copyright © 2017年 仙女. All rights reserved.
//

#include "Thread.hpp"
#include <assert.h>

static void* runIntheThread(void *arg)
{
    printf("3\n");
    Thread* th=static_cast<Thread*>(arg);
    th->Run();
    return NULL;
};

Thread::Thread(ThreadFunction& fun):threadfun_(fun),isrun(false)
{
    
}
void Thread::Start()
{
    //pthread_create(&ThreadId_, NULL,runIntheThread,this);
    
    if(pthread_create(&ThreadId_, NULL,runIntheThread,this)!=0)
    {
        printf("exit\n");
        exit(1);
    }
    
    isrun=true;
    printf("1\n");
}
void Thread::Run()
{
    //assert(!isrun);
    printf("2\n");
    threadfun_();
}
int Thread::Join()
{
    //assert(!isrun);
    isrun=false;
    return pthread_join(ThreadId_,NULL);
}
Thread::~Thread()
{
    printf("~thread\n");
    pthread_detach(ThreadId_);
}
