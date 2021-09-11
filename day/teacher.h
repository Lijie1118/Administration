#ifndef TEACHER_H
#define TEACHER_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TEACHER 1000

void teacher(void);
void all_t(void);
bool lockedup_t(void);//密码

void add_t(void);//添加学生
bool single(const char* name,const char sex);//单个添加学生
void usingle(const char* path);//批量导入学生
void del_t(void);//删除学生，为退学
void seek_t(void);//查找学生
void seekid_t(void);//根据学号查找学生
void seekname_t(void);//根据姓名查找学生
void revise_t(void);//修改学生信息
void enter_t(void);//录入学生成绩
bool enter1_t(char* stu_num,float Chinese,float Math,float English);//录入单个学生成绩
void enter2_t(const char* path);//批量录入学生成绩
void modify_t(void);//重置学生密码
void show_t(void);//显示在校学生信息
void nshow_t(void);//显示退学学生信息

typedef struct Teacher
{
	char w_t[5];//教师工号
	char name_t[20];//名字
	char sex_t;//性别 男：'m',女：'w'
	char se_t[13];//教师密码
	char lock_t;//1为锁定，0为不锁定
	char flag_t;//表示是否在职，1为在职0为离职
}Teacher;

extern int count_t;//教师人数
extern Teacher* all_teacher;//教师总信息
extern Teacher* single_teacher;//当前登录教师

#endif//TEACHER_H
