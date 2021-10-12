//Polynomial Multiplication                       (expo based)
// Using single linked list
// Assuming correctly ordered exp

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int exp,coeff;
	struct node *link;
}node;

node* multiplyTerm (int exp, int coeff, node* start);
node* multiplyPolynomials (node* poly1_start, node* poly2_start);
node* create(node* start);
void traverse (node *start);
node* add (node* poly1_start, node* poly2_start);

int main()
{
	char choice;
	node *poly1_start,*poly2_start,*poly3_start;
	
	poly1_start = NULL;
	poly2_start = NULL;
	poly3_start = NULL;
	
	do
	{
		printf("\nWant to enter a test case ? (y=Yes,n=No) : ");
		fflush(stdin);
		scanf("%c", &choice);
		
		switch (choice)
		{
			case 'y':
			case 'Y':
				printf("Enter polynomial 1 :\n");
				poly1_start = create(poly1_start);
				printf("Enter polynomial 2 :\n");
				poly2_start = create(poly2_start);
				
				poly3_start = multiplyPolynomials (poly1_start, poly2_start );
				
				printf("This is the operation performed \n (");
				traverse (poly1_start);
				printf(" ) * ( ");
				traverse (poly2_start);
				printf(" ) \n = ");
				traverse (poly3_start);
				break;
				
			case 'n':
			case 'N':
				break;
				
			default:
				printf("Invalid choice !!\n");
		}
	}
	while (choice != 'n' && choice != 'N');
	return 0;
}

node* multiplyPolynomials (node* poly1_start, node* poly2_start)
{
	node *poly3_start, *tempPoly, *t1;
	
	tempPoly = NULL;
	poly3_start = NULL;
	t1 = poly1_start;
	
	while (t1 != NULL)
	{
		tempPoly = multiplyTerm (t1->exp, t1->coeff, poly2_start);
		poly3_start = add (poly3_start, tempPoly);
		free (tempPoly);
		t1 = t1->link;
	}
	return poly3_start;
}

node* multiplyTerm (int exp, int coeff, node* start)
{
	node *tempPoly, *t, *curr, *prev;
	
	tempPoly = NULL;
	prev = NULL;
	t = start;
	
	while (t != NULL)
	{
		curr = (node*) malloc (sizeof (node));
		if (curr != NULL)
		{
			curr->exp = exp + t->exp;
			curr->coeff = coeff * t->coeff;
			curr->link = NULL;
			if (tempPoly == NULL)
				tempPoly = curr;
			if (prev != NULL)
				prev->link = curr;
			prev = curr;
			t = t->link;
		}
		else
			printf("Memory allocation not possible !!\n");
	}
	
	return tempPoly;
}

node* create(node* start)
{
	int choice, data;
	node *prev, *curr;
	
	start = NULL;
	
	do
	{
		printf("Want to enter a term (1-Yes, 0-No) : ");
		scanf("%d", &choice);
		
		switch (choice)
		{
			case 1 :
				curr = (node*) malloc (sizeof (node));
				if (curr != NULL) // successfull memonry allocation
				{
					printf("Enter the exp : ");
					scanf("%d", &curr->exp);
					printf("Enter the coeff : ");
					scanf("%d", &curr->coeff);
					
					curr->link = NULL;
					
					if (start == NULL)
					    start = curr;
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
	return start;
}

void traverse (node *start)
{
	node *temp = start;
	if (temp!=NULL)
	{
		while (temp->link != NULL)
		{
			printf("%dx^%d + ", temp->coeff, temp->exp);
			temp = temp->link;
		}
		printf("%dx^%d", temp->coeff, temp->exp);
	}
}

node* add (node* poly1_start, node* poly2_start)
{
	node *t1, *t2, *t3, *poly3_start, *prev;
	
	poly3_start = NULL;
	t1 = poly1_start;
	t2 = poly2_start;
	t3 = NULL;
	prev = NULL;
	
	while (t1!=NULL && t2!=NULL)
	{
		if (t1->exp == t2->exp)
		{
			if (t1->coeff + t2->coeff != 0)
			{
				t3 = (node*) malloc (sizeof (node));
				if (t3 != NULL)
				{
					t3->exp = t1->exp;
					t3->coeff = t1->coeff + t2->coeff;
					t3->link = NULL;
					if(poly3_start == NULL)
						poly3_start = t3;
					else
						prev->link = t3;
						
					prev = t3;
				}
				else
					printf("Memory allocation not possible !! \n");
			}
			t1 = t1->link;
			t2 = t2->link;
		}
		
		else if (t1->exp > t2->exp)
		{
			t3 = (node*) malloc (sizeof (node));
			if (t3 != NULL)
			{
				t3->exp = t1->exp;
				t3->coeff = t1->coeff;
				t3->link = NULL;
				if(poly3_start == NULL)
					poly3_start = t3;
				else
					prev->link = t3;
						
				prev = t3;
				t1 = t1->link;
			}
			else
				printf("Memory allocation not possible !! \n");
		}
		
		else //if (t1->exp < t2->exp)
		{
			t3 = (node*) malloc (sizeof (node));
			if (t3 != NULL)
			{
				t3->exp = t2->exp;
				t3->coeff = t2->coeff;
				t3->link = NULL;
				if(poly3_start == NULL)
					poly3_start = t3;
				else
					prev->link = t3;
						
				prev = t3;
				t2 = t2->link;
			}
			else
				printf("Memory allocation not possible !! \n");
		}
	}
	
	while (t1!=NULL)
	{
		t3 = (node*) malloc (sizeof (node));
		if (t3 != NULL)
		{
			t3->exp = t1->exp;
			t3->coeff = t1->coeff;
			t3->link = NULL;
			if(poly3_start == NULL)					
				poly3_start = t3;
			else
				prev->link = t3;
						
			prev = t3;
			t1 = t1->link;
		}
		else
			printf("Memory allocation not possible !! \n");
	}
	
	while (t2!=NULL)
	{
		t3 = (node*) malloc (sizeof (node));
		if (t3 != NULL)
		{
			t3->exp = t2->exp;
			t3->coeff = t2->coeff;
			t3->link = NULL;
			if(poly3_start == NULL)					
				poly3_start = t3;
			else
				prev->link = t3;
						
			prev = t3;
			t2 = t2->link;
		}
		else
			printf("Memory allocation not possible !! \n");
	}
	return poly3_start;
}


