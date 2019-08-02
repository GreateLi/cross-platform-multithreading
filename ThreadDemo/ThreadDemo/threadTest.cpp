#include "threadTest.h"
#ifdef _WIN32
#include<windows.h>
#include<stdio.h>
#endif
#include"MyAutoLock.h"

threadTest::threadTest()
{
	mythread = make_shared<my_thread>(this);
	mythread.get()->create();

	mythreadt = make_shared<my_thread>(this);
	mythreadt.get()->create();

	mythreadtt = make_shared<my_thread>(this);
	mythreadtt.get()->create();
}


threadTest::~threadTest()
{
}

void threadTest::dealwith_thing(void * thread)
{
	AutoLock lock(&myMutex);
	printf("我是线程id: %05d, testCount:%d\n",((my_thread*)thread)->GetThreadId(), testCount++);
	Sleep(1000);
}
