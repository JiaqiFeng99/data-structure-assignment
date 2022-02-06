#ifndef _IO_H_
#define _IO_H_
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
//--------------------------------------輸入輸出------------------------------------------
void wrong_input(){
	char back;
	printf("\n              Wrong input, press any key and back to main menu!\n");
	back = getch();
}
void back(){
	char back;
	printf("                    Press any key and back to main menu!\n");
    back = getch();
}
//判斷是否爲正確日期格式 
int isValidDate(int y,int m,int d,int h,int min)
{	
	int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        month[1] = 29;
	return  (m>0&&m<=12)&&(d>0&&d<=month[m-1])&&(h>0&&h<=24)&&(min>0&&min<=60);
}
#endif
//--------------------------------------輸入輸出------------------------------------------

