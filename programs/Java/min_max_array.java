// A Java Program to find the smallest and the largest number in the array

public class min_max_array
{
    public static void main(String[] args)
    {
        int arr[] = {345345,34,5,653,456345,235};
        int len = arr.length;
        // Asuming that the largest and the smallest number of
        // the array is the first element
        int min = arr[0], max = arr[0]; 
    
        for (int i = 0; i < len; i++)
        {
            // if max is less than the array at index i
            // then max is the array at index i
            if (max < arr[i])
            {
                max = arr[i];
            }
            
            // if min is greater than the array at index i
            // then min is the array at index i
            if (min > arr[i])
            {
                min = arr[i];
            }
        }

        // Printing the max and min value of the array
        System.out.println("The Largest Number Of The Array Is: " + max);
        System.out.println("The Smallest Number Of The Array Is: " + min);
    }
}