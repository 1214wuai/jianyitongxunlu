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

typedef struct Contact//����һ���ܴ��30������ΪLINK���͵Ľṹ��
{
	LINK data[MAX];
	int sz;
}Contact;

//typedef struct Contact *Contact;//���ṹ��������Ϊһ���ṹ��ָ�룬����ֱ��ָ��ṹ������

//void inint_link(Contact *Ps);//��ʼ������
void Add_link(Contact *Ps);//�����ϵ��
int Dele_link(Contact *Ps);//ɾ����ϵ��
int Find_link(Contact *Ps);//Ѱ����ϵ��
int Mod_link(Contact *Ps);//��������ϵ��
int Show_link(Contact *Ps);//��ʾ������ϵ��
int Empty_link(Contact *Ps);//�����ϵ��
int Sort_link(Contact *Ps);//����

#endif //__LINK_H__