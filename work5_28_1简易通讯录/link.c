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

void menu1()//�޸���ϵ��ʱ���õ��Ĳ˵�
{
	printf("*********************\n");
	printf("****1.����*2.�Ա�****\n");
	printf("****3.����*4.�绰****\n");
	printf("****5.��ַ*0.����****\n");
	printf("*********************\n");
}

int Find_link(Contact *Ps)//������ϵ��
{
	if (Ps->sz == 0)
	{
		printf("��ϵ�˱��Ϊ��\n");
		return 0;
	}
	int i = 0;
	printf("������Ҫ���ҵ���ϵ������:>\n");
	char name[20] = { 0 };
	scanf("%s", name);
	int ret = Find(Ps, name);
	if (ret != -1)
	{
		printf("������%s\n", Ps->data[ret].name);
		printf("�Ա�%s\n", Ps->data[ret].sex);
		printf("���䣺%d\n", Ps->data[ret].age);
		printf("�绰��%s\n", Ps->data[ret].tel);
		printf("��ַ��%s\n", Ps->data[ret].addr);
	}
	else
	{
		printf("��Ҫ���ҵ��˲�����\n");
	}
	return -1;
}

void Add_link(Contact *Ps)//�����ϵ��
{
	if (Ps->sz == MAX)
	{
		printf("ͨѶ¼����\n");
		//return -1;
	}
	else
	{
		printf("����������:>");
		scanf_s("%s", Ps->data[Ps->sz].name,sizeof(Ps->data[Ps->sz].name));
		printf("�������Ա�:>");
		scanf_s("%s", Ps->data[Ps->sz].sex,sizeof(Ps->data[Ps->sz].sex));
		printf("����������:>");
		scanf_s("%d", &(Ps->data[Ps->sz].age), sizeof(Ps->data[Ps->sz].age));
		printf("������绰:>");
		scanf_s("%s", Ps->data[Ps->sz].tel, sizeof(Ps->data[Ps->sz].tel));
		printf("�������ַ:>");
		scanf_s("%s", Ps->data[Ps->sz].addr, sizeof(Ps->data[Ps->sz].addr));
		Ps->sz ++;
		//return 0;
	}
}

int Dele_link(Contact *Ps)//ɾ����ϵ��
{
	int i = 0;
	int ret = 0;
	if (Ps->sz == 0)
	{
		printf("��ϵ�˱��Ϊ��\n");
		return 0;
	}
	char name[20] = { 0 };
	printf("��������Ҫɾ������ϵ����������:>\n");
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
		printf("û��Ҫɾ������ϵ��\n");
		return -1;
	}
}

int Mod_link(Contact *Ps)//�޸���ϵ����Ϣ
{
	if (Ps->sz == 0)
	{
		printf("��ϵ�˱��Ϊ��\n");
		return 0;
	}
	char name[20] = { 0 };
	int result = 0;
	printf("��������Ҫ�޸���ϵ�˵�������\n");
	scanf("%s", name);
	result = Find(Ps, name);
	if (result != -1)
	{
		printf("������%s\n", Ps->data[result].name);
		printf("�Ա�%s\n", Ps->data[result].sex);
		printf("���䣺%d\n", Ps->data[result].age);
		printf("�绰��%s\n", Ps->data[result].tel);
		printf("��ַ��%s\n", Ps->data[result].addr);
		int i = 0;
		do
		{
			menu1();
			printf("������Ҫ�޸ĵ�ѡ�\n");
			scanf("%d", &i);
			switch (i)
			{
			case 1:
				printf("��������޸ĳɣ�");
				scanf("%s", Ps->data[result].name);
				break;
			case 2:
				printf("����Ա��޸ĳɣ�");
				scanf("%s", Ps->data[result].sex);
				break;
			case 3:
				printf("��������޸ĳɣ�");
				scanf("%d", &(Ps->data[result].age));
				break;
			case 4:
				printf("��ѵ绰�޸ĳɣ�");
				scanf("%s", Ps->data[result].tel);
				break;
			case 5:
				printf("��ѵ�ַ�޸ĳɣ�");
				scanf("%s", Ps->data[result].addr);
				break;
			case 0:
				break;
			default:
				printf("�������");
				break;
			}
		} while (i);
	}
	else
	{
		printf("��Ҫ�޸ĵ���ϵ�˲�����\n");
	}
}

int Show_link(Contact *Ps)//��ͷ��β��ʾͨѶ¼
{
	if (Ps->sz == 0)
	{
		printf("��ϵ�˱��Ϊ��\n");
		return 0;
	}
	int i = 0;
	printf("%10s%7s%6s%10s%10s\n", "����", "�Ա�", "����", "�绰", "סַ");
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

int Empty_link(Contact *Ps)//���ͨѶ¼
{
	Ps->sz = 0;
	return 0;
}

int Sort_link(Contact *Ps)//����������ͨѶ¼
{
	int tmp = 0;
	int ret = 0;
	int i = 0;
	int j = 0;
	LINK swp;
	if (Ps->sz == 0)
	{
		printf("��ϵ���б�Ϊ��\n");
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