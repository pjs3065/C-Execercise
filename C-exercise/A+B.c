//made by 박재성
//백준 코드 번호 1000
//두 수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
//첫째 줄에 A와 B가 주어진다. (0 < A,B < 10)

#include<stdio.h>
int main(void)
{
	int n1, n2;
	int sum;
	scanf("%d %d",&n1, &n2);

	if(n1 > 0 && n1 < 10 && n2 > 0 && n2 < 10)
	{
		sum = n1 + n2;
		printf("%d\n",sum);
	}
	return 0;
}
