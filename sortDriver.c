/* Copyright (C) 1999 Ken Clowes (kclowes@ee.ryerson.ca) */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mySort.h"
#include "metrics.h"

int main(int argc, char * argv[])
{

  int a[MAX_SIZE_N_TO_SORT];
  unsigned int array_size, i;

  if (argc != 1) {
    fprintf(stderr, "Usage: %s ALONE with NO additional command line args\n",
            argv[0]);
    exit(1);
  }

  /* Read ints from stdin into an array */
  for(array_size = 0; (scanf("%d", &a[array_size]) != EOF)
        && (array_size < MAX_SIZE_N_TO_SORT);
      array_size++);

//printf("---------------\n");

  /* sort the array */
  if(array_size > 0) {
    mySort(a, 0, array_size-1);
  }
  printf("SORTED ARRAY:\n");
  /* Print out the modified array */
  for(i = 0; i < array_size; i++)
    printf("%d\n", a[i]);

if (getNumCopies() == array_size-1){
printf("\nThis is the best-case time complexity of the insertion sort algorithm\n");
}
if (getNumCopies() + getNumCompares() == (array_size*array_size-1)){
printf("\nThis is the Worst-case time complexity of the insertion sort algorithm\n\n");
}
/*
double total = getNumCopies() + getNumCompares();
double arrayXarray =(array_size*array_size)  ;


//for insertion sort only

if (array_size>99){
printf("array size : %d\n",array_size);
printf("array squared is  : %lf \n",arrayXarray);
printf("Total Operations: %lf\n",total);
printf("apporching 0.5 but is currently at %lf: \n",total/arrayXarray);
//printf("apporching 0.5 but is currently at %d: \n",total);
}
*/

  /* Print stats */
  fprintf(stderr, "Comparisons: %d\n", getNumCompares());
  fprintf(stderr, "Swaps: %d\n", getNumSwaps());
  fprintf(stderr, "Copy operations: %d\n", getNumCopies());

  exit(0);
}
