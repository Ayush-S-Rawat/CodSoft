#include<stdio.h>

int BinarySearch(int arr[], int s, int e, int ele)
{
    if(s>e)
        return -1;
    int mid=s+(e-s)/2;

    if(arr[mid]==ele)
        return mid;
    else if(arr[mid]>ele)
        return BinarySearch(arr,0,mid-1,ele);
    else
        return BinarySearch(arr,mid+1,e,ele);
}

int main()
{
    int arr[100],size,val,ch;

        do
        {
            printf("Enter size of array: ");
            scanf("%d",&size);

            printf("Enter elements of array:\n");
            for(int i=0;i<size;i++)
                scanf("%d",&arr[i]);

            printf("\nEnter element you want to search: ");
            scanf("%d",&val);

        int ans=BinarySearch(arr,0,size-1,val);

            if(ans == -1)
                printf("Element %d is not present in the array.");
            else
                printf("Element %d is present at index %d",val,ans);

            printf("\n\nPress 1 to run program again.\nEnter choice: ");
            scanf("%d",&ch);
        } while (ch==1); 
    return 0;
}