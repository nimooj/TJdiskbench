#pragma once

class BenchMarkData //: public CWnd
{
public:
	//BenchMarkData(CWnd* pParent = NULL);

	int trials = 1;
	double pageSize;

  double seqRead_4K;
  double seqRead_16K;
	double seqRead_64K;
	double seqRead_128K;
	double seqRead_256K;
	double seqRead_512K;
  double seqRead_1G;
	double seqRead_2G;
	double seqRead_4G;

  double randRead_4K;
  double randRead_16K;
	double randRead_64K;
	double randRead_128K;
	double randRead_256K;
	double randRead_512K;
  double randRead_1G;
	double randRead_2G;
	double randRead_4G;

  double seqWrite_4K;
  double seqWrite_16K;
	double seqWrite_64K;
	double seqWrite_128K;
	double seqWrite_256K;
	double seqWrite_512K;
  double seqWrite_1G;
	double seqWrite_2G;
	double seqWrite_4G;

  double randWrite_4K;
  double randWrite_16K;
	double randWrite_64K;
	double randWrite_128K;
	double randWrite_256K;
	double randWrite_512K;
  double randWrite_1G;
	double randWrite_2G;
	double randWrite_4G;

	double migration_128G;
	double migration_256G;
	double migration_512G;
};
