#include <bits/stdc++.h>  
  using namespace std;
  
void selection_sort(int A[], int N)  
{  
    int x; 
      
    for (int i = 0; i < N-1; i++) 
    {  
        x = i;
        for (int j = i+1; j < N; j++)  
        if (A[j] < A[x])  
            x = j;  
    int X = A[x];  
    A[x] = A[i];  
    A[i] = X;  
    }  
}  

  
int main()  
{  
    int A[] = { 32,45,67,12,40};  
    int Size = sizeof(A) / sizeof(A[0]);  
   
   	printf("Before sorting : ");  
    for (int i = 0; i < Size; i++)  
        cout<<A[i]<<" ";
		   
    selection_sort(A, Size);  
    
    cout<<"\nAfter sorting : ";  
    for (int i = 0; i < Size; i++)  
        cout<<A[i]<<" ";    
     
    return 0;  
}    
