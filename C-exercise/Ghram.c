//Made in 201232342_���缺 ( Clean Campus )
/*
procedure GrahamScan(set Q)
let p0 be the point with the minimum y-coordinate
let <p1, .., pm> be the remaining points in Q, sorted by the
angle in counterclockwise order around p0
Top(S) = 0
Push(p0, S); Push(p1, S); Push(p2, S)
for i = 3 to m do
while the angle formed by points NextToTop(S), Top(S)
and pi makes a non-left turn do
Pop(S)
Push(pi, S)
return S

*/


/* ��밢��
int dx, dy;
float angle;
dx = b.x - a.x;
by = b.y -a.y;
if((dx>=0) && (dy ==0)) angle = 0;
else {
	angle = abs(dy)/(abs(dx) + abs(dy));
	if((dx<0) && (dy>=0)) angle = 2-angle;
	else if((dx<=0) && (dy <0)) angle = 2 + angle
	else if((dx>0) &&(dy <0)) angle = 4-angle;
}

return (angle *90);
}

*/

#include<stdio.h>
#include<math.h>
#define SIZE 100

//��ǥ�� ������ �ִ� ����ü
typedef struct pointer
{
	float x;
	float y;
	float angle;
}pointer;

//�ٰ����� ��ǥ�� �׾Ƶ� stack�� �Է¹��� ��ǥ p
pointer stack[SIZE];
pointer p[SIZE];

//push pop�� ���� anchor
int top = 0;

void find_angle(int n);
void sort_angle(int n);

void make_convexhull(int n);
float check_ccw(pointer p1, pointer p2, pointer p3);
float total_distance(pointer p1, pointer p2);

void push(pointer p);
void pop();

void main()
{
	int i,n;
	float distance = 0.0;
	printf("How many the number of pointer(x,y) : ");
	scanf("%d",&n);

	for(i = 0; i <= n; i++)
	{
		if(i == 0) // 0�ϰ�� (0,0)�̶�� �����Ѵ�.
		{
			p[i].x = 0.0;
			p[i].y = 0.0;
			//�������� ���� �ʿ䰡 ���⿡ 0�� �׳� �־��ش�.
			stack[i].x = 0.0;
			stack[i].y = 0.0;
		}
		else
			scanf("%f %f", &p[i].x, &p[i].y);
	}

	find_angle(n); //������ ���ϰ�
	sort_angle(n); //���� ������ sort�Ѵ�(�����Ʈ)

	//ó���� �ִ� ���� ������ ���⿡ 1,2�� �־��ش�. (0���� �̹� �� �ֱ⿡ 3���� ���ִ�)
	push(p[1]);
	push(p[2]);

	make_convexhull(n);
	push(p[0]); //������ 0�� �������� �ϱ� ���ؼ� stack�ȿ� �־� �ش�.


	//�Ÿ��� ���ؼ� +2�� ���ش�(�����ؾ��ϱ⿡)
	for(i = 0; i <= top; i++)
	{
		distance = distance + total_distance(stack[i],stack[i+1]);
	}

	printf("Convex hull's distance : %.2f\n",distance + 2);
}

void find_angle(int n)
{
	int i;
	float u_v, u_u, v_v;
	float pi = 3.14;

	for(i = 1; i <= n; i++)
	{
		u_v = p[i].x;
		u_u = 1.0;
		v_v = p[i].x * p[i].x + p[i].y * p[i].y;
		p[i].angle = acos(u_v / sqrt(v_v)) * 180 / pi;

		//y�� ������ ��� 360���� ���ش�.
		if(p[i].y < 0)
			p[i].angle = 360 - p[i].angle;
	}
}

void sort_angle(int n)
{
	int i,j;
	pointer temp;
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n-1; j++)
		{
			if(p[j].angle > p[j+1].angle)
			{
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}

		}
	}
}

void push(pointer p)
{
	top++;
	stack[top] = p;
}

void make_convexhull(int n)
{
	int i;
	for(i = 3; i <= n; i++)
	{
		if(check_ccw(p[i-2],p[i-1],p[i]) == -1) // cw�� ��� pop
		{
			pop();
		}
		push(p[i]);
	}

}

float check_ccw(pointer p1, pointer p2, pointer p3)
{
	int tem;
	tem = p1.x * p2.y
		+ p2.x * p3.y
		+ p3.x * p1.y;

	tem = tem - p1.y * p2.x
		- p2.y * p3.x
		- p3.y * p1.x;

	if(tem < 0) //��ǥ�� ���ٸ� �����ؾ� �Ѵ�. 
		return -1;
	else
		return 0;
}

void pop()
{
	top--;
}

float total_distance(pointer p1, pointer p2)
{
	return sqrt(pow((p2.x - p1.x),2) + pow((p2.y - p1.y),2)); // ���� ������ �Ÿ� ���ϴ� ����
}