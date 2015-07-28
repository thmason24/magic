/* Copy square */
 
#include<stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

//hfiles
#include "copy_square.h"



void copy_square(int **  square, int ** copy, int size)
 {
 int i,j ;
 for(i=0;i<size;i++){
         for(j=0;j<size;j++){
                 copy[i][j]=square[i][j];
         }
 }
}
