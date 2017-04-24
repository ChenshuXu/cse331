#include <iostream>
#include <cassert>
#include <math.h>
#include <sys/time.h>
#include <stdlib.h>

using namespace std;

// short integer random number generator from stdlib
int rand(void); 

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int A[], int left, int right){
//    int random = rand() % (right+1);
    int pivot = A[right];
    int i = left-1;
    int j = right;
    
    for(;;){
        while(A[++i] < pivot && i <= right){
        }
        
        while(A[--j] > pivot && j >= left){
        }
        
        if (i<j){
            swap(A[i],A[j]);
        }else{
            break;
        }
    }
    swap(A[i], A[right]);
    return i;
}

void quickSort(int A[], int left, int right){
    if (left<right){
        int q = partition(A,left,right);
        quickSort(A,left,q-1);
        quickSort(A,q+1,right);
    }
}



int main()
{ 
  int size;
  //hrtime_t start, total;  // defined in sys/time.h  long long int
  timeval start, end; // type defined in sys/time.h.
  double start_sec, end_sec, t_sec;

  //double t_sec;

  cout << endl << " ----- insertion/quicksort comparison ----- " << endl;
  cout << endl << "How many elements to sort: - ";  cin >> size;
  int* dataArray = new int [size];   // get array of right size
  int* copyArray = new int [size];   // to hold a copy of random ints
  assert ( (dataArray != NULL) && (copyArray != NULL) );

  //  ============ insertion sort random integers  ===================

  for (int k=0; k< size ; k++)  dataArray[k] = rand();

  // copy the array for later use by quicksort 
 for (int k=0; k< size ; k++)  copyArray[k] = dataArray[k];

  cout << endl << "Insertion sort of Integer data initially in random order" << endl;

  //start = gethrtime();   // hi_resolution time nanoseconds

  gettimeofday(&start, NULL);  // get time at start of function


  // implement your insertionSort here or call it as a function
  //   =====================InsertionSort===============
  //   You can refer Mark Allan Weiss Third Edition Figure 7.2 page 293
  
  int j;
  int temp = 0;
  for (int i = 0; i<size; i++){
      j = i;
      while (j > 0 && dataArray[j] < dataArray[j-1]){
          temp = dataArray[j];
          dataArray[j] = dataArray[j-1];
          dataArray[j-1] = temp;
          j=j-1;
      }
      
  }

  gettimeofday(&end, NULL);  // get time at end of function
  // convert to seconds and print out
  start_sec = double(start.tv_sec) + double(start.tv_usec) * 1e-6;
  end_sec = double(end.tv_sec) + double(end.tv_usec) * 1e-6;
  t_sec = end_sec - start_sec;

  //total = gethrtime() - start;
  //t_sec = double(total) * 1.0e-9;  // convert to seconds
  cout << "For N = " << size << " # seconds = " << t_sec << "\n";

  cout << "First five sorted elts:  ";
  for ( int k=0; k<5; k++)  cout << dataArray[k] << ", " ;
  cout << endl;
  cout << "Last five sorted elts:  ";
  for ( int k=5; k>0; k--)  cout << dataArray[size-k] << ", " ;
  cout << endl << endl;

  //  ============ quicksort random integers  ===================

  cout << endl << "quicksort of Integer data initially in random order" << endl;

  //start = gethrtime();   // hi_resolution time nanoseconds
  gettimeofday(&start, NULL);  // get time at start of function


  // implement your quicksort here or call it as a function
  // =====================Quicksort ======================
  // you can refer Mark Allan Weiss Third Edition Figure 7.17 page 317. Note that this piece 
  // of code only use quick sort when the input has size at least 10. Please only implement 
  // the quicksort part no matter how large the input is. 

  quickSort(copyArray,0,size-1);

  gettimeofday(&end, NULL);  // get time at end of function
  // convert to seconds and print out
  start_sec = double(start.tv_sec) + double(start.tv_usec) * 1e-6;
  end_sec = double(end.tv_sec) + double(end.tv_usec) * 1e-6;
  t_sec = end_sec - start_sec;

  //total = gethrtime() - start;
  //t_sec = double(total) * 1.0e-9;  // convert to seconds
  cout << "For N = " << size << " # seconds = " << t_sec << "\n";

  cout << "First five sorted elts:  ";
  for ( int k=0; k<5; k++)  cout << copyArray[k] << ", " ;
  cout << endl;
  cout << "Last five sorted elts:  ";
  for ( int k=5; k>0; k--)  cout << copyArray[size-k] << ", " ;
  cout << endl << endl;

}
