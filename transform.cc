// apply transformations to magic square

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
//header files
#include "transform.h"

void transform(int ** square, int row_col_comp, int from_center, int size)
{
    int ei_1,ei_2=0; // exchange index
    int temp=0;
    
    if(size%2) //if odd
    {
        ei_1= ((size-1)/2)+from_center;
        ei_2= ((size-1)/2)-from_center;
    }
    else //of even
    {
        ei_1= ((size)/2)+from_center-1;
        ei_2= ((size)/2)-from_center;
    }
    
    if(ei_1+1 > size || ei_2+1 > size || ei_1 < 0 || ei_2 <0 )
    {
        printf("\ntransform index out of range\n");
        exit(1);
    }
        
    if(row_col_comp==0) //exchange rows
    {
        for(int i = 0;i<size;i++)
        {
            temp=square[i][ei_1];
            square[i][ei_1]=square[i][ei_2];
            square[i][ei_2]=temp;
        }
    }
    else if(row_col_comp==1)// exchange columns
    {
        for(int i = 0;i<size;i++)
        {
            temp=square[ei_1][i];
            square[ei_1][i]=square[ei_2][i];
            square[ei_2][i]=temp;
        }
    }
    else if(row_col_comp==2)  // complementary magic square
    {
        for(int i=0;i<size;i++)
            for(int j=0;j<size;j++)
            {
                square[i][j]=size*size+1-square[i][j];
            }
    }
    else //error
    {
        printf("\ninvalid row_col_comp setting\n");
        exit(1);
    }
    

}
