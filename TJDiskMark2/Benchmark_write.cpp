// Benchmark.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "Controller.cpp"
#include "Benchmark.h"
/*#include <windows.h>
#include <tchar.h>*/
#include <stdio.h>
#include <windows.h>
#include <winbase.h>


// Benchmark

IMPLEMENT_DYNAMIC(Benchmark, CWnd)

Benchmark::Benchmark(int reqOperation, int op, int size)
{
	LARGE_INTEGER start, end, f;
	QueryPerformanceFrequency(&f);

	if ((reqOperation == THROUGHPUT)&&(op == WRITE))
	{
		const unsigned long long uSize = 8ULL * 1024ULL * 1024ULL;
		unsigned long long tArr[uSize];
		FILE *pFile;
		pFile = fopen("file.binary", "wb");
		
		//http://www.tipssoft.com/bulletin/board.php?bo_table=FAQ&wr_id=735

		QueryPerformanceCounter(&start);
		Sleep(1);
		for (unsigned long long j = 0; j < 1024; j++)
		{
			fwrite(a, 1, size * sizeof(unsigned long long), pFile);
			//1024*8*size
		}
		QueryPerformanceCounter(&end);
		_int64 micro_interval = (end.QuadPart - start.QuadPart) / (f.QuadPart / 1000000);

		return (int)micro_interval;
	}
	else if ((reqOperation == THROUGHPUT) && (op == READ))
	{

	}
	
}

Benchmark::~Benchmark()
{


}


BEGIN_MESSAGE_MAP(Benchmark, CWnd)
END_MESSAGE_MAP()



// Benchmark message handlers


