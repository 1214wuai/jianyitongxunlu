#ifndef __LINK_H__
#define __LINK_H__
#pragma warning (disable:4996)

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

#define MAX 30

enum op
{
	EXIT,
	ADD,
	DEL,
	FIND,
	MOD,
	SHOW,
	EMPTY,
	SORT
};

typedef struct LINK
{
	char name[20];
	char sex[5];
	int age;
	int tel[12];
	char addr[50];
}LINK;

typedef struct Contact//定义一个能存放30个类型为LINK类型的结构体
{
	LINK data[MAX];
	int sz;
}Contact;

//typedef struct Contact *Contact;//将结构体重命名为一个结构体指针，用来直接指向结构体内容

//void inint_link(Contact *Ps);//初始化数组
void Add_link(Contact *Ps);//添加联系人
int Dele_link(Contact *Ps);//删除联系人
int Find_link(Contact *Ps);//寻找联系人
int Mod_link(Contact *Ps);//重命名联系人
int Show_link(Contact *Ps);//显示所有联系人
int Empty_link(Contact *Ps);//清空联系人
int Sort_link(Contact *Ps);//排序

#endif //__LINK_H__