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
#if defined(WIN32) || defined(_WIN32) || defined(WINDOWS) 
public:
	AutoLock(MyMutex * mutex) : m_mutex(mutex)
	{
		::EnterCriticalSection(&m_mutex->getMutex());
	}
	~AutoLock()
	{

		::LeaveCriticalSection(&m_mutex->getMutex());
	}

#else
public:
	AutoLock(MyMutex* mutex) : m_mutex(mutex)
	{
		pthread_mutex_lock(m_mutex->getMutex());
	}
	~AutoLock()
	{
	 
		pthread_mutex_unlock(m_mutex->getMutex());
	}
 private:
		 pthread_mutex_t  m_mutex;pthread_mutex_t m_mutex;
#endif
private:
	MyMutex *m_mutex;
};
#endif  //_MY_AUTO_LOCK_H