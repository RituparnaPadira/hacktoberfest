#include <stdio.h>
int main()
{
    int a[27],b[27],c[54],m,n,i,j,z,y=0,t,s=0;
    printf ("How many terms you want to add in the 1st polynomial ?? : ");
    scanf ("%d",&n);
    
    printf ("Enter 1st polynomial : \n");
    for (i=0;i<n*3;i=i+3)
    {
        printf ("Enter coefficient : ");
        scanf("%d",&a[i]);
        printf ("Enter power of x : ");
        scanf("%d",&a[i+1]);
        printf ("Enter power of y : ");
        scanf("%d",&a[i+2]);
    }
    printf ("1st polynomial is : ");
    for (i=0;i<n*3;i=i+3)
    {
        printf ("(%dx^%dy^%d) + ",a[i],a[i+1],a[i+2]);
        
    }
    printf (" 0 \n");
    printf ("How many terms you want to add in the 2nd polynomial ?? : ");
    scanf ("%d",&m);
    
    printf ("Enter 2nd polynomial : \n");
    for (i=0;i<m*3;i=i+3)
    {
        printf ("Enter coefficient : ");
        scanf("%d",&b[i]);
        printf ("Enter power of x : ");
        scanf("%d",&b[i+1]);
        printf ("Enter power of y : ");
        scanf("%d",&b[i+2]);
    }
    printf ("2nd polynomial is : ");
    for (i=0;i<m*3;i=i+3)
    {
        printf ("(%dx^%dy^%d) + ",b[i],b[i+1],b[i+2]);
        
    }
    printf (" 0\n");
    
    
    printf ("Enter 1 to add  : ");
    scanf("%d",&z);
    switch (z)
    {
        case 1:
        for (i=0;i<n*3;i++)
        {c[i]=a[i];}
        for (i=n*3,j=0;i<(n+m)*3,j<m*3;i++,j++)
        {c[i]=b[j];}
        for (i=0;i<(m+n)*3;i=i+3)
    {
        printf ("(%dx^%dy^%d) + ",c[i],c[i+1],c[i+2]);
        
    }
    printf (" 0\n");    
    }
    
    for (i=1;i<(m+n)*3;i=i+3)
    {
        for (j=4;j<(m+n)*3;j=j+3)
        {
            if (c[i]==c[j])
            { if(c[i+1]==c[j+1])
            {   
                c[i-1]=c[i-1]+c[j-1];
                c[j-1]=0;


            }
            }
        }
    }
    printf ("ADDITION \n");
    for (i=0;i<(m+n)*3;i=i+3)
    if (c[i]!=0)
    {
        printf ("(%dx^%dy^%d) + ",c[i],c[i+1],c[i+2]);
        
    }
    else
    printf (" ");


    printf (" 0 \n");
    


}

