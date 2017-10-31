#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define threadnumber 10

//定义一个文件作用域的数据
int number;

//定义临界区
CRITICAL_SECTION critical;

//测试方法声明
void beginthreadTest();
void createthreadTest();
void endthreadTest();
void criticalTest();

//功能方法声明
void run(void * p);
void notify(void *p);
DWORD WINAPI synchr(void *p);
DWORD WINAPI threadMethod(void *p);
DWORD WINAPI endThread_1(void *p);
DWORD WINAPI endThread_2(void *p);
DWORD WINAPI endThread_3(void *p);
DWORD WINAPI criticalFun(void *p);