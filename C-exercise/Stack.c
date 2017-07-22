//9.1 exercise (stack)

#include <stdio.h> 
#include <stdlib.h> 

typedef struct listNode* listptr; 
typedef struct listNode{ 

	int data; 
	listptr previous; 

}; 

typedef struct listNode listNode; 


int  push(listptr *head, int item);
int get(listptr *head);
void display(listptr *head);
int empty(listptr *head);
void finish(listptr *head);


void main(){ 

	int sel, item,pop; //���� ����, ������ �Է� ����

	listptr head = NULL; // ������ �׻� ������ ���� ���߿� ���Ե� �����͸� ������ �ϴ� head ����
	listptr mem_clear; // ��� clear�� �ֱ� ���ؼ� �ʿ��� ����
	while(1){ 

		printf("select (1) Push Item (2) Get Item (3) Show stack (4) Exit \n"); 
		printf("Choose menu : "); 
		scanf("%d", &sel); 

		switch(sel){ 

		case 1: // push �۾��Դϴ�. 

			printf("Input item value : "); 
			scanf("%d", &item);

			if(push(&head,item))
			{
				printf("Push completed!\n"); 
			}

			break; 

		case 2: // get �Լ��κ��Դϴ�. 

			if(empty(&head) == 0)
			{
				printf("Stack is empty!!!\n");
			}

			else 
			{
				printf("%d has got!\n", get(&head));
			}

			break; 

		case 3: 

			// �� 1 2 3 4 �� ������� �ְ� pop �� �ѹ� �ϰ� 5�� �־��� ġ�� 
			// ���������� ������ 5 - 3 - 2 -1 �̷������� ��µ˴ϴ�. 

			if(empty(&head) == 0)
			{
				printf("Stack is empty!!!\n");
			}

			else 
				display(&head);
			break;


		case 4: // 4�� ���α׷� ���� 

			finish(&head);

		default: 
			printf("Please Choose 1~4!\n"); 

		}
		printf("\n-----------------------------\n");
	}

}


int push(listptr *head, int item)
{
	listptr node;

	node = (listptr)malloc(sizeof(listNode)); 

	if(*head == NULL){ 
		*head = node; // ��带 �����ϰ� 
		(*head)->previous = NULL; 

	}

	else{ 

		node->previous = *head;  // ���λ��� ��尡 ������ ��带 ����Ű�� �Ѵ�. 
		*head = node;  // �׸��� ���� �����͸� ���λ��� ���� �ű��. 

	} 

	(*head)->data = item;
	return 1;
}


int get(listptr *head)
{

	listptr mem_clear; // ��� clear�� �ֱ� ���ؼ� �ʿ��� ����
	int pop;

	pop = (*head)->data; // �����͸� ������ 
	mem_clear = *head; 
	*head = (*head)->previous;// ���������ͷ� ���������� �̵� 
	free(mem_clear); 

	return pop;

} 

int empty(listptr *head)
{
	if(*head == NULL)
		return 0;
	else
		return 1;
}

void display(listptr *head)
{

	listptr temp; // ��带 ���鶧 ���� ������ 
	temp = *head; // ���������Ͱ� ���ϸ� �ȵǴϱ� �����Ѱ��� ����Ͽ� ��� 
	while(temp != NULL){ 

		printf("%d ", temp->data); 
		if(temp->previous != NULL) printf("<-"); 
		temp = temp->previous; 

	} 
	printf("\n"); 

} 


void finish(listptr *head)
{

	listptr mem_clear; // ��� clear�� �ֱ� ���ؼ� �ʿ��� ����

	if(*head == NULL) 
		exit(1); 

	else{ 

		while(*head != NULL){ 

			mem_clear = *head; 
			*head = (*head)->previous; 
			free(mem_clear); 

		} 

	}
}