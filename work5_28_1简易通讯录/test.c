#include"link.h"
#pragma warning(disable:4996)
Contact sta;
void menu(void)
{
	printf("**************************************\n");
	printf("***********1.�����ϵ��***************\n");
	printf("***********2.ɾ��ָ����ϵ��***********\n");
	printf("***********3.����ָ����ϵ��***********\n");
	printf("***********4.�޸�ָ����ϵ��***********\n");
	printf("***********5.��ʾ������ϵ��***********\n");
	printf("***********6.���������ϵ��***********\n");
	printf("***********7.����������������ϵ��*****\n");
	printf("***********0.�˳�����*****************\n");
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
		printf("��������Ҫ���еĲ���:>");
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
				printf("�������\n");
				break;
			}

		}
		else
		{
			printf("��������,����������\n");
		}
	} while(input);
}

int main()
{
	test();
	system("pause");
	return 0;
}