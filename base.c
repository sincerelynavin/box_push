#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "base.h"
#include "terminal.h"
#include "maparray.h"
#include "tutorial.h"
#include "boolean.h"
#include "controls.h"

/*function to instantly take char inputs, taken from interface.c*/
char inputScan()
{
    char ch;

    disableBuffer();
    scanf(" %c", &ch);
    enableBuffer();
    /*To allow for upper case letters to be recognized*/
    ch = tolower(ch);

    return ch; 
}

/*Box Movements = Push*/
void boxPush(int* Box,int* mc, int* mr, int* pr, int* pc, char playerInput)
{
    /*Pushing box function in order of WASD*/
    int br = Box[0], bc = Box[1];

    if (*pr - 1 == br && *pc == bc && playerInput == 'w' && br != 1)
    {
        /*Player pushing box from bottom to top*/
        Box[0] -= 1;
    }

    if (*pr == br && *pc - 1 == bc && playerInput == 'a' && bc != 1)
    {
        /*Player pushing box to leftside*/
        Box[1] -= 1;
    }

    if (*pr + 1 == br && *pc == bc && playerInput == 's' && br != *mr - 2)
    {
        /*Player pushing box from top to bottom*/
        Box[0] += 1;
    }

    if (*pr == br && *pc + 1 == bc && playerInput == 'd' && bc != *mc - 2)
    {
        /*Player pushing box to rightside*/
        Box[1] += 1;
    }
}

/*Box Movements = Pull*/
void boxPull(int* Box, int* mr, int* mc, int* pr, int* pc, char playerInput)
{
    /*Pulling box function in order of WASD*/
    int br = Box[0], bc = Box[1];

    /*Player pulling box from bottom to top*/
    if (*pr + 1 == br && *pc == bc && playerInput == 'w' && *pr != 0)
    {
        Box[0] -= 1;
    }

    /*Player pullimg box leftwards*/
    if (*pr == br && *pc + 1 == bc && playerInput == 'a' && *pc != 0)
    {
        Box[1] -= 1;
    }

    /*Player pulling box downwards*/
    if (*pr - 1 == br && *pc == bc && playerInput == 's' && *pr != *mr - 1)
    {
        Box[0] += 1;
    }

    /*Player pulling box rightwards*/
    if (*pr == br && *pc - 1 == bc && playerInput == 'd' && *pc != *mc - 1)
    {
        Box[1] += 1;
    }

}

int winCondition(int* gr, int* gc, int* Box)
{
    /*Conditions for winning*/
    int win = FALSE;

    if(Box[0] == *gr && Box[1] == *gc)
    {
        /*When box position = goal position*/
        win = TRUE;
    }

    return win;
}

void base(int** mapArray, int mr, int mc, int* pr, int* pc, int* gr, int* gc, int* Box)
{
    int win = winCondition(gr, gc, Box);

    /*Intialize the array for the map bpard*/
    intializeMapArray(mapArray, mr, mc, pr, pc, gr, gc, Box);
    
    /*Print out the map board*/
    printMapArray(mapArray, mr, mc, gr, gc, Box, win);

    /*Tutorial on how to play the game*/
    showTutorial();

    /*untiil win == TRUE, game will keep playing*/
    while (win == FALSE)
    {
        /*Player input for movement*/
        char playerInput = inputScan();

        /*Explains the behavior of the box*/
        boxPush(Box, &mc, &mr, pr, pc, playerInput);

        /*If PULL=1 is declared in make*/
        #ifdef PULL 
        boxPull(Box, &mr, &mc, pr, pc, playerInput);
        #endif

        /*Control function from controls.h*/
        controls(Box, pr, pc, &mr, &mc, playerInput);
        
        /*map board re-initialization*/
        intializeMapArray(mapArray, mr, mc, pr, pc, gr, gc, Box);
        
        /*Check for win conditions*/
        win = winCondition(gr, gc, Box);

        /*Reprint the updated map board*/
        printMapArray(mapArray, mr, mc, gr, gc, Box, win);

        /*Show tutorial every time*/
        showTutorial();

        /*Invalid input checker*/
        if (playerInput != 'w' && playerInput != 's' && playerInput != 'a' && playerInput != 'd')
        {
            printf("\nINVALID MOVEMENT\n");
        }
        
    }

    printf("\n\nYou win!!\n\n");
    
}
