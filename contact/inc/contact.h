#ifndef _CONTACT__H_
#define _CONTACT__H_

#include <stdio.h>
#include <string.h>

//常量定义
#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX  5
#define MAX_TELE 12
#define MAX_ADDR 30

//枚举定义
typedef enum
{
	EXIT = 0,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
}option;

//人的信息
typedef struct
{
	char name[MAX_NAME];		///< 姓名
	int  age;					///< 年龄
	char sex[MAX_SEX];			///< 性别
	char tele[MAX_TELE];		///< 电话
	char addr[MAX_ADDR];		///< 住址
}peoInfo_struct;

//通信录类型
typedef struct
{
	peoInfo_struct data[MAX];	//存放1000个人的信息
	int size;					//记录当前已经有的元素个数
}contact_struct;

//函数声明
void InitContact(contact_struct *ps);				///< 初始化
void AddContact(contact_struct *ps);				///< 添加
void ShowContact(const contact_struct *ps);			///< 显示
void DelContact(contact_struct *ps);				///< 删除
void SearchContact(const contact_struct *ps);		///< 查找
void ModifyContact(contact_struct *ps);				///< 修改
void SortContact(contact_struct *ps);				///< 排序

#endif

