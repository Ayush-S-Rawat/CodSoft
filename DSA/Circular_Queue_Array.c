#include<stdio.h>

void menu(int arr[], int maximum, int* s, int* e);
void display(int arr[], int maximum, int** s, int** e);
void enqueue(int arr[], int max, int** s, int** e);
void dequeue(int arr[], int max, int** s, int**e);

int main()
{
    int arr[5],maximum=5,start=-1,end=-1;
        menu(arr,maximum,&start,&end);
    return 0;
}

void menu(int arr[], int maximum, int* s, int* e)
{
    int ch;
    do
    {
        printf("Press '1' to display the Queue\nPress '2' to ENQUEUE\nPress '3' to DEQUEUE\nPress '4' to exit\n");
        printf("\nEnter operation: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            display(arr,maximum,&s,&e);
            break;
        case 2:
            enqueue(arr,maximum,&s,&e);
            display(arr,maximum,&s,&e);
            break;
        case 3:
            dequeue(arr,maximum,&s,&e);
            display(arr,maximum,&s,&e);
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

void display(int arr[], int max, int** s, int** e)
{
    printf("\n\n");
    if(((**s)==-1) || ((**e) == -1))
        printf("\nQueue is empty.\n\n");
    else
    {
        printf("TOQ --> ");
        int start = **s, end = **e;
        while(start!=end)
        {
            printf("%d ",arr[start]);
            start = (start+1)%max;
        }
        printf("%d",arr[start]);
    }
    printf("\n\n");
}

void enqueue(int arr[], int max, int** s, int** e)
{
    int end = ((**e)+1) % max;
    if(end == **s)
    {
        printf("\n\nOVERFLOW\n\n");
        return;
    }

    int ele;
    
    printf("\n\nEnter element you want to insert: ");
    scanf("%d",&ele);

    if((**e) == -1)
        (**s) = ((**s)+1)%max;
    (**e) = ((**e)+1)%max;
    arr[**e]=ele;
}

void dequeue(int arr[], int max, int** s, int**e)
{
    if((**s) == -1)
    {
        printf("\n\nUNDERFLOW\n\n");
        return;
    }
    if((**s) == (**e))
    {
        (**s) = -1;
        (**e) = -1;
    }
    else
        (**s) = ((**s)+1)%max;
}