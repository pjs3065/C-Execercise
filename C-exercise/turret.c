//made by 박재성
//백준 코드 번호 1002
/*
이석원은 조규현과 백승환에게 상대편 마린(류재명)의 위치를 계산하라는 명령을 내렸다. 
조규현과 백승환은 각각 자신의 터렛 위치에서 현재 적까지의 거리를 계산했다.
조규현의 좌표 (x1, y1)와 백승환의 좌표 (x2, y2)가 주어지고, 
조규현이 계산한 류재명과의 거리 r1과 백승환이 계산한 류재명과의 거리 r2가 주어졌을 때, 류재명이 있을 수 있는 좌표의 수를 출력하는 프로그램을 작성하시오.
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 다음과 같이 구성되어있다.
첫째 줄에 x1, y1, r1, x2, y2, r2가 주어진다. x1, y1, x2, y2는 -10,000보다 크거나 같고, 10,000보다 작거나 같은 정수이고,
r1, r2는 10,000보다 작거나 같은 자연수이다.
*/


//런타임 문제가 있음 (수정 요망)


#include<stdio.h>
#include<math.h>

double distance(double x1, double y1, double x2, double y2);

int main(void)
{
	int input_count;
	int result_count[1000]={0,};
	int count = 0;
	int index = 0;

	double i,j,k,h;
	double x1,y1,x2,y2;
	double r1, r2;

	//몇번 입력할지?
	scanf("%d",&input_count);

	//입력한 만큼 반복
	while(index!= input_count)
	{
		count = 0;
		scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&r1,&x2,&y2,&r2);

		for(i = x1-r1; i <= x1 + r1; i++)
		{
			for(j = y1-r1; j <= y1 + r1; j++)
			{
				if(distance(i,j,x1,y1) == r1)
				{
					for(k = x2-r2; k<= x2+r2; k++)
					{
						for(h= y2-r2; h<= y2+r2; h++)
						{
							if(distance(k,h,x2,y2) == r2 && i == k && j == h)
							{
								count++;
							}
						}

					}
				}
			}
		}

		if(count >= 0 && count <= 2)
		{
			result_count[index] = count;
		}
		else
		{
			result_count[index] = -1;
		}

		index++;

	}

	for(index = 0; index < input_count; index++)
	{
		printf("%d\n",result_count[index]);
	}

	return 0;
}

double distance(double x1, double y1, double x2, double y2)
{

	double d;
	d = sqrt(pow(x1-x2,2) + pow(y1-y2,2));
	return d;
}