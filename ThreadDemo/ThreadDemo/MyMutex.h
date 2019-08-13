#pragma once
#if defined(WIN32) || defined(_WIN32) || defined(WINDOWS) 
#include<windows.h>
#else
#include <pthread.h>
#endif

class base_lock
{
public:
	virtual ~base_lock() { }

public:
	virtual void lock() = 0;
	virtual void unlock() = 0;
};

#if defined(WIN32) || defined(_WIN32) || defined(WINDOWS) 
 
	class MyMutex: public base_lock
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

		virtual void lock() 
		{ 
			EnterCriticalSection(&m_mutex); 
		}
		virtual void unlock() 
		{ 
			LeaveCriticalSection(&m_mutex);
		}
	};


#else
	class MyMutex : public base_lock
	{
	private:
		pthread_mutex_t m_mutex;
	public:
		MyMutex();
		~MyMutex();
		virtual void lock();
		virtual void unlock();
	 
	};

};

#endif