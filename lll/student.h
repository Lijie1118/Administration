#ifndef STUDENT_H
#define STUDENT_H
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void student(void);
void all_s(void);
bool lockedup_s(void);//密码

void find_s(void);	//查询成绩
void revise_s(void);	//修改密码
void show_s(void);	//查看个人信息

#define STUDENT 1000

typedef struct Student
{
	float Chinese;//语文成绩
	float Math;//数学成绩
	float English;//英语成绩
	char name_s[20];//名字
	char sex_s;//性别 男：'m',女：'w'
	char stu_num[9];//学号
	char se_s[7];//学生密码
	char lock_s;//1为锁定，0为不锁定
	char flag_s;//表示是否在校，1为在校，0为退学
}Student;

extern int count_s ;//学生人数
extern Student* all_student;//学生总信息
extern Student* single_student;//当前登录学生

#endif//STUDENT_H




