#include <stdio.h>
#define FALSE 0
#define TRUE !(FALSE)
#define MAX 10
void raise(char *error)
{
    printf("\033[31m");
    printf(error);
    printf("\033[0m");
}
int arr[MAX], n = 0;
void traverse()
{
    if (!n)
    {
        raise("ERROR: EmptyArray\n");
        return;
    }
    printf("ARR: ");
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insertionSort()
{
    int temp, j;
    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        for (j = i - 1; j > -1 && arr[j] > temp; --j)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}
void shellSort()
{
    int j, temp;
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; ++i)
        {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
void heapify(int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(n, largest);
    }
}
void heapSort()
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(i, 0);
    }
}
void merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
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
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m, r);
    }
}
void bubbleSort()
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}
int partition(int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int low, int high)
{
    if (low < high)
    {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}
int main()
{
    int in;
    while (TRUE)
    {
        printf("\n------------------------- SORTING -----------------------\n");
        printf("EXIT: 0\nNEW ARRAY: 1\nINSERTION SORT: 2\nSHELL SORT: 3\nMERGE SORT: 4\nHEAP SORT: 5\nBUBBLE SORT: 6\nQUICK SORT: 7\n");
        printf("ENTER CHOICE: ");
        scanf("%d", &in);
        if (!in)
        {
            break;
        }
        if (in == 1)
        {
            n = 0;
            while (TRUE)
            {
                printf("\n-------------------- INSERT VALUES ------------------------\n");
                printf("\nSAVE ARRAY: 0\nADD MORE: 1\nENTER CHOICE: ");
                scanf("%d", &in);
                printf("\n");
                if (!in)
                    break;
                if (in == 1)
                {
                    if (n == MAX)
                    {
                        raise("ERROR: OverFlow -m no space to add element\n");
                        break;
                    }
                    printf("\nEnter value: ");
                    scanf("%d", &in);
                    arr[n++] = in;
                    traverse();
                }
                else
                    raise("ERROR: InvalidInput -m input must be an integer value between 0 and 1\n");
            }
        }
        else if (!n)
        {
            raise("ERROR: EmptyArary -m can not sort an empty array\n");
        }
        else if (in == 2)
        {
            printf("BEFORE SORTING ");
            traverse();
            insertionSort();
            printf("AFTER SORTING ");
            traverse();
        }
        else if (in == 3)
        {
            printf("BEFORE SORTING ");
            traverse();
            shellSort();
            printf("AFTER SORTING ");
            traverse();
        }
        else if (in == 4)
        {
            printf("BEFORE SORTING ");
            traverse();
            mergeSort(0, n - 1);
            printf("AFTER SORTING ");
            traverse();
        }
        else if (in == 5)
        {
            printf("BEFORE SORTING ");
            traverse();
            heapSort();
            printf("AFTER SORTING ");
            traverse();
        }
        else if (in == 6)
        {
            printf("BEFORE SORTING ");
            traverse();
            bubbleSort();
            printf("AFTER SORTING ");
            traverse();
        }
        else if (in == 7)
        {
            printf("BEFORE SORTING ");
            traverse();
            quickSort(0, n - 1);
            printf("AFTER SORTING ");
            traverse();
        }
        else
            raise("ERROR: InvalidInput -m input must be an integer value between 0 and 7\n");
    }
    return 0;
}