/* initialize_square.cc  initiazlize with constraints*/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
//header files
#include "random_swap.h"

void init_square_old(int ** square, int constraint, int pos_x, int pos_y, int size) {

    int i, j;
    int count=1;
//move x and y to matrix locations
    int x,y;
    x=pos_y-1;
    y=pos_x-1;
   
    
    
    if(constraint==0 ||  (pos_x ==0 || pos_y == 0))
    {
        for (i = 0; i < size; i++)
            for (j = 0; j < size; j++)
                square[i][j] = i * size + j + 1;   
    }
    else if(constraint==1)
    {
        count=2;
        for (i = 0; i < size; i++)
            for (j = 0; j < size; j++)
            {
                if(i != x || j != y)
                {
                    square[i][j] = count++;
                }
            }
        square[x][y]=1;
    }
    else if(constraint==2)
    {
        count=1;
        for (i = 0; i < size; i++)
            for (j = 0; j < size; j++)
            {
                if( (i < x) || (i > x+1) || (j < y) || (j > y+1))
                {
                    while(count==1 || count==2 || count ==4 || count == 5)
                    {
                        count++;
                    }                 
                    square[i][j] = count++;
                }
            }
        square[x][y]=1;
        square[x][y+1]=2;
        square[x+1][y]=4;
        square[x+1][y+1]=5;
        
    }
    else if(constraint==3)
    {
                count=1;
        for (i = 0; i < size; i++)
            for (j = 0; j < size; j++)
            {
                if( (i < x) || (i > x+2) || (j < y) || (j > y+2))
                {
                    while(count<10)
                    {
                        count++;
                    }                 
                    square[i][j] = count++;
                }
            }
        square[x][y]=1;
        square[x][y+1]=2;
        square[x][y+2]=3;

        square[x+1][y]=4;
        square[x+1][y+1]=5;
        square[x+1][y+2]=6;
    
        square[x+2][y]=7;
        square[x+2][y+1]=8;
        square[x+2][y+2]=9;

    }
 
}

