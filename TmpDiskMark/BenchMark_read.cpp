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

	// End Performance Counter
	//Sleep(1);
	QueryPerformanceCounter(&EndTime);

	// Format Performance Counter unit to second ( ns to s )
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
/*from controller*/
void init(BenchMarkData* data) {
	//data = (BenchMarkData*) VirtualAlloc(NULL, sizeof(BenchMarkData*), MEM_COMMIT, PAGE_READWRITE);
	SYSTEM_INFO sysinfo;

	GetSystemInfo(&sysinfo);
	data->pageSize = sysinfo.dwPageSize;
	//printf("page size is %lf\n", data->pageSize);
	/*CString debug;
	debug.Format(_T("page size is %lf"), data->pageSize);
	MessageBox(debug, 0, MB_ICONINFORMATION);
	AfxMessageBox(_T("Something bad happened!"), MB_OK | MB_ICONSTOP);*/
	//float angle;
	
	// set test file pathu
	//TCHAR RootPath[4];
	//wsprintf(RootPath, _T("%c:\\"), drive);
	//testFileDir.Format(_T("\\.\C:\\SBenchMark%X"), timeGetTime()); // file directory in c drive
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

void seq_write(BenchMarkData* data) {

}

long long main_thr() {
	DWORD thread_id;
	BenchMarkData* data = (BenchMarkData*)VirtualAlloc(NULL, sizeof(BenchMarkData*), MEM_COMMIT, PAGE_READWRITE);
	data->trials = 5;
	init(data);
	// Create thread for sequential read and runs it
	long long ans = seq_read(data);
	return ans;
	//CreateThread(NULL, 0, seq_read, NULL, 0, &thread_id);
	//CreateThread(NULL, 0, seq_write, NULL, 0, &thread_id);

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
