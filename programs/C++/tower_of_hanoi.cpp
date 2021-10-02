#include<iostream>
#include<math.h>

 using namespace std;
 int n=100;
 char source='A';
 char helper='B';
 char dest='C';
 class stack
 {
     int* arr;
     int top;
     public:
     stack()
     {
         arr=new int[n];
         top=-1;
     }

     void push(int x)
     {
         if(top==n-1)
         {
             cout<<"\nStack overflow :(\n";
             return;
         }
         top++;
         arr[top]=x;
       
     }


     void pop()
     {
        
         if(top==-1)
         {
            cout<<"\nno element found :( \n";
            return; 
         }
         else{
         top--;
         return;
         }
     }
    
     int Top()
     {
         if(top==-1)
         {
             cout<<"\nno element in stack :(\n";
             return -1;
         }
        
         return arr[top];

     }

     bool empty()
     {
         return top==-1;
     }
     void printstack()
     {
         int temp;
         temp=top;
         for(int i=temp;i>=0;i--)
         {
             cout<<arr[i]<<"\n";
         }
     }
     
 };

void towerofhanoi(int disk,char A,char C,char B,stack &S,stack &D,stack &H)
{
    if(disk==1)
    {
        cout<<"moving disk 1 from "<<A<<" to "<<C<<"\n";
        D.push(S.Top());
        S.pop();
        return;
    }

towerofhanoi(disk-1,A,B,C,S,H,D);
cout<<"moving disk "<<disk<<" from "<<A<<" to "<<C<<"\n";
 D.push(S.Top());
 S.pop();
towerofhanoi(disk-1,B,C,A,H,D,S);
}



     

 int main()
 {
     stack A,B,C;
     int disk;
     cout<<"enter how many disk in "<<source<<" tower : ";
     cin>>disk;
     for(int i=disk;i>=1;i--)
     A.push(i);

     A.printstack();
     towerofhanoi(disk,source,dest,helper,A,C,B);
     cout<<"number of moves "<<(pow(2,disk)-1)<<"\n";
     cout<<"disk in "<<dest<<" rod : \n";
     C.printstack();
    
    
return 0;

 }
