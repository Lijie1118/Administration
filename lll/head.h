#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void head(void);
bool lockedup_h(void);//密码
void modify_h1(void);//重置自己密码
void modify_h2(void);//重置教师密码
void add_h(void);//添加教师
void del_h(void);//删除教师
void show_h(void);//显示所有在职教师
void nshow_h(void);//显示所有离职教师

extern char se[13];

#endif//HEAD_H
