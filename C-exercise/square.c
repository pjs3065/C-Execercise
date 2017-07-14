//made by 박재성
//문제7 : 사용자부터 숫자 n을 입력받는다. 그리고 나서 다음 공식이 성립하는 최대 k값을 계산해서 출력하는 프로그램을 작성해보자.

#include<stdio.h>
int main(void)
{
	int n, temp_n;
	int k = 0;

	printf("상수 n을 입력하세요 : ");
	scanf("%d", &n);

	temp_n = n;

	while(temp_n % 2 == 0)
	{
		temp_n = temp_n / 2;
		k++;
	}

	printf("공식을 만족하는 k : %d\n", k);
}