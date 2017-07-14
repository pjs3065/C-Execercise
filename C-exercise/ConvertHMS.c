//made by 박재성
//문제6 : 사용자로부터 초를 받는다. 이를 시분초의 형태로 출력하는 프로그램을 작성해보자.

#include<stdio.h>

int main(void)
{
	int input_s;
	int input_s_t;
	int h,m,s;

	printf("초(second) 입력 : ");
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