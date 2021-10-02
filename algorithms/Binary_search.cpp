#include <iostream>
using namespace std;
//Recursive
int B_search(int a[], int l, int r, int ele)
{
    if (l <= r)
    {
        int mid = (l + (r - 1)) / 2;

        if (a[mid] == ele)
            return mid;

        if (a[mid] > ele)
        {
            return B_search(a, l, mid - 1, ele);
        }

        return B_search(a, mid + 1, r, ele);
    }

    return -1;
}
//Iterative
int Bi_search(int a[], int l, int h, int x)
{
    while (l <= h)
    {
        int k = l + (h - l) / 2;

        if (a[k] == x)
            return k;

        else if (a[k] < x)
            l = k + 1;

        else
            h = h - 1;
    }

    return -1;
}

int main()
{
    int n;
    cout << "Enter Size : ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ele;
    cout << "Enter The Element to Search :";
    cin >> ele;

    int c;
    c = B_search(a, 0, n, ele);

    if (c != -1)
    {
        cout << "\n"
             << ele << "    Element Found at index " << c;
    }
    else
    {
        cout << "\n Element Not Found";
    }
}