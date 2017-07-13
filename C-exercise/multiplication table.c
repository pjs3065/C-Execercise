// made by 박재성
// 문제2 : 사용자로부터 두 개의 숫자를 받아서 구구단을 출력하는 프로그램을 작성해보자. 3과 5를 입력하면 3단 4단 5단이 나오고 2와 4를 입력하면 2 3 4가 나오게 된다
// 순서에는 영향을 받지 않는다.

#include<stdio.h>

int main(void)
{
	int n1, n2;
	int i, j;
	int temp;

	printf("두개의 숫자를 입력하시오 : ");
	scanf("%d %d",&n1, &n2);

	if(n1 > n2)
	{
		temp = n1;
		n1 = n2;
		n2 = temp;
	}

	for(i = n1; i <= n2; i++)
	{
		printf("<%d단>\n",i);
		for(j = 1; j <= 9; j++)
		{
			printf(" %d * %d = %d \n",i,j,i*j); 
		}
		printf("\n");
	}
}