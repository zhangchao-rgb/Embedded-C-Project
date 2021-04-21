//头文件
#include "contact.h"

void InitContact(contact_struct *ps)
{
	memset(ps->data,0,sizeof(ps->data));
	ps->size = 0;	//设置通信录最初只有0个元素
}

void AddContact(contact_struct *ps)
{
	if (ps->size == MAX)
	{
		printf("通信录已满,无法增加!\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s",ps->data[ps->size].name);
		printf("请输入年龄:>");
		scanf("%d",&(ps->data[ps->size].age));
		printf("请输入性别:>");
		scanf("%s",ps->data[ps->size].sex);
		printf("请输入电话:>");
		scanf("%s",ps->data[ps->size].tele);
		printf("请输入住址:>");
		scanf("%s",ps->data[ps->size].addr);

		ps->size++;
		printf("添加成功!\n");
					
	}
}

void ShowContact(const contact_struct *ps)
{
	if (ps->size == 0)
	{
		printf("通信录为空\n");
	}
	else
	{
		int i;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","姓名","年龄","性别","电话","住址");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
	
}

static int FindByName(const contact_struct *ps,char name[MAX_NAME])
{
	int i;
	for (i = 0; i < ps->size; i++)
	{
		if(0 == strcmp(ps->data[i].name,name))
		{
			return i;
		}
	}

	return -1;	//找不到的情况
}

void DelContact(contact_struct *ps)
{
	char name[MAX_NAME];
	printf("请输入要删除人的名字:>");
	scanf("%s",name);

	//1.找人,找到返回元素下标，找不到返回-1
	int pos = FindByName(ps,name);
	if(-1 == pos)
	{
		printf("要删除的人不存在!\n");
	}
	//2.删除
	else
	{
		int j = 0;
		for (j = pos; j < ps->size-1; j++)
		{
			ps->data[j] = ps->data[j+1];
		}
		ps->size--;
		printf("删除成功!\n");
	}
	
}

void SearchContact(const contact_struct *ps)
{
	char name[MAX_NAME];
	printf("请输入要查找人的名字:>");
	scanf("%s",name);
	int pos = FindByName(ps,name);
	if(-1 == pos)
	{
		printf("要查找的人不存在!\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s","姓名","年龄","性别","电话","住址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s",
				ps->data[pos].name,
				ps->data[pos].age,
				ps->data[pos].sex,
				ps->data[pos].tele,
				ps->data[pos].addr);
	}

}

void ModifyContact(contact_struct *ps)
{
	char name[MAX_NAME];
	printf("请输入要修改人的名字:>");
	scanf("%s",name);
	int pos = FindByName(ps,name);
	if(-1 == pos)
	{
		printf("要修改的人不存在!\n");
	}
	else
	{
	
		printf("请输入名字:>");
		scanf("%s",ps->data[pos].name);
		printf("请输入年龄:>");
		scanf("%d",&(ps->data[pos].age));
		printf("请输入性别:>");
		scanf("%s",ps->data[pos].sex);
		printf("请输入电话:>");
		scanf("%s",ps->data[pos].tele);
		printf("请输入住址:>");
		scanf("%s",ps->data[pos].addr);

		printf("修改成功!\n");
		
	}

}

void SortContact(contact_struct *ps)
{
	peoInfo_struct test;
	int i,j;
	for(i=0;i<ps->size;i++)
    {
       for(j=0;j<ps->size-i-1;j++)
        {
            //if(ps->data[j].age<ps->data[j+1].age)				//根据单一数据项，对整个结构体进行排序
			if(strcmp(ps->data[j].name, ps->data[j+1].name) > 0)//根据单一数据项，对整个结构体进行排序
            {
                test=ps->data[j+1];				//结构体允许整体赋值
                ps->data[j+1]=ps->data[j];
                ps->data[j]=test;
            }
        }
    }
	
	printf("排序成功!\n");
}


