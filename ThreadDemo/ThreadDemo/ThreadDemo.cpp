// ThreadDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
#include <stdio.h>
 
#include "threadTest.h"
using namespace std;

int main()
{
    // ������Դ������
	
	threadTest * thread = new threadTest( );
 
	cout << "�߳̽�����,���س����˳�" << endl;

	getchar();
	if (nullptr != thread)
	{
		delete thread;
		thread = nullptr;
	}

	_CrtDumpMemoryLeaks();//����ڴ�й¶
	return 0;
}

