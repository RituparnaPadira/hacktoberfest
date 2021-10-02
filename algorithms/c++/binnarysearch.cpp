#include<iostream>
#include<stdio.h>
using namespace std;
void bsearch(int B[50],int j, int p)
   {
       char f='n';
       int f1=0,l1=j-1,m1;
       while(f1<=l1)
         {
             m1=(f1+l1)/2;

             if(B[m1]==p)
               { cout<<"\nElement found at pos="<<m1+1; f='y'; break;}
             else if(B[m1]<p)
               { f1=m1+1;}
             else 
               {l1=m1-1;}
         }
         if(f=='n')
          cout<<"\nElement not found";

   }

int main()
{
    int A[50],i,n,e;
    cout<<"\nEnter size of array";
    cin>>n;
    for(i=0;i<n;i++)
        cin>>A[i];

    cout<<"\nEnter element to search";
    cin>>e;
    bsearch(A,n,e);

    return 0;
}