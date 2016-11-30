#include "stdafx.h"
/*#include <windows.h>
#include <stdio.h>
//#include "Benchmark_read.cpp"
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "winmm.lib")
#include <atlstr.h>
#include <iostream>

void init(BenchMarkData* data) {
	//data = (BenchMarkData*) VirtualAlloc(NULL, sizeof(BenchMarkData*), MEM_COMMIT, PAGE_READWRITE);
	SYSTEM_INFO sysinfo;
	
	GetSystemInfo(&sysinfo);
	data->pageSize = sysinfo.dwPageSize;

	// set test file pathu
	//TCHAR RootPath[4];
	//wsprintf(RootPath, _T("%c:\\"), drive);
	//testFileDir.Format(_T("\\.\C:\\SBenchMark%X"), timeGetTime()); // file directory in c drive
	testFileDir.Format(_T("\\.\C:\\BenchMark_testDir"));
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

	return sr / data->trials;
}

void seq_write(BenchMarkData* data) {

}

long long main_thr() {
	DWORD thread_id;
	BenchMarkData* data = (BenchMarkData*)VirtualAlloc(NULL, sizeof(BenchMarkData*), MEM_COMMIT, PAGE_READWRITE);
	init(data);
	// Create thread for sequential read and runs it
	long long ans = seq_read(data);
	return ans;
	//CreateThread(NULL, 0, seq_read, NULL, 0, &thread_id);
	//CreateThread(NULL, 0, seq_write, NULL, 0, &thread_id);

}*/
