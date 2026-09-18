#ifndef HEADER_WATERSHED_SPINE_H
#define HEADER_WATERSHED_SPINE_H
/*


*/


char *get_void_boundaries_07(int *voids, int sizeX, int sizeY, int sizeZ);

void local_watershed_sort_07(double *den, int *voids, char *boundaries, int sizeX, int sizeY, int sizeZ);
void local_watershed_sort_float_07(float *den, int *voids, char *boundaries, int sizeX, int sizeY, int sizeZ);


#endif
