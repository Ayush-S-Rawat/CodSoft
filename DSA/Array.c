#include<stdio.h>

void menu(int arr[],int maximum,int* n);
void display(int arr[],int* n);
void ins(int arr[],int* n,int maxi);
void insert_beginning(int arr[],int* n,int ele);
void insert_location(int arr[],int *n,int ele,int loc);
void insert_end(int arr[],int* n,int ele);
void del(int arr[],int* n);
void delete_beginning(int arr[],int* n);
void delete_location(int arr[],int* n,int loc);
void delete_end(int arr[],int* n);
void searching(int arr[],int* n,int ele);
void sorting(int arr[],int* n);

int main()
{
    int arr[100];
    int maximum=100,n=0;
        menu(arr,maximum,&n);
    return 0;
}

void menu(int arr[],int maximum,int* n)
{
    int ch;
    int ele;
    do
    {
        printf("Press '1' to display the array\nPress '2' to insert element in array\nPress '3' to delete element in array\nPress '4' to search element in array\nPress '5' to sort the array\nPress '6' to exit\n");
        printf("\nEnter operation: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            display(arr,n);
            break;
        case 2:
            ins(arr,n,maximum);
            display(arr,n);
            break;
        case 3:
            del(arr,n);
            display(arr,n);
            break;
        case 4:
            if((*n)!=0)
            {
                printf("\nEnter Element you want to search: ");
                scanf("%d",&ele);
                searching(arr,n,ele);
            }
            else
                printf("\n\nArray is empty.\n\n");
            break;
        case 5:
            sorting(arr,n);
            display(arr,n);
            break;
        case 6:
            printf("\n\n\nExiting....");
            break;
        
        default:
            printf("\n\n\nInvalid choice....");
            break;
        }
    } while (ch!=6);
    
}

//Display

void display(int arr[],int* n)
{
    printf("\n\n");
    if((*n)==0)
        printf("\nArray is empty.\n\n");
    else
        for(int i=0;i<(*n);i++)
            printf("%d ",arr[i]);
    printf("\n\n");
}

//Insertion

void ins(int arr[],int* n,int maxi)
{
    int ch;
    int ele;
    int loc;

    if((*n)==maxi)
    {
        printf("\nArray already full.\n\n");
        return;
    }

    // printf("\n\n%p\n\n%d\n\n",n,*n);

    printf("\n\nPress '1' to insert element at the beginning\nPress '2' to insert element at the location\nPress '3' to insert element at the end\n");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
    printf("\nEnter number you want to insert: ");
    scanf("%d",&ele);

    switch (ch)
    {
    case 1:
        insert_beginning(arr,n,ele);
        printf("\nElement inserted at beginning\n");
        break;
    case 2:
        printf("\nEnter index location where you want to enter element: ");
        scanf("%d",&loc);
        if(loc>(*n))
        {
            printf("\nInvalid location....\n\n");
            return;
        }
        insert_location(arr,n,ele,loc);
        printf("\nElement inserted at location\n");
        break;
    case 3:
        insert_end(arr,n,ele);
        printf("\nElement inserted at end\n");
        break;
    
    default:
        printf("\n\n\nInvalid choice....");
        break;
    }
}

void insert_beginning(int arr[],int* n,int ele)
{
    // printf("\n\n%p\n\n%d\n\n",n,*n);
    for(int i=(*n);i>0;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0] = ele;
    (*n)++;
    // printf("%p\n\n%d",n,*n);
}

void insert_location(int arr[],int *n,int ele,int loc)
{
    for(int i=(*n);i>loc;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[loc] = ele;
    (*n)++;
}

void insert_end(int arr[],int* n,int ele)
{
    arr[(*n)]=ele;
    (*n)++;
}

//Deletion

void del(int arr[],int* n)
{
    int ch;
    int loc;

    if((*n)==0)
    {
        printf("\nArray already empty.\n\n");
        return;
    }

    printf("\n\nPress '1' to delete element from the beginning\nPress '2' to delete element from the location\nPress '3' to delete element from the end\n");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);

    switch (ch)
    {
    case 1:
        delete_beginning(arr,n);
        printf("\nElement deleted from beginning\n");
        break;
    case 2:
        printf("\nEnter index location from where you want to delete element: ");
        scanf("%d",&loc);
        if(loc>*(n))
        {
            printf("\nInvalid location....\n\n");
            return;
        }
        delete_location(arr,n,loc);
        printf("\nElement deleted from location\n");
        break;
    case 3:
        delete_end(arr,n);
        printf("\nElement deleted from end\n");
        break;
    
    default:
        printf("\n\n\nInvalid choice....");
        break;
    }
}

void delete_beginning(int arr[],int* n)
{
    for(int i=0;i<(*n)-1;i++)
    {
        arr[i]=arr[i+1];
    }
    (*n)--;
}

void delete_location(int arr[],int* n,int loc)
{
    for(int i=loc;i<(*n)-1;i++)
    {
        arr[i]=arr[i+1];
    }
    (*n)--;
}
void delete_end(int arr[],int* n)
{
    (*n)--;
}

//Searching

void searching(int arr[],int* n,int ele)
{
    int ch;
        printf("Is array sorted ('1' for yes and '2' for No): ");
        scanf("%d",&ch);
        if(ch==1)
        {
            int s=0,e=(*n)-1;
            int mid=s+(e-s)/2;

            while(s<=e)
            {
                if(arr[mid]==ele)
                {
                    printf("\n\nElement found at index: %d\n\n",mid);
                    return;
                }
                else if(arr[mid]>ele)
                    e=mid-1;
                else
                    s=mid+1;
                
                mid=s+(e-s)/2;
            }
            printf("\n\nElement not present in array.\n");
        }
        else
        {
            for(int i=0;i<(*n);i++)
            {
                if(ele == arr[i])
                {
                    printf("\n\nElement found at index: %d\n\n",i);
                    return;
                }
            }
            printf("\n\nElement not present in array.\n");
        }
}

//Sorting

void sorting(int arr[],int* n)
{
    if((*n)==0)
    {
        printf("\n\nArray is empty.\n\n");
        return;
    }

    int i,j,mini;
    for(i=0;i<(*n)-1;i++)
    {
        for(j=i+1,mini=i;j<(*n);j++)
        {
            if(arr[j]<arr[mini])
            {
                mini=j;
            }
        }
        int temp=arr[mini];
        arr[mini]=arr[i];
        arr[i]=temp;
    }
    printf("\n\nArray is now sorted\n\n");
}