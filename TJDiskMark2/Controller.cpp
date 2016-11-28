#include <windows.h>
#include <iostream>

#define READ   1
#define WRITE  2
#define RANDOM 3
#define SEQ       4
#define THROUGHPUT 5
#define INTEGRITY 6

BenchMarkData* data;

static CString testFileDir;
static CString testFilePath;


void main_thr() {
	DWORD thread_id = NULL;

	// Create thread for sequential read and runs it
	CreateThread(NULL, 0, seq_read, NULL, 0, &thread_id);
	//CreateThread(NULL, 0, seq_write, NULL, 0, &thread_id);

}

void init() {
	data = (BenchMarkData*)VirtualAlloc(NULL, );

	// Get CPU Cache page size
	SYSTEM_INFO  sysinfo;
	GetSystemInfo(&sysinfo);
	data.pageSize = sysinfo.dwPageSize;

	// set test file path
	//TCHAR RootPath[4];
	//wsprintf(RootPath, _T("%c:\\"), drive);
	testFileDir.Format(_T("\\.\C:\\SBenchMark%80X"), timeGetTime()); // file directory in c drive
	CreateDirectory(testFileDir, NULL);
	testFilePath.Format(_T("%s\\SBenchMark%08X.tmp"), testFileDir, timeGetTime());

}

LongLong seq_read() {
	int i;
	LongLong sr = 0;
	for (i = 0; i < data->trials; i++) {
		sr += Sequential_read(data);
		//SetFilePointer(hFile, 0, NULL, FILE_BEGIN);
	}

	return sr / data->trials;
}

void seq_write() {

}