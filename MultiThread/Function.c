#include "MyThread.h"


//1.���̴߳���ʾ��
void run(void * p) {
	MessageBox(0, "���̲߳���", "��Ϣ", 0);
}

//2.�̵߳Ķ���ͽⶳ
void notify(void *p) {
	int i = 0;
	while (1) {
		printf("\n%d\n", i);
		Sleep(1000);
		i++;
	}
}

//3.���̷߳����ļ�������
DWORD WINAPI synchr(void *p) {
	int i = 0;
	while (i<1000)
	{
		number++;
		i++;
	}
}

//4.�߳�ͨ��
DWORD WINAPI threadMethod(void *p) {
	int i = 0;
	while (1) {
		printf("\n%d\n", i);
		Sleep(1000);
		i++;
	}
}

//5.�����̣߳��ڲ�����1
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
//6.�����̣߳��ڲ�����2
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
//7.�����̣߳��ⲿ����
DWORD WINAPI endThread_3(void *p) {
	int i = 0;
	while (i) {
		printf("\n%d\n", i);
		Sleep(1000);
		i++;
	}
}

//8.�ٽ���ʹ��
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

