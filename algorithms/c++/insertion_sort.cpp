#include<iostream>
using namespace std;

void insertionSort(){
    int inp[]={5,3,4,1,2,7,9,6,8};
    int length = (sizeof(inp) / sizeof(inp[0]));
    int temp;
    cout<<length<<endl;
    for(int i=0;i<length-1;i++){
        for(int j=i+1;j>=1;j--){
            if(inp[j-1]>inp[j]){
                temp=inp[j];
                inp[j]=inp[j-1];
                inp[j-1]=temp;
            }
            else{
                break;
            }
        }
    }
     for(int i=0;i<length;i++){
         cout<<inp[i]<<" ";
     }
}

int main(){
  insertionSort();
  return 0;
}