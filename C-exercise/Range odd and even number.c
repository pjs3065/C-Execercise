//made by ���缺
//���� 3 : ���̰� 10�� �迭�� �����ϰ�, �� 10���� ������ �Է¹޴´�. Ȧ���̸� �տ��� ���� ä��������, ¦���̸� �ڿ��� ���� ä��������.

#include<stdio.h>
int main(void)
{
	int number[10] = {0,};
	int number2[10] = {0,};
	int front = 0, tail = 9;


	printf("�� 10���� ���� �Է�\n");

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

	printf("�迭 ����� ���: ");
	for(int i =0; i < 10; i++)
	{
		printf("%d ",number2[i]);
	}
	printf("\n");
	return 0;
}