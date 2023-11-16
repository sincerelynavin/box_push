#ifndef GAME_H
#define GAME_H

char scanInput();
void boxPush(int* Box,int* mc, int* mr, int* pr, int* pc, char playerInput);
void boxPull(int* Box, int* mr, int* mc, int* pr, int* pc, char playerInput);
int winCondition(int* gr, int* gc, int* Box);
void base(int** mapArray, int mr, int mc, int* pr, int* pc, int* gr, int* gc, int* Box);

#endif