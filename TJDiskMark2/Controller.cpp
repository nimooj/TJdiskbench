#include "Benchmark.h"
#include <windows.h>
#include <stdio.h>
#pragma comment(lib, "user32.lib")
#include <atlstr.h>
#include <iostream>

static long long Sequential_read(BenchMarkData* data);
static void Random_read(BenchMarkData* data);

BenchMarkData* data;

static CString testFileDir;
static CString testFilePath;

void init() {
	data = (BenchMarkData*) VirtualAlloc(NULL, sizeof(BenchMarkData*), MEM_COMMIT, PAGE_READWRITE);
	// Get CPU Cache page size
	SYSTEM_INFO sysinfo;
	GetSystemInfo(&sysinfo);
	data->pageSize = sysinfo.dwPageSize;

	// set test file pathu
	//TCHAR RootPath[4];
	//wsprintf(RootPath, _T("%c:\\"), drive);
	testFileDir.Format(_T("\\.\C:\\SBenchMark%80X"), timeGetTime()); // file directory in c drive
	CreateDirectory(testFileDir, NULL);
	testFilePath.Format(_T("%s\\SBenchMark%08X.tmp"), testFileDir, timeGetTime());

}

long long seq_read() {
	int i;
	long long sr = 0;
	for (i = 0; i < data->trials; i++) {
		sr += Sequential_read(data);
		//SetFilePointer(hFile, 0, NULL, FILE_BEGIN);
	}

	return sr / data->trials;
}

void seq_write() {

}

void main_thr() {
	DWORD thread_id;

	// Create thread for sequential read and runs it
	CreateThread(NULL, 0, seq_read, NULL, 0, &thread_id);
	//CreateThread(NULL, 0, seq_write, NULL, 0, &thread_id);

}