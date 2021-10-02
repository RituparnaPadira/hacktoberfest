#include<iostream>
#include<stdio.h>
 using namespace std;

void Merge(int *A, int low, int high, int mid)
{
	
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
 
	
	while (i <= mid && j <= high)
	{
		if (A[i] < A[j])
		{
			temp[k] = A[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = A[j];
			k++;
			j++;
		}
	}
 
	
	while (i <= mid)
	{
		temp[k] = A[i];
		k++;
		i++;
	}
 
	
	while (j <= high)
	{
		temp[k] = A[j];
		k++;
		j++;
	}
 
 
	
	for (i = low; i <= high; i++)
	{
		A[i] = temp[i-low];
	}
}
 

void MergeSort(int *A, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		
		MergeSort(A, low, mid);
		MergeSort(A, mid+1, high);
 
		
		Merge(A, low, high, mid);
	}
}
 
int main()
{
	int n, i;
	cout<<"\nEnter the size of array ";
	cin>>n;
 
	int arr[n];
    cout<<"\nEnter element of array";
	for(i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
    cout<<"\nOriginal  array.................\n";
	for (i = 0; i < n; i++)
        cout<<arr[i]<<"\t"; 
 
	MergeSort(arr, 0, n-1);
    
       
 
	cout<<"\nSorted array.................\n";
	for (i = 0; i < n; i++)
        cout<<arr[i]<<"\t";
 
	return 0;
}