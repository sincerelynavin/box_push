#include <stdio.h>
#include <stdlib.h>
#include "maparray.h"
#include "color.h"
#include "box.h"
#include "boolean.h"
#include "base.h"

/*creating the array*/
void createMapArray(int*** mapArray, int mr, int mc)
{
    int i;

    *mapArray = (int**) malloc(sizeof(int *) * mr);

    for (i = 0; i < mr; i++)
    {
        (*mapArray)[i] = (int *) malloc(sizeof(int) * mc);
    }   
}


/*Initializing the game map board*/
void intializeMapArray(int** mapArray, int mr, int mc, int* pr, int* pc, int* gr, int* gc, int* Box)
{
    int i, j;
    /*map rows loop*/
    for (i = 0; i < mr; i++)
    {   
        /*map coloumns groups*/
        for (j = 0; j < mc; j++)
        {
            /*assigning border characters*/
            if (i == 0 || i == mr - 1 ||j == 0 || j == mc - 1)
            {
                /*boundary will be assigned with an asterick*/
                (mapArray[i][j]) = '*'; 
            }
            else
            {
                /*all the other positions will be empty spaces*/
                (mapArray[i][j]) = ' ';
            }
        }
    }
    /*Initialization of Player*/
    (mapArray[*pr][*pc]) = 'P';

    /*Initialization of Goal*/
    (mapArray[*gr][*gc]) = 'G';

    /*Initialization of Box*/
    (mapArray[Box[0]][Box[1]]) = 'B';
}


/*Printing map board*/
void printMapArray(int** mapArray, int mr, int mc, int* gr, int* gc,int* Box, int win)
{
    int i, j;
    /*clear the terminal screen before printing map*/
    system("clear");
    /*printing the game map*/
    for (i = 0; i < mr; i++)
    {
        for(j = 0; j < mc; j++)
        {
            if (mapArray[i][j] == 'G')
            {
                /*If the game is won*/
                if (win == TRUE)
                {   
                    /*if won, the background of the Goal should be turned green*/
                    setBackground("green");
                    printf("%c", (mapArray[i][j]));
                    setBackground("reset");
                    
                }
                else
                {   
                    /*until its won, the background of the goal should be red*/
                    setBackground("red");
                    printf("%c", (mapArray[i][j]));
                    setBackground("reset");
      
                }
        
        /*Backup condition for colouring*/
		if(Box[0] == *gr && Box[1] == *gc)
		{
			setBackground("green");
			printf("%c", (mapArray[i][j]));
			setBackground("reset");
		}	
            
            }
            else
            {
                /*print the rest of the array elements*/
                printf("%c", (mapArray[i][j]));
            }
        }
        printf("\n");
    }

}

/*to avoid memory leaks, freeing the mapArray*/
void freeMapArray(int*** mapArray, int mr)
{
    int i;

    for (i = 0; i < mr; i++)
    {
        free((*mapArray)[i]);
        (*mapArray)[i] = NULL;
    }
    free((*mapArray));
    *mapArray = NULL;
}
