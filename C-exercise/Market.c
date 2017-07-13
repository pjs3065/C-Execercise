// made by 박재성
// 문제4: 현재 돈이 3500원이 있고 크림빵500원 새우깡 700원 콜라 400원을 사려고 한다. 각각 하나씩은 무조건 구입하여야하고, 돈을 모두 사용하여 살수 있는 방법을
// 모두 나열하시오.
#include<stdio.h>
int main(void)
{
	int balance = 3500;
	int cream = 500, cookie = 700, coke = 400;
	int i,j,k;

	printf("현재 당신이 소유하고 있는 금액 : %d\n",balance);
	for(i = 1; i < balance / cream; i++)
	{
		for(j = 1; j < balance / cookie; j++)
		{
			for(k = 1; k < balance / coke; k++)
			{
				if((i * cream + j * cookie + k * coke) == balance)
					printf("크림빵(%d개), 새우깡(%d봉지), 콜라(%d병)\n",i,j,k);
			}
		}
	}

	printf("어떻게 구입하시겠습니까?\n");
	return 0;

}