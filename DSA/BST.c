#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node* left;
    struct node* right;
};

void menu(struct node** root);
void ins(struct node** root);
void del(struct node** root);
void searching(struct node** root, int ele);
void traverse(struct node** root);
void preorder(struct node* root);
void inorder(struct node* root);
void postorder(struct node* root);
struct node* smallest(struct node* root);
void traverse_stack(struct node** root);
void stack_preorder(struct node* root);
void stack_inorder(struct node* root);
void stack_postorder(struct node* root);
struct node* pop(struct node* arr[], int* n);
void push(struct node* arr[], struct node* temp, int* n);


int main()
{
    struct node* root = NULL;
        menu(&root);
    return 0;
}

void menu(struct node** root)
{
    int ch;
    int ele;
    struct node* small;
    do
    {
        printf("\n\nPress '1' to insert element in BST\nPress '2' to delete element from BST\nPress '3' to search an element from BST\nPress '4' to traverse BST\nPress '5' to exit\n");
        printf("\nEnter operation: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            ins(root);
            break;
        case 2:
            del(root);
            break;
        case 3:
            if(*root != NULL)
            {
                printf("\nEnter Element you want to search: ");
                scanf("%d",&ele);
                searching(root,ele);
            }
            else
                printf("\n\nBST is empty.\n\n");
            break;
        case 4:
            traverse(root);
            break;
        case 5:
            printf("\n\nExiting....");
            break;
        default:
            printf("\n\nInvalid choice....\n\n");
            break;
        }
    } while (ch!=5);
}

void ins(struct node** root)
{
    int ele;

        printf("Enter element you want to insert: ");
        scanf("%d",&ele);

    struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->info = ele;
        temp->left = NULL;
        temp->right = NULL;

        if((*root) == NULL)
        {
            (*root) = temp;
            return;
        }

    struct node* list = (*root);
    struct node* pre = NULL;

        while(list != NULL)
        {
            pre = list;

            if(ele < list->info)
                list = list->left;
            else
                list = list->right;
        }

        if(ele < pre->info)
            pre->left = temp;
        else
            pre->right = temp;
}

void del(struct node** root)
{
    if((*root) == NULL)
    {
        printf("\n\nTree is empty. Nothing can be deleted.\n\n");
        return;
    }
    int ele;

        printf("Enter element you want to delete: ");
        scanf("%d",&ele);

    struct node* list = *root;
    struct node* pre = NULL;
    struct node* temp = NULL;

        if(list->info == ele)
        {}

        while(list != NULL)
        {
            if(list->info == ele)
            {
                if(list->left == NULL && list->right ==NULL)
                    temp = NULL;

                else if(list->left == NULL)
                    temp = list->right;

                else if(list->right == NULL)
                    temp = list->left;

                else
                {
                    struct node* head = smallest(list->right);

                    head->left = list->left;

                    temp = list->right;
                }

                if(pre == NULL)
                    (*root) = temp;
                else if(pre->info > ele)
                    pre->left = temp;
                else
                    pre->right = temp;

                free(list);

                printf("\n\n%d deleted from the BST\n\n",ele);

                return;
            }

            pre = list;

            if(ele < list->info)
                list = list->left;
            else
                list = list->right;
        }

        printf("\n\nElement you want to delete is not present in the tree\n\n");
}

void searching(struct node** root, int ele)
{
    struct node* list = *root;

        while(list != NULL)
        {
            if(list->info == ele)
            {
                printf("\n\nElement present in the tree.\n\n");
                return;
            }

            if(ele < list->info)
                list = list->left;
            else
                list = list->right;
        }

        printf("\n\nElement NOT present in the tree.\n\n");
}

