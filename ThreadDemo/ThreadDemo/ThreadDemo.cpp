// ThreadDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
#include <stdio.h>
 
#include "threadTest.h"
using namespace std;

int main()
{
    // ������Դ������
	
	//for (int i = 0; i < 100; i++)
	//{
	//	threadTest * thread = new threadTest();

	//	cout << "�߳̽�����,���س����˳�" << endl;

	//	//getchar();
	//	if (nullptr != thread)
	//	{
	//		delete thread;
	//		thread = nullptr;
	//	}
	// }

	threadTest * thread = new threadTest();
//	threadTest * thread1 = new threadTest();
	 
	getchar();
	_CrtDumpMemoryLeaks();//����ڴ�й¶
	return 0;
}

