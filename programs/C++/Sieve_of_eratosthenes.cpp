
#include<iostream>
using namespace std;
void primesieve(int n)
{
    int prime[100]={0};
    for(int i=2;i<=n;i++)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<=n;j=j+i)
            {
                prime[j]=1;
            }
        }
    }
        for(int i=2;i<=n;i++)
        {
            if(prime[i]==0)
            {
                cout<<i<<" ";
            }
        }

}
int main()
{

    int n;
    cout<<"\n ENTER THE INTEGER :";
    cin>>n;
    primesieve(n);
    return 0;
}
