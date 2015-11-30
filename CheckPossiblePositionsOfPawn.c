/*
 * CheckPossiblePositionsOfPawn.c
 *
 *  Created on: Jan 8, 2015
 *      Author: gena
 */

#include<math.h>

//Pre-definers
#define N 8
#define W 0
#define B 1

//exteren variables
extern int  side;
extern char board[N][N];


//---Function checks whether all possible positions are empty----
int CheckPossiblePositionsOfPawn(int x1,int y1,int x2,int y2)
{
	char legal;
	int i,empty,def;

	def=abs(x2-x1);

		switch (def){
		case 1 :
		   legal=board[x2][y2];
			if(legal==' ')
				empty=1;
			else
				empty=0;
			break;
		case 2 :
			for(i=0;i<2;i++){
				if(side==W)
				{
				   legal=board[x2-i][y2];
					 if(legal==' ')
						empty=1;
					 else{
						empty=0;
						break;
				         }
				}
				else if(side==B){
					legal=board[x2+i][y2];
					 if(legal==' ')
						 empty=1;
					 else{
						empty=0;
						break;
					 }
				}
			}
			break;
		}// end switch

	return empty;
}// end function


