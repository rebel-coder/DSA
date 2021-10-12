// Linked List
// Various insert and delete operations

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
}node;

void create (node** start);
void append(node** start, int newVal);
void traverse (node *start);
void insertAfter(node* start, int val, int newVal);
void insertBefore (node** start, int val, int newVal);
void insertAtPosition (node** start, int p, int newVal);
void deleteValue (node** start, int val);
int deleteAfter(node* start, int val);
int deleteAtPosition (node** start, int p);

int main()
{
	node* start;
	start=NULL;
	int choice,val,newVal,p,temp;
		
	do
	{
		printf("\n1. Create List\n");
		printf("2. Traverse\n");
		printf("3. Append\n");
		printf("4. Insert After\n");
		printf("5. Insert Before\n");
		printf("6. Insert at position\n");
		printf("7. Delete a value\n");
		printf("8. Delete After\n");
		printf("9. Delete Before\n");
		printf("10. Delete at Position\n");
		printf("11. Exit\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		
		switch (choice)
		{
			case 1 :
				create(&start);
				break;
				
			case 2 :
				traverse(start);
				break;
				
			case 3 :
				printf("Enter the new value : ");
				scanf("%d", &newVal);
				append(&start,newVal);
				break;
				
			case 4 :
				printf("Enter the value after which data is to be inserted : ");
				scanf("%d", &val);
				printf("Enter the new value : ");
				scanf("%d", &newVal);
				insertAfter(start, val, newVal);
				break;
				
			case 5 :
				printf("Enter the value before which data is to be inserted : ");
				scanf("%d", &val);
				printf("Enter the new value : ");
				scanf("%d", &newVal);
				insertBefore(&start, val, newVal);
				break;
				
			case 6 :
				printf("Enter the desired position : ");
				scanf("%d", &p);
				printf("Enter the new value : ");
				scanf("%d", &newVal);
				insertAtPosition (&start, p, newVal);
				break;
				
			case 7 :
				printf("Enter the value to be deleted : ");
				scanf("%d", &val);
				deleteValue (&start, val);
				break;
				
			case 8 :
				printf("Enter the value after which the value is to be deleted : ");
				scanf("%d", &val);
				temp = deleteAfter (start, val);
				if (temp != -1)
				    printf("%d deleted successfully.\n", temp);
				break;
				
			case 9 :
				printf("Enter the value before which the value is to be deleted : ");
				scanf("%d", &val);
				temp = deleteBefore (&start, val);
				if (temp != -1)
				    printf("%d deleted successfully.\n", temp);
				break;
				
			case 10 :
				printf("Enter the desired position : ");
				scanf("%d", &p);
				temp = deleteAtPosition (&start, p);
				if(temp != -1)
					printf("%d deleted successfully.\n", temp);
				else
					printf("Invalid position !! \n");
				break;
				
			case 11 :
				break;
				
			default :
				printf("Invalid choice !!\n");
		}
	}
	while (choice != 11);
	return 0;
}

void create(node** start)
{
	int choice, data;
	node *prev, *curr;
	
	*start = NULL;
	
	do
	{
		printf("Want to enter an element (1-Yes, 0-No) : ");
		scanf("%d", &choice);
		
		switch (choice)
		{
			case 1 :
				curr = (node*) malloc (sizeof (node));
				if (curr != NULL) // successfull memonry allocation
				{
					printf("Enter the data : ");
					scanf("%d", &curr->data);
					
					curr->link = NULL;
					
					if (*start == NULL)
					    *start = curr;
					else
					    prev->link = curr;
					    
				    prev = curr;
				}
				else
					printf("Memory allocation not possible !! \n");
			    break;
			    
			case 0 :
				break;
				
			default : 
			    printf("Invalid choice !!\n");
		}
	}
	while (choice != 0);
}

void traverse (node *start)
{
	node *temp = start;
	printf("The elements are\n");
	if (temp!=NULL)
	{
		while (temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->link;
		}
		printf("\n");
	}
	else
	   printf("No elements\n");
}

void append(node** start, int newVal)
{
	node *temp, *newNode;
	
	newNode = (node*) malloc (sizeof (node));
	if(newNode != NULL)
	{
		newNode->data = newVal;
		newNode->link = NULL;
		if (*start == NULL)
		   *start = newNode;
		else
		{
			temp = *start;
			while (temp->link != NULL)
			   temp = temp->link;
			temp->link = newNode;
		}
	}
	else
	   printf("Memory allocation not possible !!\n");
}

void insertAfter(node* start, int val, int newVal)
{
	node *target, *newNode;
	if (start != NULL)
	{
		target = start;
	    while ( target != NULL && target->data != val )
	        target = target->link;
	        
	    if (target != NULL)
	    {
	    	newNode = (node*) malloc (sizeof (node));
	    	if (newNode != NULL)
	    	{
		    	newNode->data = newVal;
		    	newNode->link = target->link;
		    	target->link = newNode;
			}
			else
			    printf("Memory allocation not possible !!\n");
		}
		else
	        printf("%d does not exist in the list !!! \n", val);
	}
	else
	    printf("%d does not exist in the list !!! \n", val);
    
}

void insertBefore (node** start, int val, int newVal)
{
	node *target, *newNode;
	
	target = *start;
	
	if (target != NULL)     // if list is not empty
	{
	    if (target->data == val)   // if val is the first value
	    {
		    newNode = (node*) malloc (sizeof (node));
		    if (newNode != NULL)   // if successful memory allocation
		    {
			    newNode->data = newVal;
			    newNode->link = target;
			    *start = newNode;
			}
			else
			   printf("Memory allocation not possible !!\n");
	    }
	    else      // if val is at any other value than start
		{
	    	while ( target->link != NULL && (target->link)->data != val)
            	target = target->link;
        
        	if (target->link != NULL)   // if list is not empty
        	{
        	    newNode = (node*) malloc (sizeof (node));
        	    if (newNode != NULL)   // if successful memory allocation
		        {
	            	newNode->data = newVal;
	    	    	newNode->link = target->link;
	    	    	target->link = newNode;
    	        }
    	        else 
			          printf("Memory allocation not possible !!\n");
	    	}
	    	else  // if complete list is traversed
            	printf("%d does not exist in the list !!! \n", val);
       }
   }
    else // if list is empty
       printf("%d does not exist in the list !!! \n", val);

}

void insertAtPosition (node** start, int p, int newVal)
{
	int i;
	node *target, *newNode;
	
	target = *start;
	
	if (p==1)   // if newVal should become the first node
	{
		newNode = (node*) malloc (sizeof (node));
		if (newNode != NULL)
		{
	   		newNode->data = newVal;
	   		newNode->link = *start;
	   		*start = newNode;
   	    }
   	    else
   	        printf("Memory allocation not possible !!\n");
	}
	
	else if (target != NULL && p>1)  // if we have to insert the node at any point other than start & list is not empty
	{	
		for (i=2; (i<p) && (target != NULL); i++)
		   target = target->link;
		   
		if (target != NULL)   // if whole list is not traversed, means it is existing position
		{
		   	newNode = (node*) malloc (sizeof (node));
		   	if (newNode != NULL)
		    {
		   		newNode->data = newVal;
		   	    newNode->link = target->link;
		        target->link = newNode;	
	        }
	        else
   	        printf("Memory allocation not possible !!\n");		
		}
	    else            // whole list is traversed + p is also not a new last node
		    printf("Invalid position !! \n");
	}
	else                            // list is empty + p is not equal to 1
	   printf("Invalid position !! \n");
}

void deleteValue (node** start, int val)
{
	node *target, *delNode;
	delNode = NULL;
	
	target = *start;
	
	if (target != NULL)            // if list is not empty
	{
		if (target->data == val)    // if val is the first value of the list
		{
			delNode = target;             // store the address of the node to be deleted, so that we can free it 
			*start = delNode->link;               // now start is the address of second element
		}
		else                                 // if val is not the first value of list
		{
			while (((target->link )!= NULL) && (((target->link)->data) != val))
			      target = target->link;
			      
			if (target->link != NULL)     
			{ 
				delNode = target->link;
				target->link = delNode->link;
		    }
		    else
		        printf("%d does not exist in the list !! \n", val);
		}
		free (delNode);
	}
	else              // if list is empty
	    printf("%d does not exist in the list !! \n", val);
	    
	
}

int deleteAfter(node* start, int val)
{
	node *target, *delNode;
	int delVal;
	
	target = start;

	if (target != NULL)                            // if list is not empty
	{
		while (target != NULL && target->data != val)
			target = target->link;
			
		if (target != NULL)                // if we have not reached the end point and got val
		{	
			if(target->link != NULL)           // if target is not the last node
			{
				delNode = target->link;
				delVal = delNode->data;
				target->link = delNode->link;
				free(delNode);
				return delVal;
			}
			else
				printf("There is no value after %d in the list !! \n", val);
		}
		else
			printf("%d does not exist in the list !!\n");
	}
	else
		printf("There are no elements in the list !!\n");
		
	return -1;
}

int deleteBefore (node** start, int val)
{
	node *target, *delNode;
	int delVal;
	
	target = *start;
	
	if (target != NULL)            // if list is not empty
	{
		if (target->data == val)   // if val is the first data
			printf("There is no element before %d !! \n",val);
			
		else if (target->link == NULL)   // if 2nd node does not exist
			printf("%d does not exist in the list !! \n", val);
			
		else if (target->link->data == val) // 2nd node exists and we have to delete node before this 2nd node
		{
			delNode = target;
			delVal = delNode->data;
			*start = delNode->link;
			free (delNode);
			return delVal;
		}
	
		else         // val is at any other node except 1st and 2nd
		{
			while (target->link->link != NULL && target->link->link->data != val)
				target = target->link;
			
			if (target->link->link != NULL)   // if we haven't traversed whole list and got the val
			{
				delNode = target->link;
				delVal = delNode->data;
				target->link = delNode->link;
				free(delNode);
				return delVal;
			}
			else
				printf("%d does not exist in the list !! \n", val);
		}
	}
	else
		printf("There are no elements in the list !! \n");
	return -1;	
}

int deleteAtPosition (node** start, int p)
{
	node *target, *delNode;
	int delVal,i;
	
	target = *start;
	
	if (target != NULL)      // if list is not empty
	{
		if (p==1)         // if first element is to be deleted
		{
			delNode = target;
			delVal = delNode->data;
			*start = delNode->link;
			free(delNode);
			return delVal;
		}
		else    // any other p
		{
			for(i=2; i<p && target!=NULL ; i++)
				target = target->link;
			
			if (target != NULL && i==p)  // bcoz for p=2 the for loop will not be executed, and we will not be able to predict whether 2nd node is present or not
			{	
				delNode = target->link;
				delVal = delNode->data;
				target->link = delNode->link;
				free (delNode);
				return delVal;
		    }
		}
	}
	return -1;
}


