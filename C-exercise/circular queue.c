/*
Implement the 4 integer stack functions using a singly linked list (with malloc to create each new node)
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int key;
	struct node *next;
}Node;

typedef struct stack
{
	Node *top;
}Stack;

void Initial(Stack *pstack);

int Stack_empty(Stack *pstack);
int Stack_full(Node *newnode);

void Push(Stack *pstack, int key);
int Pop(Stack *pstack);

void Show(Stack *pstack);
void Exit(Stack *pstack);


/*
 Implement stack using linked list.
 Show menu (push, pop, print, exit ).
 Before call push function, check that stack is full.
 Before call pop function, check that stack is empty.
 When end of program, free all made node.
*/
void main()
{
	Stack pstack;
	Node *check_full = (Node*)malloc(sizeof(Node));

	int choice;
	int key;
	int return_key;

	Initial(&pstack);

	do
	{
		printf("(1)Push, (2)Pop, (3)Print, (4)Exit : ");
		scanf("%d",&choice);

		switch(choice)
		{

		case 1:

			if(Stack_full(check_full) == -1)
			{
				printf("Full!!\n");
				free(check_full);
				break;
			}

			else
			{
				printf("Push key : ");
				scanf("%d",&key);
				Push(&pstack,key);
			}

			break;

		case 2:

			if(Stack_empty(&pstack) == -1)
			{
				printf("Empty!!\n");
			}
			else
			{
				if((return_key = Pop(&pstack)))
				{
					printf("Pop %d success!!\n",return_key);
				}
			}

			break;

		case 3:

			if(Stack_empty(&pstack) == -1)
			{
				printf("Empty!!\n");
			}

			else
			{
				Show(&pstack);
			}

			break;
		case 4:
			Exit(&pstack);
			printf("\n---------program exit!!!---------\n");
			break;

		default :
			printf("Input error!!\n");
			break;
		}

	}while(choice != 4);


}

/*
<function of description>
purpose : For initialize one stack's variable. 
Currently, it does not include anything value, so stack->top is NULL   
input : pstack's address
output : None
*/
void Initial(Stack *pstack) 
{
	pstack->top = NULL;
}

/*
<function of description>
purpose : Check whether stack is empty or stack contain something data. 
When data in stack is none, protect pop function's execution.
input : pstack's address(top)
output : If pstack->top is null then return value is -1, if it is not true then return value is 0.
*/
int Stack_empty(Stack *pstack)
{
	if(pstack->top == NULL)
		return -1;
	else
		return 0;
}

/*
<function of description>
purpose : When memory allocate, if memory state is full then protect push function's execution.	  
input : check_full node's address(temporary value for check full state)
output : if check_full is null then return value -1, if it not true then return value 0
*/
int Stack_full(Node *check_full)
{
	if(check_full == NULL)
		return -1;
	else
		return 0;
}


/*
<function of description>
purpose : For put data in stack, make new node. if it made then stack->top point it. 
And new node point top(Null) or previous node.
input : pstack's address(top)
output : None
*/
void Push(Stack *pstack, int key)
{
	Node* newnode = (Node*)malloc(sizeof(Node));

	newnode->key = key;
	newnode->next = pstack->top;
	pstack->top = newnode;
}

/*
<function of description>
purpose : Currently, store pointing node's data in return_key 
	  ,store pointing top's address in tempnode 
  ,edit top's point address to previous node's address and free current temp's address.
input : pstack's address(top)
output : return_key
*/
int Pop(Stack *pstack)
{
	int return_key;
	Node *tempnode;

	return_key = pstack->top->key;
	tempnode = pstack->top;

	pstack->top = pstack->top->next;
	free(tempnode);

	return return_key;
}

/*
<function of description>
purpose : Show pushed all node's data. Put Current pointing top's address in temporary variable, and print data in order.
		  After use temp node, free temp node.
input : pstack's address(top)
output : None
*/
void Show(Stack *pstack)
{
	Node* temp = pstack->top;

	printf("--------\n");
	while(temp!= NULL)
	{
		printf("%4d\n",temp->key);
		temp = temp->next;
	}
	printf("--------\n");
	free(temp);

}


/*
<function of description>
purpose : For end of program. For memory waste, all made node conduct free. 
input : pstack's address(top)
output : None
*/
void Exit(Stack *pstack)
{

	Node *clear;

	if(pstack->top = NULL)
	{
		exit(1);
	}

	else
	{
		while(pstack->top != NULL)
		{
			clear = pstack->top;
			pstack->top = pstack->top->next;
			free(clear);
		}
	}

}
