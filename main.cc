// version 2   introduce probability of moving up in DEV
// version 3   introduce and use the descend routine



#define _XOPEN_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <sys/time.h>
#include "evaluate.h"
#include "print_square.h"
#include "random_swap.h"
#include "descend.h"
#include "copy_square.h"
#include "transform.h"
#include "track_element.h"
#include "init_square.h"
#include "init_square_old.h"

int main(int argc, char* argv[]) {

    int size=0;
    int constraint=0;
    int pos_x=0,pos_y=0,temp;
    int c;
    int ** square;
    int ** temp_square;
    int ** solved_square;
    int best_dev_hist[50]={0};
    int dev;
    int N = 1; // sample size;
    int duration = 60000000 ; //
    int coverage_int;
    double coverage=0.03;  //likelihood of any given swap to be
                       //accomplished before restarting search
    int random_swaps;
    int num_elements;
    double M;
    double solved_count=0;
    double attempts=0;
    double total_iters=0;
    timeval tim;
    double t1,t2,time_diff;
    
     while ((c = getopt (argc, argv, "c:n:v:N:s:")) != -1)
         switch (c)
           {
           case 'n':
             size = atoi(optarg);
             break;
           case 'c':
             constraint = atoi(optarg);
             if(optind < argc)
             pos_x=atoi(argv[optind]);
             if(optind + 1  < argc)
             pos_y=atoi(argv[optind+1]);
             break;
          case 'v':
              coverage_int=atoi(optarg);
              coverage=coverage_int;
              coverage=coverage/100;
              break;
          case 'N':
              N = atoi(optarg);
              break;
           case '?':
               printf("\noption error\n");
             return 1;
           default:
             abort ();
           }

    //printf("\nsize %d con_level %d position %d %d\n",size,constraint,pos_x,pos_y);
    if (size < 3) {
        printf("Please enter a magic square of degree larger than 2 using -n degree");
        return 0;
    }
         
    if (constraint > 3) {
        printf("\ninvalid constraint\n");
        return 0;
    }
         
    if (pos_x > size-constraint+1 || pos_y > size-constraint+1) {
        printf("\ninvalid position\n");
        return 0;
    }

    // Time the program         
    gettimeofday(&tim,NULL);
    t1=tim.tv_sec+(tim.tv_usec/1000000.0);
         
    //determine how many swaps required based on desired coverage.  This is meant to be
    //the the number of swaps required to have swapped "coverage" percent of all 
    // possible swaps.

    num_elements = pow(size,2) - pow(constraint,2);
    random_swaps = log(1 - coverage) /  \
                      log(1 - (1 / ((pow(num_elements,2)-num_elements) / 2)));
    
       
    srand(time(NULL));
   if(constraint > 0 && pos_x==0 && size > 3)
   {   
       pos_x=1;
       pos_y=size/2-constraint/2;
   }
    printf(" %d %d %d %d \n", size,constraint,pos_x,pos_y);
    //I had the posx and posy swapped,  I just fix that here.
    temp=pos_x;
    pos_x=pos_y;
    pos_y=temp;
    
    // calculate M
    M = (double(size) / 2)*(1 + size * size);

    // declare square with variable size from argument
    square = new int*[size];
    temp_square = new int*[size];
    solved_square = new int*[size];
    
    // declare squares
    for (int i = 0; i < size; i++) {
        square[i] = new int[size];
        temp_square[i] = new int[size];
        solved_square[i] = new int[size];
    }
   
    //run algorithm
        for (int i = 0; i < N; i++) // N = sample size
        {

            init_square_old(square,constraint,pos_x,pos_y,size);
            descend(square,temp_square,constraint,pos_x,pos_y,size,M);
            
            dev=100000;
            attempts++; //increase attempt count
            

            for (int j = 0; j < duration; j++) 
            {

                
                init_square_old(square,constraint,pos_x,pos_y,size);
		descend(square,temp_square,constraint,pos_x,pos_y,size,M);
                dev = evaluate(square, size, M);
                
                if (dev == 0)
                {
                    copy_square(square, solved_square, size);
                    solved_count++;
                    total_iters=total_iters+j+1; // for finding average interation count
                    break;
                }

                if (j == duration-1)
                printf("\nfrom duration");
            }                     
        }
  
    if(solved_count>0)
        print_square(solved_square, size);
    else
        printf("\nno solution found");


   
    return 0;
}

