#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node* left;
    int data;
    struct node* right;
} node;

node* addNode(node*, int);
node* createBST(void);
void inOrderTraversal (node*);
node* deleteNode(node*, int);

int main()
{
    int data;
    node* root=NULL;
    int choice=1;
    do
    {
        printf("Menu-\n");
        printf("1. Create BST\n");
        printf("2. Add Node\n");
        printf("3. Delete Node\n");
        printf("0. Exit\n");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                root=createBST();
                break;
            
            case 2:
            {
                int data;
                printf("Enter data : ");
                scanf("%d", &data);
                root = addNode(root, data);
                break;
            }
            
            case 3:
            {
                int data;
                printf("Enter data to be deleted : ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            }
            
            case 4:
                break;
                
            
            default:
                printf("Wrong choice\n");
            
        }
        
        inOrderTraversal(root);
        printf("\n");
    }while(choice!=0);
    
    
    return 0;
}

node* createBST(void)
{
    node* root=NULL;
    int data;
    printf("Enter data for BST (Enter -1 to stop) : ");
    while(1)
    {
        scanf("%d", &data);
        if(data==-1)
            break;
        root = addNode(root, data);
    }
    return root;
}


node* addNode(node* root, int data)
{
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=data;
    if(root==NULL)
        return newNode;
    if(data<root->data)
        root->left=addNode(root->left, data);
    if(data>root->data)
        root->right=addNode(root->right, data);
    return root;
}

void inOrderTraversal(node* root)
{
    if(root==NULL)
        return;
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

node* deleteNode(node* root, int num)
{
    if(root==NULL)
    {
        printf("Value not found\n");
        return NULL;
    }
    if (root->data == num)
    {
        if(root->right == NULL)
        {
            node* newRoot = root->left;
            free(root);
            return newRoot;
        }
        
        node* current = root->right;
        if(current->left==NULL)
        {
            current->left = root->left;
            free(root);
            return current;
        }
        
        while(current->left->left!=NULL)
            current = current->left;
        
        root->data = current->left->data;
        node* deleteNode=current->left;
        current->left = current->left->right;
        free(deleteNode);
        return root;
        
    }
    
    if(num > root->data)
        root->right = deleteNode(root->right, num);
    if(num<root->data)    
        root->left = deleteNode(root->left, num);
    
    return root;
        
}

