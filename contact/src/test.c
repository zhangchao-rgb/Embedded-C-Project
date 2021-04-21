//头文件
#include "contact.h"

//菜单列表
void menu(void)
{
	printf("*******************************\n");
	printf("******** 1. add   2.del********\n");
	printf("******** 3.search 4.modify*****\n");
	printf("******** 5.show	  6.sort*******\n");
	printf("******** 0.exit         *******\n");
	printf("*******************************\n");

}

int main(int argc,char *argv[])
{
	int input;
	//创建通信录
	contact_struct con;	//con就是通信录，里面包含1000个元素
	//初始化通信录
	InitContact(&con);

	while(1)
	{
		menu();
		printf("请选择:>");
		scanf("%d",&input);
		switch (input)
		{
			case ADD:
				AddContact(&con);
				break;
			case DEL:
				DelContact(&con);
				break;	
			case SEARCH:
				SearchContact(&con);
				break;
			case MODIFY:
				ModifyContact(&con);
				break;
			case SHOW:
				ShowContact(&con);
				break;
			case SORT:
				SortContact(&con);
				break;
			case EXIT:
				printf("退出通信录!\n");
				return -1;
			default:
				printf("选择错误!\n");
				break;						
		}
	
	}
	
/*
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d",&input);
		switch (input)
		{
			case ADD:
				AddContact(&con);
				break;
			case DEL:
				DelContact(&con);
				break;	
			case SEARCH:
				SearchContact(&con);
				break;
			case MODIFY:
				ModifyContact(&con);
				break;
			case SHOW:
				ShowContact(&con);
				break;
			case SORT:
				SortContact(&con);
				break;
			case EXIT:
				printf("退出通信录!\n");
				break;
			default:
				printf("选择错误!\n");
				break;						
		}
	
	}
	while (input);
*/	
	return 0;
}


