#include <time.h>
#include <stdio.h>

#define MAXN 200

long long combination(int n, int r)
{
	if (r == 0 || n == r)
		return 1;
	return combination(n - 1, r - 1) + combination(n - 1, r);
}


long long combination2(int n, int r)
{
	static long long cache[MAXN][MAXN];
	if (cache[n][r] > 0)
		return cache[n][r];
	if (r == 0 || n == r)
		return (cache[n][r] = 1);
	cache[n][r] = combination2(n - 1, r - 1) + combination2(n - 1, r);
	return cache[n][r];
}


void main()
{

	int n, r;
	do
	{
	printf(" n, r : ");
	scanf("%d %d", &n, &r);
	clock_t tic1 = clock();
	printf("%lld\n", combination(n, r));
	clock_t toc1 = clock();
	clock_t tic2 = clock();
	printf("%lld\n", combination2(n, r));
	clock_t toc2 = clock();
	printf("Elapsed1: %f seconds\n",
		(double)(toc1 - tic1) / CLOCKS_PER_SEC);
	printf("Elapsed2: %f seconds\n",
		(double)(toc2 - tic2) / CLOCKS_PER_SEC);
	printf("\n");
	}while(n  != -1 && r != -1);
}