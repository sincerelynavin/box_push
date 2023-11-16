#ifndef MAPARRAY_H
#define MAPARRAY_H

void createMapArray(int*** mapArray, int mr, int mc);
void freeMapArray(int*** mapArray, int mr);
void intializeMapArray(int** mapArray, int mr, int mc, int* pr, int* pc, int* gr, int* gc, int* Box);
void printMapArray(int** mapArray, int mr, int mc, int* gr, int* gc, int* Box, int win);

#endif
