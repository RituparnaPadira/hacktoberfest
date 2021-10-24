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
       long long int p,a,b,c,x,y,count=0,f,g;
       cin>>p>>a>>b>>c>>x>>y;
       if(((x*a + b)||(y*a + c ))> p)  
         {
          cout<<"0"<<endl;
          break;
         } 
        f = x*a + b;
        g = y*a + c;
       while(p>0 && (f<=p || g<=p))
            {
              f = x*a + b;
              g = y*a + c;
             if(f<g)
                {
                 p = p - f;
                 count++;    
                }
             else
                 {
                  p = p - g;
                  count++;
                 }   
            }
       cout<<count<<endl;     
      }

 return 0;
}
