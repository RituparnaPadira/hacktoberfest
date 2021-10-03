#include <iostream>
using namespace std;

void binarySearch(int key)
{
    int mid, start, end;
    start = 0;
    bool found=false;
    int inp[] = {1, 3, 5, 7, 9, 12, 15, 18};
    end = ((sizeof(inp) / sizeof(inp[0]))-1);

    while (start <= end)
    {
        mid = ((start + end) / 2);
        if (key > inp[mid])
        {
            start = mid + 1;
        }
        else if (key < inp[mid])
        {
            end = mid - 1;
        }
        else if (key == inp[mid])
        {
            cout << "Ceiling is "<<inp[mid]<< endl;
            found=true;
            break;
        }
    }
    if(!found){
        cout<<"Ceiling is "<<inp[start]<<endl; //print "inp[end]"" here if problem is find floor of number instead of ceiling
    }
}

int main()
{
    int key;
    cout << "Enter Element to Search" << endl;
    cin >> key;
    binarySearch(key);
    return 0;
}
