#include "MyThread.h"


//1.多线程创建示例
void run(void * p) {
	MessageBox(0, "多线程测试", "信息", 0);
}

//2.线程的冻结和解冻
void notify(void *p) {
	int i = 0;
	while (1) {
		printf("\n%d\n", i);
		Sleep(1000);
		i++;
	}
}

//3.多线程访问文件域数据
DWORD WINAPI synchr(void *p) {
	int i = 0;
	while (i<1000)
	{
		number++;
		i++;
	}
}

//4.线程通信
DWORD WINAPI threadMethod(void *p) {
	int i = 0;
	while (1) {
		printf("\n%d\n", i);
		Sleep(1000);
		i++;
	}
}

//5.结束线程，内部结束1
DWORD WINAPI endThread_1(void *p) {
	int i = 0;
	while (i) {
		printf("\n%d\n", i);
		Sleep(1000);
		i++;
		if (i == 10) {
			_endthread();
		}
	}
}
//6.结束线程，内部结束2
DWORD WINAPI endThread_2(void *p) {
	int i = 0;
	while (i) {
		printf("\n%d\n", i);
		Sleep(1000);
		i++;
		if (i == 10) {
			ExitThread(0);
		}
	}
}
//7.结束线程，外部结束
DWORD WINAPI endThread_3(void *p) {
	int i = 0;
	while (i) {
		printf("\n%d\n", i);
		Sleep(1000);
		i++;
	}
}

//8.临界区使用
DWORD WINAPI criticalFun(void *p) {

	EnterCriticalSection(&critical);
	int i = 0;
	while (i<1000)
	{
		number++;
		i++;
	}
	LeaveCriticalSection(&critical);

	return 0;
}

