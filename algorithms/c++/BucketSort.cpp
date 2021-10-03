/*  
Bucket Sort is a sorting algorithm that divides the unsorted array elements into several groups called buckets. 
Each bucket is then sorted by using any of the suitable sorting algorithms or recursively applying the same bucket algorithm.

Mostly, the bucket sort is used to sort floating-point numbers in the range [0,1]
This program also sorts floating-point numbers in range 0 to 1.

Contributor: @whyanujjwhy
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//bucket sort function
void bucketSort(float arr[], int n) {
    // Create n number of empty buckets dynamic allocation
    vector<float> b[n];
  
    // put data in their prospective buckets
    for(int i=0; i<n; i++) {
       int bi = n*arr[i];
       b[bi].push_back(arr[i]);
    }
  
    // Sort the array using the default sort() function from algorithm library
    for(int i=0; i<n; i++)
       sort(b[i].begin(), b[i].end());
  
    // Concatenate all buckets in array
    int index = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < (signed)b[i].size(); j++)
          arr[index++] = b[i][j];
}

int main() {
    
    int len;
    cout<<"Enter size of array: "; 
    cin>>len;
    float data[len];
    cout<<"\nEnter space-separated "<<len<<" elements for sorting in the range [0,1]: ";
    for(int i=0; i<len; i++)             //loop for array element input  [we can also initialise the array] 
      cin>>data[i];
  
    cout<<"\nUnsorted array is :";
    for(int i=0; i<len; i++)
       cout<<data[i]<<" ";
    bucketSort(data, len);
    cout<<endl<<"\nSorted array is :";
    for(int i=0; i<len; i++)
       cout<<data[i]<<" ";
    cout<<endl;
    return 0;
}
