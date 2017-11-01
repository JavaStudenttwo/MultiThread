#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<process.h>

int num = 0;

#define threadnumber 50

//定义一个全局变量
//int num = 0;

//定义临界区
CRITICAL_SECTION critical;

//测试方法声明
void beginthreadTest();
void synchrTest();
void createthreadTest();
void endthreadTest();
void criticalTest();
//功能方法声明
void run(void * p);
DWORD WINAPI _run(void * p);
DWORD WINAPI synchr(void *p);
DWORD WINAPI threadMethod(void *p);
DWORD WINAPI endThread_1(void *p);
DWORD WINAPI endThread_2(void *p);
DWORD WINAPI endThread_3(void *p);
DWORD WINAPI criticalFun(void *p);