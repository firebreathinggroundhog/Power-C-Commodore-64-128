/* Plot.c written by Martin Sigley 
/* Date: 11/2019
/*
/* Purpose of program:
/* To set the cursor position on the
/* screen and to retrieve the cursor
/* positon. 
/*
/* This is done by using the C64
/* Kernel routine named plot located
/* at 0xFFF0.
*/

#include<stdio.h>

/* Function Plot:
/* Purpose: set and get cursor position
/* Use: internal, not intended for
/* end user. Use curset() & curget().
/* 
/* opcode 0x18 clc to set.
/* opcode 0x38 sec to get.
*/

char code[] =
{
  0x18,
  0x20,
  0xf0,  
  0xff, 
  0x60             
};

/* Function Curset:
/* Purpose: Set cursor position.
/* Use: curset(0,0) to place
/* cursor at top left corner
/* of screen.
*/
curset(x, y)
char x, y;
{
  code[0] = 0x18;
  sys(code, NULL, &y, &x);
}

/* Function Curget.
/* Purpose: Get current cursor coordinates.
/* Use: curget(&x, &y)
/* cursor column and row returned in
/* pointers x and y repectively.
*/
curget(x,y)
char *x, *y;
{
  code[0] = 0x38;
  sys(code, NULL, y, x);
}

