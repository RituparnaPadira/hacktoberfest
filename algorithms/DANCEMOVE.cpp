#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int x,y,count=0;
	    cin>>x>>y;
	    while(x!=y)
	    {
	        if(x<y){
	            
	        
	        x+=2;
	        count++;
	        }
	        if(x>y)
	        {
	        x-=1;
	        count++;
	        }
	        
	    }
	    
	   cout<<count<<endl;
	  
	    
	   
	   
	}
	return 0;
}
