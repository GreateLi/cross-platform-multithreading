#include "MyMutex.h"
#ifndef _WIN32


MyMutex::MyMutex()
{
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&m_mutex, &attr);
    pthread_mutexattr_destroy(&attr);
}


MyMutex::~MyMutex()
{
    pthread_mutex_destroy(&m_mutex);
}

virtual void MyMutex::lock() { pthread_mutex_lock(&m_mutex); }
virtual void MyMutex::unlock() { pthread_mutex_unlock(&m_mutex); }
#endif
