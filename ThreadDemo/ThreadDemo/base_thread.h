#pragma once
#ifdef WINDOWS
#include <Windows.h>
#include <process.h>
#else
#include <pthread.h>
#define INFINITE 1024*1024
#endif
#include<sstream>
#include<memory>
#include "MyMutex.h"
using namespace std;
//定义 shared_ptr<T> 的智能指
#define _PRT(T) std::shared_ptr<T>

//定义 shared_ptr<T> 的智能指
#define _PRTO(T,N,...)  std::shared_ptr<T> N(new T(##__VA_ARGS__))

//定义 shared_ptr<T> 的数组智能指
#define _PRTA(T,N,n)    std::shared_ptr<T> N(new T[n])
#define SAFE_DELETE_ARRAY(p) { if(p)  { delete[] (p);   (p) = NULL; } }
#define SAFE_RELEASE(p)      { if(p)  { (p)->Release(); (p) = NULL; } }
#define SAFE_DELETE(p)       { if(p)  { delete (p);     (p) = NULL; } }
#define SAFE_CLOSE_FILE(fp)  { if(fp) { if (!fclose(fp))(fp)= NULL; } }
#define SAFE_FREE_ARRAY(p)   { if(p)  { free(p);        (p) = NULL; } }
/*
#ifdef WINDOWS
typedef unsigned int(__stdcall *thread_func)(void*);
#else
typedef void*(*thread_func)(void*);
#endif
*/
 
class base_thread
{
public:
public:
	base_thread();
	virtual ~base_thread();

	bool create();
//	void wait();
	// 等待线程退出
	bool Wait(unsigned long milli = INFINITE);

	// 判断线程是否正在运行
	bool IsRunning();

	// 停止线程，调用后可以调用wait等待线程真正完全退出
	void Terminate();

	// 获取线程ID
	int GetThreadId() { return m_nThreadId; }
	void SleepMill(int ms);
	bool IsBreak();
protected:
	// 子类必须以该函数作为循环的条件，以保证调用terminate时能安全退出线程

	virtual void run() = 0;

#ifdef WINDOWS
	static unsigned __stdcall thread_func(void* arg);
#else
	static void* thread_func(void* arg);
#endif

private:
	MyMutex mPThread_Mutex;
#ifdef WINDOWS

	unsigned int m_nThreadId;
	HANDLE m_handle;
#else
	pthread_t m_nThreadId;
#endif
	bool m_bBreak;
};
 