#include <stdio.h>
#include <stdlib.h>
#include "base.h"
#include "terminal.h"
#include "maparray.h"
#include "boolean.h"
#include "controls.h"

void controls(int* Box, int* pr, int* pc, int *mr, int *mc, char playerInput)
{
    /*movement function for WASD*/

    int br = Box[0], bc = Box[1];

    /*upward movement where Player isn't at 0 height as to not go through top border*/
    if(playerInput == 'w' && *pr != 1)
    {
        /*Checking for box status relative to player and checking if box is at boundary*/
        if (*pr - 1 != br || *pc != bc || br != 1)
        {
            *pr -= 1;
        }
    }

    /*leftwards movement where player isn't at leftmost border*/
    else if (playerInput == 'a' && *pc != 1)
    {
        /*Checking for box status relative to player and checking if box is at boundary*/
        if (*pr != br || *pc - 1 != bc || bc != 1)
        {
            *pc -= 1;
        }
    }

    /*downward movement where player isn't at the level of the border*/
    else if (playerInput == 's' && *pr != *mr - 2)
    {
        /*Checking for box status relative to player and checking if box is at boundary*/
        if(*pr + 1 != br || *pc != bc || br != *mr - 1)
        {
            *pr += 1;
        }
    }

    /*rightwards movement where player isn't at rightmost border*/
    else if (playerInput == 'd' && *pc != *mc - 2)
    {
        /*Checking for box status relative to player and checking if box is at boundary*/
        if (*pr != br || *pc + 1 != bc || bc != *mc - 1)
        {
            *pc += 1;
        }
    }
}
