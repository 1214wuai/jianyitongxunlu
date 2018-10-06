#include"link.h"

void inint_link(Contact *Ps)
{
	//Ps->name[20] = { 0 };
	/*memset(Ps->data[MAX].name, 0, sizeof(Ps->data[MAX].name));
	memset(Ps->data[MAX].sex, 0, sizeof(Ps->data[MAX].sex));
	Ps->data[MAX].age = 0;
	memset(Ps->data[MAX].tel, 0, sizeof(Ps->data[MAX].tel));
	memset(Ps->data[MAX].addr, 0, sizeof(Ps->data[MAX].addr));
	int sz = sizeof(Ps->data);
	Ps->sz = 0;*/
}
int Find(Contact *Ps, char *name)
{
	int i = 0;
	for (i = 0; i < (Ps->sz); i++)
	{
		if (strcmp(Ps->data[i].name, name) == 0)
		{
			//printf("%s", Ps->data[i].name);
			return i;
		}
	}
	return -1;
}

void menu1()//修改联系人时所用到的菜单
{
	printf("*********************\n");
	printf("****1.姓名*2.性别****\n");
	printf("****3.年龄*4.电话****\n");
	printf("****5.地址*0.返回****\n");
	printf("*********************\n");
}

int Find_link(Contact *Ps)//查找联系人
{
	if (Ps->sz == 0)
	{
		printf("联系人表格为空\n");
		return 0;
	}
	int i = 0;
	printf("请输入要查找的联系人名字:>\n");
	char name[20] = { 0 };
	scanf("%s", name);
	int ret = Find(Ps, name);
	if (ret != -1)
	{
		printf("姓名：%s\n", Ps->data[ret].name);
		printf("性别：%s\n", Ps->data[ret].sex);
		printf("年龄：%d\n", Ps->data[ret].age);
		printf("电话：%s\n", Ps->data[ret].tel);
		printf("地址：%s\n", Ps->data[ret].addr);
	}
	else
	{
		printf("你要查找的人不存在\n");
	}
	return -1;
}

void Add_link(Contact *Ps)//添加联系人
{
	if (Ps->sz == MAX)
	{
		printf("通讯录已满\n");
		//return -1;
	}
	else
	{
		printf("请输入姓名:>");
		scanf_s("%s", Ps->data[Ps->sz].name,sizeof(Ps->data[Ps->sz].name));
		printf("请输入性别:>");
		scanf_s("%s", Ps->data[Ps->sz].sex,sizeof(Ps->data[Ps->sz].sex));
		printf("请输入年龄:>");
		scanf_s("%d", &(Ps->data[Ps->sz].age), sizeof(Ps->data[Ps->sz].age));
		printf("请输入电话:>");
		scanf_s("%s", Ps->data[Ps->sz].tel, sizeof(Ps->data[Ps->sz].tel));
		printf("请输入地址:>");
		scanf_s("%s", Ps->data[Ps->sz].addr, sizeof(Ps->data[Ps->sz].addr));
		Ps->sz ++;
		//return 0;
	}
}

int Dele_link(Contact *Ps)//删除联系人
{
	int i = 0;
	int ret = 0;
	if (Ps->sz == 0)
	{
		printf("联系人表格为空\n");
		return 0;
	}
	char name[20] = { 0 };
	printf("请输入需要删除的联系人名字名字:>\n");
	scanf("%s", name);
	ret = Find(Ps,name);
	if (ret != -1)
	{
		for (i = ret; i < Ps->sz; i++)
		{
			Ps->data[i] = Ps->data[i + 1];
			Ps->sz++;
		}
		return 1;
	}
	else
	{
		printf("没有要删除的联系人\n");
		return -1;
	}
}

int Mod_link(Contact *Ps)//修改联系人信息
{
	if (Ps->sz == 0)
	{
		printf("联系人表格为空\n");
		return 0;
	}
	char name[20] = { 0 };
	int result = 0;
	printf("请输入你要修改联系人的姓名：\n");
	scanf("%s", name);
	result = Find(Ps, name);
	if (result != -1)
	{
		printf("姓名：%s\n", Ps->data[result].name);
		printf("性别：%s\n", Ps->data[result].sex);
		printf("年龄：%d\n", Ps->data[result].age);
		printf("电话：%s\n", Ps->data[result].tel);
		printf("地址：%s\n", Ps->data[result].addr);
		int i = 0;
		do
		{
			menu1();
			printf("输入你要修改的选项：\n");
			scanf("%d", &i);
			switch (i)
			{
			case 1:
				printf("请把姓名修改成：");
				scanf("%s", Ps->data[result].name);
				break;
			case 2:
				printf("请把性别修改成：");
				scanf("%s", Ps->data[result].sex);
				break;
			case 3:
				printf("请把年龄修改成：");
				scanf("%d", &(Ps->data[result].age));
				break;
			case 4:
				printf("请把电话修改成：");
				scanf("%s", Ps->data[result].tel);
				break;
			case 5:
				printf("请把地址修改成：");
				scanf("%s", Ps->data[result].addr);
				break;
			case 0:
				break;
			default:
				printf("输入错误");
				break;
			}
		} while (i);
	}
	else
	{
		printf("你要修改的联系人不存在\n");
	}
}

int Show_link(Contact *Ps)//从头到尾显示通讯录
{
	if (Ps->sz == 0)
	{
		printf("联系人表格为空\n");
		return 0;
	}
	int i = 0;
	printf("%10s%7s%6s%10s%10s\n", "名字", "性别", "年龄", "电话", "住址");
	printf("\n");
	for (i = 0; i < Ps->sz; i++)
	{
		printf("%10s", Ps->data[i].name);
		printf("%7s", Ps->data[i].sex);
		printf("%5d", Ps->data[i].age);
		printf("%15s", Ps->data[i].tel);
		printf("%10s", Ps->data[i].addr);
		printf("\n");
	}
	printf("\n");
	return 0;
}

int Empty_link(Contact *Ps)//清空通讯录
{
	Ps->sz = 0;
	return 0;
}

int Sort_link(Contact *Ps)//按名字排序通讯录
{
	int tmp = 0;
	int ret = 0;
	int i = 0;
	int j = 0;
	LINK swp;
	if (Ps->sz == 0)
	{
		printf("联系人列表为空\n");
		return 0;
	}
	for (i = 0; i < Ps->sz - 1; i++)
	{
		for (j = 0; j < Ps->sz - i - 1; j++)
		{
			if (strcmp(Ps->data[j].name, Ps->data[j + 1].name) > 0)
			{
				swp = Ps->data[j];
				Ps->data[j] = Ps->data[j + 1];
				Ps->data[j + 1] = swp;
			}
		}
	}
	tmp = Show_link(Ps);
	return 0;
}