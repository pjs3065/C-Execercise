//made by ���缺
//���� 4 : ���ڷ� ���޵Ǵ� ���ڿ��� ȸ������ �ƴ����� ����� �ִ� ����� �Լ��� �����ϰ�, �׿� ������ main �Լ��� ������ ����.

#include<stdio.h>
#include<string.h>

int main(void)
{
	char str[20] ={0,};
	char str_t[20] = {0,};
	int length = 0;
	int count = 0;
	int i;

	//���ڿ� �Է�
	printf("���ڿ� �Է�: ");
	scanf("%s",str);
	length = strlen(str);


	//�빮�� �ҹ��ڷ� �ٲٱ�
	for(i = 0; i < length; i++)
	{
		if(str[i] >= 'A' && str[i] <='Z')
		{
			str[i] = str[i]-'A' + 'a';
		}

		str_t[i] = str[i];
	}

	//ȸ�� Ȯ��
	for(i = 0; i < length/2; i++)
	{
		if(str_t[i] == str_t[length-1-i])
		{
			count ++;
		}
	}

	//ȸ�� ���� ���
	if(count == length/2)
	{
		printf("ȸ���Դϴ�.\n");
	}
	else
	{
		printf("ȸ���� �ƴմϴ�.\n");
	}
	return 0;
}