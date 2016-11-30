/*
* Benchmark Test for seqWrite && randWrite
*/

#include "stdafx.h"
#include "TJDiskMark2.h"
#include "Controller.cpp"
#include <stdio.h>
#include <windows.h>

long long Sequential_write(BenchMarkData* data) {
	int i, j;
	BOOL result, wait = TRUE;
	DWORD writeSize;
	LARGE_INTEGER StartTime, EndTime, ElapsedSeconds;
	LARGE_INTEGER Freq;
	int loop = (int)data->trials / data->pageSize;
	static char* p_buffer = (char*)VirtualAlloc(NULL, data->pageSize, MEM_COMMIT, PAGE_READWRITE);

	// create Test File
	static HANDLE hFile = CreateFile(testFilePath, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_NO_BUFFERING | FILE_FLAG_SEQUENTIAL_SCAN, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		// handle error
		return;
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

			// End Performance Counter
			QueryPerformanceCounter(&EndTime);

			if (!result) {
				// Handle error
			}
		}
		wait = FALSE;
	}
	// Format Performance Counter unit to second ( ns to s )
	ElapsedSeconds.QuadPart = EndTime.QuadPart - StartTime.QuadPart;
	ElapsedSeconds.QuadPart *= 1000000;
	ElapsedSeconds.QuadPart /= Freq.QuadPart;

	return ElapsedSeconds.QuadPart;
}

long long Random_write(BenchMarkData* data) {

}
