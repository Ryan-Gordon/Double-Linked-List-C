////Double Linked List Implentation
////Ryan Gordon - ryangordon210@gmail.com

#include<stdio.h>
#include<stdlib.h>

// Definition of the node structure for the linked list
struct listelement
{
	int value;
	struct listelement* next;
	struct listelement* previous;
};

// Definition of the various functions used to manipulate the linked list
void addElement_AtEnd(struct listelement** tail_ptr, struct listelement** head_ptr);
void addElement_AtStart(struct listelement** head_ptr, struct listelement** tail_ptr);
void addElement_AtPosition(struct listelement** head_ptr, struct listelement** tail_ptr, int position);


void deleteElement_AtStart(struct listelement** head_ptr, struct listelement** tail_ptr);
void deleteElement_AtEnd(struct listelement** head_ptr, struct listelement** tail_ptr);

void printElements_fromEnd(struct listelement* head_ptr);

void printElements(struct listelement* head_ptr);

int length(struct listelement* head_ptr);

int addingAtPositionBool = 0;


void main()
{
	//Declare all variables --- pointer to top of the list, choice of function by the user, integer being
	//searched for
	struct listelement* top;
	struct listelement* bottom;
	int choice;
	int search_integer;
	int pos;

	// List is empty at the start
	top = NULL;
	bottom = NULL;



	do
	{

		printf("Please Enter your choice!\n");

		printf(" 1: To add an element at the end!\n");

		printf(" 2: To add an element at the start!\n");

		printf(" 3: To add an element at a defined location!\n");

		printf(" 4: Display the elements!\n");

		printf(" 5: Display the elements in reverse!\n");

		printf(" 6: To delete an element from the start!\n");

		printf(" 7: To delete an element from the end!\n");

		printf(" 8: To display the length of the list!\n");

		printf(" -1: To terminate\n");

		scanf("%d", &choice);

		if (choice == 1)

			addElement_AtEnd(&bottom, &top);

		else if (choice == 2)

			addElement_AtStart(&top, &bottom);

		else if (choice == 3)
		{

			printf("Please enter the position\n");

			scanf("%d", &pos);
			addElement_AtPosition(&top, &bottom, pos);

		}
		else if (choice == 4)

			printElements(top);

		else if (choice == 5)

			printElements_fromEnd(bottom);


		else if (choice == 6)

			deleteElement_AtStart(&top, &bottom);

		else if (choice == 7)

			deleteElement_AtEnd(&top, &bottom);

		else if (choice == 8)
		{

			printf("The length of the list is: %d\n", length(top));
		}




	} while (choice != -1);

}



// This function add an element at the start of the list
void addElement_AtStart(struct listelement** head_ptr, struct listelement** tail_ptr)
{

	//Create new node and populate it with data
	struct listelement *newNode;

	struct listelement *temp;

	temp = *head_ptr;

	newNode = (struct listelement*)malloc(sizeof(struct listelement));

	printf("\nEnter data for this node");

	scanf("%d", &newNode->value);
	printf("\nAdding at start");

	if (*head_ptr == NULL)
	{
		newNode->next = NULL;
		newNode->previous = NULL;

		*head_ptr = newNode;
		*tail_ptr = newNode;
	}

	else
	{
		printf("\n\n List has elements");
		newNode->next = *head_ptr;
		newNode->previous = NULL;
		temp->previous = newNode;

		*head_ptr = newNode;
	}
}


/// Function to add an element at the end of the list
void addElement_AtEnd(struct listelement** tail_ptr, struct listelement** head_ptr)
{
	struct listelement *temp;
	struct listelement *newNode;



	// if the list is empty then call function to add element at the start of the list
	if (*tail_ptr == NULL)
	{

		addElement_AtStart(head_ptr, tail_ptr);

	}

	else
	{

		temp = *tail_ptr;

		//Create the new node
		newNode = (struct listelement*)malloc(sizeof(struct listelement));
		//Populate the new node's data
		printf("\nEnter data for this node");
		scanf("%d", &newNode->value);

		//Link up the node after the last node in the list.
		newNode->next = NULL;
		newNode->previous = temp;
		temp->next = newNode;
		*tail_ptr = newNode;
	}
}


