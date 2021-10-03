/*  
Counting sort is a sorting algorithm that sorts the elements of an array by counting 
the number of occurrences of each unique element in the array. The count is stored in 
an auxiliary array and the sorting is done by mapping the count as an index of the auxiliary array.

Time Complexity: O(n+r)          n = no. of elements    r = range of elements
Space Complexity: O(n+r)

Contributor: @whyanujjwhy
*/

//counting sort
#include <iostream>
using namespace std;

void countSort(int array[], int size) {
  // The size of count must be at least the (max+1) but
  // we cannot assign declare it as int count(max+1) in C++ as
  // it does not support dynamic memory allocation.
  // so, its size is provided statically.
  int output[10];
  int count[10];
  int max = array[0];

  //the largest element of the array
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  //initialize count array with all zeros.
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  //store the count of each element
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  //store the cummulative count of each array
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  //find the index of each element of the original array in count array, and
  //place the elements in output array
  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  //copy the sorted elements into original array
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

//print the array
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}


//driver func
int main() {
  int n;
  cout<<"Enter size of array: ";      //user input for size of array ex: 5
  cin>>n;
  int arr[n];
  cout<<"\nEnter space-separated "<<n<<" elements for sorting: "; // ex: 6 5 4 5 2
  for(int i=0; i<n; i++)             //loop for arrat element input  [we can also initialise the array] 
    cin>>arr[i];
  countSort(arr, n);
  printArray(arr, n);                     // output ex: 2 4 5 5 6
}
