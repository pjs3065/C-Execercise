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

	int sel, item,pop; //선택 변수, 아이템 입력 변수

	listptr head = NULL; // 스택은 항상 데이터 제일 나중에 삽입된 데이터를 포인팅 하는 head 변수
	listptr mem_clear; // 모두 clear해 주기 위해서 필요한 변수
	while(1){ 

		printf("select (1) Push Item (2) Get Item (3) Show stack (4) Exit \n"); 
		printf("Choose menu : "); 
		scanf("%d", &sel); 

		switch(sel){ 

		case 1: // push 작업입니다. 

			printf("Input item value : "); 
			scanf("%d", &item);

			if(push(&head,item))
			{
				printf("Push completed!\n"); 
			}

			break; 

		case 2: // get 함수부분입니다. 

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

			// 즉 1 2 3 4 를 순서대로 넣고 pop 을 한번 하고 5를 넣었다 치면 
			// 넣은순서의 역순인 5 - 3 - 2 -1 이런식으로 출력됩니다. 

			if(empty(&head) == 0)
			{
				printf("Stack is empty!!!\n");
			}

			else 
				display(&head);
			break;


		case 4: // 4면 프로그램 종료 

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
		*head = node; // 노드를 삽입하고 
		(*head)->previous = NULL; 

	}

	else{ 

		node->previous = *head;  // 새로생긴 노드가 원래의 노드를 가리키게 한다. 
		*head = node;  // 그리고 스택 포인터를 새로생긴 노드로 옮긴다. 

	} 

	(*head)->data = item;
	return 1;
}


int get(listptr *head)
{

	listptr mem_clear; // 모두 clear해 주기 위해서 필요한 변수
	int pop;

	pop = (*head)->data; // 데이터를 꺼내고 
	mem_clear = *head; 
	*head = (*head)->previous;// 이전데이터로 스택포인터 이동 
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

	listptr temp; // 노드를 만들때 쓰는 포인터 
	temp = *head; // 스택포인터가 변하면 안되니까 복제한것을 사용하여 출력 
	while(temp != NULL){ 

		printf("%d ", temp->data); 
		if(temp->previous != NULL) printf("<-"); 
		temp = temp->previous; 

	} 
	printf("\n"); 

} 


void finish(listptr *head)
{

	listptr mem_clear; // 모두 clear해 주기 위해서 필요한 변수

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