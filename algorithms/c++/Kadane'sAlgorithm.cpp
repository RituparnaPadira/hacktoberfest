#include <iostream>
using namespace std;

int main()
{
	int arr[5];
	
	for(int i=0; i<5; i++)
	{
		cin>>arr[i];                
	}
	
	int curr=0;
	int max1=0;
	
	for(int i=0; i<5; i++)
	{
		curr=max(arr[i], arr[i]+curr);
		max1=max(max1,curr);
	}
	
	cout<<"\n"<<max1;
	
	return 0;
}
