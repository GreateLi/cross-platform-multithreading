// ThreadDemo.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <stdio.h>
 
#include "threadTest.h"
using namespace std;

int main()
{
    // 这里可以传入对象
	
	//for (int i = 0; i < 100; i++)
	//{
	//	threadTest * thread = new threadTest();

	//	cout << "线程结束了,按回车键退出" << endl;

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
	_CrtDumpMemoryLeaks();//检测内存泄露
	return 0;
}

