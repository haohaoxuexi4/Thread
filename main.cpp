//
//  main.cpp
//  Thread
//
//  Created by 仙女 on 2017/4/29.
//  Copyright © 2017年 仙女. All rights reserved.
//

#include <iostream>
#include "Thread.hpp"
struct aa {
    void test()
    {
        int i=0;
        printf("ddd=%d\n",i);
        i++;
        //sleep(1);
    }
};
void g()
{
    for (int i=0; i<9; i++) {
        printf("ni=\n");

    }
};
typedef std::function<void ()> ThreadFunction;

int main(int argc, const char * argv[]) {
    // insert code here...

    ThreadFunction f=std::bind(g);
    Thread th(f);
    th.Start();
    //th.Run();
    sleep(3);
    return 0;
}
