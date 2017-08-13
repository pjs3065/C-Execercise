#include<stdio.h>
#include<stdlib.h>

struct DIGIT
{
	int digits;  // 숫자 저장
}numbers[10]; // digits numbers 갯수 10개까지

int top = -1; // 배열 인덱스 top 

void push(int num); // 숫자삽입
int get(); // 숫자 가져오기

int add(int number1, int number2); // 더하기
int sub(int number1, int number2); // 뺄셈
int divi(int number1, int number2); // 나눗셈
int mul(int number1, int number2); // 곱셈


void main()
{
	FILE *fp;
	char all[10]= {0,};
	int number;
	int number1,number2;
	int count =1 ;

	fp = fopen("postfix.txt","r"); // postfix.txt를 읽어온다.

	if(fp == NULL)
	{
		printf("error\n");
		exit(1);
	}

	while(fscanf(fp, "%s", all) != EOF)
	{
		printf("Read %s \n",all);
		if(all[0] >= '0' && all[0] <= '9') // 숫자이면
		{
			number = atoi(all); // 문자열을 숫자로 바꿔서
			push(number); // 숫자 추가
		}
		else if(all[0] == '+' || all[0] == '-' || all[0] == '*' || all[0] == '/')
		{
			number2 = get(); // 현재 top 위치의 number을 불러오기
			number1 = get(); // 이전 top 위치의 number을 불러오기
								// 지금 top 위치는 현재 top 위치의 -2

			switch(all[0]) // 사칙연산 함수 실행
			{
			case '+':
				number = add(number1, number2);
				break;
			case '-':
				number = sub(number1, number2);
				break;
			case '*':
				number = mul(number1, number2);
				break;
			case '/':
				number = divi(number1, number2);      
				break;
			}

			printf("-> %d %s %d = %d\n",number1,all,number2,number); // 연산 과정 출력
			push(number); // 연산한 그 값을 push 시켜서 다시 쌓아 올림
		}

		else if(all[0] == '.') // . 일경우 result 값 출력
		{
			printf("result : %d\n",numbers[top].digits); // 현재 top에 남아 있는 digits가 결과물
			top = -1; // 다시 초기화 다음 라인 실행
			printf("----------%dth line end ----------\n\n",count);
			count++;
		}

	}
	fclose(fp);
}

void push(int number)
{
	top++; // top 증가
	numbers[top].digits = number; // 그전이 -1이었다면 지금 top 0위치에 number가 삽입

}

int get()
{
	return numbers[top--].digits; // 현재 탑위치의 digits값 반환후 top 을 -1해줌.
}

int add(int number1, int number2)
{
	return number1+number2;
}
int sub(int number1, int number2)
{
	return number1-number2;
}
int divi(int number1, int number2)
{
	return number1/number2;
}
int mul(int number1, int number2)
{
	return number1*number2;
}