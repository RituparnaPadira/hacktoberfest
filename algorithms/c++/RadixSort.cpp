/*  
Radix sort is a sorting algorithm that sorts the elements by first grouping the individual digits of the same place value. 
Contributor: @whyanujjwhy
*/

#include <iostream>
using namespace std;

//to get the largest element
int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if(array[i] > max)
      max = array[i];
  return max;
}

//counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place) {
  const int max = 10;
  int output[size];
  int count[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  //count of elements
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

  //calculate cumulative count
  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];

  //sorting of elements
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

//main func to implement radix sort
void radixsort(int array[], int size) {

  //get max element
  int max = getMax(array, size);

  //counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}

//printing an array
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

//driver func
int main() {
  int n;
  cout<<"Enter size of array: ";      //user input for size of array
  cin>>n;
  int arr[n];
  cout<<"\nEnter space-separated "<<n<<" elements for sorting: ";
  for(int i=0; i<n; i++)             //loop for arrat element input  [we can also initialise the array] 
    cin>>arr[i];
  radixsort(arr, n);
  printArray(arr, n);
}
