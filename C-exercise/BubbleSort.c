//made by 박재성
//문제 5 : 거품 정렬(오름차순, 내림 차순 선택)


void BubbleSort_asc(int *str, int count);
void BubbleSort_des(int *str, int count);
void swap(int *str1, int *str2);

#include<stdio.h>
int main(void)
{
	int str[7] = {0,};
	int i, choice;

	//7개 정수값 입력
	printf("7개의 정수를 입력하시오\n");
	for(i = 0; i < 7; i++)
	{
		printf("?: ");
		scanf("%d",str+i);
	}

	//정렬 조건 선택
	printf("정렬을 선택하시오\n");
	printf("(1) 오름차순 (2) 내림차순 : ");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		//오름차순
		BubbleSort_asc(str,7);
		break;
	case 2:
		//내림차순
		BubbleSort_des(str,7);
		break;
	default:
		//잘못 입력시
		printf("입력 번호에 해당하는 선택이 존재 하지 않습니다\n");
		return 0;
	}

	//출력 값
	printf("결과 값 : ");
	for(i = 0; i < 7; i++)
	{
		printf("%d ",*(str+i));
	}
	printf("\n");
	return 0;
}


//오름차순 정렬
void BubbleSort_asc(int *str, int count)
{
	int i,j;

	for(i = 0; i < count; i++)
	{
		for(j = 0; j < count-1; j++)
		{
			if(*(str+j) > *(str+j+1))
			{
				swap(str+j, str+j+1);
			}
		}
	}
}

//내림차순 정렬
void BubbleSort_des(int *str, int count)
{
	int i,j;

	for(i = 0; i < count; i++)
	{
		for(j = 0; j < count-1; j++)
		{
			if(*(str+j) < *(str+j+1))
			{
				swap(str+j,str+j+1);
			}
		}
	}
}

//자리 바꾸기
void swap(int *str1, int *str2)
{
	int temp;	
	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}