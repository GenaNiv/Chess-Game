/*
 * King.c
 *
 *  Created on: Jan 8, 2015
 *      Author: gena
 */
//----------King's move validation-------------------
#define N 8
#define W 0
#define B 1
#include<math.h>

extern int  side;
extern char board[N][N];

int extern RookFirstMoveW; //This global variable was defined for castling move (White King).
int extern RookFirstMoveB;

int King(char AttakedFigure,int y1,int x1,int y2,int x2)
{
	int check,Castling,i;
	static int KingFirstMoveW=0, KingFirstMoveB=0; //This variable will be used to checking a legality of casting move.
	int Row, Column;
	char legal, FigureColor;
	Row=abs(x2-x1);
    Column=abs(y2-y1);
    Castling=x2-x1;

    FigureColor=CheckAttakedFigure(AttakedFigure);

    if(Row<=1 && Column<=1) //The block checks a regular legal King's moves.
    {
    	switch (side)
    	{
    	case W:
    		if(FigureColor=='e' || FigureColor=='b')
    		{
    			check=1;
    			KingFirstMoveW++;
    			break;
    		}
    		else
    		{
    			check=0;
    			break;
    		}
    		break;
    	case B:
    		if(FigureColor=='e' || FigureColor=='w')
    		{
    		    check=1;
    		    KingFirstMoveB++;
    		    break;
    		}
    		else
    		{
    		    check=0;
    		    break;
    		}
    		break;
    	}
    }   //End of the block that checks a regular legal King's moves.

    else if((Row==2 && Column==0) && KingFirstMoveW==0 && RookFirstMoveW==0) //If statement to check legality of a white piece move
    {
    	if(Castling>0)// Castling to right side
    	{
    		for(i=1;i<=3;i++)
    		{
    			legal=board[y1][x1+i];
    			if(legal==' ' || legal=='R' || legal=='r')
    			{
    				check=2;
    			}
    			else
    			{
    				check=0;
    				break;
    			}
    		}// for loop end

    		    if(check==2) //Castling executable statement
    		    {
    		    	board[y1][x1+1]='R';
    		    	board[y1][x1+3]=' ';
    		    	KingFirstMoveW++;
    		    	check=1;
    		    }
    	}

    	else if(Castling<0)// Castling to left side
        	{
        		for(i=1;i<=4;i++)
        		{
        			legal=board[y1][x1-i];
        			if(legal==' ' || legal=='R' || legal=='r')
        			{
        				check=2;
        			}
        			else
        			{
        				check=0;
        				break;
        			}
        		}// for loop end

        		    if(check==2) //Castling executable statement
        		    {
        		    	board[y1][x1-1]='R';
        		    	board[y1][x1-4]=' ';
        		    	KingFirstMoveW++;
        		    	check=1;
        		    }
        	}
    } //end for White Casting
    else if((Row==2 && Column==0) && KingFirstMoveB==0 && RookFirstMoveB==0) //If statement to check legality of a black piece move
        {
        	if(Castling>0)// Castling to right side
        	{
        		for(i=1;i<=3;i++)
        		{
        			legal=board[y1][x1+i];
        			if(legal==' ' || legal=='R' || legal=='r')
        			{
        				check=2;
        			}
        			else
        			{
        				check=0;
        				break;
        			}
        		}// for loop end

        		    if(check==2) //Castling executable statement
        		    {
        		    	board[y1][x1+1]='r';
        		    	board[y1][x1+3]=' ';
        		    	KingFirstMoveB++;
        		    	check=1;
        		    }
        	}
        	else if(Castling<0)// Castling to left side
        	     {
        	        for(i=1;i<=4;i++)
        	        	{
        	        		legal=board[y1][x1-i];
        	        		if(legal==' ' || legal=='R' || legal=='r')
        	                {
        	        		   check=2;
        	        	    }
        	        		else
        	        		{
        	        		    check=0;
        	        			break;
        	        		}
        	        	}// for loop end

        	         if(check==2) //Castling executable statement
        	         {
        	        	 board[y1][x1-1]='r';
        	        	 board[y1][x1-4]=' ';
        	        	 KingFirstMoveB++;
        	        	 check=1;
        	         }
        	    }
        } //end for Black Casting
    else
    	check=0;

	return check;
}

