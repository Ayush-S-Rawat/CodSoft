//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int r, c, b;
    cin >> r >> c >> b;
    int ***arr = new int **[r];

    for (int i = 0; i < r; i++)
    {
        arr[i] = new int *[c];
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            arr[i][j] = new int[b];
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            for (int k = 0; k < b; k++)
            {
                cin >> arr[i][j][k];
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            for (int k = 0; k < b; k++)
            {
                cout << " " << arr[i][j][k];
            }
        }
    }

    // for (int i = 0; i < r; i++)
    // {
    //     for (int j = 0; j < c; j++)
    //     {
    //         cout << " " << arr[i][j];
    //     }
    //     cout << endl;
    // }


    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            delete []arr[i][j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
    return 0;
}