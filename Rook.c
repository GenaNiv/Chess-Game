/*
 * Rook.c
 *
 *  Created on: Jan 8, 2015
 *      Author: gena
 */
//---------Rook's move validation---------
#define N 8
#define W 0
#define B 1
#include<math.h>
#include "isValidInput.h"
extern int  side;
extern char board[N][N];

int extern RookFirstMoveW; //This global variable was defined for castling move (White King).
int extern RookFirstMoveB;
//---Function implementation---
int Rook(char AttakedFigure,int x1,int y1,int x2,int y2){
    char legal,FigureColor;
	int check;
	int i,defX,defY;
		defX=x2-x1;
		defY=y2-y1;

 	FigureColor=CheckAttakedFigure(AttakedFigure);// Validate whether attacked figure is white or black

 	if(x1==x2 || y1==y2){
	   switch(side){
		  case W:  // White move
	     	if(x1==x2) { //Horizontal test
				  if(defY<0){//Left direction
						for(i=1;i<=abs(defY);i++){
							legal=board[x1][y1-i];
							if(legal==' ' || (legal==board[x2][y2] && FigureColor== 'b')){
							   check=1;
							   RookFirstMoveW=1;
							}
							else{
							   check=0;
							   break;
						    }
						}
				  	}
				  else if(defY>0){//Right direction
							for(i=1;i<=abs(defY);i++){
								legal=board[x1][y1+i];
								if(legal==' ' || (legal==board[x2][y2] && FigureColor== 'b')){
									check=1;
									RookFirstMoveW=1;
								}
								else{
									check=0;
									break;
								}
							}
						}
					}//Horizontal test done

	     	else if(y1==y2){//Perpendicular test
	     		    if(defX>0){ //North direction
	     		    	for(i=1;i<=abs(defX);i++){
	     		    		legal=board[x1+i][y1];
	     		    		if(legal==' ' || (legal==board[x2][y2] && FigureColor== 'b')){
	     		    			check=1;
	     		    			RookFirstMoveW=1;
	     		    		}
	     		    		else{
	     		    			check=0;
	     		    			break;
	     		    		}
	     		    	}
	     		    }
	     		    else if(defX<0){ //South direction
	     		    	for(i=1;i<=abs(defX);i++){
	     		    		legal=board[x1-i][y1];
	     		    		if(legal==' ' || (legal==board[x2][y2] && FigureColor== 'b')){
	     		    			check=1;
	     		    			RookFirstMoveW=1;
	     		    		}
	     		    		else{
	     		    			check=0;
	     		    			break;
	     		    		}
	     		    	}
	     		    }
	     	      }//Perpendicular test done
          break;
		  case B:
			  if(x1==x2){ //Horizontal test
			  	if(defY<0){//Left direction
			  	   for(i=1;i<=abs(defY);i++){
			  		   legal=board[x1][y1-i];
			  			 if(legal==' ' || (legal==board[x2][y2] && FigureColor== 'w')){
			  							   check=1;
			  							   RookFirstMoveB=1;
			  			 }
			  			 else{
			  				check=0;
			  				break;
			  			 }
			  		}
			  	}
			  	else if(defY>0){ //Right direction
			  		for(i=1;i<=abs(defY);i++){
			  			legal=board[x1][y1+i];
			  			if(legal==' ' || (legal==board[x2][y2] && FigureColor== 'w')){
			  				check=1;
			  				RookFirstMoveB=1;
			  			}
			  			else{
			  				check=0;
			  				break;
			  			}
			  		}
			  	}
			  }//Horizontal test done

			  else if(y1==y2){ //Perpendicular test
			  	  if(defX>0){ //North direction
			  	     for(i=1;i<=abs(defX);i++){
			  	     	legal=board[x1+i][y1];
			  	     	if(legal==' ' || (legal==board[x2][y2] && FigureColor== 'w')){
			  	     		check=1;
			  	     		RookFirstMoveB=1;
			  	     	}
			  	     	else{
			  	     		 check=0;
			  	     		 break;
			  	     	}
			  	     }
			  	   }
			  	   else if(defX<0){ //South direction
			  	       for(i=1;i<=abs(defX);i++){
			  	     	  legal=board[x1-i][y1];
			  	     	  if(legal==' ' || (legal==board[x2][y2] && FigureColor== 'w')){
			  	     		 check=1;
			  	     		 RookFirstMoveB=1;
			  	     	  }
			  	     	  else{
			  	     		  check=0;
			  	     		  break;
			  	     	  }
			  	     	}
			  	     }
			  }//Perpendicular test done
         break;
		 }//end switch

		}// end if
 	else
 		check=0;

	return check;
}// end function Rook(...)

