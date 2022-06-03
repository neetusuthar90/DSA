#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int list[10] = {2, 3, 4, 5, 6};
    int list1[10];

    for (int i = 0; i < 5; i++)
    {
        int temp;
        int x = list[i];
        temp = find_cube(x);
        list1[i] = temp;
    }
    printf("[");
    for (int j = 0; j < 5; j++)
    {
        int z = list1[j];
        printf("%d ", z);
    }
    printf("]");
    return 0;
}

void find_cube(int s)
{
    int result;
    result = s * s * s;
    return result;
}