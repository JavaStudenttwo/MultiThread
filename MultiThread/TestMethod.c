#include "MyThread.h"


//1.����ʹ��beingthread()������������̷߳��ʹ�������
void beginthreadTest() {
	//����HANDLE���飬���ڽ���beginthread��������ֵ
	HANDLE handles[100];
	for (int i = 0; i < 10; i++)
	{
		handles[i] = _beginthread(synchr, 0, NULL);
		//�ȴ������߳�ֹͣ
		//WaitForSingleObject(handles[i],INFINITE);
	}
	//�ȴ������߳�ֹͣ
	WaitForMultipleObjects(10, handles, TRUE, INFINITE);

	printf("\n%d\n", number);
}

//2.����ʹ��createthread()���������߳�
void createthreadTest() {
	//����;1, 2,���̷߳���ջ�Ĵ�С����Ϊ0������Ĭ�Ϸ�ʽ�����С
	HANDLE handle = CreateThread(NULL, 0, threadMethod, NULL, 0, NULL);
	printf("\n����ִ�У��߳̽�������\n");
	system("pause");
	//�����߳�
	SuspendThread(handle);
	printf("\n����ִ�У��߳̽����ⶳ\n");
	system("pause");
	//�ⶳ�߳�
	ResumeThread(handle);
	system("pause");

}

//3.�߳̽���
void endthreadTest() {

	printf("���Ե�һ���߳̽�������");
	system("pause");
	_beginthread(endThread_1,0, NULL);
	//CreateThread(NULL, 0, endThread_1, NULL, 0, NULL);

	printf("���Եڶ����߳̽�������");
	system("pause");
	CreateThread(NULL, 0, endThread_2, NULL, 0, NULL);

	printf("���Ե������߳̽�������");
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