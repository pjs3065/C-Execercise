//made by ���缺
//���� �ڵ� ��ȣ 1001
//�� �� A�� B�� �Է¹��� ���� A-B�� ����Ͻÿ�.
//ù° �ٿ� A�� B�� �־�����. (0 < A,B < 10)

#include<stdio.h>
int main(void)
{
	int n1, n2, sub;
	int temp;
	scanf("%d %d",&n1, &n2);

	if(n1 > 0 && n1 < 10 && n2 > 0 && n2 < 10)
	{
		sub = n1 - n2;
		printf("%d\n",sub);
	}

	return 0;
}
