#include <stdio.h>
#include <stdlib.h>
#include <getch.h>
#include <string.h>

#include "head.h"
#include "student.h"
#include "teacher.h"
#include "tools.h"

char menu(void)
{
	system("clear");
	puts("****管理系统****");
	puts("1、校长");
	puts("2、老师");
	puts("3、学生");	
	puts("4、退出系统");
	puts("****************");
	puts("请输入指令");
	char ch = getch();
	printf("%c\n",ch);
	return ch;
}

char menu_h(void)
{
	system("clear");
	puts("****校长系统****");
	puts("1、重置自己密码");
	puts("2、重置教师密码");
	puts("3、添加教师");
	puts("4、删除教师");	
	puts("5、显示在职教师");
	puts("6、显示离职教师");
	puts("7、退出系统");
	puts("****************");
	puts("请输入指令");
	char ch = getch();
	printf("%c\n",ch);
	return ch;
}

char menu_t(void)
{
	system("clear");
	puts("****教师系统****");
	puts("1、添加学生");
	puts("2、删除学生");
	puts("3、查找学生");	
	puts("4、修改学生信息");
	puts("5、录入学生成绩");
	puts("6、重置学生密码");
	puts("7、显示所有在校学生信息");
	puts("8、显示所有退出学生信息");
	puts("9、退出系统");
	puts("****************");
	puts("请输入指令");
	char ch = getch();
	printf("%c\n",ch);
	return ch;
}

char menu_s(void)
{
	system("clear");
	puts("****学生系统****");
	puts("1、查询成绩");
	puts("2、修改密码");
	puts("3、查看个人信息");	
	puts("4、退出系统");
	puts("****************");
	puts("请输入指令");
	char ch = getch();
	printf("%c\n",ch);
	return ch;
}

char menu_s1(void)
{
		system("clear");
		puts("*****添加学生*****");
		puts("1、单个学生添加");
		puts("2、批量添加学生");
		puts("3、返回上一级");
		puts("****************");
		puts("请输入指令");
		char ch = getch();
		printf("%c\n",ch);
		return ch;
}

char menu_s2(void)
{
		system("clear");
		puts("*****查找学生*****");
		puts("1、按学号查找");
		puts("2、按姓名查找");
		puts("3、返回上一级");
		puts("****************");
		puts("请输入指令");
		char ch = getch();
		printf("%c\n",ch);
		return ch;
}

char menu_s3(void)
{
		system("clear");
		puts("*****入录学生成绩*****");
		puts("1、录入单个学生成绩");
		puts("2、批量录入学生成绩");
		puts("3、返回上一级");
		puts("********************");
		puts("请输入指令");
		char ch = getch();
		printf("%c\n",ch);
		return ch;
}

void show_sleep(const char* msg,double sec)
{
	printf("%s",msg);
	fflush(stdout);
	usleep(sec*1000000);
}

Student* getstudentById(const char* id)
{
	if(strlen(id)!=8)
	{
	return NULL;
	}
	for(int i=0;i<count_s;i++)
	{
		if(!strcmp(id,all_student[i].stu_num))
		{
			return &all_student[i];
		}
	}
	return NULL;
}

Teacher* getteacherById(const char* id)
{
	if(strlen(id)!=4)
	{
	return NULL;
	}
	for(int i=0;i<count_t;i++)
	{
		if(!strcmp(id,all_teacher[i].w_t))
		{
			return &all_teacher[i];
		}
	}
	return NULL;
}
	
	void anykey_continue(void)
	{
		stdin->_IO_read_ptr = stdin->_IO_read_end;
		puts("请按任意键继续...");
		getch();
	}

bool read_m (void)
{
	strcpy(se,"123");
	
	FILE* frp = fopen("one","r");
	if(NULL == frp)
	{
		return false;
	}
	
	fread(&count_s,sizeof(int),1,frp);
		printf("1\n");
	fread(&count_t,sizeof(int),1,frp);
		printf("1\n");
	fread(all_student,sizeof(Student),count_s,frp);
		printf("1\n");
	fread(all_teacher,sizeof(Teacher),count_t,frp);
		printf("1\n");
		printf("1\n");
	fclose(frp);
	frp = NULL;
		printf("1\n");
	return true;
}

void keep_m(void)
{
	FILE* frp = fopen("one","w");
	fwrite(&count_s,sizeof(int),1,frp);
	fwrite(&count_t,sizeof(int),1,frp);
	fwrite(all_student,sizeof(Student),count_s,frp);
	fwrite(all_teacher,sizeof(Teacher),count_t,frp);
	fwrite(se,1,strlen(se),frp);
	fclose(frp);
	frp = NULL;
}

















