//made by ���缺
//���� 1: ���̰� 10�� �迭�� �����ϰ� �� 10���� ������ �޾Ƽ� Ȧ���� ¦���� ���� ��� ����ض�.

#include<stdio.h>

int main(void)
{
	int number[10] = {0,};
	int oddNumber[10] = {0,}, oddCounter = 0;
	int evenNumber[10] = {0,}, evenCounter = 0;

	printf("�� 10���� ���� �Է��Ͻÿ�\n");

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

	printf("Ȧ�� ��� : ");
	for(int i = 0; i < oddCounter; i++)
	{
		printf("%d, ",oddNumber[i]);
	}

	printf("\n¦�� ��� : ");
	for(int i = 0; i < evenCounter; i++)
	{
		printf("%d, ",evenNumber[i]);
	}
	printf("\n");
	return 0;
}