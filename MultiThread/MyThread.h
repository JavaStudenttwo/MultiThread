#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define threadnumber 10

//����һ���ļ������������
int number;

//�����ٽ���
CRITICAL_SECTION critical;

//���Է�������
void beginthreadTest();
void createthreadTest();
void endthreadTest();
void criticalTest();

//���ܷ�������
void run(void * p);
void notify(void *p);
DWORD WINAPI synchr(void *p);
DWORD WINAPI threadMethod(void *p);
DWORD WINAPI endThread_1(void *p);
DWORD WINAPI endThread_2(void *p);
DWORD WINAPI endThread_3(void *p);
DWORD WINAPI criticalFun(void *p);