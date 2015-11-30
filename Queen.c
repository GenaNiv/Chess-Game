/*
 * Queen.c
 *
 *  Created on: Jan 8, 2015
 *      Author: gena
 */

//--------Queen's move validation---------
#define N 8
#define W 0
#define B 1
#include<math.h>

//--- Function implementation
int Queen(int x1,int y1,int x2,int y2){
	int check;
	int Row, Column;

	Row=abs(x2-x1);
	Column=abs(y2-y1);

		if(Row==Column)
		    check=1;
		else if(x1==x2 || y1==y2)
		   check=1;
	    else
		   check=0;
		return check;
}// end function
