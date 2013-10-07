#ifndef __COMMON_H__
#define __COMMON_H__
#include <vector>
#include <cstdio>
#include "triangle.h"
using std::vector;

#define EPS 1e-5

void read_obj_file(const char *file_name, vector<Triangle>& triangles);

#endif //__COMMON_H__
