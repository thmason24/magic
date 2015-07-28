/* show a single element in a square*/

#include<stdio.h>
#include<iostream>

//header files
#include "print_square.h"


void track_element(int ** square, int element, int size)
{

for(int i=0; i<size ; i++)
{
   for(int j = 0 ; j < size ; j++)
   {
     if (square[i][j]==element)
     {
         printf(" %d " , square[i][j]);
     }
     else
     {
         printf(" ## ");
     }
   }
     printf(" \n ");
}

 
}

