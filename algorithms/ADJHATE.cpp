#include <bits/stdc++.h>
using namespace std;

int main() 
{
 int t;
 cin>>t;
 while(t--)
      {
       long long int n,e=0,o=0,cnt=0;
       cin>>n;
       long long int a[n];
       vector<long long int> b,c;
       for(int i=0;i<n;i++)
           {
            cin>>a[i];
            if(a[i]%2==0) 
               {
                e++;
                b.push_back(a[i]);
               } 
            else
               {
               o++;
               c.push_back(a[i]);
               }
           }
       if(e==0||o==0)
          cout<<"-1";
        
        else{
        for(int i=0;i<b.size();i++)
           {
            cout<<b[i]<<" ";   
           }
        for(int i=0;i<c.size();i++)
           {
            cout<<c[i]<<" ";   
           }}
       cout<<"\n";       
      }
 return 0;
}
