/*  
Heap Sort is based on the binary heap data structure. In the binary heap the child nodes of a parent node 
are smaller than or equal to it in the case of a max heap, and the child nodes of a parent node are 
greater than or equal to it in the case of a min heap.


This is a max heap sort algorithm!

contributor: @whyanujjwhy

*/

#include <iostream>
using namespace std;

//recursive function to convert elements into max_heap
void heapify(int arr[], int n, int i) {
  int max=i;                     //initailly max as root
  int lChild=2*i+1;
  int rChild=2*i+2;
  
  //when left child > root
  if(lChild < n && arr[lChild] > arr[max])
     max=lChild;
     
  //when right child > max
  if(rChild < n && arr[rChild] > arr[max])
     max=rChild;
  
  //if max is not root
  if(max != i) {
    swap(arr[i], arr[max]);
    heapify(arr, n, max);      //heapify affected sub-tree, recursively
  }
}

//main function for heapsort
void heapSort(int arr[], int n) {
  //re-arrangement 
  for(int i=n/2 -1; i>=0; i--)
    heapify(arr, n, i);
  
  //extracting elements
  for(int i=n-1; i>=0; i--) {
    swap(arr[0], arr[i]);     //current root -> end
    
    heapify(arr, i, 0);       //calling max_heapify on the heap reduced
  }  
}

//printing array
void display(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout<<arr[i]<<" ";
  cout<<"\n";
}
 
//Driver code
int main() {
  int n;
  cout<<"Enter size of array: ";      //user input for size of array
  cin>>n;
  int arr[n];
  cout<<"\nEnter space-separated "<<n<<" elements for sorting: ";
  for(int i=0; i<n; i++)             //loop for arrat element input  [we can also initialise the array] 
    cin>>arr[i];
  cout<<"\nOriginal array:\n";
  display(arr, n);
  heapSort(arr, n);
  
  cout<<"Sorted array:\n";
  display(arr, n);
  }     
