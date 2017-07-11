#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int cycle_len(int n);

int main()
{
	int i,j,n;
	int temp,max;

	while (1)
	{
		max = 1;

		scanf("%d %d", &i, &j);

		for (n=i; n <= j; n++)
		{
			temp = cycle_len(n);

			if (max < temp)
				max = temp;
		}

		printf("%d %d %d\n",i, j, max);
	}

}

int cycle_len(int n)
{
	int len=1;

	while (n != 1)
	{
		if (n % 2 == 0)	//Â¦¼ö
		{
			n = n / 2;
		}
		else			//È¦¼ö
		{
			n = 3 * n + 1;
		}

		len++;
	}
	return len;
}