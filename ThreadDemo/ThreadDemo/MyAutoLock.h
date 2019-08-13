#pragma once

#ifndef   _MY_AUTO_LOCK_H
#define   _MY_AUTO_LOCK_H

#ifdef _WIN32
#include<windows.h>
#else
#include <pthread.h>
#endif
#include "MyMutex.h"
class AutoLock {

private:
	MyMutex *m_mutex;
public:
	AutoLock(MyMutex * mutex) : m_mutex(mutex)
	{
		if (m_mutex)
			m_mutex->lock();
	}
	~AutoLock()
	{
		if (m_mutex)
			m_mutex->unlock();
	}
 
};
#endif  //_MY_AUTO_LOCK_H