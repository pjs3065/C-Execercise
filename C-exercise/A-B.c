//made by 박재성
//백준 코드 번호 1001
//두 수 A와 B를 입력받은 다음 A-B를 계산하시오.
//첫째 줄에 A와 B가 주어진다. (0 < A,B < 10)

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
