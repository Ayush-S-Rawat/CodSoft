#include<stdio.h>

int main()
{
    int arr[100][100],sparse[5001][3],zero=0,n_zero=0,r,c,r_sparse,ele;

        printf("Enter number of Rows: ");
        scanf("%d",&r);
        printf("Enter number of Columns: ");
        scanf("%d",&c);

        printf("Enter elements in the matrix\n");
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            {
                printf("Element (%d,%d): ",i,j);
                scanf("%d",&arr[i][j]);
                if(arr[i][j] == 0)
                    zero++;
                else
                    n_zero++;
            }
    
    int condition = (r*c)/4;
        
        if(n_zero <= condition)
        {
            printf("\n\nEntered Matrix is a Sparse Matrix\n\n");

            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {
                    printf("%d  ",arr[i][j]);
                }
                printf("\n");
            }
            
            printf("\n\nSparse Tripletx:\n");

            int k=1;

            sparse[0][0] = r;
            sparse[0][1] = c;
            sparse[0][2] = n_zero;

            for(int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                {
                    if(arr[i][j] != 0)
                    {
                        sparse[k][0] = i;
                        sparse[k][1] = j;
                        sparse[k][2] = arr[i][j];
                        k++;
                    }
                }
            
            r_sparse = k;
            for(int i=0;i<r_sparse;i++)
            {
                for(int j=0;j<3;j++)
                {
                    printf("%d ",sparse[i][j]);
                }
                printf("\n");
            }
        }
        else
        {
            printf("\n\nEntered Matrix is a NOT a Sparse Matrix\n\n");

            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {
                    printf("%d  ",arr[i][j]);
                }
                printf("\n");
            }
        }
    return 0;
}