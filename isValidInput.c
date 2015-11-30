/*
 * isValidInput.c
 *
 *  Created on: Jan 8, 2015
 *      Author: gena
 */
#include<math.h>
#include "Bishop.h"
#include "Rook.h"
#include "Knigth.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include "FindChar.h"

//Pre-definers
#define N 8
#define W 0
#define B 1

//------Function checks legality of the move-------
int isValidInput(char StartMove,char EndMove,int StartX1,int StartY1,int EndX2,int EndY2)
{
	int res;
    switch (StartMove)
    {
    case 'K':
    	res=King(EndMove,StartX1,StartY1,EndX2,EndY2);
    	break;
    case 'B':
        res=Bishop(EndMove,StartX1,StartY1,EndX2,EndY2);
        break;
    case 'R':
        res=Rook(EndMove,StartX1,StartY1,EndX2,EndY2);
        break;
    case 'Q':
        res=Queen(StartX1,StartY1,EndX2,EndY2);
        break;
    case 'N':
        res=Knigth(EndMove,StartX1,StartY1,EndX2,EndY2);
        break;
    case 'P':
        res=Pawn(EndMove,StartX1,StartY1,EndX2,EndY2);
        break;
    case 'k':
        res=King(EndMove,StartX1,StartY1,EndX2,EndY2);
        break;
    case 'b':
        res=Bishop(EndMove,StartX1,StartY1,EndX2,EndY2);
        break;
    case 'r':
        res=Rook(EndMove,StartX1,StartY1,EndX2,EndY2);
        break;
    case 'q':
        res=Queen(StartX1,StartY1,EndX2,EndY2);
        break;
    case 'n':
        res=Knigth(EndMove,StartX1,StartY1,EndX2,EndY2);
         break;
    case 'p':
        res=Pawn(EndMove,StartX1,StartY1,EndX2,EndY2);
        break;
    }
    return res;
}// end function

//Function checks whether an attacked figure is relates to an opponent side
char CheckAttakedFigure(char Figure)
{
	char decision;

	if(Figure=='P'|| Figure=='R' || Figure=='N' || Figure=='B' || Figure=='Q' || Figure=='K')
	{
		decision='w'; //---White piece
	}
	else if(Figure=='p' || Figure=='r' || Figure=='n' || Figure=='b' || Figure=='q' || Figure=='k')
	{
		decision='b'; //---Black piece
	}
	else if(Figure==' ')
        decision='e'; //Empty space

	return decision;
} // end function




