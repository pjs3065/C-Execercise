//made by ���缺
//���� 3: �ΰ��� ������ �Է¹޾Ƽ� �ִ� ������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include<stdio.h>
#pragma warning (disable:4996)

int main(void)
{
	int n1, n2;
	int n1_t, n2_t;

	int max;
	int gcm = 1;
	int i;

	printf("�ΰ��� ������ �Է��Ͻÿ� ");
	scanf("%d %d",&n1, &n2);

	n1_t = n1;
	n2_t = n2;

	max = (n1_t > n2_t)? n1_t : n2_t;

	for(i = 1; i <= max; i++)
	{
		if(n1_t % i == 0 && n2_t % i == 0)
		{
			gcm = i;
		}
	}

	printf("GCM : %d\n",gcm);
	return 0;
}