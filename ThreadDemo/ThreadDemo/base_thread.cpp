
#include "base_thread.h"
#include"MyAutoLock.h"
base_thread::base_thread()
	: m_nThreadId(0)
	, m_bBreak(false)
{
#ifdef WINDOWS
	m_handle = NULL;
#endif
}

base_thread::~base_thread()
{
	if (IsRunning())
	{
		Terminate();
		Wait();
	}
#ifdef WINDOWS
	if (NULL != m_handle)
	{
		CloseHandle(m_handle);
	}
	m_handle = NULL;
#else
	m_thread_t = 0;
#endif
}

bool base_thread::create()
{
	m_bBreak = false;
	bool ret = false;
#ifdef WINDOWS
	m_handle = (HANDLE)_beginthreadex(NULL, 0, thread_func, this, 0, &m_nThreadId);
 
	if (NULL != m_handle)
	{
		ret = true;
	}
#else
	if (0 == pthread_create(&m_nThreadId, NULL, thread_func, this))
	{
		ret = true;
	}
	else
	{
		m_nThreadId = 0;
	}
#endif
	return ret;
}

 bool base_thread::Wait(unsigned long milli /*= INFINITE*/)
{
	bool retWait = false;
	if (!IsRunning())
	{
		return true;
	}
 
#ifdef WINDOWS
		DWORD ret = WaitForSingleObject(m_handle, milli);
		if (WAIT_OBJECT_0 == ret)
		{
			retWait = true;
		}
		else if (WAIT_TIMEOUT == ret)
		{
			retWait = false;
		}
		if (NULL != m_handle)
		{
			CloseHandle(m_handle);
		}
		m_handle = NULL;
		return retWait;
#else
	int ret = pthread_join(m_nThreadId, NULL);
	m_nThreadId = 0;
	//POSIX_ASSERT(ret);

	return true;
#endif // WINDOWS
}

#ifdef WINDOWS
unsigned __stdcall base_thread::thread_func(void* arg)
#else
void* base_thread::thread_func(void* arg)
#endif
{
	base_thread *pthis = (base_thread*)arg;
	pthis->run();
	return 0;
}

bool base_thread::IsRunning()
{
	AutoLock lock(&mPThread_Mutex);
	bool ret = 0 != m_nThreadId;
	 
	return ret;
}

void base_thread::Terminate()
{
	AutoLock lock(&mPThread_Mutex);
	m_bBreak = true;	
}

bool base_thread::IsBreak()
{
	return m_bBreak;
}

void base_thread::SleepMill(int ms)
{
#ifdef WIN32
	Sleep(ms);
#else
	usleep(ms * 1000);
#endif
}