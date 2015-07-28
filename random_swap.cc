/* random_swap.ccc  swap two numbers in the magic square*/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
//header files
#include "random_swap.h"

void random_swap(int ** square, int width, int constraint, int pos_x, int pos_y, int size) {

    int temp1, temp2;
    int i1, j1, i2, j2;

    for (int i = 0; i < width; i++) {
        i1=-1, j1=-1, i2=-1, j2=-1;
        if (constraint==0 || (pos_x==0 && pos_y==0))
        {
            i1 = rand() % size;
            j1 = rand() % size;
            i2 = rand() % size;
            j2 = rand() % size;            
            while(i1==i2 && j1==j2) // retry if square 2 = square 1
            {
                i2 = rand() % size;
                j2 = rand() % size;
            }
        }
        else
        {
            while(i1<0 || j1<0 || ((i1+1 >= pos_y && i1+1 < pos_y+constraint) && (j1+1 >= pos_x && j1+1 < pos_x+constraint)))
            {
                i1 = rand() % size;
                j1 = rand() % size;
            }
            // check that i and j are initialized,  out of constrained area and that the two swapped numbers are not equal
            while(i2<0 || j2<0 || ((i2+1 >= pos_y && i2+1 < pos_y+constraint) && (j2+1 >= pos_x && j2+1 < pos_x+constraint)) 
                    || (i1==i1 && j1==j2) )
            {
                i2 = rand() % size;
                j2 = rand() % size;
            }
        }
        
        temp1 = square[i1][j1];
        temp2 = square[i2][j2];

        square[i1][j1] = temp2;
        square[i2][j2] = temp1;
    }

   // printf("i1=%d, j1=%d, i2=%d, j2=%d\n ",i1,j1,i2,j2);
   
}

