//made by ���缺
//���� 2: ����ڷκ��� 10���� ���·� ������ �ϳ� �Է¹��� ���� 2������ ��ȯ�ؼ� ����ϴ� ���α׷��� �ۼ��� ����.

#include<stdio.h>

int main(void)
{
	int maxNumber = 1;
	int inputNumber, inputTempNumber;

	printf("10���� ���� �Է�: ");
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