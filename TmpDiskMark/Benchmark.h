#pragma once
#include "BenchMarkData.h"

long long Sequential_read(BenchMarkData* data);
void init(BenchMarkData* data);
long long main_thr(int op);
long long seq_write(BenchMarkData* data);
