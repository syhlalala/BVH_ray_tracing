#include "common.h"

void read_obj_file(const char *file_name, vector<Triangle>& triangles) {
	static const int BUFFER_SIZE = 10000;

	FILE *fin = fopen(file_name, "r");
	char buffer[BUFFER_SIZE];
	vector<Vector3> points;
	triangles.clear();
		
	while (fgets(buffer, BUFFER_SIZE - 1 , fin))
		if (buffer[1] == ' ') {
			if (buffer[0] == 'v') {
				Vector3 v;
				sscanf(buffer + 1, "%f%f%f", &v.x, &v.y, &v.z);
				points.push_back(v);
			} else if (buffer[0] == 'f') {
				int id[3];
				for (int i = 0, j = 1; i < 3; ++i) {
					while (buffer[j] != ' ') ++j;
					sscanf(buffer + j, "%d", id + i);
					++j;
				}
				
				triangles.push_back( Triangle(points[ id[0] - 1 ], points[ id[1] - 1 ], points[ id[2] - 1 ]) );
			}
		}
	
	fclose(fin);
}