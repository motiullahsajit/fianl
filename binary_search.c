#include <stdio.h>

int main()
{

    int n, value, flag = 0;
    scanf("%d %d", &n, &value);

    int arr[n], front = 0, back = n - 1, mid = (front + back) / 2;

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    while (front <= back)
    {
        if (arr[mid] == value)
        {
            flag = 1;
            break;
        }
        else if (arr[mid] < value)
        {
            front = mid + 1;
            mid = (front + back) / 2;
        }
        else if (arr[mid] > value)
        {
            back = mid + 1;
            mid = (front + back) / 2;
        }
    }

    if (flag)
        printf("Value Found !!\n");
    else
        printf("Value Not Found !!\n");

    return 0;
}