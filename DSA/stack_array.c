#include<stdio.h>

void menu(int arr[],int* n, int maximum);
void display(int arr[],int** n);
void push(int arr[], int max, int** n);
void pop(int arr[], int** n);


int main()
{
    int arr[1000],maximum=5,n=-1;
        menu(arr,&n,maximum);
    return 0;
}

void menu(int arr[],int *n, int maximum)
{
    int ch;
    do
    {
        printf("Press '1' to display the Stack\nPress '2' to PUSH\nPress '3' to POP\nPress '4' to exit\n");
        printf("\nEnter operation: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            display(arr,&n);
            break;
        case 2:
            push(arr,maximum,&n);
            display(arr,&n);
            break;
        case 3:
            pop(arr,&n);
            display(arr,&n);
            break;
        case 4:
            printf("\n\n\nExiting....");
            break;
        
        default:
            printf("\n\n\nInvalid choice....\n\n");
            break;
        }
    } while (ch!=4);
}

void display(int arr[],int** n)
{
    printf("\n\n");
    if((**n)==-1)
        printf("\nStack is empty.\n\n");
    else
        for(int i=0;i<=(**n);i++)
            printf("%d ",arr[i]);
    printf(" <-- TOS\n\n");
}

void push(int arr[], int max, int** n)
{
    if((**n)+1 == max)
    {
        printf("\n\nOVERFLOW\n\n");
        return;
    }

    int ele;
    
    printf("\n\nEnter element you want to insert: ");
    scanf("%d",&ele);

    (**n)++;
    arr[**n]=ele;
}

void pop(int arr[], int** n)
{
    if((**n) == -1)
    {
        printf("\n\nUNDERFLOW\n\n");
        return;
    }

    (**n)--;
}