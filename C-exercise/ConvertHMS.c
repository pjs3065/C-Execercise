//made by ���缺
//����6 : ����ڷκ��� �ʸ� �޴´�. �̸� �ú����� ���·� ����ϴ� ���α׷��� �ۼ��غ���.

#include<stdio.h>

int main(void)
{
	int input_s;
	int input_s_t;
	int h,m,s;

	printf("��(second) �Է� : ");
	scanf("%d",&input_s);

	input_s_t = input_s;
	h = input_s / 3600;
	input_s_t = input_s_t % 3600;
	m = input_s_t / 60;
	input_s_t = input_s_t % 60;
	s = input_s_t;

	printf("[h:%d, m:%d, s:%d]\n",h,m,s);
	return 0;
}