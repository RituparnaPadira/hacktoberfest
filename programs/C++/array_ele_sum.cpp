// A C++ Program to find the sum of the elements of an array

#include <iostream>

int main()
{
    // Creating an integer array
    int arr[] = {1, 4, 4, 6, 3, 2, 6, 7, 3, 5};
    // Storing the array length in a variable
    int len = sizeof(arr) / sizeof(arr[0]);
    // Initializing the sum of the elements to zero at first
    int sum = 0;

    // A loop to iterate over the array and increament the sum
    for (int i = 0; i < len; i++)
    {
        // same as sum = sum + i;
        sum += i;
    }

    // Displaying the sum
    std::cout << "The Sum of the elements of the given array is: " << sum << std::endl;
}