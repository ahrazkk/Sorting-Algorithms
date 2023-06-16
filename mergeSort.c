//I did a lot of testing which is why theirs a lot of extra directives. I was too lazy to remove and double check which ones to not remove
#include "mySort.h"

#include <math.h>

#include <stdio.h>

#include <stdlib.h>



void mergeSorted(int array[], int first, int middle, int last) {
  int i, k, j;

  //size of each subarray
  int n1 = middle - first + 1;
  int n2 = last - middle;



  //temporary arrays to hold subarrays numbers
  int Left[n1];
  int Right[n2];



  //Copy elements from original array to temporary arrays on the left side of the merge Sort
  for (i = 0; i < n1; i++) {
    myCopy( & array[first + i], & Left[i]);



  }
  //same thing as previos one but on the right side 
  for (j = 0; j < n2; j++) {
    myCopy( & array[middle + j + 1], & Right[j]);
  }






  j = 0;
  i = 0;
  k = first;



  //Merge elements back into original array in the proper sorted order
  while (i < n1 && j < n2) {
    if (myCompare(Left[i], Right[j]) <= 0) {
      myCopy( & Left[i], & array[k]);
      i++;
    } else {
      myCopy( & Right[j], & array[k]);
      j++;
    }
    k++;
  }



  // Copy remaining elements from Left array
  while (i < n1) {
    myCopy( & Left[i], & array[k]);
    i++;
    k++;
  }


  //same thing but for the right array 
  while (j < n2) {
    myCopy( & Right[j], & array[k]);
    j++;
    k++;
  }
}




void mySort(int array[], unsigned int first, unsigned int last) {
  if (first < last) {

    //middle number
    int middle = first + (last - first) / 2;


    // Recursively sort left and right subarrays
    mySort(array, first, middle);
    mySort(array, middle + 1, last);


    //once sorted out, merge them back in correct order
    mergeSorted(array, first, middle, last);
  }
}



// after testing my compare seems to be working, Not too sure about mycopy and if its supposed to be used as much
