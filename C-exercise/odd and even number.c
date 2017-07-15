//made by 박재성
//문제 1: 길이가 10인 배열을 선언하고 총 10개의 정수를 받아서 홀수와 짝수를 구분 지어서 출력해라.

#include<stdio.h>

int main(void)
{
	int number[10] = {0,};
	int oddNumber[10] = {0,}, oddCounter = 0;
	int evenNumber[10] = {0,}, evenCounter = 0;

	printf("총 10개의 숫자 입력하시오\n");

	for(int i = 0; i < 10; i++)
	{
		printf("?: ");
		scanf("%d",&number[i]);
	}

	for(int i = 0; i < 10; i++)
	{
		if(number[i] %2 == 0)
		{
			evenNumber[evenCounter] = number[i];
			evenCounter++;
		}

		else
		{
			oddNumber[oddCounter] = number[i];
			oddCounter++;
		}
	}

	printf("홀수 출력 : ");
	for(int i = 0; i < oddCounter; i++)
	{
		printf("%d, ",oddNumber[i]);
	}

	printf("\n짝수 출력 : ");
	for(int i = 0; i < evenCounter; i++)
	{
		printf("%d, ",evenNumber[i]);
	}
	printf("\n");
	return 0;
}