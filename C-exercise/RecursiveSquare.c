//made by 박재성  
//문제8 : 사용자부터 숫자 n을 입력받는다. 그리고 나서 다음 공식이 성립하는 2의 n을 계산해서 출력하는 프로그램을 작성해보자.  
//단 재귀함수를 이용해라

#include<stdio.h>

int square(int k);

int main(void)
{

	int k;
	int result;
	
	printf("정수를 입력하세요 : ");
	scanf("%d",&k);
	
	result = square(k);

	printf("2의 %d승은 : %d이다.\n",k,result);
	return 0;

}

int square(int k)
{
	if(k == 0)
		return 1;
	else
		return 2 * square(k-1);
}




