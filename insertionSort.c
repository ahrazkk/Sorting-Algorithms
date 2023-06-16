#include "mySort.h"

#include <math.h>

#include <stdio.h>

void mySort(int array[], unsigned int first, unsigned int last) {
  int i, j, key;

 
   

  for (i = 0; i <= last; i++) {  			//first +1 is the same as just i=1, when code runs, if you remove the +1 the stats are myCompare = 4, myCopy = 5, otherwise, with it, its myCompare = 4, myCopy = 4
    key = array[i];								//for myCopy, if on the left side you 													have an array item (e.g., array[i] = tmp) you need to use myCopy.
    j = i - 1;

 
																//be mindful of which way you make either your 																varibles appear in the matrices, or the opperator sign

    while ( j>= 0 && myCompare(key, array[j]) < 0) { 		//j>= 0 does not compare array elements
	
     myCopy( & array[j], & array[j + 1]); 					//pointer uses and sign+left side contained array item
      j--;



    }
    myCopy( & key, & array[j + 1]); //left side contained array item

  }

}



