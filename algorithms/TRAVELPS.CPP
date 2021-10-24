#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,a,b,count=0,count1=0;
	    cin>>n>>a>>b;
	    string s;
	    cin>>s;
	    for(int i=0;i<n;i++)
	    {
	        if (s[i]=='0')
	        count++;
	        else
	         count1++;
	    }
	    
	    int res=0;
	   res= (a*count) +  (b*count1);
	   cout<<res<<endl;
	    
	   
	   
	}
	return 0;
}
