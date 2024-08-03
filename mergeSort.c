#include <stdio.h>
#include <stdlib.h>

void printArray (int arr[], int size);
void merge(int arr[],int mid, int left, int right);
void mergeSort(int arr[], int left , int right);

int main()
{
    int arr[10] = {10, 8 , 3, 6, 11, 9, 17, 5, 4, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unordered array: ");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("\n");
    printf("Ordered array: ");
    printArray(arr, n);

    return 0;
}

void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[],int mid, int left, int right)
{
    //sublist size == L[n1]
    int n1 = mid - left + 1;
    int n2 = right - mid;

    //sublist
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));


    //copy data to the sublists(temporaly arrays)
    for(int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for(int j = 0; j < n2;j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    //merge the temporary arrays back to the original array
    int i = 0;
    int j = 0;
    int k = left;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    //copy the rest elements of L[]
    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    //copy the rest elements of R[]
    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    //free the temporary memory
    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;
        //sort the first and the second division
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        //combine the 2 divisions
        merge(arr, mid, left, right);
    }
}
