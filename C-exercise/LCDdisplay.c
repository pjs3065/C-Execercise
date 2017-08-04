//made by ���缺
//����4: LCD DISPLAY

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_S 10		// (1 <= s <= 10)
#define MAX_DIGITS 8	// (0 < n <= 99999999)

void main()
{
	int s;
	char n[MAX_DIGITS + 1];	//��µ� ���ڸ� �Է¹޴� ���ڹ迭
	int num_digits, digit;

	char result[5][(MAX_S + 3)*MAX_DIGITS];	//���ڵ��� LCD ���÷��� ������� ����ϱ� ���� ���ڹ迭

	char hor_bar[2][MAX_S + 1] = { "          ","----------" };
	char ver_bar[2][2] = { " ","|" };

	//���� 0~9 �� ���� ����(0,2,4��)(-)
	char hor[10][3] = { { 1,0,1 },{ 0,0,0 },{ 1,1,1 },{ 1,1,1 },{ 0,1,0 },{ 1,1,1 },{ 1,1,1 },{ 1,0,0 },{ 1,1,1 },{ 1,1,1 } };
	//���� 0~9 �� ���� ����(|)
	char ver[10][4] = { { 1,1,1,1 },{ 0,1,0,1 },{ 0,1,1,0 },{ 0,1,0,1 },{ 1,1,0,1 },{ 1,0,0,1 },{ 1,0,1,1 },{ 0,1,0,1 },{ 1,1,1,1 },{ 1,1,0,1 } };


	int i, j;

	scanf("%d", &s);	// ���� ũ�� �Է¹ޱ�

	while (s != 0)
	{
		/*ó���� �����Ⱚ���� �ʱ�ȭ�Ǿ������Ƿ� ���ڿ��� ���� �˸��� '\0' ���� + �ݺ��ɶ����� �ʱ�ȭ*/
		for (i = 0; i < 5; i++)
			result[i][0] = '\0';


		//���� bar�� ���̸� s�� ������� ���� ���ڿ��� ���� �˸���'\0'�� ����
		hor_bar[0][s] = '\0';
		hor_bar[1][s] = '\0';

		scanf("%s", n);	// ��µ� ���� �Է¹ޱ�

		num_digits = strlen(n);	// ���ڵ��� ���� ���ϱ�

		for (i = 0; i < num_digits; i++)
		{
			digit = n[i] - '0';	// �ƽ�Ű�ڵ带 ���������� ��ȯ 

								/*���� ���̸� �� column(��)�� ����*/
			if (i > 0)
				for (j = 0; j < 5; j++)
					strcat(result[j], " ");

			/*ù°�� ���� bar*/
			strcat(result[0], " ");
			strcat(result[0], hor_bar[hor[digit][0]]);
			strcat(result[0], " ");

			/*��°�� ���� bar*/
			strcat(result[1], ver_bar[ver[digit][0]]);
			strcat(result[1], hor_bar[0]);
			strcat(result[1], ver_bar[ver[digit][1]]);

			/*��°�� ���� bar*/
			strcat(result[2], " ");
			strcat(result[2], hor_bar[hor[digit][1]]);
			strcat(result[2], " ");

			/*��°�� ���� bar*/
			strcat(result[3], ver_bar[ver[digit][2]]);
			strcat(result[3], hor_bar[0]);
			strcat(result[3], ver_bar[ver[digit][3]]);

			/*�ټ�°�� ���� bar*/
			strcat(result[4], " ");
			strcat(result[4], hor_bar[hor[digit][2]]);
			strcat(result[4], " ");
		}

		puts(result[0]);

		for (i = 0; i<s; i++)
			puts(result[1]);

		puts(result[2]);

		for (i = 0; i<s; i++)
			puts(result[3]);

		puts(result[4]);

		putchar('\n');

		/*�տ��� ������ \0 �� �ǵ�������*/
		hor_bar[0][s] = ' ';
		hor_bar[1][s] = '-';

		//�ݺ��ؼ� �Է¹޴� ���α׷�
		scanf("%d", &s);

	}
}