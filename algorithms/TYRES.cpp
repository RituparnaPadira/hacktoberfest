#include <bits/stdc++.h>
using namespace std;

int main() 
{
 int t;
 cin>>t;
 while(t--)
       {
        int n;
        cin>>n;
        if(n%4==0 || n%2==1) cout<<"NO"<<endl;
        else if((n%4)%2==0) cout<<"YES"<<endl;
       }
 return 0;
}
