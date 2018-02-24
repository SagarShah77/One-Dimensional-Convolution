/************************************************************
 * Program: convolution.c                                   *  
 * Date: April 11, 2017                                     *
 * sagar                       Status: debug                *  
 * 						                                    * 
 * Purpose:                                                 *
 *    Perform 1D convolution with the kernel                * 
 ************************************************************/ 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

FILE* read;     //input data file to be convolved  

#define dataSize    512  
#define kernelSize  3   

int    i, j, k, l, buffer_index; 
float  x_buffer[dataSize], conv[dataSize];   //input sensor data   
float  kernel[kernelSize];      //kernel  

/*------------------------------------------------*
    main program 
 *------------------------------------------------*/ 
int main(void)
{

kernel[0] = -1.0;      //kernel  
kernel[1] =  0.0;      
kernel[2] =  1.0;     

/*
kernel[0] = -0.037;      //kernel  
kernel[1] = -0.332;      //kernel  
kernel[2] = -0.037;      //kernel  
*/ 
/*
sigma = 1.200000
-1 -0.037370
 0 -0.332452
 1 -0.037370
i*/ 

/*------------------------------------------------
   input sensor data
  ------------------------------------------------*/
   printf("1D convolution\n"); 

   read = fopen("TestData.txt", "r");
   if (read < 0)
    {
        perror("unable to read the data from file");
        return 1;
    }
    while(!feof(read))
   {
      fscanf(read, "%f", &x_buffer[l]);
      printf("l x = %d %f\n", l, x_buffer[l]);
      l++;
   }
   fclose(read);
   buffer_index = l;   // the input data size  

  /*----------------------------------------------   
   The kernel is alway odd numbered 
   e.g., N = 2*k + 1 as follows 
   -K, ... -1, 0, 1, ... , K  
   so the for-loop index is defined such way  
    ----------------------------------------------*/
    j = (kernelSize - 1)/2; 

    for (i=0; i<=(buffer_index-j) ; i++) 
    {
      for (k=-j; k<=j ; k++) 
      {
       conv[i] = conv[i] + x_buffer[i+j+k]*kernel[j+k];  //x_buffer[i+j] with j to shift a half 
                                                       //of the kernel size to take care of 
                                                       //boundary 
       //printf("inner i conv[i] %d %f\n", i, conv[i]);
}
       printf("i conv[i] %d %f\n", i, conv[i]);
}
return 0; 
} 

