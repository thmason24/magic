/* initialize_square.cc  initiazlize with constraints*/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
//header files
#include "random_swap.h"

void init_square(int ** square, int constraint, int pos_x, int pos_y, int size) {

    int i, j;
    int count=1;
//move x and y to matrix locations
    int x,y;
    x=pos_y-1;
    y=pos_x-1;
    int const_2[4] = {1,2,4,5};
    int x2[4]=       {0,0,1,1};
    int y2[4]=       {0,1,0,1};
    
    int const_3[9] = {1,2,3,4,5,6,7,8,9};
    int x3[9]=       {0,0,0,1,1,1,2,2,2};
    int y3[9]=       {0,1,2,0,1,2,0,1,2};
    
    
    
    if(constraint==0 ||  (pos_x ==0 || pos_y == 0))
    {
  
    }
    else if(constraint==1)
    {
        for (i = 0; i < size; i++)
            for (j = 0; j < size; j++)
            {
                if(square[i][j]==1)
                {
                    square[i][j] = square[x][y];
                    square[x][y]=1;                    
                }
            }
        square[x][y]=1;
    }
    else if(constraint==2)
    {
        count=0;
        for (count=0;count<4;count++)
        for (i = 0; i < size; i++)
            for (j = 0; j < size; j++)
            {
                if(square[i][j]==const_2[count])
                {
                    square[i][j]=square[x+x2[count]][y+y2[count]];
                    square[x+x2[count]][y+y2[count]] = const_2[count];
                }
            }

        
    }
    else if(constraint==3)
    {
        count=0;
        for (count=0;count<9;count++)
        for (i = 0; i < size; i++)
            for (j = 0; j < size; j++)
            {
                if(square[i][j]==const_3[count])
                {
                    square[i][j]=square[x+x3[count]][y+y3[count]];
                    square[x+x3[count]][y+y3[count]] = const_3[count];
                }
            }

    }
 
}

