#pragma once
#include"my_thread.h"
class threadTest
{
public:
	threadTest();
	~threadTest();

public :
	void dealwith_thing(void * thread);

private :
	MyMutex myMutex;
	int testCount;
	_PRT( my_thread) mythread;

	_PRT(my_thread) mythreadt;

	_PRT(my_thread) mythreadtt;
};

