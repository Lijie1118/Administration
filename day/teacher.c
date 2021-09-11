#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "teacher.h"
#include "student.h"
#include "tools.h"


int count_t = 0;
/*
Teacher t[2] = {
		{"0001","张三",'m',"123",0,1},
		{"0002","李四",'w',"123",0,1}
};

void all_t(void)
{
	all_teacher = &t[0];
	count_t = 2;
}
*/

void all_t(void)
{
	all_teacher = malloc(sizeof(Teacher)*TEACHER);
	count_t = 0;
	//all_teacher = &t[0];
}

Teacher* all_teacher = NULL;
Teacher* single_teacher = NULL;

void teacher(void)
{
	if(!lockedup_t())
	{
		return;
	}
	for(;;)
	{
		switch(menu_t())
		{
			case '1':		add_t();			break;
			case '2':		del_t();			break;
			case '3':		seek_t();			break;
			case '4':		revise_t();			break;
			case '5':		enter_t();			break;
			case '6':		modify_t();			break;
			case '7':		show_t();			break;
			case '8':		nshow_t();			break;
			case '9':		return;
		}
	}
	
}


bool lockedup_t(void)
{
	char w_t1[5]; 
	char se_t1[7];
	printf("请输入工号：");
	scanf("%4s",w_t1);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	Teacher* te = getteacherById(w_t1);
	if(NULL == te || 0 == te->flag_t)
	{
		show_sleep("工号无效，请检查!\n",1.5);
		return false;
	}
	else
	{
		int count = 0;
		if(strcmp(all_teacher->se_t,"123") == 0)
	{
		printf("第一次登陆需修改密码\n");
		printf("请输入新密码(不能为初始密码，最多六位)：");
		scanf("%s",te->se_t);
		while(strcmp(te->se_t,"123") == 0)
		{
			printf("此密码与初始密码相同，请重新输入：\n");
			scanf("%s",te->se_t);
		}
		show_sleep("修改密码成功\n",1.5);
	}
		if(0 == te -> lock_t)
		{
			do{
				if(0 == count)
				{
					printf("请再次输入密码：");
				}
				else
				{
					printf("密码错误，请重新输入密码(还有%d次机会):\n",3-count);
				}
				scanf("%6s",se_t1);
				stdin->_IO_read_ptr = stdin->_IO_read_end;
			}while(count++ < 2 && 0 != strcmp(se_t1,te->se_t));
		}
		else
		{
			show_sleep("该帐号被锁定，无法登录!\n",1.5);
			return false;
		}
		if(0 == strcmp(se_t1,te->se_t))
		{
			show_sleep("登陆成功!\n",1.5);
			single_teacher = te;
			return true;
		}
		else
		{
			show_sleep("帐号已锁定，请联系校长解锁!\n",1.5);
			te -> lock_t = 1;
			return false;
		}
	}
	return false;
}


void add_t(void)
{
	for(;;)
	{
		char name[20] = {};
		char sex;
		char file[500] = {};
		switch(menu_s1())
		{
			case '1':
				printf("请输入学生姓名、性别：");
				scanf("%s %c",name,&sex);
				if(single(name,sex))
				{
					show_sleep("添加学生成功\n",1.5);
				}
				else
				{
					show_sleep("系统维护中，暂时无法添加...\n",1.5);
				}
				break;
			case '2':
				printf("请导入学生名单文件：");
				scanf("%s",file);
				usingle(file);
			case '3':	return;
		}
	}
}

bool single(const char* name,const char sex)
{
	if(STUDENT <= count_s)
	{
		return false;
	}
	all_student[count_s].Chinese = 0;
	all_student[count_s].Math = 0;
	all_student[count_s].English = 0;
	strcpy(all_student[count_s].name_s,name);
	all_student[count_s].sex_s = sex;
	sprintf(all_student[count_s].stu_num,"%4d%04d",((int)(time(NULL)/3600/24/365)+1970),count_s+1);
	strcpy(all_student[count_s].se_s,"123");
	all_student[count_s].lock_s = 0;
	all_student[count_s].flag_s = 1;
	count_s++;
	return true;
}

