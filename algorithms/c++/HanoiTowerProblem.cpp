#include <bits/stdc++.h>

using namespace std;

int counti =0;

void T_O_Hanoi(int n, char src, char dest, char helper)
{
	if (n==0){
		return;
	}
	
	T_O_Hanoi(n-1, src, helper, dest);
	counti++;
	cout<<" Step "<<counti<<" Move from "<<src<<" to "<<dest<<endl;
	T_O_Hanoi(n-1, helper, dest, src);
}

int main(){
	
	int n;
	cout<<"Enter number of disk : ";
	cin>>n;
	T_O_Hanoi(n, 'A', 'C', 'B');
	
	return 0;
}
