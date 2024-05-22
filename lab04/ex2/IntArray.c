#include "IntArray.h"
int max(int arr[], int size)
{
    if (size < 1)
    {
        return -1;
    }

    int ind = 0;
    int i;
    for (i = 1; i < size; i++)
    {
        if (arr[i] > arr[ind])
        {
            ind = i;
        }
    }
    return ind;
}
int secondMax(int arr[], int size)
{
    if (size < 2)
    {
        return -1;
    }

    int maxind = max(arr, size);
    int secondmax = -1;
    int i;
    for (i = 0; i < size; i++)
    {
        if (i == maxind)
        {
            continue;
        }
        if (arr[i] >= arr[maxind])
        {
            secondmax = maxind;
            maxind = i;
        }
        else if (secondmax == -1 || arr[i] > arr[secondmax])
        {
            secondmax = i;
        }
    }
    return secondmax;
}
float average(int arr[], int size)
{
    if (size == 0)
    {
        return 0;
    }
    int sum = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return (float)sum / size;
}