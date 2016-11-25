/*
* Benchmark Test for seqRead && randRead
*/

#include "stdafx.h"
#include "TJDiskMark2.h"
#include "Controller.cpp"
#include "Benchmark.h"
#include <stdio.h>
#include <windows.h>
#include <winbase.h>

int loop = (int)data.trials / data.pageSize;

static void Sequential_read(BenchMarkData* data);
static void Random_read(BenchMarkData* data);

LongLong Sequential_read(BenchMarkData* data)
{

	int i, j;
	BOOL result, wait = TRUE;
	DWORD readSize;
	LARGE_INTEGER StartTime, EndTime, ElapsedSeconds;
	LARGE_INTEGER Freq;

	static char* p_buffer = (char*)VirtualAlloc(NULL, data->pageSize, MEM_COMMIT, PAGE_READWRITE);

	// create Test File
	static HANDLE hFile = CreateFile(testFilePath, GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_READONLY | FILE_FLAG_NO_BUFFERING | FILE_FLAG_SEQUENTIAL_SCAN, NULL);

	if (hFile == INVALID_HANDLE_VALUE) {
		// handle error
		return;
	}

	// kernel-mode access to performance counter
	// Start Performance Counter
	StartTime = keQueryPerformanceCounter(&freq);
	while (wait)
	{
		for (j = 0; j < loop; j++)
		{

			result = ReadFile(hFile, p_buffer, data->pageSize, &readSize, NULL);

			// End Performance Counter
			EndTime = KeQueryPerformanceCounter(NULL);

			if (!result) {
				// Handle error
			}

		}
		wait = FALSE;
	}
	// Format Performance Counter unit to second ( ns to s )
	ElapsedSeconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;
	ElapsedSeconds.QuadPart *= 1000000;
	ElapsedSeconds.QuadPart /= Frequency.QuadPart;

	return ElapsedSeconds.QuadPart;
}

/*
void Random_read(void* dlg) {
static CString cstr;
int count;
double score, maxScore;
DWORD start, finish;
int i, j;
DWORD readSize, writeSize;
int bufSize;
int loop;
int split;
score = 0.0;
maxScore = 0.0;

// init
if(size == 512)
{
bufSize = size * 1024;
loop = 20;
split = 2 * (int)(DiskTestSize / 1024 / 1024);
}
else if(size == 4)
{
bufSize = size * 1024;
loop = 160;
split = 256 * (int)(DiskTestSize / 1024 / 1024);
}
else
{
return ;
}

//////////////////////////////////////////////
// Read Test
//////////////////////////////////////////////
if(! ((CDiskMarkDlg*)dlg)->m_DiskBenchStatus)
{
return ;
}

for(j = 0; j <= Trials; j++)
{
if(j == 0)
{
cstr.Format(_T("Preparing... Random Read %dKB"), size);
}
else
{
cstr.Format(_T("Random Read %dKB [%d/%d]"), size, j, Trials);
}
::PostMessage(((CDiskMarkDlg*)dlg)->GetSafeHwnd(), WM_USER_UPDATE_MESSAGE, (WPARAM)&cstr, 0);

hFile = ::CreateFile(TestFilePath, GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING,
FILE_ATTRIBUTE_NORMAL|FILE_FLAG_NO_BUFFERING|FILE_FLAG_RANDOM_ACCESS, NULL);
if(hFile == INVALID_HANDLE_VALUE)
{
ShowErrorMessage(((CDiskMarkDlg*)dlg)->m_MesDiskCreateFileError);
((CDiskMarkDlg*)dlg)->m_DiskBenchStatus = FALSE;
return ;
}

count = 0;
WaitFlag = TRUE;
SetTimer(((CDiskMarkDlg*)dlg)->GetSafeHwnd(), TIMER_ID, DISK_TEST_TIME, TimerProc);
start = timeGetTime();
LARGE_INTEGER pointer;
do{
for(i = 0; i < loop; i++)
{
pointer.QuadPart = xor128() % split * bufSize;
if(SetFilePointerEx(hFile, pointer, NULL, FILE_BEGIN)
&& ReadFile(hFile, buf, bufSize, &readSize, NULL))
{
count++;
}
else
{
CloseHandle(hFile);
ShowErrorMessage(((CDiskMarkDlg*)dlg)->m_MesDiskReadError);
((CDiskMarkDlg*)dlg)->m_DiskBenchStatus = FALSE;
return ;
}
}
}while(WaitFlag);
CloseHandle(hFile);
finish = timeGetTime();

if(j != 0)
{
score = count * (bufSize / 1000.0) / (finish - start);
if(score > maxScore)
{
maxScore = score;
}
readScore = score;
::PostMessage(((CDiskMarkDlg*)dlg)->GetSafeHwnd(), WM_USER_UPDATE_SCORE, 0, 0);
if(! ((CDiskMarkDlg*)dlg)->m_DiskBenchStatus)
{
return ;
}
}
}
readScore = maxScore;
::PostMessage(((CDiskMarkDlg*)dlg)->GetSafeHwnd(), WM_USER_UPDATE_SCORE, 0, 0);
}
*/
