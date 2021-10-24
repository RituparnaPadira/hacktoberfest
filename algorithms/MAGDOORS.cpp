#include <bits/stdc++.h>
using namespace std;

void init_code()
{
 #ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
 #endif // ONLINE_JUDGE
}


int main()
{
 init_code();
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 
  int t;
 cin>>t;
 while(t--)
      {
       string s;
       cin>>s;
       int f=0,j=0;
       for(int i=0;i<s.size();i++)
          {
           if(s[i]=='0')
             {
              for(j=i;j<s.size();j++)
                 {
                  if(s[j]=='1') 
                     break;      
                 }
               f++;      
               i=j;
             }
          }
       if(s[s.size()-1]=='0') cout << 2*f-1 <<endl;
       else cout<<2*f<<endl; 
      }

 return 0;
}

