#include "MyThread.h"


void run(void * p) {
	MessageBox(0, "多线程测试", "信息", 0);

}
//多线程创建示例
DWORD WINAPI _run(void * p) {
	MessageBox(0, "多线程测试", "信息", 0);
	
}

//多线程访问文件域数据
DWORD WINAPI synchr(void *p) {
	int i = 1;
	while (i<1000)
	{
		i++;
	}
}

//线程通信
DWORD WINAPI threadMethod(void *p) {
	int i = 0;
	while (1) {
		printf("\n%d\n", i);
		Sleep(1000);
		i++;
	}
}

//结束线程，内部结束1
DWORD WINAPI endThread_1(void *p) {
	int i = 1;
	while (1) {
		printf("\n%d\n", i);
		Sleep(1000);
		i++;
		if (i == 10) {
			_endthread();
		}
	}
}
//结束线程，内部结束2
DWORD WINAPI endThread_2(void *p) {
	int i = 1;
	while (1) {
		printf("\n%d\n", i);
		Sleep(1000);
		i++;
		if (i == 10) {
			ExitThread(0);
		}
	}
}
//结束线程，外部结束
DWORD WINAPI endThread_3(void *p) {
	int i = 1;
	while (1) {
		printf("\n%d\n", i);
		Sleep(1000);
		i++;
	}
}

//临界区使用
DWORD WINAPI criticalFun(void *p) {

	
	int i = 1;
	EnterCriticalSection(&critical);
	while (i<1000)
	{
		num++;
		i++;
	}
	LeaveCriticalSection(&critical);

	return 0;
}

