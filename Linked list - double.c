// Double Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *fwd, *back;
}node;

void create (node** start);
void traverseFwd (node* start);
void traverseBack (node* start);
void append (node** start, int newVal);
void insertAfter (node* start, int val, int newVal);
void insertBefore (node** start, int val, int newVal);
void insertAtPosition (node** start, int p, int newVal);
void deleteValue (node** start, int val);
int deleteAfter(node* start, int val);
int deleteBefore (node** start, int val);
int deleteAtPosition (node** start, int p);

int main()
{
	node* start;
	start = NULL;
	int choice,val,newVal,p,temp;
	
	do
	{
		printf("\n1. Create list\n");
		printf("2. Traverse Forward\n");
		printf("3. Traverse backward\n");
		printf("4. Append\n");
		printf("5. Insert After\n");
		printf("6. Insert Before\n");
		printf("7. Insert at position\n");
		printf("8. Delete a value\n");
		printf("9. Delete After\n");
		printf("10. Delete Before\n");
		printf("11. Delete at Position\n");
		printf("12. Exit\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		
		switch (choice)
		{
			case 1:
				create (&start);
				break;
			
			case 2:
				traverseFwd(start);
				break;
				
			case 3:
				traverseBack(start);
				break;
				
			case 4:
				printf("Enter the new value : ");
				scanf("%d", &newVal);
				append(&start, newVal);
				break;
			
			case 5:
				printf("Enter the value after which data is to be inserted : ");
				scanf("%d", &val);
				printf("Enter the new value : ");
				scanf("%d", &newVal);
				insertAfter(start, val, newVal);
				break;
				
			case 6 :
				printf("Enter the value before which data is to be inserted : ");
				scanf("%d", &val);
				printf("Enter the new value : ");
				scanf("%d", &newVal);
				insertBefore(&start, val, newVal);
				break;
				
			case 7 :
				printf("Enter the desired position : ");
				scanf("%d", &p);
				printf("Enter the new value : ");
				scanf("%d", &newVal);
				insertAtPosition (&start, p, newVal);
				break;
				
			case 8 :
				printf("Enter the value to be deleted : ");
				scanf("%d", &val);
				deleteValue (&start, val);
				break;
				
			case 9 :
				printf("Enter the value after which the value is to be deleted : ");
				scanf("%d", &val);
				temp = deleteAfter (start, val);
				if (temp != -1)
				    printf("%d deleted successfully.\n", temp);
				break;
				
			case 10 :
				printf("Enter the value before which the value is to be deleted : ");
				scanf("%d", &val);
				temp = deleteBefore (&start, val);
				if (temp != -1)
				    printf("%d deleted successfully.\n", temp);
				break;
				
			case 11 :
				printf("Enter the desired position : ");
				scanf("%d", &p);
				temp = deleteAtPosition (&start, p);
				if(temp != -1)
					printf("%d deleted successfully.\n", temp);
				break;
				
			case 12 :
				break;
				
			default:
				printf("Invalid choice !! \n");
		}
	}
	while (choice != 12);
	
	return 0;
}

void create (node** start)
{
	int choice;
	node *prev, *curr;
	
	*start = NULL;
	
	do
	{
		printf("Want to enter an element (1=Yes, 0=No) : ");
		scanf("%d", &choice);
		
		switch (choice)
		{
			case 1:
				curr = (node*) malloc (sizeof (node));
				if (curr != NULL) // successfull memonry allocation
				{
					printf("Enter the data : ");
					scanf("%d", &curr->data);
					
					curr->fwd = NULL;
					
					if (*start == NULL)   // if first node
					{
						curr->back = NULL;
						*start = curr;
					}
					else
					{
					    curr->back = prev;
					    prev->fwd = curr;
					}
				    prev = curr;
				}
				else
					printf("Memory allocation not possible !! \n");
				break;
				
			case 0:
				break;
				
			default:
				printf("Invalid choice !! \n");
		}
	}
	while (choice != 0);
}

void traverseFwd (node* start)
{
	node *temp = start;
	
	if (temp!=NULL)
	{
		printf("The elements are\n");
		while (temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->fwd;
		}
	}
	else
	   printf("No elements\n");
}

void traverseBack (node* start)
{
	node* temp = start;
	
	if(temp!=NULL)  // if list is not empty
	{
		while (temp->fwd != NULL)  
			temp  = temp->fwd;                 // reach the last node
		
		printf("The elements in reverse order are\n");	
		while (temp!=NULL)
		{
			printf("%d ", temp->data);
			temp = temp->back;
		}
		printf("\n");
	}
	else
		printf("No elements\n");
}

void append (node** start, int newVal)
{
	node *temp, *newNode;
	
	newNode = (node*) malloc (sizeof (node));
	if(newNode != NULL)
	{
		newNode->data = newVal;
		newNode->fwd = NULL;
		if (*start == NULL)   // this will become the first node of the list
		{
			newNode->back = NULL;
			*start = newNode;
		}
		else
		{
			temp = *start;
			while (temp->fwd != NULL)
			   temp = temp->fwd;         // temp reaches to the last node
			
			newNode->back = temp;
			temp->fwd = newNode;
		}
	}
	else
	   printf("Memory allocation not possible !!\n");
}

void insertAfter (node* start, int val, int newVal)
{
	node *target, *newNode;
	
	target = start;
    while ( target != NULL && target->data != val )
        target = target->fwd;             // target is at position after which we will insert the element
        
    if (target != NULL)
    {
    	newNode = (node*) malloc (sizeof (node));
    	if (newNode != NULL)
    	{
	    	newNode->data = newVal;
	    	newNode->fwd = target->fwd;
	    	newNode->back = target;
	    	target->fwd = newNode;
	    	if (newNode->fwd != NULL)
	    		newNode->fwd->back = newNode;
		}
		else
		    printf("Memory allocation not possible !!\n");
	}
	else
        printf("%d does not exist in the list !!! \n", val);
}

void insertBefore (node** start, int val, int newVal)
{
	node *target, *newNode;
	
	target = *start;
	
	while ( target!= NULL && target->data != val)
		target = target->fwd;
		
	if (target != NULL)  // the whole list is not traversed and we have got val
	{
		newNode = (node*) malloc (sizeof(node));
		if (newNode != NULL)
		{
			newNode->data = newVal;
			newNode->fwd = target;
			newNode->back = target->back;
			target->back = newNode;
			if (target->back == NULL)   // if the newNode is now the frst node
				*start = newNode;
			else
				newNode->back->fwd = newNode;
		}
		else
			printf("Memory allocation not possible !! \n");
	}
	else
		printf("%d does not exist in the list !! \n");
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
	   		newNode->fwd = target;
	   		newNode->back = NULL;
	   		*start = newNode;
	   		if (target!=NULL)
	   		target->back = newNode;
	   		
   	    }
   	    else
   	        printf("Memory allocation not possible !!\n");
	}
	
	else if (target != NULL && p>1)  // if we have to insert the node at any point other than start & list is not empty
	{	
		for (i=2; (i<p) && (target != NULL); i++)
		   target = target->fwd;
		   
		if (target != NULL)   // if whole list is not traversed, means it is existing position
		{
		   	newNode = (node*) malloc (sizeof (node));
		   	if (newNode != NULL)
		    {
		   		newNode->data = newVal;
	    		newNode->fwd = target->fwd;
	    		newNode->back = target;
	    		target->fwd = newNode;
	    		if (newNode->fwd != NULL)
	    			newNode->fwd->back = newNode;
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
	
	target = *start;
	
	if (target != NULL)            // if list is not empty
	{
		while ( target!=NULL && target->data != val)   // reach the node to be deleted
			target = target->fwd;
			
		if (target != NULL)
		{
			delNode = target;              // target is at the node to be deleted
			if (delNode->back != NULL)           // if it is not the first node
				delNode->back->fwd = delNode->fwd;
			else                                     // if it is the first node
				*start = delNode->fwd;
			if (delNode->fwd != NULL)                 // if it is not the last node
				delNode->fwd->back = delNode->back;
			free (delNode);
		}
		else
			 printf("%d does not exist in the list !! \n", val);
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
			target = target->fwd;
			
		if (target != NULL)                // if we have not reached the end point and got val
		{	
			if(target->fwd != NULL)           // if target is not the last node
			{
				delNode = target->fwd;
				delVal = delNode->data;
				target->fwd = delNode->fwd;
				if (delNode->fwd != NULL)            // if delNode is not the last node
					delNode->fwd->back = target;
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
		else
		{
			while (target!=NULL && target->data != val)
			   target = target->fwd;
			   
			if (target != NULL)
			{
				delNode = target->back;
				delVal = delNode->data;
				target->back = delNode->back;
				if (delNode->back == NULL)
					*start = target;
				else
					delNode->back->fwd = target;
					
				free (delNode);
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
	
	delVal = -1;
	target = *start;
	
	if (target != NULL)      // if list is not empty
	{
		for(i=1; i<p && target!=NULL ; i++)
			target = target->fwd;
		
		if (target != NULL && p>=1)
		{	
			delNode = target;
			delVal = delNode->data;
			if (delNode->fwd != NULL)
				delNode->fwd->back = delNode->back;
			if (delNode->back != NULL)
				delNode->back->fwd = delNode->fwd;
			else
				*start = delNode->fwd;
			free (delNode);
	    }
	    else
	    	printf("Invalid position !! \n");
	}
	else
		printf("There are no elements in the list !! \n");
	return delVal;
}


