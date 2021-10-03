#include<bits/stdc++.h>    
using namespace std;    
 
void bubble_sort(int A[], int N) 
{  
	int X;  
   	for(int i = 0; i < N; i++)    
    {    
      	for(int j = i+1; j < N; j++)    
        {    
            if(A[j] < A[i])    
            {    
                X = A[i];    
                A[i] = A[j];    
                A[j] = X;     
            }     
        }     
    }     
    
 }  
 
int main()    
{    
    int i, j,temp;     
    int A[] = {34,78,45,23,2};     
    int N = sizeof(A)/sizeof(A[0]);   
    
	cout<<"Before sorting : ";  
    for(int i = 0; i < N; i++)    
       cout<<A[i]<<" ";     
    
    bubble_sort(A, N);  
    
    cout<<"\nAfter sorting : ";    
    for(int i = 0; i < N; i++)    
       cout<<A[i]<<" ";     
       
return 0;  
}
