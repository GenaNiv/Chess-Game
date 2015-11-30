/*
 * set_coords.c
 *
 *  Created on: Jan 8, 2015
 *      Author: gena
 */
#include<stdio.h>
#include<string.h>

extern int  x,y;
extern char move[5];

//--------Function transfers line column points to arithmetic coordinates-----------
int set_coords()
{
	int valid=1;
  // get y value from character
  if(strchr(move,'a'))
    y = 0;
  else if(strchr(move,'b'))
    y = 1;
  else if(strchr(move,'c'))
    y = 2;
  else if(strchr(move,'d'))
    y = 3;
  else if(strchr(move,'e'))
    y = 4;
  else if(strchr(move,'f'))
    y = 5;
  else if(strchr(move,'g'))
    y = 6;
  else if(strchr(move,'h'))
    y = 7;
  else
	  {
	  printf("Invalid move. Please try again-\n");
	  valid=0;
	  }
  // get x value from character
   if(strchr(move,'8'))
    x = 7;
  else if(strchr(move,'7'))
    x = 6;
  else if(strchr(move,'6'))
    x = 5;
  else if(strchr(move,'5'))
    x = 4;
  else if(strchr(move,'4'))
    x= 3;
  else if(strchr(move,'3'))
    x = 2;
  else if(strchr(move,'2'))
    x = 1;
  else  if(strchr(move,'1'))
    x = 0;
  else
  	  {
  	  printf("Invalid move. Please try again-\n");
  	  valid=0;
  	  }
   return valid;
}// end function set_coords()
