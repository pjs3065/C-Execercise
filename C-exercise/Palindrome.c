//made by 박재성
//문제 4 : 인자로 전달되는 문자열이 회문인지 아닌지를 출력해 주는 기능의 함수를 정의하고, 그에 적절한 main 함수를 구현해 보자.

#include<stdio.h>
#include<string.h>

int main(void)
{
	char str[20] ={0,};
	char str_t[20] = {0,};
	int length = 0;
	int count = 0;
	int i;

	//문자열 입력
	printf("문자열 입력: ");
	scanf("%s",str);
	length = strlen(str);


	//대문자 소문자로 바꾸기
	for(i = 0; i < length; i++)
	{
		if(str[i] >= 'A' && str[i] <='Z')
		{
			str[i] = str[i]-'A' + 'a';
		}

		str_t[i] = str[i];
	}

	//회문 확인
	for(i = 0; i < length/2; i++)
	{
		if(str_t[i] == str_t[length-1-i])
		{
			count ++;
		}
	}

	//회문 여부 출력
	if(count == length/2)
	{
		printf("회문입니다.\n");
	}
	else
	{
		printf("회문이 아닙니다.\n");
	}
	return 0;
}