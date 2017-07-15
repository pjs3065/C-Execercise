//made by 박재성
//문제 2: 사용자로부터 10진수 형태로 정수를 하나 입력받은 다음 2진수로 변환해서 출력하는 프로그램을 작성해 보자.

#include<stdio.h>

int main(void)
{
	int maxNumber = 1;
	int inputNumber, inputTempNumber;

	printf("10진수 정수 입력: ");
	scanf("%d",&inputNumber);

	inputTempNumber = inputNumber;

	while(inputNumber >= maxNumber * 2)
	{
		maxNumber = maxNumber * 2;
	}
	
	for(int i = maxNumber; i > 0; i = i / 2)
	{
		if(inputTempNumber >= i)
		{
			printf("%d", inputTempNumber / i);
			inputTempNumber = inputTempNumber % i;
		}

		else
			printf("0");
	}
	printf("\n");
	return 0;
}