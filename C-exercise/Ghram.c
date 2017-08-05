//Made in 201232342_박재성 ( Clean Campus )
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


/* 상대각도
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

//좌표와 각도를 넣는 구조체
typedef struct pointer
{
	float x;
	float y;
	float angle;
}pointer;

//다각형의 좌표를 쌓아둘 stack과 입력받을 좌표 p
pointer stack[SIZE];
pointer p[SIZE];

//push pop에 사용될 anchor
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
		if(i == 0) // 0일경우 (0,0)이라고 가정한다.
		{
			p[i].x = 0.0;
			p[i].y = 0.0;
			//시작점을 구할 필요가 없기에 0을 그냥 넣어준다.
			stack[i].x = 0.0;
			stack[i].y = 0.0;
		}
		else
			scanf("%f %f", &p[i].x, &p[i].y);
	}

	find_angle(n); //각도를 구하고
	sort_angle(n); //구한 각도를 sort한다(버블소트)

	//처음에 넣는 것은 오류가 없기에 1,2를 넣어준다. (0번은 이미 들어가 있기에 3점이 들어가있다)
	push(p[1]);
	push(p[2]);

	make_convexhull(n);
	push(p[0]); //마지막 0로 마무리를 하기 위해서 stack안에 넣어 준다.


	//거리를 구해서 +2를 해준다(포장해야하기에)
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

		//y가 음수일 경우 360도를 빼준다.
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
		if(check_ccw(p[i-2],p[i-1],p[i]) == -1) // cw일 경우 pop
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

	if(tem < 0) //좌표가 같다면 무시해야 한다. 
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
	return sqrt(pow((p2.x - p1.x),2) + pow((p2.y - p1.y),2)); // 두점 사이의 거리 구하는 공식
}