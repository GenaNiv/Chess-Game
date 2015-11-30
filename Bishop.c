//---------Bishop's move validation-------
#define N 8
#define W 0
#define B 1
#include<math.h>

extern int  side;
extern char board[N][N];
//---Function implementation---
int Bishop(char AttakedFigure,int x1,int y1,int x2,int y2){
	int check,i,j;
	int Row, Column,SignRow,SignCol;
	char legal;
	char FigureColor;
	Row=abs(x2-x1);
	Column=abs(y2-y1);
	SignRow=x2-x1;
	SignCol=y2-y1;

	FigureColor=CheckAttakedFigure(AttakedFigure);

	if(Row==Column){
		 switch(side){
		 case W:
			 if(SignRow>0 && SignCol>0){ //Check if the North-East direction is legal
				 for(i=1,j=1;i<=Row && j<=Column;i++,j++){
					 legal=board[x1+i][y1+j];
					 if(legal==' ' || (legal==board[x2][y2] && FigureColor=='b')){
						 check=1;
					 }
					 else{
						 check=0;
						 break;
					 }
				 }
			 }
			 else if(SignRow>0 && SignCol<0){ //Check if the North-West direction is legal
				 for(i=1,j=1;i<=Row && j<=Column;i++,j++){
					 legal=board[x1+i][y1-j];
					 if(legal==' ' || (legal==board[x2][y2] && FigureColor=='b')){
						 check=1;
					 }
					 else{
						 check=0;
						 break;
					 }
				 }
			 }
			 else if(SignRow<0 && SignCol<0){ //Check if the South-West direction is legal
				 for(i=1,j=1;i<=Row && j<=Column;i++,j++){
					 legal=board[x1-i][y1-j];
					 if(legal==' ' || (legal==board[x2][y2] && FigureColor=='b')){
						 check=1;
					 }
					 else{
						 check=0;
						 break;
					 }
				 }
			 }
			 else if(SignRow<0 && SignCol>0){ //Check if the South-East direction is legal
				 for(i=1,j=1;i<=Row && j<=Column;i++,j++){
					 legal=board[x1-i][y1+j];
					 if(legal==' ' || (legal==board[x2][y2] && FigureColor=='b')){
						 check=1;
					 }
					 else{
						 check=0;
						 break;
					 }
				 }
			 }
			 break;
		 case B: //start check Black move
			 if(SignRow>0 && SignCol>0){ //Check if the North-East direction is legal
			 	for(i=1,j=1;i<=Row && j<=Column;i++,j++){
			 		legal=board[x1+i][y1+j];
			 		 if(legal==' ' || (legal==board[x2][y2] && FigureColor=='w')){
			 			check=1;
			 		 }
			 		 else{
			 			check=0;
			 			break;
			 		 }
			 	 }
			 }
			  else if(SignRow>0 && SignCol<0){ //Check if the North-West direction is legal
			 		for(i=1,j=1;i<=Row && j<=Column;i++,j++){
			 			legal=board[x1+i][y1-j];
			 			if(legal==' ' || (legal==board[x2][y2] && FigureColor=='w')){
			 			   check=1;
			 			 }
			 			else{
			 				check=0;
			 				break;
			 			}
			 		}
			   }
			  else if(SignRow<0 && SignCol<0){ //Check if the South-West direction is legal
			 		for(i=1,j=1;i<=Row && j<=Column;i++,j++){
			 			legal=board[x1-i][y1-j];
			 			if(legal==' ' || (legal==board[x2][y2] && FigureColor=='w')){
			 				check=1;
			 			}
			 			else{
			 			check=0;
			 			break;
			 			}
			 		}
			  }
			   else if(SignRow<0 && SignCol>0){ //Check if the South-East direction is legal
			 		  for(i=1,j=1;i<=Row && j<=Column;i++,j++){
			 			 legal=board[x1-i][y1+j];
			 			 if(legal==' ' || (legal==board[x2][y2] && FigureColor=='w')){
			 				check=1;
			 			 }
			 			 else{
			 				check=0;
			 				break;
			 			 }
			 		  }
			 	}

		 }//end switch
	}
	else
	    check=0;

	return check;
}// end function
