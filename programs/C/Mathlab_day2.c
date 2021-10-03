#include <stdio.h>
int main()
{
    int n,i,j;
    float sum,t,u,x,a[100][100];
    printf("Enter no of data points:\n");
    scanf("%d",&n);
    printf("Enter values of x and y\n");
    for(i=0;i<n;i++)
    {
        scanf("%f",&a[i][0]);
        scanf("%f",&a[i][1]);
    }
    for(j=2;j<=n;j++)
    {
        for(i=0;i<=n-j;i++)
        a[i][j]=a[i+1][j-1]-a[i][j-1];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n-i;j++)
        printf("%f  ",a[i][j]);
        printf("\n");
    }
    printf("Enter interpolating point:\n");
    scanf("%f",&x);
    sum=a[0][1];
    t=1;
    u=(x-a[0][0])/(a[1][0]-a[0][0]);
    for(j=2;j<=n;j++)
    {
        t=t*(u-j+2)/(j-1);
        sum=sum+t*a[0][j];
    }
    printf("f(%f)=%f",x,sum);
    return 0;
}

