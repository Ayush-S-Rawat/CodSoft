//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void displayarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void ins_at_index(int arr[], int n, int index, int value)
{
    for (int i = n; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
}

void insertionsort(int arr[], int n)
{
    int i,j;
    for (i = 1; i < n; i++)
    {
        int temp = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = temp;
    }
}

int main()
{
    int n, arr[10000] = {13, 23, 5, 78, 19};
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter elments of array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "\nArray before Insertion Sort:\n";
    displayarray(arr, n);
    insertionsort(arr, n);
    cout << "\nArray after Insertion Sort:\n";
    displayarray(arr, n);
    return 0;
}