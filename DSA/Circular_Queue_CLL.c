#include<stdio.h>
#include<stdlib.h>

struct node
{
    int num;
    struct node* next;
};

void menu(struct node** head, int* n, int maxi);
void display(struct node** head);
void enqueue(struct node** head, int* n, int maxi);
void dequeue(struct node** head, int* n);

int main()
{
    struct node* head = NULL;
    int maxi=5,n=0;
        menu(&head,&n,maxi);
    return 0;
}

void menu(struct node** head, int* n, int maxi)
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
            display(head);
            break;
        case 2:
            enqueue(head,n,maxi);
            display(head);
            break;
        case 3:
            dequeue(head,n);
            display(head);
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

void display(struct node** head)
{
    if (*head == NULL)
    {
        printf("\n\nQueue is Empty\n\n");
        return;
    }
    struct node *head1 = *head;

    printf("\n\n");

    do
    {
        printf("%d ",head1->num);
        head1 = head1->next;
    } while (head1 != *head);

    printf("\n\n");
}

void enqueue(struct node** head, int* n, int maxi)
{
    if((*n) == maxi)
    {
        printf("\n\nOVERFLOW !!!\n\n");
        return;
    }
    
    int ele;

    printf("\n\nEnter number you want to insert: ");
    scanf("%d",&ele);

    (*n)++;

    if(*head == NULL)
    {
        struct node* temp = (struct node*)malloc(sizeof(struct node));

        *head = temp;
        temp->num = ele;
        temp->next = *head;
        return;
    }
    struct node* temp=(struct node*)malloc(sizeof(struct node));

    struct node* head1=(*head)->next;
    struct node* list=*head;

    while(head1!=*head)
    {
        list=head1;
        head1=head1->next;
    }
    list->next=temp;
    temp -> num=ele;
    temp->next=*head;
}

void dequeue(struct node** head, int* n)
{
    if(*head == NULL)
    {
        printf("\nUNDERFLOW !!!\n\n");
        return;
    }

    (*n)--;

    if((*head)->next==(*head))
    {
        struct node* temp=*head;
        *head=NULL;
        free(temp);
        return;
    }
    struct node* head1 = (*head)->next;
    struct node* list = *head;

    while(head1!=*head)
    {
        list=head1;
        head1=head1->next;
    }
    
    list->next = head1->next;
    (*head) = (*head)->next;
    free(head1);
}