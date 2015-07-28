/* play_piece.c  advance game one move with inputs of the player making the move, 
the column he wishes to play and the current board state*/

#include<stdio.h>
#include<iostream>

//header files
#include "print_square.h"


void print_square(int ** square, int size)
{

for(int i=0; i<size ; i++)
{
   for(int j = 0 ; j < size ; j++)
     printf(" %4d " , square[i][j]);
     printf(" \n");
}

 
}

