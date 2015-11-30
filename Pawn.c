/*
 * Pawn.c
 *
 *  Created on: Jan 8, 2015
 *      Author: gena
 */
// -----Pawn's move validation---------
#define N 8
#define W 0
#define B 1
#include<math.h>
#include "FindChar.h"
#include "isValidInput.h"
#include "CheckPossiblePositionsOfPawn.h"

extern int  side; //to decide who should move, white or black
//---Function's implementation---
int Pawn(char AttakedFigure,int x1,int y1,int x2,int y2)
{
	//---variable definition---
    int check,i,test=0,empt;// test variable checks whether the move is legal, test=0 move illegal test = 1 move legal
	char CharTest,FigureColor;
	static char PawnTestW[8]={'a','b','c','d','e','f','g','h'};//In order to check if specific pawn is still live (for white pawns)
	static char PawnTestB[8]={'a','b','c','d','e','f','g','h'};//In order to check if specific pawn is still live (for black pawns)

	CharTest=FindChar(); //Function returns column character in order to validate if a pawn could  perform first move, jumping two squires
	FigureColor=CheckAttakedFigure(AttakedFigure); // Function checks whether the attacked piece is white, black or empty space.
	empt=CheckPossiblePositionsOfPawn(x1,y1,x2,y2);// Function checks whether path "clear" to perform move.
	switch(side)
	{
	  case W:  // White move
	    if((y1==y2 && x2-x1==2) || (y1==y2 && x2-x1==1)){ //forward moving
			//Could pawn perform first move jumping two squires?
			   for(i=0;i<8;i++){
				  if(PawnTestW[i]==CharTest){
					 PawnTestW[i]=' '; //Deleting column character
					 test=1;
				  }
			   }
		   //====================================================
			   if(test==1){
				 if((y1==y2 && x2-x1==2 && empt==1) || (y1==y2 && x2-x1==1 && empt==1))
				 	check=1;
				 else
				 	check=0;
			   }
			   else if(test==0){
				  if(y1==y2 && x2-x1==1 && empt==1)
				 	check=1;
				  else
				 	check=0;
				}
		 }
		 // Diagonal tests to check if diagonal move for attacking is legal
		else if((x2-x1==1 && y2-y1==1 && FigureColor=='b') || ((x2-x1==1 && y2-y1==-1) && FigureColor=='b')){
			check=1;
		}
		else check=0;
		break;

	  case B:  // Black move
	    if((y1==y2 && x2-x1==-2) || (y1==y2 && x2-x1==-1)){
		  	for(i=0;i<8;i++){
		  		if(PawnTestB[i]==CharTest){
		  			PawnTestB[i]=' ';
		  			test=1;
		  		 }
		  	}
		  		if(test==1){
		  			if((y1==y2 && x2-x1==-2 && empt==1) || (y1==y2 && x2-x1==-1 && empt==1))
		  				check=1;
		  			else
		  				 check=0;
		  		}
		  		else if(test==0){
		  			if(y1==y2 && x2-x1==-1 && empt==1)
		  				check=1;
		  			else
		  				 check=0;
		  		}
		}
        // Diagonal tests to check if diagonal move for attacking is legal
		  	else if((x2-x1==-1 && y2-y1==-1 && FigureColor=='w') || ((x2-x1==(-1) && y2-y1==1) && FigureColor=='w')){
		  		check=1;
		  	}
		  	else check=0;
		  		break;
	}//end switch
	return check;
}//end function