void usingle(const char* path)
{
	FILE*  frp = fopen(path,"r");
	if(NULL == frp)
	{
		show_sleep("文件打开失败，请检查文件路径!\n",1.5);
		return;
	}
	char name[20] = {};
	char sex = 0;
	int count = 0;
	while(0 < fscanf(frp,"%s %c\n",name,&sex))
	{
		if(!single(name,sex))
		{
			break;
		}
		count++;
	}
	fclose(frp);
	frp = NULL;
	printf("添加了%d个学生\n",count);
	anykey_continue();
}

void del_t(void)
{
	char stu_num2[9];
	char stu_num3[9];
	printf("请输入要删除的学生学号：");
	scanf("%8s",stu_num2);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	Student* st1 = getstudentById(stu_num2);
	if(NULL == st1 || 0 == st1->flag_s)
	{
		show_sleep("学号无效，请检查!\n",1.5);
		return;
	}
	printf("请再次输入要删除的学生学号：");
	scanf("%8s",stu_num3);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	if(!strcmp(stu_num2,stu_num3))
	{
		printf("学号：%s\n姓名：%s\n性别：%s\n语文：%.1f\n数学：%.1f\n英语：%.1f\n",st1->stu_num,st1->name_s,st1->sex_s == 'w'?"女":"男",st1->Chinese,st1->Math,st1->English);
		printf("请确认是否删除该学生(y/n)");
		if('y' == getchar() || 'Y' == getchar())
		{
			st1->flag_s = 0;
			printf("删除成功！\n");
			anykey_continue();
		}
		else
		{
			printf("已取消该删除操作\n");
		}
	}
	else
		{
			printf("两次学号输入不相等，已取消该删除操作\n");
			anykey_continue();
		}
}

void seek_t(void)
{
	for(;;)
	{
		switch(menu_s2())
		{
			case '1':	seekid_t();			break;
			case '2':	seekname_t();	break;
			case '3':	return;
		}
	}
}

void seekid_t(void)
{
	char stu_num2[9];
	printf("请输入要查找的学生的学号：");
	scanf("%8s",stu_num2);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	Student* st1 = getstudentById(stu_num2);
	if(NULL == st1)
	{
		printf("未查询到该学生，请检查学号是否正确！");
	}
	else
	{
		printf("语文：%.1f\n数学：%.1f\n英语：%.1f\n姓名：%s\n性别：%c\n学号%s\n有无锁定：%hhd\n是否在校：%hhd\n",st1->Chinese,st1->Math,st1->English,st1->name_s,st1->sex_s,st1->stu_num,st1->lock_s,st1->flag_s);
	}
	anykey_continue();
}

void seekname_t(void)
{
	char name_s[20];
	int seek = 0;
	printf("请输入要查找的学生的姓名：");
	scanf("%s",name_s);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	for(int i=0; i<count_s; i++)
	{
		if(0 ==strcmp(all_student[i].name_s,name_s))
		{
			printf("语文：%.1f\n数学：%.1f\n英语：%.1f\n姓名：%s\n性别：%c\n学号%s\n有无锁定：%hhd\n是否在校：%hhd\n",all_student[i].Chinese,all_student[i].Math,all_student[i].English,all_student[i].name_s,all_student[i].sex_s,all_student[i].stu_num,all_student[i].lock_s,all_student[i].flag_s);
			seek = 1;
		}
	}
	if(!seek)
	{
		printf("未查询到该学生，请检查姓名是否正确！");
	}
	anykey_continue();
}

void revise_t(void)
{
	char stu_num2[9];
	char name_s[20];
	char sex_s;
	printf("请输入要修改的学生学号：");
	scanf("%8s",stu_num2);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	Student* st1 = getstudentById(stu_num2);
	printf("学号：%s\n姓名：%s\n性别：%s\n",st1->stu_num,st1->name_s,st1->sex_s == 'w'?"女":"男");
	printf("请输入修改后的学生姓名、性别：");
	scanf("%s %c",name_s,&sex_s);
	strcpy(st1->name_s,name_s);
	st1->sex_s = sex_s;
	anykey_continue();
}

