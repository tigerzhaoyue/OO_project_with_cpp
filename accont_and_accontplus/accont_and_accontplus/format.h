#pragma once
#include <iostream>
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();

void restore(format f, precis p);