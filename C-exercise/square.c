//made by ���缺
//����7 : ����ں��� ���� n�� �Է¹޴´�. �׸��� ���� ���� ������ �����ϴ� �ִ� k���� ����ؼ� ����ϴ� ���α׷��� �ۼ��غ���.

#include<stdio.h>
int main(void)
{
	int n, temp_n;
	int k = 0;

	printf("��� n�� �Է��ϼ��� : ");
	scanf("%d", &n);

	temp_n = n;

	while(temp_n % 2 == 0)
	{
		temp_n = temp_n / 2;
		k++;
	}

	printf("������ �����ϴ� k : %d\n", k);
}