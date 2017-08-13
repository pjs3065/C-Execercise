#include<stdio.h>
#include<stdlib.h>

struct DIGIT
{
	int digits;  // ���� ����
}numbers[10]; // digits numbers ���� 10������

int top = -1; // �迭 �ε��� top 

void push(int num); // ���ڻ���
int get(); // ���� ��������

int add(int number1, int number2); // ���ϱ�
int sub(int number1, int number2); // ����
int divi(int number1, int number2); // ������
int mul(int number1, int number2); // ����


void main()
{
	FILE *fp;
	char all[10]= {0,};
	int number;
	int number1,number2;
	int count =1 ;

	fp = fopen("postfix.txt","r"); // postfix.txt�� �о�´�.

	if(fp == NULL)
	{
		printf("error\n");
		exit(1);
	}

	while(fscanf(fp, "%s", all) != EOF)
	{
		printf("Read %s \n",all);
		if(all[0] >= '0' && all[0] <= '9') // �����̸�
		{
			number = atoi(all); // ���ڿ��� ���ڷ� �ٲ㼭
			push(number); // ���� �߰�
		}
		else if(all[0] == '+' || all[0] == '-' || all[0] == '*' || all[0] == '/')
		{
			number2 = get(); // ���� top ��ġ�� number�� �ҷ�����
			number1 = get(); // ���� top ��ġ�� number�� �ҷ�����
								// ���� top ��ġ�� ���� top ��ġ�� -2

			switch(all[0]) // ��Ģ���� �Լ� ����
			{
			case '+':
				number = add(number1, number2);
				break;
			case '-':
				number = sub(number1, number2);
				break;
			case '*':
				number = mul(number1, number2);
				break;
			case '/':
				number = divi(number1, number2);      
				break;
			}

			printf("-> %d %s %d = %d\n",number1,all,number2,number); // ���� ���� ���
			push(number); // ������ �� ���� push ���Ѽ� �ٽ� �׾� �ø�
		}

		else if(all[0] == '.') // . �ϰ�� result �� ���
		{
			printf("result : %d\n",numbers[top].digits); // ���� top�� ���� �ִ� digits�� �����
			top = -1; // �ٽ� �ʱ�ȭ ���� ���� ����
			printf("----------%dth line end ----------\n\n",count);
			count++;
		}

	}
	fclose(fp);
}

void push(int number)
{
	top++; // top ����
	numbers[top].digits = number; // ������ -1�̾��ٸ� ���� top 0��ġ�� number�� ����

}

int get()
{
	return numbers[top--].digits; // ���� ž��ġ�� digits�� ��ȯ�� top �� -1����.
}

int add(int number1, int number2)
{
	return number1+number2;
}
int sub(int number1, int number2)
{
	return number1-number2;
}
int divi(int number1, int number2)
{
	return number1/number2;
}
int mul(int number1, int number2)
{
	return number1*number2;
}