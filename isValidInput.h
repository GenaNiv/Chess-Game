/*
 * isValidInput.h
 *
 *  Created on: Jan 8, 2015
 *      Author: gena
 */

#ifndef ISVALIDINPUT_H_
#define ISVALIDINPUT_H_


//---Function declaration---
int isValidInput(char StartMove,char EndMove,int StartX1,int StartY1,int EndX2,int EndY2);//Function checks legality of the move
char CheckAttakedFigure(char Figure); //Function checks whether an attacked figure is relates to an opponent side
//int CheckPossiblePositionsOfPawn(int x1,int y1,int x2,int y2); //Function checks whether all possible positions are empty

#endif /* ISVALIDINPUT_H_ */
