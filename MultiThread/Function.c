#include "MyThread.h"


void run(void * p) {
	MessageBox(0, "���̲߳���", "��Ϣ", 0);

}
//���̴߳���ʾ��
DWORD WINAPI _run(void * p) {
	MessageBox(0, "���̲߳���", "��Ϣ", 0);
	
}

//���̷߳����ļ�������
DWORD WINAPI synchr(void *p) {
	int i = 1;
	while (i<1000)
	{
		i++;
	}
}

//�߳�ͨ��
DWORD WINAPI threadMethod(void *p) {
	int i = 0;
	while (1) {
		printf("\n%d\n", i);
		Sleep(1000);
		i++;
	}
}

//�����̣߳��ڲ�����1
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
//�����̣߳��ڲ�����2
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
//�����̣߳��ⲿ����
DWORD WINAPI endThread_3(void *p) {
	int i = 1;
	while (1) {
		printf("\n%d\n", i);
		Sleep(1000);
		i++;
	}
}

//�ٽ���ʹ��
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

