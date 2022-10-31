#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node* left;
    int data;
    struct node* right;
};

struct node* create (struct node*);
void preOrderTraversal (struct node*);
void inOrderTraversal (struct node*);
void postOrderTraversal (struct node*);
int height (struct node*);
int countLeaf (struct node*);
int countNonLeaf(struct node*);
int search (struct node*, int);

int main()
{
    struct node* root = NULL;
    int choice;
    do
    {
        printf("Menu:- \n");
        printf("1. Create Tree\n");
        printf("2. Pre-Order Traversal\n");
        printf("3. In-Order Traversal\n");
        printf("4. Post-order \n");
        printf("5. Height of tree\n");
        printf("6. Count no. of leaf and non-leaf nodes\n");
        printf("7. Search for a value in tree\n");
        printf("0. Quit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                root = create(NULL);
                break;
            
            case 2:
                preOrderTraversal(root);
                printf("\n");
                break;
            
            case 3:
                inOrderTraversal(root);
                printf("\n");
                break;
            
            case 4:
                postOrderTraversal(root);
                printf("\n");
                break;
            
            case 5:
                printf("Height of tree is %d\n", height(root));
                break;
            
            case 6:
                printf("Number of leaf nodes is %d\n", countLeaf(root));
                printf("Number of non-leaf nodes is %d\n", countNonLeaf(root));
                break;
            
            case 7:
            {
                int num;
                printf("Enter number to be searched : ");
                scanf("%d", &num);
                if(search(root, num))
                    printf("Number found\n");
                else
                    printf("Number not found\n");
                break;
            }
            
            case 0:
                break;
            
            default:
                printf("Wrong choice\n");
            
        }
        
        printf("\n");
    }while(choice);
    return 0;
}

struct node* create(struct node* root)
{
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    
    if(root==NULL)
        printf("Enter root : ");
        
    scanf("%d", &newnode->data);
    
    if(newnode->data == -1)
        return NULL;
        
    printf("Enter left child of %d (Enter -1 if no child) : ", newnode->data);
    newnode->left = create(newnode);
    printf("Enter right child of %d (Enter -1 if no child) : ", newnode->data);
    newnode->right = create(newnode);
    return newnode;
}

void preOrderTraversal(struct node* root)
{
    if(root==NULL)
        return;
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(struct node* root)
{
    if(root==NULL)
        return;
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

void postOrderTraversal(struct node* root)
{
    if(root==NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}

int height(struct node* root)
{
    if(root==NULL)
        return -1;
    if(height(root->left)>=height(root->left))
        return 1+height(root->left);
    return 1+height(root->right);
}

int countLeaf(struct node* root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1; 
    return countLeaf(root->left) + countLeaf(root->right);
}

int countNonLeaf(struct node* root)
{
    if(root==NULL)
        return 1;
    if(root->left==NULL && root->right==NULL)
        return 0; 
    return countNonLeaf(root->left) + countNonLeaf(root->right);
}

int search(struct node* root, int num)
{
    if(root==NULL)
        return 0;
    if(root->data==num)
        return 1;
    return (search(root->left, num) || search(root->right, num));
}


