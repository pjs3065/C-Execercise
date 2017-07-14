//made by 박재성
//문제 5: 10개의 소수를 출력하는 프로그램을 작성해 보자. 정수 n이 과 n으로 밖에 나눠지지 않느다면, 이는 소수에 해당된다. 따라서 3은 소수다.
//그러나 4는 소수가 아니다. 1,2,4로 나누어지기 때문이다.
#include<stdio.h>

int main(void)
{
	int i, j;
	int primeCount = 0;
	int count;

	printf("{ ");
	for(i=2; primeCount < 10; i++)
	{
		count = 0;
		for(j=2; j<=30; j++)
		{
			if(i != j && j != 1 && i % j == 0)
			{
				count++;
			}
		}

		if(count == 0)
		{
			primeCount++;
			printf("%d ",i);
		}
	}
	printf("}\n");

	return 0;
}