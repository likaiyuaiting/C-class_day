#include<stdio.h>
#include<stdlib.h>

int leep(int year)
{
	return year % 4==0 && year % 100 != 0 || year % 400==0;
}

int main(void)
{
	int year, month,zhou,sub=0,i;
	int month12[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	printf("�������ѯ����XXXX-XX��");
	scanf("%d-%d",&year,&month);
	if (year<2000 && month>12)
	{
		printf("�������"); 
		goto loop;
	}
	for (i = 2000; i < year; i++)
		sub += 365 + leep(i);
	//�����1��1�������ڼ�
	zhou = (sub + 6) % 7;
	//printf("%d",zhou);
	//���µ�һ�������ڼ�
	sub = 0;
	for (i = 1; 1 < month; i++)
	{
		sub += month12[i];
		if (i == 2)
			sub += leep(year);
	}
	int day_zhou=(sub+zhou)%7;
	int j = 0;
	//��ʾ����
	printf("sun mon tue wed thu fri sta");
	for (i = 0; i < day_zhou; i++)
		printf("	");
	for (i = 1; i <= month12[month]; i++)
	{
		j++;
		printf("%4d",i);
		if (j % 7 == 0)
			printf("\n");	
	}
	if (month == 2)
		printf("29");
	system("pause");
loop:	return 0;
}