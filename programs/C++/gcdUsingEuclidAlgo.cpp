/* This program can be used to calculate GCD and LCM of two numbers a and b in O(log min(a,b)) time complexity*/ 
#include<bits/stdc++.h>
using namespace std;
int findGcd(int a,int b){
	if(a==0)
		return b;
	return findGcd(b%a,a);
}
int main(){
	cout<<"Enter 1st number"<<endl;
	int a,b;
	cin>>a;
	cout<<"Enter 2nd number"<<endl;
	cin>>b;
	int gcd = findGcd(a,b);
	cout<<"GCD of two numbers is: "<<findGcd(a,b)<<endl;
	if(gcd!=0)
		cout<<"LCM of two numbers is: "<<a*b/gcd<<endl;
	else
		cout<<"LCM of two numbers is: "<<"0"<<endl;
	return 0;
}