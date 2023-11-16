#include <stdio.h>
#include <stdlib.h>
#include "base.h"
#include "box.h"
#include "boolean.h"
#include "controls.h"
#include "tutorial.h"
#include "maparray.h"



int main(int argc, char* argv[])
{
    /*Defining inputs, acronymed for convenience*/
    int mr; /*map-row*/
    int mc; /*map-coloumn*/
    int pr; /*player-row*/
    int pc; /*player-coloumn*/
    int gr; /*goal-row*/
    int gc; /*goal-coloumn*/
    int** mapArray; /*array for map board*/ 

    /*Making sure the number of command line arguments are correct (6 including argv[0] which is the program name)*/
    if (argc != 7) 
    {
        printf("\nNumber of inputs must be equal to 6\n Format: [row] [col] [player_row] [player_col] [goal_row] [goal_col]\n");

    }
    
    else
    {

	int Box[2];
        /*using atoi to convert arguments from string to integer*/
        mr = atoi(argv[1]); /*since argv[0] is the program name, we start with argv[1]*/
        mc = atoi(argv[2]);
        pr = atoi(argv[3]);
        pc = atoi(argv[4]);
        gr = atoi(argv[5]);
        gc = atoi(argv[6]);

       
        /*map row restriction*/
        if (mr < 5 || mr > 25)
        {
            printf("\nERROR: Map row size must be between 5 and 25\n");
            return 1;
        }

        /*map coloumn restriction*/
        if (mc < 5 || mc > 50)
        {
            printf("\nERROR: Map coloumn size must be between 5 and 50\n");
            return 1;
        }

        /*Checking for negativity. Since mr and mc are restricted to be larger than 5, they inherently positive so only the rest need to be checked for negativity*/
        if (pr <= 0 || pc <= 0 || gr <= 0 || gc <= 0)
        {
            printf("\nERROR: All arguments must be positive integers");
            return 1;
        }

        /*Making sure player and goal is within bounds*/
        if (pr >= mr || pc >= mc || gr >= mr || gc >= mc)
        {
            printf("\n Player should be within the map boundaries\n");
            return 1;
        }

        /*Checking for overlaps in player and goal positioning*/
        if (pr == gr || pc == gc)
        {
            printf("\nGoal should be within map boundaries\n"); 
            return 1;
        }
 

        /*Randomizer from box.c*/
        gameBox(Box, mr, mc, pr, pc, gr, gc);

        /*array creator from maparray.c*/
        createMapArray(&mapArray, mr + 3, mc + 3);

        /*gamebase from base.c*/
        base(mapArray, mr + 3, mc + 3, &pr, &pc, &gr, &gc, Box);
        
        /*freeing memory from maparray.c*/
        freeMapArray(&mapArray, mr + 3);


    }
    return 0;

}
