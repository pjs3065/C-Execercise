// made by ���缺
// ����4: ���� ���� 3500���� �ְ� ũ����500�� ����� 700�� �ݶ� 400���� ����� �Ѵ�. ���� �ϳ����� ������ �����Ͽ����ϰ�, ���� ��� ����Ͽ� ��� �ִ� �����
// ��� �����Ͻÿ�.
#include<stdio.h>
int main(void)
{
	int balance = 3500;
	int cream = 500, cookie = 700, coke = 400;
	int i,j,k;

	printf("���� ����� �����ϰ� �ִ� �ݾ� : %d\n",balance);
	for(i = 1; i < balance / cream; i++)
	{
		for(j = 1; j < balance / cookie; j++)
		{
			for(k = 1; k < balance / coke; k++)
			{
				if((i * cream + j * cookie + k * coke) == balance)
					printf("ũ����(%d��), �����(%d����), �ݶ�(%d��)\n",i,j,k);
			}
		}
	}

	printf("��� �����Ͻðڽ��ϱ�?\n");
	return 0;

}