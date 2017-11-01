#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<process.h>
 
int num = 0;

#define threadnumber 10
CRITICAL_SECTION critical;
DWORD WINAPI criticalFun(void *p);

int main() {
	InitializeCriticalSection(&critical);
	HANDLE handle[threadnumber];
	for (int i = 0; i < threadnumber; i++)
	{
		handle[i] = CreateThread(NULL, 0, criticalFun, NULL, 0, NULL);
	}
	WaitForMultipleObjects(threadnumber, handle, TRUE, INFINITE);
	DeleteCriticalSection(&critical);
	printf("\nnumber = %d\n", num);
	system("pause");
}

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