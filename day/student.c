#include <stdio.h>
#include <string.h>

#include "teacher.h"
#include "student.h"
#include "tools.h"

int count_s = 0;
/*
//测试
Student s[2] = {
		{20,85,40,"张三",'m',"20210001","123",0,1},
		{10,60,70,"李四",'w',"20210002","123",0,1}
};

void all_s(void)
{
	all_student = &s[0];
	count_s = 2;
}

*/

void all_s(void)
{
	all_student = malloc(sizeof(Student)*STUDENT);
	count_s = 0;
}

Student* all_student = NULL;
Student* single_student = NULL;

void student(void)
{
	single_student = malloc(sizeof(Student)*STUDENT);
	if(!lockedup_s())
	{
		return;
	}
	for(;;)
	{
		//menu_s();
		switch(menu_s())
		{
			case '1':		find_s();			break;
			case '2':		revise_s();			break;
			case '3':		show_s();			break;
			case '4':		return ;
		}
	}
}

void find_s(void)
{
	float Chinese[3] = {0,100,0},Math[3] = {0,100,0},English[3] = {0,100,0};
	int count = 0;
	int a1[count_s];
	float grade[count_s];
	for(int i=0;i<count_s;i++)
	{
		if(all_student[i].flag_s)
		{
			if(all_student[i].Chinese > Chinese[0])
			{
				Chinese[0] = all_student[i].Chinese;
			}
			if(all_student[i].Chinese < Chinese[1])
			{
				Chinese[1] = all_student[i].Chinese;
			}
			Chinese[2] += all_student[i].Chinese;
			if(all_student[i].Math > Math[0])
			{
				Math[0] = all_student[i].Math;
			}
			if(all_student[i].Math < Math[1])
			{
				Math[1] = all_student[i].Math;
			}
			Math[2] += all_student[i].Math;
			if(all_student[i].English > English[0])
			{
				English[0] = all_student[i].English;
			}
			if(all_student[i].English < English[1])
			{
				English[1] = all_student[i].English;
			}
			English[2] += all_student[i].English;
			grade[count] = all_student[i].Chinese + all_student[i].Math + all_student[i].English;
			a1[count] = i;
			count++;
		}
	}
	int a=0,b=0;
	for(a=0; a<count; a++)
	{
		for(b=a+1; b<count; b++)
		{
			if(grade[b] > grade[a])
			{
				float t1 = grade[b];
				grade[b] = grade[a];
				grade[a] = t1;
				int t2 = a1[b];
				a1[b] = a1[a];
				a1[a] = t2;
			}
		}
		printf("%.2f %.2f %.2f %.2f\n",grade[a],all_student[a1[a]].Chinese,all_student[a1[a]].Math,all_student[a1[a]].English);
	}
	printf("语文：最高分：%.2f 最低分：%.2f 平均分：%.2f\n",Chinese[0],Chinese[1],Chinese[2]/count);
	printf("数学：最高分：%.2f 最低分：%.2f 平均分：%.2f\n",Math[0],Math[1],Math[2]/count);
	printf("英语：最高分：%.2f 最低分：%.2f 平均分：%.2f\n",English[0],English[1],English[2]/count);
	anykey_continue();
}

void revise_s(void)
{
	char se_s2[7];
	printf("请输入原密码：");
	scanf("%s",se_s2);
	if(strcmp(se_s2,single_student->se_s) != 0)
	{
		show_sleep("与原密码不符合，修改失败！\n",1.5);
		return;	
	}
	printf("请输入新密码(不能为初始密码，最多六位)：");
	scanf("%s",single_student->se_s);
	while(strcmp(single_student->se_s,"123") == 0)
		{
			printf("此密码与初始密码相同，请重新输入：\n");
			scanf("%s",single_student->se_s);
		}
	show_sleep("修改密码成功\n",1.5);
}

void show_s(void)
{
	printf("学号：%s\n姓名：%s\n性别：%s\n语文：%.2f\n数学：%.2f\n英语：%.2f\n",single_student->stu_num,single_student->name_s,single_student->sex_s == 'w'?"女":"男",single_student->Chinese,single_student->Math,single_student->English);
	anykey_continue();
}

bool lockedup_s(void)
{
	char stu_num1[9]; 
	char se_s1[7];
	printf("请输入学号：");
	scanf("%8s",stu_num1);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	/*
	for(int i=0; i<count_s; i++)
	{
		printf("%f %f %f %s %c %s %s %hhd %hhd\n",all_student[i].Chinese,all_student[i].Math,all_student[i].English,all_student[i].name_s,all_student[i].sex_s,all_student[i].stu_num,all_student[i].se_s,all_student[i].lock_s,all_student[i].flag_s);
	}
	printf("%s %d\n",stu_num1,count_s);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	*/
	Student* st = getstudentById(stu_num1);
	if(NULL == st || 0 == st->flag_s)
	{
		show_sleep("学号无效，请检查!\n",1.5);
		return false;
	}
	else
	{
		int count = 0;
		if(strcmp(all_student->se_s,"123") == 0)
	{
		printf("第一次登陆需修改密码\n");
		printf("请输入新密码(不能为初始密码，最多六位)：");
		scanf("%s",st->se_s);
		while(strcmp(st->se_s,"123") == 0)
		{
			printf("此密码与初始密码相同，请重新输入：\n");
			scanf("%s",st->se_s);
		}
		show_sleep("修改密码成功\n",1.5);
	}
		if(0 == st -> lock_s)
		{
			do{
				if(0 == count)
				{
					printf("请再次输入密码：");
				}
				else
				{
					printf("密码错误，请重新输入密码(还有%d次机会):\n",3-count);
					//printf("%s\n",st->se_s);
					//printf("%s\n",se_s1);
				}
				scanf("%6s",se_s1);
				stdin->_IO_read_ptr = stdin->_IO_read_end;
			}while(count++ < 2 && 0 != strcmp(se_s1,st->se_s));
		}
		else
		{
			show_sleep("该帐号被锁定，无法登录!\n",1.5);
			return false;
		}
		if(0 == strcmp(se_s1,st->se_s))
		{
			show_sleep("登陆成功!\n",1.5);
			single_student = st;
			return true;
		}
		else
		{
			show_sleep("帐号已锁定，请联系教师解锁!\n",1.5);
			st -> lock_s = 1;
			return false;
		}
	}
	return false;
}




















