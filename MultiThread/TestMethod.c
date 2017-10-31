#include "MyThread.h"


//1.测试使用beingthread()方法开启多个线程访问公共数据
void beginthreadTest() {
	//定义HANDLE数组，用于接收beginthread方法返回值
	HANDLE handles[100];
	for (int i = 0; i < 10; i++)
	{
		handles[i] = _beginthread(synchr, 0, NULL);
		//等待单个线程停止
		//WaitForSingleObject(handles[i],INFINITE);
	}
	//等待所有线程停止
	WaitForMultipleObjects(10, handles, TRUE, INFINITE);

	printf("\n%d\n", number);
}

//2.测试使用createthread()方法创建线程
void createthreadTest() {
	//参数;1, 2,该线程分配栈的大小，若为0，则按照默认方式分配大小
	HANDLE handle = CreateThread(NULL, 0, threadMethod, NULL, 0, NULL);
	printf("\n继续执行，线程将被冻结\n");
	system("pause");
	//冻结线程
	SuspendThread(handle);
	printf("\n继续执行，线程将被解冻\n");
	system("pause");
	//解冻线程
	ResumeThread(handle);
	system("pause");

}

//3.线程结束
void endthreadTest() {

	printf("测试第一种线程结束方法");
	system("pause");
	_beginthread(endThread_1,0, NULL);
	//CreateThread(NULL, 0, endThread_1, NULL, 0, NULL);

	printf("测试第二种线程结束方法");
	system("pause");
	CreateThread(NULL, 0, endThread_2, NULL, 0, NULL);

	printf("测试第三种线程结束方法");
	system("pause");
	HANDLE handle = CreateThread(NULL, 0, endThread_3, NULL, 0, NULL);
	TerminateThread(handle , 0 );

}

void criticalTest() {
	InitializeCritialSection(&critical);
	HANDLE handle[threadnumber];
	for (int i = 0; i < threadnumber; i++)
	{
		handle[i] = CreateThread(NULL, 0, criticalFun, NULL, 0, NULL);
	}
	WaitForMultipleObjects(threadnumber,handle,TRUE,INFINITE);
	DeleteCriticalSection(&critical);
	printf("number = %d",number);
	
}