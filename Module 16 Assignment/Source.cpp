#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

bool SequentialSearch(int arr[100], int value)
{
    for (size_t i = 0; i < 100; i++)
    {
        if (arr[i] == value)
        {
            return true;
        }
    }
    return false;
}

int BinarySearch(int arr[100], int low, int high, int value)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;

        
        if (arr[mid] == value)
        {
            return mid;
        }
        
        if (arr[mid] > value)
        {
            return BinarySearch(arr, low, mid - 1, value);
        }
        
        return BinarySearch(arr, mid + 1, high, value);
    }
    return -1;
}

int InterpolationSearch(int arr[], int low, int high, int value)
{
    int pos;
  
    if (low <= high && value >= arr[low] && value <= arr[high])
    {   
        pos = low+ (((double)(high - low) / (arr[high] - arr[low]))  * (value - arr[low]));

        if (arr[pos] == value)
        {
            return pos;
        }
        
        if (arr[pos] < value)
        {
            return InterpolationSearch(arr, pos + 1, high, value);
        }
        
        if (arr[pos] > value)
        {
            return InterpolationSearch(arr, low, pos - 1, value);
        }
    }
    return -1;
}

int main()
{
    int arr[100]{};
    bool isDuplicate = false;
    for (size_t i = 0; i < 100; i++)
    {
        for (size_t j = 0; j < length; j++)
        {
            
            arr[i] = rand() % 100;
        }
       
        
    }
    clock_t time;
    time = clock();
    SequentialSearch(arr,5);
    time = clock() - time;

    int timeElapsed = time / CLOCKS_PER_SEC;
    cout << "Looking for value 5 took " << timeElapsed << " seconds" << endl;

    return 0;
}