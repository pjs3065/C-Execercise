// made by ���缺
// ����2 : ����ڷκ��� �� ���� ���ڸ� �޾Ƽ� �������� ����ϴ� ���α׷��� �ۼ��غ���. 3�� 5�� �Է��ϸ� 3�� 4�� 5���� ������ 2�� 4�� �Է��ϸ� 2 3 4�� ������ �ȴ�
// �������� ������ ���� �ʴ´�.

#include<stdio.h>

int main(void)
{
	int n1, n2;
	int i, j;
	int temp;

	printf("�ΰ��� ���ڸ� �Է��Ͻÿ� : ");
	scanf("%d %d",&n1, &n2);

	if(n1 > n2)
	{
		temp = n1;
		n1 = n2;
		n2 = temp;
	}

	for(i = n1; i <= n2; i++)
	{
		printf("<%d��>\n",i);
		for(j = 1; j <= 9; j++)
		{
			printf(" %d * %d = %d \n",i,j,i*j); 
		}
		printf("\n");
	}
}