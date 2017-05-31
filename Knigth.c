/*
 * Knigth.c
 *
 *  Created on: Jan 8, 2015
 *      Author: gena
 */

#include<math.h>
#include "isValidInput.h"

//-----Knigth's move validation------------
#define N 8
#define W 0
#define B 1

extern int  side;

//---Function implementation
int Knigth(char AttakedFigure,int x1,int y1,int x2,int y2){
	int check;
    int Row, Column;
    char FigureColor;

    Row=abs(x2-x1);
    Column=abs(y2-y1);

   	FigureColor=CheckAttakedFigure(AttakedFigure);//Check figure type in the coordinate (x2,y2)

	switch (side){
	case W:
		if((Row==1 && Column==2 && FigureColor=='b') || (Row==2 && Column==1 && FigureColor=='b') || (Row==1 && Column==2 && FigureColor=='e') || (Row==2 && Column==1 && FigureColor=='e'))
			 check=1;
		else
			 check=0;
		break;
	case B:
		if((Row==1 && Column==2 && FigureColor=='w' ) || (Row==2 && Column==1 && FigureColor=='w') || (Row==1 && Column==2 && FigureColor=='e') || (Row==2 && Column==1 && FigureColor=='e'))
			 check=1;
		else
			 check=0;
		break;
	}
    return check;
}//end function
