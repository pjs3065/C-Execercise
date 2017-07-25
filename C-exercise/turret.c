//made by ���缺
//���� �ڵ� ��ȣ 1002
/*
�̼����� �������� ���ȯ���� ����� ����(�����)�� ��ġ�� ����϶�� ����� ���ȴ�. 
�������� ���ȯ�� ���� �ڽ��� �ͷ� ��ġ���� ���� �������� �Ÿ��� ����ߴ�.
�������� ��ǥ (x1, y1)�� ���ȯ�� ��ǥ (x2, y2)�� �־�����, 
�������� ����� �������� �Ÿ� r1�� ���ȯ�� ����� �������� �Ÿ� r2�� �־����� ��, ������� ���� �� �ִ� ��ǥ�� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����. �� �׽�Ʈ ���̽��� ������ ���� �����Ǿ��ִ�.
ù° �ٿ� x1, y1, r1, x2, y2, r2�� �־�����. x1, y1, x2, y2�� -10,000���� ũ�ų� ����, 10,000���� �۰ų� ���� �����̰�,
r1, r2�� 10,000���� �۰ų� ���� �ڿ����̴�.
*/


//��Ÿ�� ������ ���� (���� ���)


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

	//��� �Է�����?
	scanf("%d",&input_count);

	//�Է��� ��ŭ �ݺ�
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