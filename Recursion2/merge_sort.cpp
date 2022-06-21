#include <iostream>
using namespace std;

void merge(int *a, int si, int ei)
{
    int mid = (si + ei) / 2;
    int n1 = mid - si + 1;
    int n2 = ei - mid;

    int *arr1 = new int[n1];
    int *arr2 = new int[n2];

    // Copy elements
    int k = si;
    for (int i = 0; i < n1; i++)
    {
        arr1[i] = a[k++];
    }
    k = mid + 1;
    for (int i = 0; i < n2; i++)
    {
        arr2[i] = a[k++];
    }

    int i = 0, j = 0;
    k = si;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            a[k++] = arr1[i++];
        }
        else
        {
            a[k++] = arr2[j++];
        }
    }

    // Store remaining elements of first array
    while (i < n1)
        a[k++] = arr1[i++];

    // Store remaining elements of second array
    while (j < n2)
        a[k++] = arr2[j++];
}

void Merge_Sort(int *a, int si, int ei)
{
    if (si >= ei)
    {
        return;
    }

    int mid = (si + ei) / 2;
    Merge_Sort(a, si, mid);
    Merge_Sort(a, mid + 1, ei);

    merge(a, si, ei);
}

int main()
{
    int arr[] = {23,5,6,43,9,1,12,17,13};
    int l = sizeof(arr) / sizeof(arr[0]);
    Merge_Sort(arr, 0, l - 1);

    for (int i = 0; i < l; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}