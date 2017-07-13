// made by 박재성
// 문제 : 10진수 정수를 입력 받아서 16진수 출력하는 프로그램을 작성해 보자. 서식문자 활용에 대한 문제이므로 쉽게 해결할 수 있을 것이다.

#include<stdio.h>
int main(void)
{
	int dec;

	printf("10진수 정수를 입력 하시오 : ");
	scanf("%d",&dec);

	printf("16진수로 변환한 값은 : %x\n",dec);
	return 0;
}