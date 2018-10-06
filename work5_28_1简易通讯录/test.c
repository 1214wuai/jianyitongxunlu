#include"link.h"
#pragma warning(disable:4996)
Contact sta;
void menu(void)
{
	printf("**************************************\n");
	printf("***********1.添加联系人***************\n");
	printf("***********2.删除指定联系人***********\n");
	printf("***********3.查找指定联系人***********\n");
	printf("***********4.修改指定联系人***********\n");
	printf("***********5.显示所有联系人***********\n");
	printf("***********6.清空所有联系人***********\n");
	printf("***********7.以名字排序所有联系人*****\n");
	printf("***********0.退出程序*****************\n");
	printf("**************************************\n");
}

void test(void)
{
	char ch;
	sta.sz = 0;
	char input = 0;
	/*inint_link(&sta);*/
	do
	{
		menu();
		printf("请输入你要进行的操作:>");
		scanf("%c", &input);
		/*printf("%d\n");
		while (1);*/
		while('\n'!=(ch=getchar()));
		if (input >= '0' && input <= '7')
		{
			switch (input-'0')
			{
			case ADD:
				Add_link(&sta);
				break;
			case DEL:
				Dele_link(&sta);
				break;
			case FIND:
				Find_link(&sta);
				break;
			case MOD:
				Mod_link(&sta);
				break;
			case SHOW:
				Show_link(&sta);
				break;
			case EMPTY:
				Empty_link(&sta);
				break;
			case SORT:
				Sort_link(&sta);
				break;
			case EXIT:
				break;
			default:
				printf("输入错误\n");
				break;
			}

		}
		else
		{
			printf("输入有误,请重新输入\n");
		}
	} while(input);
}

int main()
{
	test();
	system("pause");
	return 0;
}