#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<process.h>

int num = 0;

#define threadnumber 50

//����һ��ȫ�ֱ���
//int num = 0;

//�����ٽ���
CRITICAL_SECTION critical;

//���Է�������
void beginthreadTest();
void synchrTest();
void createthreadTest();
void endthreadTest();
void criticalTest();
//���ܷ�������
void run(void * p);
DWORD WINAPI _run(void * p);
DWORD WINAPI synchr(void *p);
DWORD WINAPI threadMethod(void *p);
DWORD WINAPI endThread_1(void *p);
DWORD WINAPI endThread_2(void *p);
DWORD WINAPI endThread_3(void *p);
DWORD WINAPI criticalFun(void *p);