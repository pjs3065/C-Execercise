//made by ���缺
//����2: Minewseeper

// M*N�� ���ڹ翡�� �� ĭ�� ������ ĭ�� ��� ���ڰ� �ִ��� �����ֱ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

char matrix[SIZE][SIZE];

int main()
{
   int n, m;   //���ڹ��� ��� ��(0< n,m <=100)
   int i, j, a, b;
   int time = 0;

   while (1)
   {
      scanf("%d %d", &n, &m); // ��� �� �Է¹ޱ�
      getchar();            // �Է¹��� ����

      if (n == 0 && m == 0)   // 0 0�Է½� ����
         break;

      for (i = 0; i < n; i++) // �� �� ���� ���� �Է¹ޱ�
      {
         gets(matrix[i]);
      }

      for (i = 0; i < n; i++)   //.�� ĭ�� 0���� �ٲ��ֱ�
      {
         for (j = 0; j < m; j++)
         {
            if ((matrix[i][j]) == '.')
               matrix[i][j] = '0';

         }
      }

      for (i = 0; i < n; i++)
      {
         for (j = 0; j < m; j++)
         {
            if (matrix[i][j] == '*')   //*�� ���
            {
               for (a = -1; a <= 1; a++)  //������ 8���� ĭ�� 1�� ������Ŵ
               {
                  for (b = -1; b <= 1; b++)
                  {
                     if (((i + a) < 0 || (j + b)<0) || ((i + a) >= n || (j + b) >= m))   //���ڹ� ���� �ȿ�����
                        continue;

                     if (a == 0 && b == 0)   // �ڱ��ڽ��� ����
                        continue;

                     if (matrix[i + a][j + b] == '*') //�����ִ� �κ��� ���� ����X
                        continue;

                     //��ġ�� �� Ʋ�� �κ�: matrix[i+a][j+b] = atoi(matrix[i+a][j+b]) + 1; 
                     matrix[i + a][j + b]++;      //*�� ��� ������ 8���� ĭ�� 1�� ������Ŵ
                  }
               }
            }
         }
      }


      printf("\nField#%d \n", ++time);

      for (i = 0; i < n; i++)
      {
         for (j = 0; j < m; j++)
         {
            printf("%c ", matrix[i][j]);
         }
         printf("\n");
      }

   }
   return 0;
}

