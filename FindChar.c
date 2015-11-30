/*
 * FindChar.c
 *
 *  Created on: Jan 8, 2015
 *      Author: gena
 */

#include<stdlib.h>
#include<string.h>

//---Global variables---
extern char PawnMove[5];


//---function implementation---
char FindChar(void)
{
	char ch;

	 if(strchr(PawnMove,'a'))
		 ch = 'a';
	  else if(strchr(PawnMove,'b'))
		  ch = 'b';
	  else if(strchr(PawnMove,'c'))
		  ch = 'c';
	  else if(strchr(PawnMove,'d'))
		  ch = 'd';
	  else if(strchr(PawnMove,'e'))
		  ch = 'e';
	  else if(strchr(PawnMove,'f'))
		  ch = 'f';
	  else if(strchr(PawnMove,'g'))
		  ch = 'g';
	  else if(strchr(PawnMove,'h'))
		  ch = 'h';
	return ch;
}//end function
