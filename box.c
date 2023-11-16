#include <stdio.h>
#include <stdlib.h>
#include "box.h"
#include "random.h"

void gameBox(int* pBox, int mr, int mc, int pr, int pc, int gr, int gc)
{
    /*randomizer*/
    int br; /*box-row*/
    int bc; /*box-coloumn*/
    
    do
    	{
    	initRandom();
    	br = randomUCP(2, mr - 3); /*Ensures it doesn't end up next to the border*/
    	bc = randomUCP(2, mc - 3); 
    	}

        /*ensures that there will be no overlap in box and player as well as box and goal*/
    	while((br == pr && bc == pc) || (br == gr && bc == gc));
    
    
    pBox[0] = br;
    pBox[1] = bc;

}
