#pragma once
#include"my_thread.h"
//#include"base_lock.h"

class threadTest
{
public:
	threadTest();
	~threadTest();

public :
	void dealwith_thing(void * thread);
	void dealwith_thingTT(void * thread);
private :
	void dealwith_thingCount(void * thread);
	void dealwith_thingNumber(void * thread);
	MyMutex myMutex;

	MyMutex mMutexTest;

	//win_cs_lock cs_lock_count;
	//win_cs_lock cs_lock_number;
	int testCount;
	int testNumber;
	_PRT( my_thread) mythread;

	_PRT(my_thread) mythreadt;

	_PRT(my_thread) mythreadtt;
};

