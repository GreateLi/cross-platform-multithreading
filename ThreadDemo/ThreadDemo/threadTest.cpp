#include "threadTest.h"
#ifdef _WIN32
#include<windows.h>
#include<stdio.h>
#endif
#include"MyAutoLock.h"
//#include"auto_lock.h"


threadTest::threadTest()
{
	testNumber = 0;
	testCount = 0;
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


void threadTest::dealwith_thingTT(void * thread)
{
	//AutoLock lock(&mMutexTest);
	//printf("我是线程id: %05d, testNumber:%d\n", ((my_thread*)thread)->GetThreadId(), testNumber++);
	//Sleep(1000);
	dealwith_thingNumber(thread);
}

void threadTest::dealwith_thing(void * thread)
{
	dealwith_thingCount(thread);
	dealwith_thingNumber(thread);
}

void threadTest::dealwith_thingCount(void * thread)
{
	 AutoLock lock(&mMutexTest);
	//auto_lock lock(&cs_lock_count);
	printf("我是线程id: %05d, testCount:%d\n", ((my_thread*)thread)->GetThreadId(), testCount++);
	Sleep(1000);
}
void threadTest::dealwith_thingNumber(void * thread)
{
	  AutoLock llock(&myMutex);
	
	//auto_lock lock(&cs_lock_number );
	printf("我是线程---id: %05d, ----------------------testNumber:%d\n", ((my_thread*)thread)->GetThreadId(), testNumber++);
}
