#include<stdio.h>

struct lecture
{
   char sub_name[25];
   int credit;
   char grade;
} Class[5];

struct person
{
   char name[25];
   int age;
   struct lecture Class[5];
}person;

float calculate(struct person person, int n);

void main()
{
   float score;
   int n;
   int i;

   printf("name : ");
   scanf("%s", person.name);
   printf("age : ");
   scanf("%d", &person.age);
   printf("how many lecture : ");
   scanf("%d", &n);
   for (i = 0; i<n; i++)
   {
      printf("sub name : ");
      scanf("%s", person.Class[i].sub_name);
      printf("grade : ");
      scanf(" %c", &person.Class[i].grade);
      printf("credit :");
      scanf("%d", &person.Class[i].credit);
   }

   score = calculate(person, n);
   printf("your GPA : %f", score);
}

float calculate(struct person person, int n)
{
   int i;
   float score = 0;
   float credit = 0;
   float result;
   for (i = 0; i<n; i++)
   {
      if (person.Class[i].grade == 'A')
      {
         score = score + person.Class[i].credit * 4.0;
      }

      else if (person.Class[i].grade == 'B')
      {
         score = score + person.Class[i].credit * 3.0;
      }
      else if (person.Class[i].grade == 'C')
      {
         score = score + person.Class[i].credit * 2.0;
      }
      else if (person.Class[i].grade == 'D')
      {
         score = score + person.Class[i].credit * 1.0;
      }
      else if (person.Class[i].grade == 'F')
      {
         score = score + person.Class[i].credit * 0.0;
      }
      credit = credit + person.Class[i].credit;
   }

   result = score / credit;
   return result;
}