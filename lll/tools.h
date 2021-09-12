#ifndef TOOLS_H
#define TOOLS_H

#include <stdbool.h>

#include "head.h"
#include "student.h"
#include "teacher.h"

char menu(void);
char menu_h(void);
char menu_t(void);
char menu_s(void);
char menu_s1(void);
char menu_s2(void);
char menu_s3(void);
void show_sleep(const char* msg,double sec);//睡眠

Student* getstudentById(const char* id);//根据学生学号查找学生
Teacher* getteacherById(const char* id);//根据教师工号查找教师
void anykey_continue(void);//按任意键继续
bool read_m (void);//读取数据
void keep_m(void);//保存数据

#endif//TOOLS_H
