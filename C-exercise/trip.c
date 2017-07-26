//made by 박재성
//문제3: 여행(The Trip)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define MAX 1000

float cal(float *s, int n);

int main()
{
	int n;	// 학생 수
	int i;
	float min;
	float s[MAX];	//각 학생이 지출한 경비를 저장할 배열

	while (1)
	{
		scanf("%d", &n);

		if (n == 0)
			break;

		for (i = 0; i < n; i++)	// 각 학생이 지출한 경비
		{
			scanf("%f", &s[i]);
		}

		min = cal(s, n);
		printf("$%.2f\n", min);
	}


	return 0;

}
float cal(float *s, int n)
{
	int i;
	float total = 0.0;
	float gap = 0.0, gap2 = 0.0;

	for (i = 0; i < n; i++)
	{
		//total += s[i];
		total += *(s + i);
	}

	total = total / n;

	for (i = 0; i < n; i++)
	{
		if (total > s[i])
		{
			gap = total - s[i];
			gap = ((int)(gap * pow(10.0, 2))) / pow(10.0, 2);	// ★소수를 둘째자리까지 나타내기ex) 5.995 -> 5.99★
			gap2 += gap;
		}

	}
	return gap2;

}