void traverse(struct node** root)
{
    int ch;
    struct node* temp = *root;

        if(temp == NULL)
        {
            printf("\n\nTree is empty...cannot traverse !!!\n\n");
            return;
        }
        do
        {
            printf("\n\nPress 1 to Preoreder traversal\nPress 2 for Inorder traversal\nPress 3 for Postorder traversal\nPress 4 to check Traversal through stack\nPress 5 to go back to Main Menu\n\nEnter your choice: ");
            scanf("%d",&ch);

            switch (ch)
            {
            case 1:
                printf("\n\n");
                preorder(temp);
                printf("\n\n");
                break;
            case 2:
                printf("\n\n");
                inorder(temp);
                printf("\n\n");
                break;
            case 3:
                printf("\n\n");
                postorder(temp);
                printf("\n\n");
                break;
            case 4:
                printf("\n\n");
                traverse_stack(root);
                printf("\n\n");
                break;
            case 5:
                printf("\n\nGoing back to Main Menu\n\n");
                break;
            default:
                printf("\n\nInvalid choice....\n\n");
                break;
            }
        } while (ch!=5);
}

void traverse_stack(struct node** root)
{
    int ch;
    struct node* temp = *root;

        if(temp == NULL)
        {
            printf("\n\nTree is empty...cannot traverse !!!\n\n");
            return;
        }
        do
        {
            printf("\n\nPress 1 to Preoreder traversal\nPress 2 for Inorder traversal\nPress 3 for Postorder traversal\nPress 4 to go back to Traverse Menu\n\nEnter your choice: ");
            scanf("%d",&ch);

            switch (ch)
            {
            case 1:
                printf("\n\n");
                stack_preorder(temp);
                printf("\n\n");
                break;
            case 2:
                printf("\n\n");
                stack_inorder(temp);
                printf("\n\n");
                break;
            case 3:
                printf("\n\n");
                stack_postorder(temp);
                printf("\n\n");
                break;
            case 4:
                printf("\n\nGoing back to Traverse Menu\n\n");
                break;
            default:
                printf("\n\nInvalid choice....\n\n");
                break;
            }
        } while (ch!=4);
}

void preorder(struct node* root)
{
    if(root == NULL)
        return;

    printf("%d ",root->info);

    preorder(root->left);

    preorder(root->right);
}

void inorder(struct node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);

    printf("%d ",root->info);

    inorder(root->right);
}

void postorder(struct node* root)
{
    if(root == NULL)
        return;

    postorder(root->left);

    postorder(root->right);

    printf("%d ",root->info);
}

struct node* smallest(struct node* root)
{
    struct node* list = root;
    struct node* pre = NULL;
    int ele = root->info;

        while(list != NULL)
        {
            pre = list;
            list = list->left;
        }
    return pre;
}

void stack_preorder(struct node* root)
{
    struct node* arr[100];
    struct node* list = root;
    int i=-1;

    while(list!=NULL)
    {
        printf("%d  ",list->info);

        if(list->right != NULL)
            push(arr,list->right,&i);
        
        if(list->left == NULL)
            list = pop(arr,&i);
        else
            list = list->left;
    }
}

void stack_inorder(struct node* root)
{
    struct node* arr[100];
    struct node* list = root;
    int i=-1;

    while(list!=NULL)
    {
        push(arr,list,&i);
        if(list->left == NULL)
        {
            struct node* temp;
            do
            {
                temp = pop(arr,&i);
                if(temp == NULL)
                    break;
                printf("%d  ",temp->info);
            } while(temp->right == NULL);

            if(temp == NULL)
                list = temp;
            else
                list = temp->right;
        }
        else
            list = list->left;
    }
}

void stack_postorder(struct node* root)
{
    struct node* arr[100];
    struct node* list = root;
    int i=-1;

    while(list!=NULL)
    {
        push(arr,list,&i);
        if(list->right != NULL)
        {
            list->right->info /= -1;
            push(arr,list->right,&i);
        }
        if(list->left == NULL)
        {
            struct node* temp;
            int num;
            do
            {
                temp = pop(arr,&i);
                if(temp == NULL)
                    break;
                num = temp->info;
                if(num>0)
                    printf("%d  ",temp->info);
            } while(num >= 0);
            if(temp!=NULL)
            {
                if(temp->info < 0)
                    temp->info *= (-1);
            }
            list = temp;
        }
        else
            list = list->left;
    }
}

void push(struct node* arr[], struct node* temp, int* n)
{
    (*n)++;
    arr[(*n)] = temp;
}

struct node* pop(struct node* arr[], int* n)
{
    if((*n) == -1)
        return NULL;
    else
    {
        (*n)--;
        return arr[(*n)+1];
    }
}