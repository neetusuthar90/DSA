// Decresing order

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void inplaceHeapSort(int *input, int n)
{
    // Build Heap in input array
    for (int i = 1; i < n; i++)
    {
        int childIndex = i;

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;

            if (input[childIndex] < input[parentIndex])
            {
                swap(input[childIndex], input[parentIndex]);
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }
    
    // Remove elements
    int size = n;
    while (size > 1)
    {
        swap(input[0], input[size - 1]);
        size--;

        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while (leftChildIndex < size)
        {
            int minIndex = parentIndex;
            if (input[minIndex] > input[leftChildIndex])
            {
                minIndex = leftChildIndex;
            }
            if (rightChildIndex < size && input[rightChildIndex] < input[minIndex])
            {
                minIndex = rightChildIndex;
            }
            if (minIndex == parentIndex)
            {
                break;
            }

            swap(input[parentIndex], input[minIndex]);

            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
    }    
}

int main()
{
    int input[] = {10,5,8,1,4};
    int size = sizeof(input)/sizeof(input[0]);
    inplaceHeapSort(input,size);
    for(int i = 0; i<size; i++){
        cout << input[i] << " ";
    }
    cout << endl;
}