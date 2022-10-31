// Ishant Sihag

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node* left;
    int data;
    struct node* right;
};

struct node* addNode(struct node*, int);
void preOrderTraversal (struct node*);
void inOrderTraversal (struct node*);
int search (struct node*, int);
struct node* presence(struct node*, int);
int height (struct node*);
struct node *lRotate(struct node* root);
struct node *rRotate(struct node *root);

int main()
{
    struct node* root = NULL;
    for(int i=0; i<25; i++)/// looping for inserion
        root = addNode(root, i);
    printf("AVL tree constructed by inserting 0 to 24 elements\n");
    
    char choice;
    do
    {// menu priunting
        printf("i) Insert :\n");
        printf("s) search :\n");
        printf("p) Print Preorder and Inorder in Separate lines:\n");
        printf("q) Quit:\n");
        printf("Enter Your Choice: ");
        scanf("%c", &choice);
        getchar();
        switch(choice)
        {
            case 'i':
            {
                int data;
                printf("Enter a data to insert: ");
                scanf("%d", &data);
                root = addNode(root, data);
                break;
            }
            
            case 's':
            {    
                int num;
                printf("Enter data you want to search: ");
                scanf("%d", &num);
                
                int find = search(root, num);
                if(find)
                    printf("Present\n");
                else
                    printf("Not Present\n");
                
                if(find)
                {
                    struct node* temp = presence(root, num);
                    printf("Balance factor of %d is %d", num, height(temp->left) - height(temp->right));
                    printf("Height of %d in the AVL tree is %d", num, height(temp));
                }
                
                
                break;
            }
            
            case 'p':
                printf("Preorder sequence: ");
                preOrderTraversal(root);
                printf("\n");
                
                printf("Inorder sequence: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            
            case 'q':
                break;
            
            default:
                printf("Wrong choice\n");
            
        }
        
        printf("\n");
    }while(choice);
    return 0;
}

struct node* addNode(struct node* root, int data)
{
    if(root==NULL)
    {// alllocation memory
        struct node*newNode=(struct node*)malloc(sizeof(struct node));
        newNode->left=NULL;
        newNode->data=data;
        newNode->right=NULL;
        return newNode;
    }
    if(root->data < data)
        root->right=addNode(root->right,data);
    if(root->data > data)
        root->left=addNode(root->left,data);
    
    int balanceFactor = height(root->left)-height(root->right); //  calculating b factor
    
    if(balanceFactor>=2)
    {
        if(root->left->data>data)
            return rRotate(root);// r roation
        else
        {
            root->left=lRotate(root);//lr roation
            return rRotate(root);
        }
    }
    
    if(balanceFactor<=-2)
    {
        if(root->right->data>data)
        {
            root->right=rRotate(root); // RL rotaion
            return lRotate(root);
        }
        else
            return lRotate(root);//l rotaion
    }
    
    return root;
}
void preOrderTraversal(struct node* root)
{// typical pring code
    if(root==NULL)
        return;
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(struct node* root)
{// typical pring code
    if(root==NULL)
        return;
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

int search(struct node* root, int num)
{
    if(root==NULL)
        return 0;
    if(root->data==num)
        return 1;
    return (search(root->left, num) || search(root->right, num));
}

struct node* presence(struct node* root, int num)
{
    if(root==NULL)
        return NULL;
    if(root->data==num)
        return root;
    
    
    if(presence(root->left, num)==NULL && (presence(root->right, num))==NULL)
        return NULL;
    return (presence(root->left, num))==NULL?(presence(root->right, num)):(presence(root->left, num));
}

int height(struct node*root)
{
    if(root == NULL)
        return -1;
    else 
    {
        if(height(root->left)>height(root->right))
            return (height(root->left)+1);
        else
            return (height(root->right)+1);
    }
}

struct node *lRotate(struct node* root)
{  
    struct node *temp1 = root->right;
    struct node *temp2 = temp1->left;
 
    temp1->left = root;
    root->right = temp2;
 
    return temp1;
    
}    
struct node *rRotate(struct node *root) 
{ 
    
    struct node *temp1 = root->left;// storing temporary pointers
    struct node *temp2 = temp1->right;
 
    temp1->right = root;// rotaion
    root->left = temp2;
 
    return temp1;
    
}


