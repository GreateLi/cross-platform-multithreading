#pragma once
#if defined(WIN32) || defined(_WIN32) || defined(WINDOWS) 
#include<windows.h>
#else
#include <pthread.h>
#endif
#if defined(WIN32) || defined(_WIN32) || defined(WINDOWS) 
 
	class MyMutex
	{
	private:
		CRITICAL_SECTION m_mutex;

	public:
		MyMutex()
		{
			::InitializeCriticalSection(&m_mutex);
		};
		~MyMutex()
		{
			::DeleteCriticalSection(&m_mutex);
		};
	  CRITICAL_SECTION getMutex() { return m_mutex; };
	};


#else
	class MyMutex
	{
	private:
		pthread_mutex_t m_mutex;
	public:
		MyMutex();
		~MyMutex();
		pthread_mutex_t  getMutex() { return m_mutex; };
	};

};

#endif