void enter_t(void)
{
	for(;;)
	{
		char stu_num2[9];
		float Chinese = 0;
		float Math = 0;
		float English = 0;
		char file[500] = {};
		switch(menu_s3())
		{
			case '1':
				printf("请输入需要录入成绩的学生学号：");
				scanf("%8s",stu_num2);
				stdin->_IO_read_ptr = stdin->_IO_read_end;
				printf("请输入各科成绩：(语文、数学、英语)：");
				scanf("%f %f %f",&Chinese,&Math,&English);
				stdin->_IO_read_ptr = stdin->_IO_read_end;
				if(enter1_t(stu_num2,Chinese,Math,English))
				{
					show_sleep("成绩录入成功!\n",1.5);
				}
				break;
			case '2':
				printf("请导入学生成绩文件：");
				scanf("%s",file);
				enter2_t(file);
				break;
			case '3':	return;
		}
	}
}

bool enter1_t(char* stu_num,float Chinese,float Math,float English)
{
	Student* s = getstudentById(stu_num);
	if(NULL == s || 0 == s->flag_s)
	{
		show_sleep("学号无效，请检查!\n",1.5);
		return false;
	}
	else
	{
		s->Chinese = Chinese;
		s->Math = Math;
		s->English = English;
		return true;
	}
}

void enter2_t(const char* path)
{
	FILE* frp = fopen(path,"r");
	if(NULL == frp)
	{
		show_sleep("文件打开失败，请检查文件路径!\n",1.5);
		return;
	}
	char stu_num2[9] = {};
	float Chinese = 0;
	float Math = 0;
	float English = 0;
	while(0 < fscanf(frp,"%s %f %f %f\n",stu_num2,&Chinese,&Math,&English))
	{
		enter1_t(stu_num2,Chinese,Math,English);
	}
	fclose(frp);
	frp = NULL;
	printf("批量录入成功！");
	anykey_continue();
}

void modify_t(void)
{
	char stu_num2[9];
	char stu_num3[9];
	printf("请输入要重置密码学生的学号：");
	scanf("%8s",stu_num2);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	Student* st1 = getstudentById(stu_num2);
	if(NULL == st1 || 0 == st1->flag_s)
	{
		show_sleep("学号无效，请检查!\n",1.5);
		return;
	}
	printf("请再次输入要重置密码学生的学号：");
	scanf("%8s",stu_num3);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	if(!strcmp(stu_num2,stu_num3))
	{
		printf("学号：%s\n姓名：%s\n性别：%s\n语文：%.1f\n数学：%.1f\n英语：%.1f\n",st1->stu_num,st1->name_s,st1->sex_s == 'w'?"女":"男",st1->Chinese,st1->Math,st1->English);
		printf("请确认是否重置该学生的密码(y/n)");
		if('y' == getchar() || 'Y' == getchar())
		{
			st1->lock_s = 0;
			strcpy(st1->se_s,"123");
			printf("重置成功！\n");
			anykey_continue();
		}
		else
		{
			printf("已取消重置操作\n");
			anykey_continue();
		}
	}
	else
		{
			printf("两次学号输入不相等，已取消重置操作\n");
			anykey_continue();
		}
}

void show_t(void)
{
	int count = 0;
	printf("*****在校学生*****\n");
	printf("\n");
	for(int i=0; i<count_s; i++)
	{
		if(all_student[i].flag_s)
		{
			printf("学生%d：\n",++count);
			printf("语文：%.1f\n数学：%.1f\n英语：%.1f\n姓名：%s\n性别：%c\n学号%s\n有无锁定：%hhd\n是否在校：%hhd\n",all_student[i].Chinese,all_student[i].Math,all_student[i].English,all_student[i].name_s,all_student[i].sex_s,all_student[i].stu_num,all_student[i].lock_s,all_student[i].flag_s);
			printf("\n");
		}
	}
	printf("******************\n");
	anykey_continue();
}

void nshow_t(void)
{
	int count = 0;
	printf("*****退学学生*****\n");
	printf("\n");
	for(int i=0; i<count_s; i++)
	{
		if(!all_student[i].flag_s)
		{
			printf("学生%d：\n",++count);
			printf("语文：%.1f\n数学：%.1f\n英语：%.1f\n姓名：%s\n性别：%c\n学号%s\n有无锁定：%hhd\n是否在校：%hhd\n",all_student[i].Chinese,all_student[i].Math,all_student[i].English,all_student[i].name_s,all_student[i].sex_s,all_student[i].stu_num,all_student[i].lock_s,all_student[i].flag_s);
			printf("\n");
		}
	}
	printf("******************\n");
	anykey_continue();
}






