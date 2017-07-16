//made by ���缺
//���� 5 : ��ǰ ����(��������, ���� ���� ����)


void BubbleSort_asc(int *str, int count);
void BubbleSort_des(int *str, int count);
void swap(int *str1, int *str2);

#include<stdio.h>
int main(void)
{
	int str[7] = {0,};
	int i, choice;

	//7�� ������ �Է�
	printf("7���� ������ �Է��Ͻÿ�\n");
	for(i = 0; i < 7; i++)
	{
		printf("?: ");
		scanf("%d",str+i);
	}

	//���� ���� ����
	printf("������ �����Ͻÿ�\n");
	printf("(1) �������� (2) �������� : ");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		//��������
		BubbleSort_asc(str,7);
		break;
	case 2:
		//��������
		BubbleSort_des(str,7);
		break;
	default:
		//�߸� �Է½�
		printf("�Է� ��ȣ�� �ش��ϴ� ������ ���� ���� �ʽ��ϴ�\n");
		return 0;
	}

	//��� ��
	printf("��� �� : ");
	for(i = 0; i < 7; i++)
	{
		printf("%d ",*(str+i));
	}
	printf("\n");
	return 0;
}


//�������� ����
void BubbleSort_asc(int *str, int count)
{
	int i,j;

	for(i = 0; i < count; i++)
	{
		for(j = 0; j < count-1; j++)
		{
			if(*(str+j) > *(str+j+1))
			{
				swap(str+j, str+j+1);
			}
		}
	}
}

//�������� ����
void BubbleSort_des(int *str, int count)
{
	int i,j;

	for(i = 0; i < count; i++)
	{
		for(j = 0; j < count-1; j++)
		{
			if(*(str+j) < *(str+j+1))
			{
				swap(str+j,str+j+1);
			}
		}
	}
}

//�ڸ� �ٲٱ�
void swap(int *str1, int *str2)
{
	int temp;	
	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}