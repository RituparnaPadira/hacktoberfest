#include <bits/stdc++.h>
using namespace std;


int main()
{
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 
 int t;
 cin>>t;
 while(t--)
      {
       int n,p,x,y;
       cin>>n>>p>>x>>y;
       int  s[n];
       for (int i = 0; i < n; i++)
           {
            cin>>s[i];
           }
       int i = 0,time=0;
       while(i<=p-1)
            {
             if(s[i]==0) time += x;
             else time += y;   
             i++;
            }        
       cout<<time<<endl;
      }

 return 0;
}

