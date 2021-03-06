#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "head.h"
#include "tools.h"
#include "teacher.h"

char se[13];

void head(void)
{
	if(!lockedup_h())
	{
		return;
	}
	for(;;)
	{
		switch(menu_h())
		{
			case '1':		modify_h1();			break;
			case '2':		modify_h2();			break;
			case '3':		add_h();				break;
			case '4':		del_h();				break;
			case '5':		show_h();			break;
			case '6':		nshow_h();			break;
			case '7':		return;
		}
	}
}

bool lockedup_h(void)
{
	char se1[7] = {};
	printf("请输入初始密码：");
	for(int i=0;i<3;i++)
	{
		scanf("%6s",se1);
		stdin->_IO_read_ptr = stdin->_IO_read_end;
		if(!strcmp(se1,se))
		{
			printf("登录成功！\n");
			if(!strcmp(se,"123"))
			{
				modify_h1();
			}
			return true;
		}
		else if(i == 2)
		{
			show_sleep("请稍后重试！\n",1.5);
		}
		else
		{
			show_sleep("密码错误，请输入密码：",1.5);
		}
	}
	return false;
}

void modify_h1(void)
{
	char se1[7] = {}; 
	printf("请输入密码：");
	scanf("%s",se1);
	if(strcmp(se,se1) != 0)
	{
		show_sleep("与原密码不符合，修改失败！\n",1.5);
		return;	
	}
	printf("请输入新密码：");
	scanf("%s",se1);
	if(!strcmp(se,se1))
	{
		show_sleep("与初始密码相同，修改失败！\n",1.5);
		return;
	}
	strcpy(se,se1);
	show_sleep("修改密码成功\n",1.5);
}

void modify_h2(void)
{
	char w_t[9] = {};
	char w_t1[9] = {};
	printf("请输入要重置密码教师的工号：");
	scanf("%4s",w_t);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	Teacher* te = getteacherById(w_t);
	if(NULL == te || 0 == te->flag_t)
	{
		show_sleep("此教师工号无效，请检查!\n",1.5);
		return;
	}
	printf("请再次输入要重置密码教师的工号：");
	scanf("%4s",w_t1);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	if(!strcmp(w_t,w_t1))
	{
		printf("工号：%s\n姓名：%s\n性别：%s\n有无锁定：%hhd\n是否在职：%hhd\n",te->w_t,te->name_t,te->sex_t == 'w'?"女":"男",te->lock_t,te->flag_t);
		printf("请确认是否重置该教师的密码(y/n)");
		if('y' == getchar() || 'Y' == getchar())
		{
			te->lock_t = 0;
			strcpy(te->se_t,"123");
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
			printf("两次工号输入不相等，已取消重置操作\n");
			anykey_continue();
		}
}

void add_h(void)
{
	if(TEACHER <=count_t)
	{
		show_sleep("系统维护中，暂时无法添加...\n",1.5);
		return;
	}
	printf("请输入教师的姓名、性别：");
	scanf("%s %c",all_teacher[count_t].name_t,&all_teacher[count_t].sex_t);
	sprintf(all_teacher[count_t].w_t,"%04d",count_t+1);
	strcpy(all_teacher[count_t].se_t,"123");
	all_teacher[count_t].lock_t = 0;
	all_teacher[count_t].flag_t = 1;
	count_t++;
	//printf("%d",count_t);
	show_sleep("添加教师成功\n",1.5);
}

void del_h(void)
{
	char w_t[9] = {};
	char w_t1[9] = {};
	printf("请输入要删除的教师的工号：");
	scanf("%4s",w_t);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	Teacher* te = getteacherById(w_t);
	if(NULL == te || 0 == te->flag_t)
	{
		show_sleep("此教师工号无效，请检查!\n",1.5);
		return;
	}
	printf("请再次输入要删除的教师的工号：");
	scanf("%4s",w_t1);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	if(!strcmp(w_t,w_t1))
	{
		printf("工号：%s\n姓名：%s\n性别：%s\n有无锁定：%hhd\n是否在职：%hhd\n",te->w_t,te->name_t,te->sex_t == 'w'?"女":"男",te->lock_t,te->flag_t);
		printf("请确认是否删除该教师(y/n)");
		if('y' == getchar() || 'Y' == getchar())
		{
			te->flag_t = 0;
			printf("删除成功！\n");
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
			printf("两次工号输入不相等，已取消删除操作\n");
			anykey_continue();
		}
}

void show_h(void)
{
	int count = 0;
	printf("*****在职教师*****\n");
	printf("\n");
	for(int i=0; i<count_t; i++)
	{
		if(all_teacher[i].flag_t)
		{
			printf("教师%d：\n",++count);
			printf("工号：%s\n姓名：%s\n性别：%s\n有无锁定：%hhd\n是否在职：%hhd\n",all_teacher[i].w_t,all_teacher[i].name_t,all_teacher[i].sex_t == 'w'?"女":"男",all_teacher[i].lock_t,all_teacher[i].flag_t);
			printf("\n");
		}
	}
	printf("******************\n");
	anykey_continue();
}

void nshow_h(void)
{
	int count = 0;
	printf("*****离职教师*****\n");
	printf("\n");
	for(int i=0; i<count_t; i++)
	{
		if(!all_teacher[i].flag_t)
		{
			printf("教师%d：\n",++count);
			printf("工号：%s\n姓名：%s\n性别：%s\n有无锁定：%hhd\n是否在职：%hhd\n",all_teacher[i].w_t,all_teacher[i].name_t,all_teacher[i].sex_t == 'w'?"女":"男",all_teacher[i].lock_t,all_teacher[i].flag_t);
			printf("\n");
		}
	}
	printf("******************\n");
	anykey_continue();
}




