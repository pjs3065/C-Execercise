//made by ���缺
//���� 5: 10���� �Ҽ��� ����ϴ� ���α׷��� �ۼ��� ����. ���� n�� �� n���� �ۿ� �������� �ʴ��ٸ�, �̴� �Ҽ��� �ش�ȴ�. ���� 3�� �Ҽ���.
//�׷��� 4�� �Ҽ��� �ƴϴ�. 1,2,4�� ���������� �����̴�.
#include<stdio.h>

int main(void)
{
	int i, j;
	int primeCount = 0;
	int count;

	printf("{ ");
	for(i=2; primeCount < 10; i++)
	{
		count = 0;
		for(j=2; j<=30; j++)
		{
			if(i != j && j != 1 && i % j == 0)
			{
				count++;
			}
		}

		if(count == 0)
		{
			primeCount++;
			printf("%d ",i);
		}
	}
	printf("}\n");

	return 0;
}