#pragma once

class BenchMarkData //: public CWnd
{
public:
	//BenchMarkData(CWnd* pParent = NULL);

	int trials;
	double pageSize;

	double seqRead_64K;
	double seqRead_128K;
	double seqRead_256K;
	double seqRead_512K;
	double seqRead_2G;
	double seqRead_4G;
	double seqRead_8G;
	double seqRead_16G;
	double seqRead_32G;

	double randRead_64K;
	double randRead_128K;
	double randRead_256K;
	double randRead_512K;
	double randRead_2G;
	double randRead_4G;
	double randRead_8G;
	double randRead_16G;
	double randRead_32G;

	double migration_128G;
	double migration_256G;
	double migration_512G;
};