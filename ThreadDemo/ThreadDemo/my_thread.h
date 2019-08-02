#pragma once
#include "base_thread.h"
class my_thread :
	public base_thread
{
public:
	my_thread(void* arg);
 
	~my_thread();
protected:
	// 线程运行体
	virtual void run();
	void * object;
	void* pClass;
};

