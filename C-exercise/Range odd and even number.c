//made by 박재성
//문제 3 : 길이가 10인 배열을 선언하고, 총 10개의 정수를 입력받는다. 홀수이면 앞에서 부터 채워나가고, 짝수이면 뒤에서 부터 채워나간다.

#include<stdio.h>
int main(void)
{
	int number[10] = {0,};
	int number2[10] = {0,};
	int front = 0, tail = 9;


	printf("총 10개의 숫자 입력\n");

	for(int i = 0; i < 10; i++)
	{
		printf("?: ");
		scanf("%d",&number[i]);
	}

	for(int i = 0; i < 10; i++)
	{
		if(number[i] % 2 == 0)
		{
			number2[tail] = number[i];
			tail--;
		}

		else
		{
			number2[front] = number[i];
			front ++;
		}
	}

	printf("배열 요소의 출력: ");
	for(int i =0; i < 10; i++)
	{
		printf("%d ",number2[i]);
	}
	printf("\n");
	return 0;
}