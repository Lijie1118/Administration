#include <stdio.h>
#include "head.h"
#include "student.h"
#include "teacher.h"
#include "tools.h"

int main(int argc,const char* argv[])
{
		all_t();
		all_s();
		if(!read_m())
		{
			printf("数据初始化失败，请检查文件！");
			return -1;
		}
	for(;;)
	{
		switch(menu())
		{
			case '1':		head();		break;
			case '2':		teacher();	break;
			case '3':		student();	break;
			case '4':		return 0;
		}
		}
	keep_m();
	return 0;
}
