#include "MyThread.h"


//测试使用beingthread()方法开启线程
void beginthreadTest() {
	HANDLE handles[2];
	handles[0] = _beginthread(run, 0, NULL);
	handles[1] = _beginthread(run, 0, NULL);
	HANDLE handle = CreateThread(NULL, 0,_run, NULL, 0, NULL);
}

//测试使用beingthread()方法开启多个线程访问公共数据
void synchrTest() {
	//定义HANDLE数组，用于接收beginthread方法返回值
	HANDLE handles[100];
	for (int i = 0; i < 10; i++)
	{
		handles[i] = CreateThread(NULL, 0, synchr, NULL, 0, NULL);
		//等待单个线程停止
		//WaitForSingleObject(handles[i],INFINITE);
	}
	//等待所有线程停止
	WaitForMultipleObjects(10, handles, TRUE, INFINITE);

	printf("\n%d\n", num);
}

//测试使用createthread()方法创建线程
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

//结束线程
void endthreadTest() {

	printf("测试第一种线程结束方法");
	system("pause");
	//_beginthread(endThread_1,0, NULL);

	printf("测试第二种线程结束方法");
	system("pause");
	//CreateThread(NULL, 0, endThread_2, NULL, 0, NULL);

	printf("测试第三种线程结束方法");
	system("pause");
	HANDLE handle = CreateThread(NULL, 0, endThread_3, NULL, 0, NULL);
	Sleep(3000);
	TerminateThread(handle , 0 );

}

//临界区
void criticalTest() {

	InitializeCriticalSection(&critical);
	HANDLE handle[threadnumber];
	for (int i = 0; i < threadnumber; i++)
	{
		handle[i] = CreateThread(NULL, 0, criticalFun, NULL, 0, NULL);
	}
	WaitForMultipleObjects(threadnumber,handle,TRUE,INFINITE);
	DeleteCriticalSection(&critical);
	printf("\nnumber = %d\n",num);
	
}