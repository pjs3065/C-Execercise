//made by ���缺  
//����8 : ����ں��� ���� n�� �Է¹޴´�. �׸��� ���� ���� ������ �����ϴ� 2�� n�� ����ؼ� ����ϴ� ���α׷��� �ۼ��غ���.  
//�� ����Լ��� �̿��ض�

#include<stdio.h>

int square(int k);

int main(void)
{

	int k;
	int result;
	
	printf("������ �Է��ϼ��� : ");
	scanf("%d",&k);
	
	result = square(k);

	printf("2�� %d���� : %d�̴�.\n",k,result);
	return 0;

}

int square(int k)
{
	if(k == 0)
		return 1;
	else
		return 2 * square(k-1);
}




