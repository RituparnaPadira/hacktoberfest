#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--)
	{
	    
	    int mex;
	    cin>>mex;
	    bool flag=true;
	    int c=0,nm=mex;
	    if(nm==0)
	    {
	        cout<<"1"<<endl;
	        continue;
	    }
	    while(nm!=0)
	    {
	        int l=nm%2;
	        if(l==0)
	        flag=false;
	        nm=nm/2;
	        c++;
	    }
	    if(flag)
	    cout<<mex+1<<endl;
	    else
	    {
	        int s=0;
	        c--;
	        while(c--)
	        {
	            s+=pow(2,c);
	        }
	        cout<<s+1<<endl;
	    }
	   
	}
	return 0;
}
