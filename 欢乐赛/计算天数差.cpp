#include<stdio.h>

// 定义一个结构体保存日期
typedef struct Date
{
	int y;// 年
	int m;// 月
	int d;// 日
}Date;

// 平年的12个月的天数
const int monthDays[12]
= { 31, 28, 31, 30, 31, 30,
31, 31, 30, 31, 30, 31 };

// 计算从年份1到当前年份（如2021）的闰年数gg
// 作用就是，我计算年份1到当前年份的天数*365+闰年的年数，就计算出了从年份1到现在年份的天数
int countLeapYears(Date d)
{
	int years = d.y;

	// 如果今年还没过完2月份，那么今年就不用参与计算
	if (d.m <= 2)
		years--;

	// 这条公式是计算从年份1到现在年份的闰年数
	return years / 4 - years / 100 + years / 400;
}

// 计算两个日期的天数
// 主要逻辑，计算出两个日期的天数，然后相减就得出了两个日期相差的天数
int getDifference(Date dt1, Date dt2)
{
	// 假如输入dt1= 2021年10月10日
	// 假如输入dt2= 2021年10月23日
	int i;
	// 先假设1-2021年都是平年，那么年份1到2021年的天数为2021*365+10【没加月份的天数】
	long int n1 = dt1.y * 365 + dt1.d;
	// 计算1月到9月的天数
	for (i = 0; i < dt1.m - 1; i++)
		n1 += monthDays[i];
	// 然后计算闰年数，补上闰年的天数
	n1 += countLeapYears(dt1);
	long int n2 = dt2.y * 365 + dt2.d;
	for (i = 0; i < dt2.m - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(dt2);
	// 如果dt1大于dt2那么dt1-dt2的天数
	if (n1 > n2)
	{
		return n1 - n2;
	}
	else
	{
		// 如果dt2大于dt1那么，dt2-dt1的天数
		return (n2 - n1);
	}
}

int main()
{
	Date dt1;
	Date dt2;
	int diff;
	printf("请输入第一个日期的年月日（以空格分开如2021 10 10）：");
	scanf("%d %d %d", &dt1.y, &dt1.m, &dt1.d);
	printf("请输入第二个日期的年月日（以空格分开如2021 10 10）：");
	scanf("%d %d %d", &dt2.y, &dt2.m, &dt2.d);
	diff = getDifference(dt1, dt2);
	printf("%04d-%02d-%02d 与 %04d-%02d-%02d相差%d天\n", dt1.y, dt1.m, dt1.d, dt2.y, dt2.m, dt2.d, diff);
	return 0;
}
