// Ishant Sihag

#include <stdio.h> // For Basic inout output functions
#include <stdlib.h> // For dynamic memory allocation

struct node // Node creation for doubly linked list
{
    int data;
    struct node* previous;
    struct node* next;
};

// Fuction Prototype declaraion
int h(int, int);
void insert(struct node*[], int, int);
void delete(struct node*[], int, int);
int search(struct node*[], int, int);
void display(struct node*[], int);

int main()
{
    int m=2, choice;
    printf("Enter hash table size m: ");
    scanf("%d", &m); // Inputting the hash table size
    struct node** hashTable=(struct node**)calloc(m, sizeof(struct node*)); // Creation of Hash Table
    
    do
    { // Displaying the menu as indtructed in question
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        int check=scanf("%d", &choice);
        if(check==0) // Checking for charater entries in the the integer input for excessive error handling
        {
            printf("Invalid Character Entered\nTry again\n");
            choice=0;
            getchar();
        }
        
        switch(choice)
        {
            case 1:
            {
                int number;
                printf("Enter value to insert: ");
                scanf("%d", &number);
                insert(hashTable, m, number); // Calling the normal insert function for insertion
                break;
            }
            
            case 2:
            {
                int number;
                printf("Enter an element to be deleted: ");
                scanf("%d", &number);
                delete(hashTable, m, number); // Calling the normal delete function for deletion
                break;
            }
            
            case 3:
            {
                int number;
                printf("enter the element to be searched:");
                scanf("%d", &number);
                int result = search(hashTable, m, number); // Calling the normal search function for searching
                
                if(result==-1) // Displaying the output got ffrom search function
                    printf("Not Present\n");
                else
                    printf("searched element %d is found in slot number %d\n", number, result);
                break;
            }
            
            case 4:
                display(hashTable, m); // Calling display function
                break;
            
            case 5:
                break;
            
            default:
                printf("Invalid choice Entered\n"); // For all invalid choices
                printf("Enter a number between 1 to 5\n");
            
        }
        
    }while(choice!=5); // The quitting value is 5
    return 0;
}

int h(int k, int m)
{
    return k<0?m+k%m:k%m;
}

void insert(struct node** hashTable, int m, int x)
{
    struct node* newNode = malloc(sizeof(struct node)); // Creation of a new node
    newNode->data=x; // INserting data in newly created node
    newNode->next=hashTable[h(x, m)]; // Adding next link
    hashTable[h(x, m)]=newNode; // Linking newly created node with hash Table
    if(hashTable[h(x, m)]!=NULL)
        hashTable[h(x, m)]->previous=newNode; // Adding reverse links
    newNode->previous=NULL; // reverse link for new node
}

void delete(struct node** hashTable, int m, int x)
{
    struct node* currentNode=hashTable[h(x, m)], *temp=NULL; 
    while(currentNode!=NULL && currentNode->data!=x) // Same as search fucntion
    {
        temp=currentNode;
        currentNode=currentNode->next;
    }
    if(currentNode==NULL) // If value not found
        return;
    if(temp!=NULL) // If value found at starting point
        temp->next=currentNode->next;
    else
        hashTable[h(x, m)]=currentNode->next;
    free(currentNode); // Release of the memory used after deletion of node
    
}

int search(struct node** hashTable, int m, int x)
{
    struct node* currentNode=hashTable[h(x, m)]; // A pointer for travelling
    while(currentNode!=NULL && currentNode->data!=x) // Moving till end point or till end of doubly linked list
        currentNode=currentNode->next; // Moving forward
    if(currentNode==NULL) // if value not found returning the reserved value as invlaid index
        return -1;
    return h(x, m); // returing the origional index 
}

void display(struct node** hashTable, int m)
{
    for(int i=0; i<m; i++) // Travelling the whole hash table
    {
        printf("index %d: ", i); // Printting the index value
        if(hashTable[i]==NULL) // if index of hash table is empty 
        {
            printf("NULL\n");
            continue; // not continuing forward with null pointer
        }
        struct node* currentNode=hashTable[i]; // A temporary pointer for travelling the doubly linked list
        while(currentNode!=NULL) // Moving till end of the double linked list
        {
            printf("%d ", currentNode->data); // Printting the actfual value
            currentNode=currentNode->next; // Moving forward
        }
        printf("\n"); 
    }
}