// Function to add element after a position.... First element is number 1
void addElement_AtPosition(struct listelement** head_ptr, struct listelement** tail_ptr, int position)
{
	int i;
	struct listelement *temp;
	struct listelement *newNode;
	
	// if the list is empty then call function to add element at the start of the list
	// If the user enters a number before 1 refuse the fn
	if (position<1)
	{
		printf("The position must be greater than 1\n");
		
		return;
	}
	if (position == 1)
	{
		addElement_AtStart(&head_ptr, &tail_ptr);
		return;
	}
	else if (position>length(*head_ptr))
	{
		printf("The list is only of length %d and you have entered a position of %d\n", length(*head_ptr), position);
		return;
	}

	printf("\nadding at position");
		temp = *head_ptr;

		if (*head_ptr == NULL) {
			addElement_AtStart(&head_ptr, &tail_ptr);
			return;
		}
		// Loop until the position required by the user...
		for (i = 0; i<position - 1; i++)
		{
			temp = temp->next;

		}

		//Create the new node
		newNode = (struct listelement*)malloc(sizeof(struct listelement));
		//Populate the new node's data
		printf("\nEnter data for this node");
		scanf("%d", &newNode->value);

		//Link up the node after the specified node in the list.
		(temp->previous)->next = newNode;
		newNode->previous = temp->previous;
		temp->previous = newNode;
		newNode->next = temp;
}


// This function display the contents of the list
void printElements(struct listelement* head_ptr)
{

	struct listelement *temp;

	temp = head_ptr;

	while (temp != NULL) // go to the last node

	{

		///Display the contents

		printf("Contents %d", temp->value);

		temp = temp->next;

	}

}


// This function display the contents of the list
void printElements_fromEnd(struct listelement* tail_ptr)
{

	struct listelement *temp;

	temp = tail_ptr;

	while (temp != NULL) // go to the last node

	{

		///Display the contents

		printf("Contents %d", temp->value);

		temp = temp->previous;

	}

}




// This function returns the length of the list
int length(struct listelement* head_ptr)
{

	struct listelement *temp;

	int length = 0;

	temp = head_ptr;



	while (temp != NULL) // go to the last node

	{

		length = length + 1;

		temp = temp->next;

	}

	return length;

}




// Function to delete an element at the start of the list...
void deleteElement_AtStart(struct listelement** head_ptr, struct listelement** tail_ptr)
{

	//Declare local variables
	int data;
	struct listelement *temp;
	struct listelement *newNode;


	//If the list is empty
	if (*head_ptr == NULL)
	{
		printf("Nothing to delete\n");
	}

	//If the list has only one element
	else if (length(*head_ptr) == 1)
	{

		//Set head_ptr to null and free the memory
		temp = *head_ptr;
		*head_ptr = NULL;
		*tail_ptr = NULL;

		free(temp);

	}

	else
	{
		//Set head_ptr to null and free the memory
		temp = *head_ptr;
		*head_ptr = temp->next;
		(temp->next)->previous = NULL;

		// Delete last element
		printf("Deleting the element with %d\n", temp->value);
		free(temp);

	}

}


// Function to delete an element at the start of the list...
void deleteElement_AtEnd(struct listelement** head_ptr, struct listelement** tail_ptr)
{

	//Declare local variables
	int data;
	struct listelement *temp;
	struct listelement *newNode;
	struct listelement *old_temp;

	//If the list is empty
	if (*tail_ptr == NULL)
	{
		printf("Nothing to delete\n");
	}

	//If the list has only one element
	else if (length(*head_ptr) == 1)
	{

		//Set head_ptr to null and free the memory
		temp = *head_ptr;
		*head_ptr = NULL;
		*tail_ptr = NULL;

		free(temp);

	}

	else
	{
		//Set head_ptr to null and free the memory
		temp = *tail_ptr;
		*tail_ptr = temp->previous;
		(temp->previous)->next = NULL;

		// Delete last element
		printf("Deleting the element with %d\n", temp->value);
		free(temp);

	}

}

