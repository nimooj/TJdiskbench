/*
* Benchmark Test for seqRead && randRead
*/

#include "stdafx.h"
#include "Benchmark.h"
#include <stdio.h>
#include <windows.h>
#pragma comment(lib, "user32.lib")
#include <atlstr.h>
#include <iostream>
#include <strsafe.h>

using namespace std;

static CString testFileDir;
static CString testFilePath;

long long Sequential_read(BenchMarkData* data)
{
	//data = (BenchMarkData*)VirtualAlloc(NULL, sizeof(BenchMarkData*), MEM_COMMIT);

	//SYSTEM_INFO dl; 
	int i, j;
	BOOL result, wait = TRUE;
	DWORD readSize;
	LARGE_INTEGER StartTime, EndTime, ElapsedSeconds;
	LARGE_INTEGER Freq;
	double bufferSize = data->pageSize * 1024;
	int loop = (int)bufferSize / data->pageSize;
	static char* p_buffer = (char*)VirtualAlloc(NULL, bufferSize, MEM_COMMIT, PAGE_READWRITE);
	CString str;

	// create Test File
	static HANDLE hFile = CreateFile(testFilePath, GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_NO_BUFFERING | FILE_FLAG_SEQUENTIAL_SCAN, NULL);
	
	if (hFile == INVALID_HANDLE_VALUE) {
		
		return -10000;
	}

	// kernel-mode access to performance counter
	// Start Performance Counter
	QueryPerformanceFrequency(&Freq);
	QueryPerformanceCounter(&StartTime);
	while (wait)
	{
		for (j = 0; j < loop; j++)
		{
			result = ReadFile(hFile, p_buffer, data->pageSize, &readSize, NULL);

			if (!result) {
				// Handle error
			}

		}
		wait = FALSE;
	}

	QueryPerformanceCounter(&EndTime);

	str.Format(_T("starttime: %d ms, endtime: %d ms"), StartTime.QuadPart, EndTime.QuadPart); // float형을 CString형으로 바꿔주기 위한 방법. 
	AfxMessageBox(str);
	ElapsedSeconds.QuadPart = EndTime.QuadPart - StartTime.QuadPart;
	ElapsedSeconds.QuadPart *= 1000000;
	str.Format(_T("%d ms"), ElapsedSeconds.QuadPart); // float형을 CString형으로 바꿔주기 위한 방법. 
	AfxMessageBox(str);
	ElapsedSeconds.QuadPart /= Freq.QuadPart;
//	CString str;
	str.Format(_T("time spent is %d ms"), ElapsedSeconds.QuadPart); // float형을 CString형으로 바꿔주기 위한 방법. 
	AfxMessageBox(str);
	return ElapsedSeconds.QuadPart;
}
long long Sequential_write(BenchMarkData* data) {
	int i, j;
	BOOL result, wait = TRUE;
	DWORD writeSize;
	LARGE_INTEGER StartTime, EndTime, ElapsedSeconds;
	LARGE_INTEGER Freq;
	int loop = (int)data->trials / data->pageSize;
	static char* p_buffer = (char*)VirtualAlloc(NULL, data->pageSize, MEM_COMMIT, PAGE_READWRITE);

	// create Test File
	static HANDLE hFile = CreateFile(testFilePath, GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_NO_BUFFERING | FILE_FLAG_SEQUENTIAL_SCAN, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		// handle error
		return -1000012;
	}

	// kernel-mode access to performance counter
	// Start Performance Counter
	QueryPerformanceFrequency(&Freq);
	QueryPerformanceCounter(&StartTime);
	while (wait)
	{
		for (j = 0; j < loop; j++)
		{

			result = WriteFile(hFile, p_buffer, data->pageSize, &writeSize, NULL);
			FlushFileBuffers(hFile);

			if (!result) {
				// Handle error
			}
		}
		wait = FALSE;
	}

	// End Performance Counter
	QueryPerformanceCounter(&EndTime);
	// Format Performance Counter unit to second ( ns to s )
	ElapsedSeconds.QuadPart = EndTime.QuadPart - StartTime.QuadPart;
	ElapsedSeconds.QuadPart *= 1000000;
	ElapsedSeconds.QuadPart /= Freq.QuadPart;

	return ElapsedSeconds.QuadPart;
}

/*from controller*/
void init(BenchMarkData* data) {
	//data = (BenchMarkData*) VirtualAlloc(NULL, sizeof(BenchMarkData*), MEM_COMMIT, PAGE_READWRITE);
	SYSTEM_INFO sysinfo;

	GetSystemInfo(&sysinfo);
	data->pageSize = sysinfo.dwPageSize;
	testFileDir.Format(_T("C:\\BenchMark_testDir"));
	CreateDirectory(testFileDir, NULL);
	//testFilePath.Format(_T("%s\\SBenchMark%08X.tmp"), testFileDir, timeGetTime());
	testFilePath.Format(_T("%s\\BenchMark_testFile.tmp"), testFileDir);
}

long long seq_read(BenchMarkData* data) {
	int i;
	long long sr = 0;
	for (i = 0; i < data->trials; i++) {
		sr += Sequential_read(data);
		//SetFilePointer(hFile, 0, NULL, FILE_BEGIN);
	}
	return sr/data->trials;
}

long long seq_write(BenchMarkData* data) {
	int i;
	long long sr = 0;
	for (i = 0; i < data->trials; i++) {
		sr += Sequential_write(data);
		//SetFilePointer(hFile, 0, NULL, FILE_BEGIN);
	}
	return sr/data->trials;
}

long long main_thr(int d) {
	DWORD thread_id;
	BenchMarkData* data = (BenchMarkData*)VirtualAlloc(NULL, sizeof(BenchMarkData*), MEM_COMMIT, PAGE_READWRITE);
	data->trials = 5;
	init(data);
	long long ans;
	if (d == 1) {
		ans = seq_read(data);
	}
	else if (d == 2)
	{
		ans = seq_write(data);
	}
	return ans;
}
