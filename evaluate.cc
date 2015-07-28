/* play_piece.c  advance game one move with inputs of the player making the move, 
the column he wishes to play and the current board state*/

#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include <math.h>

//header files
#include "evaluate.h"


int evaluate(int ** square, int size, double M)
{

int sum_r,sum_c;
int sum_rows_sum=0, sum_cols_sum = 0;
int sum_diag_1=0, sum_diag_2 = 0;
int i,j;
double dev = 0 ;

// find sums for each row and oolumn
//printf("\n");
//printf("Rows  Columns\n");
for(i=0; i<size ; i++)
{
// printf("\n") ;
 sum_r = 0;
 sum_c = 0;
   for(j=0; j<size ;j++)
   {
   sum_r = sum_r + square[i][j];
   sum_c = sum_c + square[j][i];
   }
   sum_rows_sum = sum_rows_sum + abs(sum_r-M); 
   sum_cols_sum = sum_cols_sum + abs(sum_c-M); 
}

// sum diagonals

for(i=0;i<size;i++)
{
 sum_diag_1 = sum_diag_1 + square[i][i] ;
 sum_diag_2 = sum_diag_2 + square[i][size-1-i] ; 
}

// calcuate total deviance from M
    dev = sum_rows_sum + sum_cols_sum + abs(sum_diag_1-M) + abs(sum_diag_2-M);

return dev;
 
}

