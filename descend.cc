/* random_swap.cc  swap two numbers in the magic square start*/
/* always start in a random place*/
/* save time on eval by only computing the effected rows,columns and diagonals*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <math.h>
//header files
#include "descend.h"
#include "evaluate.h"
#include "copy_square.h"

void descend(int ** square, int ** temp_square, int constraint, int pos_x, int pos_y, int size, double M) {

    int temp1, temp2;
    int i1, j1, i2, j2;
    int ii1, jj1, ii2, jj2;
    int offset_i1,offset_j1,offset_i2,offset_j2;
    int delta_swap,delta_dev,sum_i1,sum_j1,sum_i2,sum_j2,sum_diag1,sum_diag2;
    int new_sum;
    bool improved;
    
// printf("\nbest_dev at init %d",evaluate(square,size,M));
    do {
        improved = false;
 //       copy_square(square, temp_square, size);
        
        offset_i1=rand()%size;
        offset_j1=rand()%size;
        offset_i2=rand()%size;
        offset_j2=rand()%size;
 
        for (ii1 = 0; ii1 < size && !improved; ii1++)
            for (jj1 = 0; jj1 < size && !improved; jj1++)
                for (ii2 = 0; ii2 < size && !improved; ii2++)
                    for (jj2 = 0; jj2 < size && !improved; jj2++) {
                        
                        i1=(ii1+offset_i1)%size;
                        j1=(jj1+offset_j1)%size;
                        i2=(ii2+offset_i2)%size;
                        j2=(jj2+offset_j2)%size;             
      //                  printf("\n %d %d %d %d",i1,j1,i2,j2);
        //                printf("\n M= %f",M);
                        
                        if (!(i1 == i2 && j1 == j2) && \
                       !(i1 >= pos_y-1 && i1 < pos_y-1 + constraint && j1 >= pos_x-1 && j1 <  pos_x-1 + constraint) && \
                       !(i2 >= pos_y-1 && i2 < pos_y-1 + constraint && j2 >= pos_x-1 && j2 <  pos_x-1 + constraint)) 
                        {

                            // evaluate affected rows (i1 and j1) and 
                            // effected colummns (j1 and j2)
                            // and diagonals if i1=j1, i2=j2, i1 = -i1, j1=-j2
                            // if calculated lower than effect swap
                            temp1 = square[i1][j1];
                            temp2 = square[i2][j2];
                            delta_swap=temp1-temp2;
                            
                            sum_i1=0;
                            sum_j1=0;
                            sum_i2=0;
                            sum_j2=0;
                            sum_diag1=0;
                            sum_diag2=0;
                            delta_dev=0;
                            
                            for(int i=0;i<size;i++)
                            {
                                sum_i1=sum_i1+square[i1][i];
                                sum_j1=sum_j1+square[i][j1];
                                sum_i2=sum_i2+square[i2][i];
                                sum_j2=sum_j2+square[i][j2];
                                sum_diag1=sum_diag1+square[i][i];
                                sum_diag2=sum_diag2+square[i][size-1-i];
                            }
                            
                            if(i1!=i2)
                            {
                                new_sum=sum_i1-delta_swap;
                                delta_dev=delta_dev-(abs(sum_i1-M)-abs(new_sum-M));
                                new_sum=sum_i2+delta_swap;
                                delta_dev=delta_dev-(abs(sum_i2-M)-abs(new_sum-M));
                            }

                            if(j1!=j2)
                            {
                                new_sum=sum_j1-delta_swap;
                                delta_dev=delta_dev-(abs(sum_j1-M)-abs(new_sum-M));
                                new_sum=sum_j2+delta_swap;
                                delta_dev=delta_dev-(abs(sum_j2-M)-abs(new_sum-M));
                            }
                            if(!(i1==j1 && i2==j2)) 
                            {
                                if(i1==j1)
                                {
                                    new_sum=sum_diag1-delta_swap;
                                    delta_dev=delta_dev-(abs(sum_diag1-M)-abs(new_sum-M));
                                }
                                if(i2==j2)
                                {
                                    new_sum=sum_diag1+delta_swap;
                                    delta_dev=delta_dev-(abs(sum_diag1-M)-abs(new_sum-M));
                                }
                            }
                        

                            if(!(i1==size-1-j1 && i2==size-1-j2)) 
                            {
                                if(i1==size-1-j1)
                                {
                                    new_sum=sum_diag2-delta_swap;
                                    delta_dev=delta_dev-(abs(sum_diag2-M)-abs(new_sum-M));
                                }
                                if(i2==size-1-j2)
                                {
                                    new_sum=sum_diag2+delta_swap;
                                    delta_dev=delta_dev-(abs(sum_diag2-M)-abs(new_sum-M));
                                }
                            }
                            
                      //      printf("\nindexes %d %d %d %d",i1,j1,i2,j2);                         
                      //      printf("\nsums %d %d %d %d %d %d",sum_i1,sum_j1,sum_i2,sum_j2,sum_diag1,sum_diag2);
                      //      printf("\ndelta swap %d delta dev %d ",delta_swap,delta_dev);

                        
                            if (delta_dev<0) {
                                // effect swap in real square (instead of a full copy)
                                square[i1][j1] = temp2;
                                square[i2][j2] = temp1;
 //                             printf("\nbest_dev %d",evaluate(square,size,M));
                                improved = true;
                        //        printf("\n delta dev %d %d",delta_dev,evaluate(square,size,M));
                            }
                        }

                    }
    } while (improved);
}