/*
 * main.c
 *
 *  Created on: Jan 8, 2015
 *      Author: gena
 */
//---Standard header files---
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h> // will be used for move algorithms

//---Added header header files---
#include "Bishop.h"
#include "Rook.h"
#include "Knigth.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include "FindChar.h"
#include "isValidInput.h"
#include "CheckPossiblePositionsOfPawn.h"

//---PreDefiners----
#define N 8
#define W 0
#define B 1

//---Global variables---
char move[5],PawnMove[5];
int RookFirstMoveW=0; //This global variable was defined for castling move (White King).
int RookFirstMoveB=0; //This global variable was defined for castling move (Black King).
int PawnFirstMove=1;
int  x,y;             //Board's Coordinates
int  checkmat=0;
int  side=W;          //To identify who's turn?
char piece_moved;
char choice;
char board[N][N]={    //Two dimensional array for representing chess boar
			{'R','N','B','Q','K','B','N','R'},
			{'P','P','P','P','P','P','P','P'},
			{' ',' ',' ',' ',' ',' ',' ',' '},
			{' ',' ',' ',' ',' ',' ',' ',' '},
			{' ',' ',' ',' ',' ',' ',' ',' '},
			{' ',' ',' ',' ',' ',' ',' ',' '},
			{'p','p','p','p','p','p','p','p'},
			{'r','n','b','q','k','b','n','r'}};

//---Functions prototypes----
void DispalyAndInstructions(char board[][N]);
void BoardPrinting(char board[][N]);
int set_coords(void);
void GetPlayerMove(char board[][N]);

//----MAIN FUNCTION-----
int main(){
	DispalyAndInstructions(board);   //Function displays basic game's instructions
    while(!checkmat){
    	if(side==W){
    		printf("Player with White pieces, please make move\n");
    		GetPlayerMove(board);
    		side=B;
    	}
    	else{
    		printf("Player with Black pieces, please make move\n");
    		GetPlayerMove(board);
    		side=W;
    	}
    }

	return 0;
}// end main function

//----------Function prints chess board----------
void BoardPrinting(char board[][N]){ //Func. definition
int line, column,i;
	char name[N]={'a','b','c','d','e','f','g','h'};
	char dash[17]={'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'};

	printf("\n      -----Chess Board-----\n");

	for(column=0;column<N;column++){
		printf("   %c",name[column]);
	}
	printf("\n");
	for(column=0;column<17;column++){
			printf(" %c",dash[column]);
		}
	printf("\n");

//---------Board setting------
	for(line=7;line>=0;line--){
		printf("%d|",line+1);
			for(column=0;column<N;column++){
				printf(" %c |",board[line][column]);
				if(column!=0 && column%7==0){
					printf("\n");
					for(i=0;i<17;i++){
						printf(" %c",dash[i]);
					}
					printf("\n");
				}
			}
		}
}// end BoardPrinting function

//------Function gets move from player from point to point--------------
void GetPlayerMove(char board[][N]){
	int moveOk=0,x1,x2,y1,y2;
	int check_move;
	char MoveFrom,MoveTo;
	int Valid;

	while(moveOk==0){
		printf("\nEnter move from: ");
	    scanf("%s",move);
		if(strlen(move)!=2){
			printf("Invalid string length. Try again-");
			continue;
		}

		check_move=set_coords();
		if(check_move==0){
           continue;
		}
		strcpy(PawnMove,move);
		x1=x;                  // move from x coordinate
		y1=y;                  // move from y coordinate
		MoveFrom=board[x][y];  // Character (Piece) move from

		printf("\nEnter move to: ");
		scanf("%s",move);
		if(strlen(move)!=2){
			printf("Invalid string length. Try again-");
			continue;
		}

		check_move=set_coords();
		if(check_move==0){
			continue;
		}

		x2=x;                // move to x coordinate
		y2=y;                // move to y coordinate
		MoveTo=board[x][y];  //Character (Piece) move to

		Valid=isValidInput(MoveFrom,MoveTo,x1,y1,x2,y2); //Need add if statement

		if(Valid==1){
			piece_moved=board[x1][y1];
			board[x1][y1]=' ';
			board[x2][y2]=piece_moved;
		}
		else{
		printf("\nThis is an INVALID move, try again-");
		continue;
		}
		printf("\n");
		BoardPrinting(board);

		moveOk=1;
	}
}// end GetPlayerMove function

//--------Function Display instruction-------------------
void DispalyAndInstructions(char board[][N]){
	printf("\nGeneral Instructions-");
	printf("\n1.This Chess engine is played between two opponents.");
	printf("\n2.Signs: Uppercase letters are White pieces Lowercase letters are Black pieces.");
	printf("\n3.The player with the white pieces always moves first.");
	printf("\n4.If a king cannot escape check-mate then the game is over.\n");
	BoardPrinting(board);
}// end DispalyAndInstructions function

/*int move(int old_r, int old_c, int new_r, int new_c)
{
if (checkMov(old_r, old_c, new_r, new_c)) {
board[new_r][new_c] = board[old_r][old_c];
board[old_r][old_c] = 0;
}
else printf("Invalid move.\n");

return 0;
}*/
