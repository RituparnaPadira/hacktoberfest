#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--)
	{
	    ll x,y,min,max;
	    cin>>x>>y;
	    min=x*2;
	    cout<<min<<" ";
	    max=x*y*(x*y-1);
	    cout<<max<<endl;
	}
	return 0;
}
