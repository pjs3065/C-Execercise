//made by 박재성
//문제 3: 두개의 정수를 입력받아서 최대 공약수를 구하는 프로그램을 작성하시오.

#include<stdio.h>
#pragma warning (disable:4996)

int main(void)
{
	int n1, n2;
	int n1_t, n2_t;

	int max;
	int gcm = 1;
	int i;

	printf("두개의 정수를 입력하시오 ");
	scanf("%d %d",&n1, &n2);

	n1_t = n1;
	n2_t = n2;

	max = (n1_t > n2_t)? n1_t : n2_t;

	for(i = 1; i <= max; i++)
	{
		if(n1_t % i == 0 && n2_t % i == 0)
		{
			gcm = i;
		}
	}

	printf("GCM : %d\n",gcm);
	return 0;
}