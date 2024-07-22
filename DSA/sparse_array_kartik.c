#include <stdio.h>

int check(int row, int column, int arr[][column]);
void convert(int row, int column, int arr[][column], int converted[][3]);
void display(int row, int column, int arr[][column]);

int main()
{
    int row, column;

    printf("Enter number of row in sparse array\n");
    scanf("%d", &row);
    printf("Enter number of columns in sparse array\n");
    scanf("%d", &column);
    int array[row][column];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("Enter value for %d row and %d column\n", i + 1, j + 1);
            int val;
            scanf("%d", &val);
            array[i][j] = val;
        }
    }
    printf("Your entered array.\n");
    display(row, column, array);
    int sparse = check(row, column, array);
    if (sparse != -1)
    {
        printf("Your array is a sparse array.\n");
        int converted[sparse][3];
        printf("Sparse Array after conversion\n");
        convert(row, column, array, converted);
        display(sparse, 3, converted);
    }
    else
    {
        printf("Your array is not a sparse array.\n");
    }

    return 0;
}

int check(int row, int column, int arr[][column])
{
    int nonzeroele = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (arr[i][j] != 0)
            {
                nonzeroele += 1;
            }
        }
    }

    if ((row * column) / 2 >= nonzeroele)
    {
        return nonzeroele;
    }
    else
    {
        return -1;
    }
}

void convert(int row, int column, int arr[][column], int converted[][3])
{
    int count = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (arr[i][j] != 0)
            {
                converted[count][0] = i;
                converted[count][1] = j;
                converted[count][2] = arr[i][j];
                count++;
            }
        }
    }
}

void display(int row, int column, int arr[][column])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}