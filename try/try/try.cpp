#include<stdio.h>
#include<windows.h>
#include<iostream> 
#include<cstring> 
#include<cstdio> 
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define framex 5 //不贪吃的蛇 
#define framey 5
#define wide 20
#define high 20


#define LING	1E-6  //24点计算 
#define CONT	4
#define VOLUE	24


using namespace std;

//////////////////////////////////////////////

float number[CONT];
char expression[CONT][20];
bool m_judge = false; //判断是否有解。
int count = 0;



void Find(int n)
{
	int i = 0, j = 0;

	if (n == 1)
	{
		if (fabs(number[0] - 24) <= LING)
		{
			for (i = 0; i < 20; i++)
			{
				printf("%c", expression[0][i]);
			}
			printf("\t\t");
			m_judge = true;
			count++;
			if ((count % 2) == 0) //使输出时每行三个表达式
				printf("\n");
		}
		else
		{
		}
	}
	for (i = 0; i < n; i++)	//查找
	{
		for (j = i + 1; j < n; j++)	//与其后面的查找进行计算
		{
			float a, b;
			char expressiona[20], expressionb[20];
			a = number[i];
			b = number[j];
			number[j] = number[n - 1];

			strcpy(expressiona, expression[i]);
			strcpy(expressionb, expression[j]);
			strcpy(expression[j], expression[n - 1]);
			sprintf(expression[i], "(%s+%s)", expressiona, expressionb);
			number[i] = a + b;
			Find(n - 1);
			///////////////////////////////////
			sprintf(expression[i], "(%s-%s)", expressiona, expressionb);
			number[i] = a - b;
			Find(n - 1);
			sprintf(expression[i], "(%s-%s)", expressionb, expressiona);
			number[i] = b - a;
			Find(n - 1);
			sprintf(expression[i], "(%s*%s)", expressiona, expressionb);
			number[i] = a * b;
			Find(n - 1);
			if (b != 0)
			{
				sprintf(expression[i], "(%s/%s)", expressiona, expressionb);
				number[i] = a / b;
				Find(n - 1);
			}
			if (a != 0)
			{
				sprintf(expression[i], "(%s/%s)", expressionb, expressiona);
				number[i] = b / a;
				Find(n - 1);
			}
			number[i] = a;	// 最后一层的Find(2)调用完成后将a重新赋值给number[i]即number[0]
			number[j] = b;	// 最后一层的Find(2)调用完成后将b重新赋值给nubmer[j]即number[1]
			strcpy(expression[i], expressiona);
			strcpy(expression[j], expressionb);
		}
	}
}





//////////////////////////////////////////////////////////////////////////24点计算 





int ds = 1;//单人游戏或双人游戏选择 
int i, j;
float z = 0;//新手关分数 
int sudu = 0;//手速关 
int zb[200][200];//地图边界 
int sl = 0;//顺利条件 
int dt = 1;//地图选择 
char c1; int c2; int c3;
long long mm = 0;//开发模式密码 
int sfkf = 0;//是否进入开发模式 
int kfxz = 1;//开发模式的地图选择 
int sw = 0;//禁止死亡 
int fh = 0;//是否复活 
int dl[200][200];//地图内空间 
int pf = 2;//皮肤 
float yf = 0;//原来的分数
int yf1 = 896;//原来的分数
int yf2 = 640;//原来的分数
int yf3 = 384;//原来的分数
int yf4 = 0;//原来的分数
int tc = 0;//退出程序 
int zg[200][200];//自动走路走过的路 
int zd = 0;//是否从第一节点开始游戏
long int dyjd;//不同地图的第一节点 
int fhs = 100;//复活时用  
int sd = 0;//蛇的初速度
int tz = 0;//改变蛇的初速度 
int nd = 2;//难度 
int xs = 5;//显示速度 
int fw = 1;//玩家服务
int qk = 0;//是否清空游戏纪录
int zs = 0; int zsfz = 0;//迷宫关补丁 
int a = 29; int b = 4;//迷宫关节点复活
int bushu = 0;//迷宫关分数 
int ms = 0;//娱乐模式选择 
int yx = 1;//控制隐形时间 
int tg = 0;//查看地图跳过选择 
int dj = 1;//等级 
int fhcs = 0;//复活次数 



int ys1 = 0;
int ys2 = 0;
int qk2 = 0;
int sw1 = 0;
int fh1 = 0;
int sd1 = 0;
int sd2 = 0;
int sd3 = 0;


void gotoxy(HANDLE hout, int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hout, pos);
}//坐标定位函数 




//游戏封面
void cover(HANDLE hout) {
	system("cls");
	gotoxy(hout, framex + wide, framey - 5);
	printf("          不贪吃的蛇");
	gotoxy(hout, framex + 20, framey + 3);
	printf("用键盘输入任意数后按回车键继续......\n");
	gotoxy(hout, framex + 20, framey + 7);
	printf("切记：本程序要且仅要输入阿拉伯数字\n");
	gotoxy(hout, framex + 23, framey + 11);
	printf("详细规则请选择玩家服务查看\n");
	gotoxy(hout, framex + 30, framey + 18);
	printf("张梓浩版权所有\n");
	int a;
	scanf("%d", &a);
	system("cls");
}



void welcome(HANDLE hout) {
hyjm:system("cls");
	gotoxy(hout, framex + wide, framey + 1);
	printf("        欢迎玩此游戏");
	gotoxy(hout, framex + wide, framey + 4);
	printf("        1、单人游戏");
	gotoxy(hout, framex + wide, framey + 7);
	printf("        2、双人游戏\n\n\n\n\n\n\n\n\n");
	scanf("%d", &c2);
	switch (c2) {
	case 1:ds = 1;
		break;
	case 2:ds = 2;
		break;
	default:printf("输入错误，请重新选择\n\n");
		Sleep(1000);
		goto hyjm;
		break;
	}
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////





//定义蛇的结构体 
struct  Snake {
	int x[100];
	int y[100];
	int speed;
	int length;
};




//初始化蛇 
void initsnake(struct Snake* snake) {
	snake->x[0] = framex - 7;
	snake->y[0] = framey - 2;//蛇的初始坐标 
	snake->length = 10;
	snake->speed = 400;//蛇的参数 
	for (i = 1; i < snake->length; i++) {
		snake->x[i] = snake->x[i - 1] + 1;
		snake->y[i] = snake->y[i - 1];
	}
}





//打印蛇 
void printsnake(HANDLE hout, struct Snake* snake) {
	for (i = 0; i < snake->length; i++) {
		gotoxy(hout, snake->x[i], snake->y[i]);
		if (i == snake->length - 1)
			switch (pf) {
			case 1:printf("!"); break;
			case 2:printf("#"); break;
			case 3:printf("@"); break;
			case 4:printf("$"); break;
			case 5:printf("^"); break;
			case 6:printf("-"); break;
			case 7:printf("+"); break;
			case 8:printf("="); break;
			case 9:printf(","); break;
			case 10:printf(":"); break;
			}

	}
}





//移动蛇 
void movesnake(HANDLE hout, struct Snake* snake) {
	gotoxy(hout, snake->x[0], snake->y[0]);
	printf("  ");
	for (i = 1; i < snake->length; i++) {
		snake->x[i - 1] = snake->x[i];
		snake->y[i - 1] = snake->y[i];
	}
}





//主菜单 
void menu(HANDLE hout, struct Snake* snake) {
cd:system("cls");
	gotoxy(hout, framex + wide + 30, framey + 2);
	printf("        当前等级:%d级", dj);
	gotoxy(hout, framex + wide, framey + 3);
	printf("            主菜单");
	gotoxy(hout, framex + wide, framey + 6);
	printf("        1、经典模式");
	gotoxy(hout, framex + wide, framey + 9);
	printf("        2、娱乐模式");
	gotoxy(hout, framex + wide, framey + 12);
	printf("        3、玩家服务");
	gotoxy(hout, framex + wide, framey + 15);
	printf("        4、地图查看");
	gotoxy(hout, framex + wide, framey + 18);
	printf("        5、后台设置");
	gotoxy(hout, framex + wide, framey + 21);
	printf("        6、退出游戏\n\n\n\n\n");
	scanf("%d", &c1);
	switch (c1) {
	case 1:ksyx:
	system("cls");
	printf("                                   请选择地图\n\n\n\n\n\n");
	printf("                              1、新手关(1级解锁)\n\n");
	printf("                              2、手速关(7级解锁)\n\n");
	printf("                              3、迷宫关(3级解锁)\n\n\n\n\n\n\n\n\n\n\n\n");
	scanf("%d", &dt);
	if (dt != 1 && dt != 2 && dt != 3) {
		printf("输入错误，请重新选择\n\n");
		dt = 1;
		Sleep(1000);
		goto cd;
	}
	if (dt == 2) {
		if (dj < 7) {
			printf("等级不足，请重新选择\n\n");
			dt = 1;
			Sleep(1000);
			goto cd;
		}
	}
	if (dt == 3) {
		if (dj < 3) {
			printf("等级不足，请重新选择\n\n");
			dt = 1;
			Sleep(1000);
			goto cd;
		}
	}
	kfxz = dt;




	if (tg == 1) {
		goto xztg;
	}



sm:
	system("cls");
	printf("                                   请选择难度\n\n\n\n\n\n");
	printf("                               1、简单(通关升1级)\n\n");
	printf("                               2、普通(通关升2级)\n\n");
	printf("                               3、困难(通关升3级)\n\n\n\n\n\n\n\n\n\n\n\n");
	scanf("%d", &nd);
	if (nd != 1 && nd != 2 && nd != 3) {
		printf("输入错误，请重新选择\n\n");
		nd = 1;
		Sleep(1000);
		goto sm;
	}



fz:
	system("cls");
	printf("                                 请选择辅助技能\n\n\n\n\n\n");
	printf("                                  1、开始游戏\n\n");
	printf("                                  2、选择角色\n\n");
	printf("                                  3、节点开始\n\n");
	printf("                                  4、开启护盾\n\n\n\n\n\n\n\n\n");
	scanf("%d", &c2);
	switch (c2) {
	case 1:
		break;
	case 2:system("cls");
		printf("                                请选择你喜欢的角色\n\n\n\n\n");
		printf("1、!!!!!!!!!!!!!!!!\n\n");
		printf("2、################\n\n");
		printf("3、@@@@@@@@@@@@@@@@\n\n");
		printf("4、$$$$$$$$$$$$$$$$\n\n");
		printf("5、^^^^^^^^^^^^^^^^\n\n");
		printf("6、----------------\n\n");
		printf("7、++++++++++++++++\n\n");
		printf("8、================\n\n");
		printf("9、''''''''''''''''\n\n");
		printf("10、::::::::::::::::\n");
		scanf("%d", &pf);
		if (pf != 1 && pf != 2 && pf != 3 && pf != 4 && pf != 5 && pf != 6 && pf != 7 && pf != 8 && pf != 9 && pf != 10) {
			printf("输入错误，请重新选择\n\n");
			Sleep(1000);
			goto fz;
		}
		goto fz;
		break;
	case 3:
		if (dt != 3) {
			zd = 1;
		}
		if (dt == 3) {
			zd = 2;
		}
		goto fz;
		break;
	case 4:
		fh = 1;
		goto fz;
		break;
	default:
		printf("输入错误，请重新选择\n\n");
		Sleep(1000);
		goto fz;
		break;
	}

xztg:
	break;
	case 4:system("cls");
		sfkf = 1;
		tg = 1;
		goto ksyx;
		break;
	case 5:system("cls");
		printf("               后台设置属于开外挂，为了您的正常游戏，最好不要设置\n\n\n");
		printf("                               请选择设置的内容\n\n");
		printf("                                 1、禁止死亡\n\n");
		printf("                              2、更改蛇的初速度\n\n");
		printf("                              3、死亡后任意复活\n\n");
		printf("                              4、在任意节点开始\n\n");
		printf("                                 5、更改等级\n\n");
		printf("                                 6、退出设置");
		printf("\n\n\n\n\n");
		scanf("%d", &c2);
		switch (c2) {
		case 1:sw = 1;
			goto cd;
			break;
		case 2:printf("                                请输入蛇的初速度\n\n");
			scanf("%d", &sd);
			sd = sd - 400;
			tz = 1;
			goto cd;
			break;
		case 3:printf("                                请输入复活的次数\n\n");
			scanf("%d", &fh);
			goto cd;
			break;
		case 4:printf("                      请输入开始的节点(不要太大，否则会出错)\n\n");
			printf("                         如果不是迷宫关，第一个数请输入0\n\n");
			scanf("%d", &a);
			scanf("%d", &dyjd);
			if (dyjd < 200) {
				fhs = 0;
			}
			else {
				b = dyjd;
				dyjd = 0;
			}
			goto cd;
			break;
		case 5:scanf("%d", &dj);
			goto cd;
			break;
		case 6:goto cd;
			break;
		default:
			printf("输入错误，请重新选择\n\n");
			Sleep(1000);
			goto cd;
		}
		break;
	case 3:xzfw:
		system("cls");
		printf("                                    请选择服务\n\n\n\n\n\n");
		printf("                                 1、清空游戏纪录\n\n");
		printf("                                  2、规则说明\n\n");
		printf("                                 3、查看游戏纪录\n\n\n\n\n\n\n\n");
		scanf("%d", &fw);
		if (fw != 1 && fw != 2 && fw != 3) {
			printf("输入错误，请重新选择\n\n");
			fw = 1;
			Sleep(1000);
			goto xzfw;
		}
		else {
			switch (fw) {
			case 1:yf = 0;
				yf1 = 896;
				yf2 = 640;
				yf3 = 384;
				yf4 = 0;
				qk = 1;
				goto cd;
				break;
			case 2:system("cls");
				printf("1、开始游戏前请关闭中文输入法\n\n");
				printf("2、请使用方向键或WSAD键控制蛇的方向\n\n");
				printf("3、蛇碰到两边的墙( * )就会死亡\n\n");
				printf("4、本程序只能用键盘操作，不能用鼠标点击\n\n");
				printf("5、本程序要且仅要输入阿拉伯数字，不能输入字母\n\n");
				printf("6、请自己看程序内的提示操作\n\n");
				printf("用键盘输入任意数后按回车键继续......\n\n");
				scanf("%d", &c3);
				goto cd;
				break;
			case 3:system("cls");
				printf("你新手关的纪录为:%1.0f\n\n", yf / 118 * 100);
				printf("你手速关简单模式的纪录为:%d\n\n", 896 - yf1);
				printf("你手速关普通模式的纪录为:%d\n\n", 640 - yf2);
				printf("你手速关困难模式的纪录为:%d\n\n", 384 - yf3);
				printf("你迷宫关的纪录为:%d\n\n", yf4);
				scanf("%d", &c1);
				goto cd;
				break;
			}
		}
		break;
	case 6:tc = 1;
		goto js;
		break;
	case 2:system("cls");
		printf("                                   请选择玩法\n\n\n\n\n\n");
		printf("                                  1、定时隐形\n\n");
		printf("                                  2、地图消失\n\n");
		printf("                                  3、屏幕黑屏\n\n");
		printf("                                  4、随蛇显示\n\n");
		printf("                                  5、极速模式\n\n");
		printf("                                  6、炫彩模式\n\n\n\n\n\n");
		scanf("%d", &ms);
		if (ms != 1 && ms != 2 && ms != 3 && ms != 4 && ms != 5 && ms != 6) {
			printf("输入错误，请重新选择\n\n");
			ms = 0;
			Sleep(1000);
			goto cd;
		}
		else if (ms == 5) {
			sd = -300;
			tz = 1;
			goto ksyx;
		}
		else {
			goto ksyx;
		}
	default:printf("输入错误，请重新选择\n");
		Sleep(1000);
		goto cd;
		break;
	}//switch
js:system("cls");
}


/////////////////////////////////////////////////////////////



//地图创建函数 
void d1(HANDLE hout, int h, int z, int c) {
	for (int q = 0; q < c; q++) {
		gotoxy(hout, h, z + q);
		printf("*");
		zb[h][z + q] = 1;
		gotoxy(hout, h + 4, z + q);
		printf("*");
		zb[h + 4][z + q] = 1;



		dl[h + 1][z + q] = 1;
		dl[h + 2][z + q] = 1;
		dl[h + 3][z + q] = 1;
	}
}//横向 
void d2(HANDLE hout, int h, int z, int c) {
	for (int w = 0; w < c; w++) {
		gotoxy(hout, h + w, z);
		printf("*");
		zb[h + w][z] = 1;
		gotoxy(hout, h + w, z + 2);
		printf("*");
		zb[h + w][z + 2] = 1;


		dl[h + w][z + 1] = 1;
	}
}//竖直 
void d3(HANDLE hout, int h, int z) {
	gotoxy(hout, h, z);
	printf("*");
	zb[h][z] = 1;
	gotoxy(hout, h, z + 1);
	printf("*");
	zb[h][z + 1] = 1;
	gotoxy(hout, h + 1, z + 1);
	printf("*");
	zb[h + 1][z + 1] = 1;
	gotoxy(hout, h + 2, z + 1);
	printf("*");
	zb[h + 2][z + 1] = 1;
	gotoxy(hout, h + 3, z + 1);
	printf("*");
	zb[h + 3][z + 1] = 1;
	gotoxy(hout, h + 4, z + 1);
	printf("*");
	zb[h + 4][z + 1] = 1;


	dl[h + 1][z] = 1;
	dl[h + 2][z] = 1;
	dl[h + 3][z] = 1;
	dl[h + 4][z] = 1;
}//拐角
void d4(HANDLE hout, int h, int z) {
	gotoxy(hout, h, z);
	printf("*");
	zb[h][z] = 1;
	gotoxy(hout, h + 1, z);
	printf("*");
	zb[h + 1][z] = 1;
	gotoxy(hout, h + 2, z);
	printf("*");
	zb[h + 2][z] = 1;
	gotoxy(hout, h + 3, z);
	printf("*");
	zb[h + 3][z] = 1;
	gotoxy(hout, h + 3, z + 1);
	printf("*");
	zb[h + 3][z + 1] = 1;
	gotoxy(hout, h + 3, z + 2);
	printf("*");
	zb[h + 3][z + 2] = 1;



	dl[h][z + 1] = 1;
	dl[h + 1][z + 1] = 1;
	dl[h + 2][z + 1] = 1;
	dl[h][z + 2] = 1;
	dl[h + 1][z + 2] = 1;
	dl[h + 2][z + 2] = 1;

}//拐角 
void d5(HANDLE hout, int h, int z) {
	gotoxy(hout, h, z);
	printf("*");
	zb[h][z] = 1;
	gotoxy(hout, h, z + 1);
	printf("*");
	zb[h][z + 1] = 1;
	gotoxy(hout, h - 1, z + 1);
	printf("*");
	zb[h - 1][z + 1] = 1;
	gotoxy(hout, h - 2, z + 1);
	printf("*");
	zb[h - 2][z + 1] = 1;
	gotoxy(hout, h - 3, z + 1);
	printf("*");
	zb[h - 3][z + 1] = 1;
	gotoxy(hout, h - 4, z + 1);
	printf("*");
	zb[h - 4][z + 1] = 1;



	dl[h - 1][z] = 1;
	dl[h - 2][z] = 1;
	dl[h - 3][z] = 1;
	dl[h - 4][z] = 1;
}//拐角 
void d6(HANDLE hout, int h, int z) {
	gotoxy(hout, h, z);
	printf("*");
	zb[h][z] = 1;
	gotoxy(hout, h - 1, z);
	printf("*");
	zb[h - 1][z] = 1;
	gotoxy(hout, h - 2, z);
	printf("*");
	zb[h - 2][z] = 1;
	gotoxy(hout, h - 3, z);
	printf("*");
	zb[h - 3][z] = 1;
	gotoxy(hout, h - 3, z + 1);
	printf("*");
	zb[h - 3][z + 1] = 1;
	gotoxy(hout, h - 3, z + 2);
	printf("*");
	zb[h - 3][z + 2] = 1;



	dl[h][z + 1] = 1;
	dl[h - 1][z + 1] = 1;
	dl[h - 2][z + 1] = 1;
	dl[h][z + 2] = 1;
	dl[h - 1][z + 2] = 1;
	dl[h - 2][z + 2] = 1;
}//拐角 
void d7(HANDLE hout, int h, int z, int c) {
	gotoxy(hout, h, z);
	printf("*");
	zb[h][z] = 1;
	gotoxy(hout, h, z + 1);
	printf("*");
	zb[h][z + 1] = 1;
	gotoxy(hout, h + 1, z + 1);
	printf("*");
	zb[h + 1][z + 1] = 1;
	gotoxy(hout, h + 2, z + 1);
	printf("*");
	zb[h + 2][z + 1] = 1;
	gotoxy(hout, h + 3, z + 1);
	printf("*");
	zb[h + 3][z + 1] = 1;
	gotoxy(hout, h + 4, z + 1);
	printf("*");
	zb[h + 4][z + 1] = 1;



	dl[h + 1][z] = 1;
	dl[h + 2][z] = 1;
	dl[h + 3][z] = 1;
	dl[h + 4][z] = 1;


	for (int u = 0; u < c; u++) {
		gotoxy(hout, h + u + 5, z + 1);
		printf("*");
		zb[h + u + 5][z + 1] = 1;
		gotoxy(hout, h + u + 5, z - 1);
		printf("*");
		zb[h + u + 5][z - 1] = 1;



		dl[h + u + 5][z] = 1;

	}
	gotoxy(hout, h + 5 + c, z - 1);
	printf("*");
	zb[h + 5 + c][z - 1] = 1;
	gotoxy(hout, h + 6 + c, z - 1);
	printf("*");
	zb[h + 6 + c][z - 1] = 1;
	gotoxy(hout, h + 7 + c, z - 1);
	printf("*");
	zb[h + 7 + c][z - 1] = 1;
	gotoxy(hout, h + 8 + c, z - 1);
	printf("*");
	zb[h + 8 + c][z - 1] = 1;
	gotoxy(hout, h + 8 + c, z);
	printf("*");
	zb[h + 8 + c][z] = 1;
	gotoxy(hout, h + 8 + c, z + 1);
	printf("*");
	zb[h + 8 + c][z + 1] = 1;



	dl[h + 5 + c][z] = 1;
	dl[h + 6 + c][z] = 1;
	dl[h + 7 + c][z] = 1;
	dl[h + 5 + c][z + 1] = 1;
	dl[h + 6 + c][z + 1] = 1;
	dl[h + 7 + c][z + 1] = 1;
}//连续拐角  
void d8(HANDLE hout, int h, int z, int c) {
	gotoxy(hout, h, z);
	printf("*");
	zb[h][z] = 1;
	gotoxy(hout, h, z + 1);
	printf("*");
	zb[h][z + 1] = 1;
	gotoxy(hout, h - 1, z + 1);
	printf("*");
	zb[h - 1][z + 1] = 1;
	gotoxy(hout, h - 2, z + 1);
	printf("*");
	zb[h - 2][z + 1] = 1;
	gotoxy(hout, h - 3, z + 1);
	printf("*");
	zb[h - 3][z + 1] = 1;
	gotoxy(hout, h - 4, z + 1);
	printf("*");
	zb[h - 4][z + 1] = 1;



	dl[h - 1][z] = 1;
	dl[h - 2][z] = 1;
	dl[h - 3][z] = 1;
	dl[h - 4][z] = 1;


	for (int u = 0; u < c; u++) {
		gotoxy(hout, h - u - 5, z + 1);
		printf("*");
		zb[h - u - 5][z + 1] = 1;
		gotoxy(hout, h - u - 5, z - 1);
		printf("*");
		zb[h - u - 5][z - 1] = 1;


		dl[h - u - 5][z] = 1;
	}
	gotoxy(hout, h - 5 - c, z - 1);
	printf("*");
	zb[h - 5 - c][z - 1] = 1;
	gotoxy(hout, h - 6 - c, z - 1);
	printf("*");
	zb[h - 6 - c][z - 1] = 1;
	gotoxy(hout, h - 7 - c, z - 1);
	printf("*");
	zb[h - 7 - c][z - 1] = 1;
	gotoxy(hout, h - 8 - c, z - 1);
	printf("*");
	zb[h - 8 - c][z - 1] = 1;
	gotoxy(hout, h - 8 - c, z);
	printf("*");
	zb[h - 8 - c][z] = 1;
	gotoxy(hout, h - 8 - c, z + 1);
	printf("*");
	zb[h - 8 - c][z + 1] = 1;



	dl[h - 5 - c][z] = 1;
	dl[h - 6 - c][z] = 1;
	dl[h - 7 - c][z] = 1;
	dl[h - 5 - c][z + 1] = 1;
	dl[h - 6 - c][z + 1] = 1;
	dl[h - 7 - c][z + 1] = 1;
}//连续拐角  







////////////////////////////////////////////
////////////////////////////////////////////






//新手关地图 
void makeframe1(struct Snake* snake) {
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	zb[5][4] = 1;
	zb[9][4] = 1;
	zb[5][3] = 1;
	zb[9][3] = 1;
	zb[5][2] = 1;
	zb[9][2] = 1;
	zb[7][2] = 1;
	dl[7][4] = 1;
	dl[7][3] = 1;//空气墙 



	if (tz == 1) {
		snake->speed = 400 + sd;
		goto jx;
	}



	switch (nd) {
	case 1:snake->speed = 300;//定速 
		break;
	case 2:snake->speed = 250;
		break;
	case 3:snake->speed = 200;
		break;
	}



jx:



	if (ms == 4) {
		gotoxy(hout, 37, 10);
		printf("游戏开始,难度等级1级");
		d1(hout, 5, 5, 7);
		d7(hout, 5, 12, 4);
		d1(hout, 13, 14, 3);
		d7(hout, 13, 17, 4);
		d1(hout, 21, 19, 3);
		d7(hout, 21, 22, 2);
		d1(hout, 27, 24, 1);
		d3(hout, 27, 25);
		d2(hout, 32, 24, 20);
		gotoxy(hout, 5, 30);
		printf("已完成百分之25,难度等级2级，已经会玩了，加油！");
		d4(hout, 52, 24);
		d1(hout, 51, 26, 3);
		d7(hout, 51, 29, 2);
		d1(hout, 57, 31, 5);
		d7(hout, 57, 36, 2);
		d1(hout, 63, 38, 5);
		gotoxy(hout, 5, 40);
		printf("已完成百分之40,难度等级3级，难关还在后面呢！");
		d7(hout, 63, 43, 0);
		d1(hout, 67, 45, 3);
		d8(hout, 71, 48, 4);
		d1(hout, 59, 50, 7);
		gotoxy(hout, 5, 55);
		printf("已完成百分之50,难度等级4级，还不错哦！");
		d8(hout, 63, 57, 0);
		d8(hout, 59, 59, 0);
		d8(hout, 55, 61, 0);
		d8(hout, 51, 63, 0);
		d8(hout, 47, 65, 0);
		d1(hout, 39, 67, 5);
		gotoxy(hout, 5, 75);
		printf("已完成百分之70,难度等级5级,接受死亡吧！");
		d7(hout, 39, 72, 2);
		d7(hout, 45, 74, 2);
		d7(hout, 51, 76, 2);
		d1(hout, 57, 78, 3);
		d8(hout, 61, 81, 2);
		d1(hout, 51, 83, 5);
		gotoxy(hout, 5, 85);
		printf("已完成百分之85,难度等级6级,最后的冲刺！");
		d8(hout, 55, 88, 2);
		d8(hout, 49, 90, 2);
		d8(hout, 43, 92, 0);
		d8(hout, 39, 94, 0);
		d1(hout, 31, 96, 5);
		d7(hout, 31, 101, 0);
		d7(hout, 35, 103, 0);
		d7(hout, 39, 105, 0);
		d7(hout, 43, 107, 0);
		d7(hout, 47, 109, 0);
		d1(hout, 51, 110, 10);
		ms = -1;
	}

	if (ms == -1) {
		goto js1;
	}

	if (snake->x[snake->length - 1] == 7 && snake->y[snake->length - 1] == 3) {
		gotoxy(hout, 37, 10);
		printf("游戏开始,难度等级1级");
		d1(hout, 5, 5, 7);
		d7(hout, 5, 12, 4);
		d1(hout, 13, 14, 3);
		d7(hout, 13, 17, 4);
		d1(hout, 21, 19, 3);
		d7(hout, 21, 22, 2);
		d1(hout, 27, 24, 1);
		d3(hout, 27, 25);
		d2(hout, 32, 24, 20);
		if (ms == 2 || ms == 3) {
			for (int l = 0; l < 200; l++) {
				for (int x = 0; x < 200; x++) {
					if (zb[l][x] == 1) {
						gotoxy(hout, l, x);
						printf(" ");
					}
				}
			}
		}
	}


	if (snake->x[snake->length - 1] == 33 && snake->y[snake->length - 1] == 25) {
		gotoxy(hout, 5, 30);
		printf("已完成百分之25,难度等级2级，已经会玩了，加油！");
		d4(hout, 52, 24);
		d1(hout, 51, 26, 3);
		d7(hout, 51, 29, 2);
		d1(hout, 57, 31, 5);
		d7(hout, 57, 36, 2);
		d1(hout, 63, 38, 5);
		if (ms == 2 || ms == 3) {
			for (int l = 0; l < 200; l++) {
				for (int x = 0; x < 200; x++) {
					if (zb[l][x] == 1) {
						gotoxy(hout, l, x);
						printf(" ");
					}
				}
			}
		}
	}



	if (snake->x[snake->length - 1] == 65 && snake->y[snake->length - 1] == 39) {
		gotoxy(hout, 5, 40);
		printf("已完成百分之40,难度等级3级，难关还在后面呢！");
		d7(hout, 63, 43, 0);
		d1(hout, 67, 45, 3);
		d8(hout, 71, 48, 4);
		d1(hout, 59, 50, 7);
		if (ms == 2 || ms == 3) {
			for (int l = 0; l < 200; l++) {
				for (int x = 0; x < 200; x++) {
					if (zb[l][x] == 1) {
						gotoxy(hout, l, x);
						printf(" ");
					}
				}
			}
		}
	}



	if (snake->x[snake->length - 1] == 61 && snake->y[snake->length - 1] == 51) {
		gotoxy(hout, 5, 55);
		printf("已完成百分之50,难度等级4级，还不错哦！");
		d8(hout, 63, 57, 0);
		d8(hout, 59, 59, 0);
		d8(hout, 55, 61, 0);
		d8(hout, 51, 63, 0);
		d8(hout, 47, 65, 0);
		d1(hout, 39, 67, 5);
		if (ms == 2 || ms == 3) {
			for (int l = 0; l < 200; l++) {
				for (int x = 0; x < 200; x++) {
					if (zb[l][x] == 1) {
						gotoxy(hout, l, x);
						printf(" ");
					}
				}
			}
		}
	}



	if (snake->x[snake->length - 1] == 41 && snake->y[snake->length - 1] == 68) {
		gotoxy(hout, 5, 75);
		printf("已完成百分之70,难度等级5级,接受死亡吧！");
		d7(hout, 39, 72, 2);
		d7(hout, 45, 74, 2);
		d7(hout, 51, 76, 2);
		d1(hout, 57, 78, 3);
		d8(hout, 61, 81, 2);
		d1(hout, 51, 83, 5);
		if (ms == 2 || ms == 3) {
			for (int l = 0; l < 200; l++) {
				for (int x = 0; x < 200; x++) {
					if (zb[l][x] == 1) {
						gotoxy(hout, l, x);
						printf(" ");
					}
				}
			}
		}
	}



	if (snake->x[snake->length - 1] == 53 && snake->y[snake->length - 1] == 84) {
		gotoxy(hout, 5, 85);
		printf("已完成百分之85,难度等级6级,最后的冲刺！");
		d8(hout, 55, 88, 2);
		d8(hout, 49, 90, 2);
		d8(hout, 43, 92, 0);
		d8(hout, 39, 94, 0);
		d1(hout, 31, 96, 5);
		if (ms == 2 || ms == 3) {
			for (int l = 0; l < 200; l++) {
				for (int x = 0; x < 200; x++) {
					if (zb[l][x] == 1) {
						gotoxy(hout, l, x);
						printf(" ");
					}
				}
			}
		}
	}



	if (snake->x[snake->length - 1] == 33 && snake->y[snake->length - 1] == 97) {
		d7(hout, 31, 101, 0);
		d7(hout, 35, 103, 0);
		d7(hout, 39, 105, 0);
		d7(hout, 43, 107, 0);
		d7(hout, 47, 109, 0);
		d1(hout, 51, 110, 10);
		if (ms == 2 || ms == 3) {
			for (int l = 0; l < 200; l++) {
				for (int x = 0; x < 200; x++) {
					if (zb[l][x] == 1) {
						gotoxy(hout, l, x);
						printf(" ");
					}
				}
			}
		}
	}

js1:
	if (snake->x[snake->length - 1] == 53 && snake->y[snake->length - 1] == 118) {
		sl = 1;
	}


}


//手速关地图 
void makeframe2(struct Snake* snake) {
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	zb[5][4] = 1;
	zb[9][4] = 1;
	zb[5][3] = 1;
	zb[9][3] = 1;
	zb[5][2] = 1;
	zb[9][2] = 1;
	zb[7][2] = 1;
	dl[7][4] = 1;
	dl[7][3] = 1;//空气墙 



	if (tz == 1) {
		snake->speed = (131 - snake->y[snake->length - 1]) * 5 + sd;
		goto jx1;
	}

	switch (nd) {
	case 1:snake->speed = (131 - snake->y[snake->length - 1]) * 7;//定速 
		xs = 7;
		break;
	case 2:snake->speed = (131 - snake->y[snake->length - 1]) * 5;
		xs = 5;
		break;
	case 3:snake->speed = (131 - snake->y[snake->length - 1]) * 3;
		xs = 3;
		break;
	}



	if (snake->y[snake->length - 1] >= 0 && snake->y[snake->length - 1] <= 26) {
		gotoxy(hout, 50, 5);
		printf("当前速度%d", 128 * xs - snake->speed);
	}


	else if (snake->y[snake->length - 1] >= 27 && snake->y[snake->length - 1] <= 43) {
		gotoxy(hout, 10, 30);
		printf("当前速度%d", 128 * xs - snake->speed);
	}


	else if (snake->y[snake->length - 1] >= 44 && snake->y[snake->length - 1] <= 63) {
		gotoxy(hout, 50, 50);
		printf("当前速度%d", 128 * xs - snake->speed);
	}


	else if (snake->y[snake->length - 1] >= 64 && snake->y[snake->length - 1] <= 80) {
		gotoxy(hout, 10, 70);
		printf("当前速度%d", 128 * xs - snake->speed);
	}


	else if (snake->y[snake->length - 1] >= 81 & snake->y[snake->length - 1] <= 95) {
		gotoxy(hout, 10, 80);
		printf("当前速度%d", 128 * xs - snake->speed);
	}


	else if (snake->y[snake->length - 1] >= 96 && snake->y[snake->length - 1] <= 110) {
		gotoxy(hout, 50, 100);
		printf("当前速度%d", 128 * xs - snake->speed);
	}


	else if (snake->y[snake->length - 1] >= 111 && snake->y[snake->length - 1] <= 130) {
		gotoxy(hout, 10, 110);
		printf("当前速度%d", 128 * xs - snake->speed);
	}//速度实时输出 






jx1:


	if (ms == 4) {
		d1(hout, 5, 5, 5);
		d7(hout, 5, 10, 4);
		d7(hout, 13, 12, 4);
		d7(hout, 21, 14, 4);
		d7(hout, 29, 16, 4);
		d7(hout, 37, 18, 4);
		d7(hout, 45, 20, 4);
		d7(hout, 53, 22, 4);
		d1(hout, 61, 24, 10);
		d8(hout, 65, 34, 2);
		d8(hout, 59, 36, 2);
		d8(hout, 53, 38, 2);
		d8(hout, 47, 40, 2);
		d8(hout, 41, 42, 2);
		d5(hout, 35, 44);
		d2(hout, 11, 43, 20);
		d6(hout, 10, 43);
		d1(hout, 7, 46, 5);
		d7(hout, 7, 51, 0);
		d7(hout, 11, 53, 0);
		d7(hout, 15, 55, 0);
		d7(hout, 19, 57, 0);
		d7(hout, 23, 59, 0);
		d7(hout, 27, 61, 0);
		d1(hout, 31, 63, 5);
		d7(hout, 31, 68, 0);
		d7(hout, 35, 70, 0);
		d7(hout, 39, 72, 0);
		d7(hout, 43, 74, 0);
		d7(hout, 47, 76, 0);
		d7(hout, 51, 78, 0);
		d1(hout, 55, 80, 3);
		d8(hout, 59, 83, 0);
		d8(hout, 55, 85, 0);
		d8(hout, 51, 87, 2);
		d8(hout, 45, 89, 2);
		d8(hout, 39, 91, 0);
		d8(hout, 35, 93, 0);
		d1(hout, 27, 95, 5);
		d7(hout, 27, 100, 0);
		d7(hout, 31, 102, 2);
		d7(hout, 37, 104, 0);
		d7(hout, 41, 106, 2);
		d7(hout, 47, 108, 0);
		d1(hout, 51, 110, 3);
		d8(hout, 55, 113, 0);
		d8(hout, 51, 115, 2);
		d8(hout, 45, 117, 0);
		d8(hout, 41, 119, 2);
		d8(hout, 35, 121, 2);
		d1(hout, 25, 123, 10);
		ms = -1;
	}

	if (ms == -1) {
		goto js2;
	}


	if (snake->x[snake->length - 1] == 7 && snake->y[snake->length - 1] == 3) {
		d1(hout, 5, 5, 5);
		d7(hout, 5, 10, 4);
		d7(hout, 13, 12, 4);
		d7(hout, 21, 14, 4);
		d7(hout, 29, 16, 4);
		d7(hout, 37, 18, 4);
		d7(hout, 45, 20, 4);
		d7(hout, 53, 22, 4);
		d1(hout, 61, 24, 10);
		if (ms == 2 || ms == 3) {
			for (int l = 0; l < 200; l++) {
				for (int x = 0; x < 200; x++) {
					if (zb[l][x] == 1) {
						gotoxy(hout, l, x);
						printf(" ");
					}
				}
			}
		}
	}


	if (snake->x[snake->length - 1] == 63 && snake->y[snake->length - 1] == 27) {
		d8(hout, 65, 34, 2);
		d8(hout, 59, 36, 2);
		d8(hout, 53, 38, 2);
		d8(hout, 47, 40, 2);
		d8(hout, 41, 42, 2);
		d5(hout, 35, 44);
		d2(hout, 11, 43, 20);
		if (ms == 2 || ms == 3) {
			for (int l = 0; l < 200; l++) {
				for (int x = 0; x < 200; x++) {
					if (zb[l][x] == 1) {
						gotoxy(hout, l, x);
						printf(" ");
					}
				}
			}
		}
	}



	if (snake->x[snake->length - 1] == 15 && snake->y[snake->length - 1] == 44) {
		d6(hout, 10, 43);
		d1(hout, 7, 46, 5);
		d7(hout, 7, 51, 0);
		d7(hout, 11, 53, 0);
		d7(hout, 15, 55, 0);
		d7(hout, 19, 57, 0);
		d7(hout, 23, 59, 0);
		d7(hout, 27, 61, 0);
		d1(hout, 31, 63, 5);
		if (ms == 2 || ms == 3) {
			for (int l = 0; l < 200; l++) {
				for (int x = 0; x < 200; x++) {
					if (zb[l][x] == 1) {
						gotoxy(hout, l, x);
						printf(" ");
					}
				}
			}
		}
	}



	if (snake->x[snake->length - 1] == 33 && snake->y[snake->length - 1] == 64) {
		d7(hout, 31, 68, 0);
		d7(hout, 35, 70, 0);
		d7(hout, 39, 72, 0);
		d7(hout, 43, 74, 0);
		d7(hout, 47, 76, 0);
		d7(hout, 51, 78, 0);
		d1(hout, 55, 80, 3);
		if (ms == 2 || ms == 3) {
			for (int l = 0; l < 200; l++) {
				for (int x = 0; x < 200; x++) {
					if (zb[l][x] == 1) {
						gotoxy(hout, l, x);
						printf(" ");
					}
				}
			}
		}
	}



	if (snake->x[snake->length - 1] == 57 && snake->y[snake->length - 1] == 81) {
		d8(hout, 59, 83, 0);
		d8(hout, 55, 85, 0);
		d8(hout, 51, 87, 2);
		d8(hout, 45, 89, 2);
		d8(hout, 39, 91, 0);
		d8(hout, 35, 93, 0);
		d1(hout, 27, 95, 5);
		if (ms == 2 || ms == 3) {
			for (int l = 0; l < 200; l++) {
				for (int x = 0; x < 200; x++) {
					if (zb[l][x] == 1) {
						gotoxy(hout, l, x);
						printf(" ");
					}
				}
			}
		}
	}




	if (snake->x[snake->length - 1] == 29 && snake->y[snake->length - 1] == 96) {
		d7(hout, 27, 100, 0);
		d7(hout, 31, 102, 2);
		d7(hout, 37, 104, 0);
		d7(hout, 41, 106, 2);
		d7(hout, 47, 108, 0);
		d1(hout, 51, 110, 3);
		if (ms == 2 || ms == 3) {
			for (int l = 0; l < 200; l++) {
				for (int x = 0; x < 200; x++) {
					if (zb[l][x] == 1) {
						gotoxy(hout, l, x);
						printf(" ");
					}
				}
			}
		}
	}



	if (snake->x[snake->length - 1] == 53 && snake->y[snake->length - 1] == 111) {
		d8(hout, 55, 113, 0);
		d8(hout, 51, 115, 2);
		d8(hout, 45, 117, 0);
		d8(hout, 41, 119, 2);
		d8(hout, 35, 121, 2);
		d1(hout, 25, 123, 10);
		if (ms == 2 || ms == 3) {
			for (int l = 0; l < 200; l++) {
				for (int x = 0; x < 200; x++) {
					if (zb[l][x] == 1) {
						gotoxy(hout, l, x);
						printf(" ");
					}
				}
			}
		}
	}


js2:
	if (snake->x[snake->length - 1] == 27 && snake->y[snake->length - 1] == 130) {
		sl = 1;
	}


}



void makeframe3(struct Snake* snake) {
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	zb[5][4] = 1;
	zb[9][4] = 1;
	zb[5][3] = 1;
	zb[9][3] = 1;
	zb[5][2] = 1;
	zb[9][2] = 1;
	zb[7][2] = 1;
	dl[7][4] = 1;
	dl[7][3] = 1;//空气墙 




	if (tz == 1) {
		snake->speed = 400 + sd;
		goto jx2;
	}



	switch (nd) {
	case 1:snake->speed = 200;//定速 
		break;
	case 2:snake->speed = 150;
		break;
	case 3:snake->speed = 100;
		break;
	}



jx2:

	if (ms == 4) {
		d1(hout, 5, 5, 5);
		d3(hout, 5, 10);
		d2(hout, 10, 9, 5);
		d5(hout, 19, 10);
		d1(hout, 15, 9, 1);
		d4(hout, 16, 7);
		d2(hout, 13, 7, 3);
		d6(hout, 12, 5);
		d2(hout, 13, 5, 7);
		d4(hout, 20, 5);
		d1(hout, 19, 7, 5);
		d5(hout, 23, 12);
		d2(hout, 17, 11, 1);
		d6(hout, 16, 11);
		d7(hout, 13, 14, 2);
		d5(hout, 23, 16);
		d2(hout, 13, 15, 7);
		d3(hout, 9, 16);
		d1(hout, 9, 13, 3);
		d6(hout, 8, 11);
		d1(hout, 5, 13, 5);
		d3(hout, 5, 18);
		d2(hout, 9, 17, 15);
		d5(hout, 27, 18);
		d1(hout, 23, 5, 13);
		d6(hout, 26, 3);
		d2(hout, 27, 3, 1);
		d4(hout, 28, 3);
		//////////////
		d1(hout, 27, 5, 5);
		d3(hout, 27, 10);
		d2(hout, 32, 9, 5);
		d5(hout, 41, 10);
		d1(hout, 37, 9, 1);
		d4(hout, 38, 7);
		d2(hout, 35, 7, 3);
		d6(hout, 34, 5);
		d2(hout, 35, 5, 7);
		d4(hout, 42, 5);
		d1(hout, 41, 7, 5);
		d5(hout, 45, 12);
		d2(hout, 39, 11, 1);
		d6(hout, 38, 11);
		d7(hout, 35, 14, 2);
		d5(hout, 45, 16);
		d2(hout, 35, 15, 7);
		d3(hout, 31, 16);
		d1(hout, 31, 13, 3);
		d6(hout, 30, 11);
		d1(hout, 27, 13, 5);
		d3(hout, 27, 18);
		d2(hout, 31, 17, 15);
		d5(hout, 49, 18);
		d1(hout, 45, 5, 13);
		d6(hout, 48, 3);
		d2(hout, 49, 3, 1);
		d4(hout, 50, 3);
		/////////////////
		d1(hout, 49, 5, 5);
		d3(hout, 49, 10);
		d2(hout, 54, 9, 5);
		d5(hout, 63, 10);
		d1(hout, 59, 9, 1);
		d4(hout, 60, 7);
		d2(hout, 57, 7, 3);
		d6(hout, 56, 5);
		d2(hout, 57, 5, 7);
		d4(hout, 64, 5);
		d1(hout, 63, 7, 5);
		d5(hout, 67, 12);
		d2(hout, 61, 11, 1);
		d6(hout, 60, 11);
		d7(hout, 57, 14, 2);
		d5(hout, 67, 16);
		d2(hout, 57, 15, 7);
		d3(hout, 53, 16);
		d1(hout, 53, 13, 3);
		d6(hout, 52, 11);
		d1(hout, 49, 13, 5);
		d3(hout, 49, 18);
		d2(hout, 53, 17, 15);
		d5(hout, 71, 18);
		d1(hout, 67, 5, 13);
		d6(hout, 70, 3);
		d2(hout, 71, 3, 1);
		d4(hout, 72, 3);
		d1(hout, 71, 5, 15);
		d5(hout, 75, 20);
		d2(hout, 5, 19, 67);
		ms = -1;
	}

	if (ms == -1) {
		goto js3;
	}



	if (snake->x[snake->length - 1] == 7 && snake->y[snake->length - 1] == 3 ||
		snake->x[snake->length - 1] == 29 && snake->y[snake->length - 1] == 4 ||
		snake->x[snake->length - 1] == 51 && snake->y[snake->length - 1] == 4 ||
		snake->x[snake->length - 1] == 73 && snake->y[snake->length - 1] == 4 ||
		snake->x[snake->length - 1] == 29 && snake->y[snake->length - 1] == 5 ||
		snake->x[snake->length - 1] == a && snake->y[snake->length - 1] == b + 1 ||
		snake->x[snake->length - 1] == a + 2 && snake->y[snake->length - 1] == b ||
		snake->x[snake->length - 1] == a - 2 && snake->y[snake->length - 1] == b) {
		d1(hout, 5, 5, 5);
		d3(hout, 5, 10);
		d2(hout, 10, 9, 5);
		d5(hout, 19, 10);
		d1(hout, 15, 9, 1);
		d4(hout, 16, 7);
		d2(hout, 13, 7, 3);
		d6(hout, 12, 5);
		d2(hout, 13, 5, 7);
		d4(hout, 20, 5);
		d1(hout, 19, 7, 5);
		d5(hout, 23, 12);
		d2(hout, 17, 11, 1);
		d6(hout, 16, 11);
		d7(hout, 13, 14, 2);
		d5(hout, 23, 16);
		d2(hout, 13, 15, 7);
		d3(hout, 9, 16);
		d1(hout, 9, 13, 3);
		d6(hout, 8, 11);
		d1(hout, 5, 13, 5);
		d3(hout, 5, 18);
		d2(hout, 9, 17, 15);
		d5(hout, 27, 18);
		d1(hout, 23, 5, 13);
		d6(hout, 26, 3);
		d2(hout, 27, 3, 1);
		d4(hout, 28, 3);
		//////////////
		d1(hout, 27, 5, 5);
		d3(hout, 27, 10);
		d2(hout, 32, 9, 5);
		d5(hout, 41, 10);
		d1(hout, 37, 9, 1);
		d4(hout, 38, 7);
		d2(hout, 35, 7, 3);
		d6(hout, 34, 5);
		d2(hout, 35, 5, 7);
		d4(hout, 42, 5);
		d1(hout, 41, 7, 5);
		d5(hout, 45, 12);
		d2(hout, 39, 11, 1);
		d6(hout, 38, 11);
		d7(hout, 35, 14, 2);
		d5(hout, 45, 16);
		d2(hout, 35, 15, 7);
		d3(hout, 31, 16);
		d1(hout, 31, 13, 3);
		d6(hout, 30, 11);
		d1(hout, 27, 13, 5);
		d3(hout, 27, 18);
		d2(hout, 31, 17, 15);
		d5(hout, 49, 18);
		d1(hout, 45, 5, 13);
		d6(hout, 48, 3);
		d2(hout, 49, 3, 1);
		d4(hout, 50, 3);
		/////////////////
		d1(hout, 49, 5, 5);
		d3(hout, 49, 10);
		d2(hout, 54, 9, 5);
		d5(hout, 63, 10);
		d1(hout, 59, 9, 1);
		d4(hout, 60, 7);
		d2(hout, 57, 7, 3);
		d6(hout, 56, 5);
		d2(hout, 57, 5, 7);
		d4(hout, 64, 5);
		d1(hout, 63, 7, 5);
		d5(hout, 67, 12);
		d2(hout, 61, 11, 1);
		d6(hout, 60, 11);
		d7(hout, 57, 14, 2);
		d5(hout, 67, 16);
		d2(hout, 57, 15, 7);
		d3(hout, 53, 16);
		d1(hout, 53, 13, 3);
		d6(hout, 52, 11);
		d1(hout, 49, 13, 5);
		d3(hout, 49, 18);
		d2(hout, 53, 17, 15);
		d5(hout, 71, 18);
		d1(hout, 67, 5, 13);
		d6(hout, 70, 3);
		d2(hout, 71, 3, 1);
		d4(hout, 72, 3);
		d1(hout, 71, 5, 15);
		d5(hout, 75, 20);
		d2(hout, 5, 19, 67);
		gotoxy(hout, 73, 21);
		printf("*");
		gotoxy(hout, 74, 21);
		printf("*");
		gotoxy(hout, 75, 21);
		printf("*");
		if (ms == 2 || ms == 3) {
			for (int l = 0; l < 200; l++) {
				for (int x = 0; x < 200; x++) {
					if (zb[l][x] == 1) {
						gotoxy(hout, l, x);
						printf(" ");
					}
				}
			}
		}
	}



js3:
	if (snake->x[snake->length - 1] == 7 && snake->y[snake->length - 1] == 20) {
		sl = 1;
	}
}




//死亡判断 
int ifdead(struct Snake* snake) {
	if (zb[snake->x[snake->length - 1]][snake->y[snake->length - 1]] == 1)
		if (sw == 0)
			return 0;
		else
			return 1;

	for (i = 0; i < snake->length - 1; i++)
		if (snake->x[snake->length - 1] == snake->x[i] && snake->y[snake->length - 1] == snake->y[i])
			if (sw == 0 && zs == 0)
				return 0;
			else
				return 1;

	return 1;
}



//输出地图 
void kf() {
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (kfxz) {
	case 1:gotoxy(hout, 37, 10);
		printf("游戏开始,难度等级1级");
		d1(hout, 5, 5, 7);
		d7(hout, 5, 12, 4);
		d1(hout, 13, 14, 3);
		d7(hout, 13, 17, 4);
		d1(hout, 21, 19, 3);
		d7(hout, 21, 22, 2);
		d1(hout, 27, 24, 1);
		d3(hout, 27, 25);
		d2(hout, 32, 24, 20);
		gotoxy(hout, 5, 30);
		printf("已完成百分之25,难度等级2级，已经会玩了，加油！");
		d4(hout, 52, 24);
		d1(hout, 51, 26, 3);
		d7(hout, 51, 29, 2);
		d1(hout, 57, 31, 5);
		d7(hout, 57, 36, 2);
		d1(hout, 63, 38, 5);
		gotoxy(hout, 5, 40);
		printf("已完成百分之40,难度等级3级，难关还在后面呢！");
		d7(hout, 63, 43, 0);
		d1(hout, 67, 45, 3);
		d8(hout, 71, 48, 4);
		d1(hout, 59, 50, 7);
		gotoxy(hout, 5, 55);
		printf("已完成百分之50,难度等级4级，还不错哦！");
		d8(hout, 63, 57, 0);
		d8(hout, 59, 59, 0);
		d8(hout, 55, 61, 0);
		d8(hout, 51, 63, 0);
		d8(hout, 47, 65, 0);
		d1(hout, 39, 67, 5);
		gotoxy(hout, 5, 75);
		printf("已完成百分之70,难度等级5级,接受死亡吧！");
		d7(hout, 39, 72, 2);
		d7(hout, 45, 74, 2);
		d7(hout, 51, 76, 2);
		d1(hout, 57, 78, 3);
		d8(hout, 61, 81, 2);
		d1(hout, 51, 83, 5);
		gotoxy(hout, 5, 85);
		printf("已完成百分之85,难度等级6级,最后的冲刺！");
		d8(hout, 55, 88, 2);
		d8(hout, 49, 90, 2);
		d8(hout, 43, 92, 0);
		d8(hout, 39, 94, 0);
		d1(hout, 31, 96, 5);
		d7(hout, 31, 101, 0);
		d7(hout, 35, 103, 0);
		d7(hout, 39, 105, 0);
		d7(hout, 43, 107, 0);
		d7(hout, 47, 109, 0);
		d1(hout, 51, 110, 10);
		printf("\n\n");
		break;
	case 2:gotoxy(hout, 50, 5);
		printf("当前速度");
		d1(hout, 5, 5, 5);
		d7(hout, 5, 10, 4);
		d7(hout, 13, 12, 4);
		d7(hout, 21, 14, 4);
		d7(hout, 29, 16, 4);
		d7(hout, 37, 18, 4);
		d7(hout, 45, 20, 4);
		d7(hout, 53, 22, 4);
		d1(hout, 61, 24, 10);
		gotoxy(hout, 10, 30);
		printf("当前速度");
		d8(hout, 65, 34, 2);
		d8(hout, 59, 36, 2);
		d8(hout, 53, 38, 2);
		d8(hout, 47, 40, 2);
		d8(hout, 41, 42, 2);
		d5(hout, 35, 44);
		d2(hout, 11, 43, 20);
		gotoxy(hout, 50, 50);
		printf("当前速度");
		d6(hout, 10, 43);
		d1(hout, 7, 46, 5);
		d7(hout, 7, 51, 0);
		d7(hout, 11, 53, 0);
		d7(hout, 15, 55, 0);
		d7(hout, 19, 57, 0);
		d7(hout, 23, 59, 0);
		d7(hout, 27, 61, 0);
		d1(hout, 31, 63, 5);
		d7(hout, 31, 68, 0);
		d7(hout, 35, 70, 0);
		d7(hout, 39, 72, 0);
		d7(hout, 43, 74, 0);
		d7(hout, 47, 76, 0);
		d7(hout, 51, 78, 0);
		d1(hout, 55, 80, 3);
		gotoxy(hout, 10, 80);
		printf("当前速度");
		d8(hout, 59, 83, 0);
		d8(hout, 55, 85, 0);
		d8(hout, 51, 87, 2);
		d8(hout, 45, 89, 2);
		d8(hout, 39, 91, 0);
		d8(hout, 35, 93, 0);
		d1(hout, 27, 95, 5);
		gotoxy(hout, 50, 100);
		printf("当前速度");
		d7(hout, 27, 100, 0);
		d7(hout, 31, 102, 2);
		d7(hout, 37, 104, 0);
		d7(hout, 41, 106, 2);
		d7(hout, 47, 108, 0);
		d1(hout, 51, 110, 3);
		gotoxy(hout, 10, 110);
		printf("当前速度");
		d8(hout, 55, 113, 0);
		d8(hout, 51, 115, 2);
		d8(hout, 45, 117, 0);
		d8(hout, 41, 119, 2);
		d8(hout, 35, 121, 2);
		d1(hout, 25, 123, 10);
		printf("\n\n");
		break;
	case 3:d1(hout, 5, 5, 5);
		d3(hout, 5, 10);
		d2(hout, 10, 9, 5);
		d5(hout, 19, 10);
		d1(hout, 15, 9, 1);
		d4(hout, 16, 7);
		d2(hout, 13, 7, 3);
		d6(hout, 12, 5);
		d2(hout, 13, 5, 7);
		d4(hout, 20, 5);
		d1(hout, 19, 7, 5);
		d5(hout, 23, 12);
		d2(hout, 17, 11, 1);
		d6(hout, 16, 11);
		d7(hout, 13, 14, 2);
		d5(hout, 23, 16);
		d2(hout, 13, 15, 7);
		d3(hout, 9, 16);
		d1(hout, 9, 13, 3);
		d6(hout, 8, 11);
		d1(hout, 5, 13, 5);
		d3(hout, 5, 18);
		d2(hout, 9, 17, 15);
		d5(hout, 27, 18);
		d1(hout, 23, 5, 13);
		d6(hout, 26, 3);
		d2(hout, 27, 3, 1);
		d4(hout, 28, 3);
		//////////////
		d1(hout, 27, 5, 5);
		d3(hout, 27, 10);
		d2(hout, 32, 9, 5);
		d5(hout, 41, 10);
		d1(hout, 37, 9, 1);
		d4(hout, 38, 7);
		d2(hout, 35, 7, 3);
		d6(hout, 34, 5);
		d2(hout, 35, 5, 7);
		d4(hout, 42, 5);
		d1(hout, 41, 7, 5);
		d5(hout, 45, 12);
		d2(hout, 39, 11, 1);
		d6(hout, 38, 11);
		d7(hout, 35, 14, 2);
		d5(hout, 45, 16);
		d2(hout, 35, 15, 7);
		d3(hout, 31, 16);
		d1(hout, 31, 13, 3);
		d6(hout, 30, 11);
		d1(hout, 27, 13, 5);
		d3(hout, 27, 18);
		d2(hout, 31, 17, 15);
		d5(hout, 49, 18);
		d1(hout, 45, 5, 13);
		d6(hout, 48, 3);
		d2(hout, 49, 3, 1);
		d4(hout, 50, 3);
		/////////////////
		d1(hout, 49, 5, 5);
		d3(hout, 49, 10);
		d2(hout, 54, 9, 5);
		d5(hout, 63, 10);
		d1(hout, 59, 9, 1);
		d4(hout, 60, 7);
		d2(hout, 57, 7, 3);
		d6(hout, 56, 5);
		d2(hout, 57, 5, 7);
		d4(hout, 64, 5);
		d1(hout, 63, 7, 5);
		d5(hout, 67, 12);
		d2(hout, 61, 11, 1);
		d6(hout, 60, 11);
		d7(hout, 57, 14, 2);
		d5(hout, 67, 16);
		d2(hout, 57, 15, 7);
		d3(hout, 53, 16);
		d1(hout, 53, 13, 3);
		d6(hout, 52, 11);
		d1(hout, 49, 13, 5);
		d3(hout, 49, 18);
		d2(hout, 53, 17, 15);
		d5(hout, 71, 18);
		d1(hout, 67, 5, 13);
		d6(hout, 70, 3);
		d2(hout, 71, 3, 1);
		d4(hout, 72, 3);
		d1(hout, 71, 5, 15);
		d5(hout, 75, 20);
		d2(hout, 5, 19, 67);
		printf("\n\n");
		break;
	}
}




//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////













void map(HANDLE hout) {
	for (int f1 = 1; f1 <= 79; f1++) {
		gotoxy(hout, f1, 0);
		printf("*");
		zb[f1][0] = 1;
	}
	for (int f2 = 1; f2 <= 23; f2++) {
		gotoxy(hout, 1, f2);
		printf("*");
		zb[1][f2] = 1;
	}
	for (int f3 = 1; f3 <= 79; f3++) {
		gotoxy(hout, f3, 23);
		printf("*");
		zb[f3][23] = 1;
	}
	for (int f4 = 1; f4 <= 23; f4++) {
		gotoxy(hout, 79, f4);
		printf("*");
		zb[79][f4] = 1;
	}
}




//定义蛇的结构体 
struct  snake1 {
	int x1[100];
	int y1[100];
	int speed1;
	int length1;
};



struct  snake2 {
	int x2[100];
	int y2[100];
	int speed2;
	int length2;
};





void menu2(HANDLE hout, struct snake1* snake1, struct snake2* snake2) {
cd:system("cls");
	gotoxy(hout, framex + wide, framey + 1);
	printf("            主菜单");
	gotoxy(hout, framex + wide, framey + 4);
	printf("        1、开始游戏");
	gotoxy(hout, framex + wide, framey + 7);
	printf("        2、玩家服务");
	gotoxy(hout, framex + wide, framey + 10);
	printf("        3、后台设置");
	gotoxy(hout, framex + wide, framey + 13);
	printf("        4、退出游戏\n\n\n\n\n\n\n\n\n");
	scanf("%d", &c1);
	switch (c1) {
	case 1:system("cls");
		printf("                                     游戏规则：\n\n");
		printf("                1、一号玩家用WASD键操控，二号玩家用方向键操控\n\n");
		printf("          2、若一位玩家的蛇头碰到另一位玩家的蛇尾，另一位玩家就会死亡\n\n");
		printf("               3、你们需要不断按键盘来移动，碰到四周的墙也会死亡\n\n");
		printf("             4、一位玩家不按键盘可以停止移动，另一位玩家会继续移动\n\n");
		printf("                               再次查看请选择玩家服务\n\n");
		Sleep(5000);
		break;
	case 2:system("cls");
		printf("                                    请选择服务\n\n");
		printf("                                 1、查看游戏规则\n\n");
		printf("                                 2、查看游戏纪录\n\n");
		printf("                                 3、清空游戏纪录\n\n");
		scanf("%d", &c1);
		switch (c1) {
		case 1:

			system("cls");
			printf("                                     游戏规则：\n\n");
			printf("                1、一号玩家用WASD键操控，二号玩家用方向键操控\n\n");
			printf("          2、若一位玩家的蛇头碰到另一位玩家的蛇尾，另一位玩家就会死亡\n\n");
			printf("               3、你们需要不断按键盘来移动，碰到四周的墙也会死亡\n\n");
			printf("             4、一位玩家不按键盘可以停止移动，另一位玩家会继续移动\n");
			scanf("%d", &c2);
			goto cd;
			break;



		case 2:
			system("cls");
			printf("                               一号玩家^赢了%d次\n\n", ys1);
			printf("                               二号玩家#赢了%d次\n\n", ys2);
			scanf("%d", &c2);
			goto cd;
			break;



		case 3:

			ys1 = 0;
			ys2 = 0;
			qk2 = 1;
			goto cd;
			break;



		default:
			printf("输入错误，请重新选择\n\n");
			Sleep(1000);
			goto cd;
			break;

		}
		break;
	case 3:system("cls");
		printf("               后台设置属于开外挂，为了您的正常游戏，最好不要设置\n\n\n");
		printf("                               请选择设置的内容\n\n\n");
		printf("                                 1、禁止死亡\n\n\n");
		printf("                              2、更改蛇的初速度\n\n\n");
		printf("                              3、死亡后任意复活\n\n\n");
		printf("                                 4、退出设置\n\n\n");
		printf("\n\n\n\n\n");
		scanf("%d", &c2);
		switch (c2) {
		case 1:sw1 = 1;
			goto cd;
			break;
		case 2:system("cls");
			printf("                              请输入一号蛇的初速度\n\n");
			scanf("%d", &sd1);
			printf("                              请输入二号蛇的初速度\n\n");
			scanf("%d", &sd2);
			sd3 = 1;
			goto cd;
			break;
		case 3:printf("                                请输入复活的次数\n\n");
			scanf("%d", &fh1);
			goto cd;
			break;
		case 4:goto cd;
			break;
		default:
			printf("输入错误，请重新选择\n\n");
			Sleep(1000);
			goto cd;
			break;
		}
		break;
	case 4:tc = 1;
		break;
	default:printf("输入错误，请重新选择\n\n");
		Sleep(1000);
		goto cd;
		break;
	}//switch
}





//初始化蛇 
void initsnake1(struct snake1* snake1) {
	snake1->x1[0] = 9;
	snake1->y1[0] = 5;//蛇的初始坐标 
	snake1->length1 = 5;
	snake1->speed1 = 200;//蛇的参数 
	for (i = 1; i < snake1->length1; i++) {
		snake1->x1[i] = snake1->x1[i - 1] + 1;
		snake1->y1[i] = snake1->y1[i - 1];
	}
}


void initsnake2(struct snake2* snake2) {
	snake2->x2[0] = 67;
	snake2->y2[0] = 5;//蛇的初始坐标 
	snake2->length2 = 5;
	snake2->speed2 = 200;//蛇的参数
	for (i = 1; i < snake2->length2; i++) {
		snake2->x2[i] = snake2->x2[i - 1] + 1;
		snake2->y2[i] = snake2->y2[i - 1];
	}
}







//打印蛇 
void printsnake1(HANDLE hout, struct snake1* snake1) {
	for (i = 0; i < snake1->length1; i++) {
		gotoxy(hout, snake1->x1[i], snake1->y1[i]);
		if (i == snake1->length1 - 1)
			printf("^");
	}
}





void printsnake2(HANDLE hout, struct snake2* snake2) {
	for (i = 0; i < snake2->length2; i++) {
		gotoxy(hout, snake2->x2[i], snake2->y2[i]);
		if (i == snake2->length2 - 1)
			printf("#");
	}
}





//移动蛇 
void movesnake1(HANDLE hout, struct snake1* snake1) {
	gotoxy(hout, snake1->x1[0], snake1->y1[0]);
	printf("  ");
	for (i = 1; i < snake1->length1; i++) {
		snake1->x1[i - 1] = snake1->x1[i];
		snake1->y1[i - 1] = snake1->y1[i];
	}

}



void movesnake2(HANDLE hout, struct snake2* snake2) {
	gotoxy(hout, snake2->x2[0], snake2->y2[0]);
	printf("  ");
	for (i = 1; i < snake2->length2; i++) {
		snake2->x2[i - 1] = snake2->x2[i];
		snake2->y2[i - 1] = snake2->y2[i];
	}
}








//死亡判断 
int ifdead1(struct snake1* snake1) {
	if (zb[snake1->x1[snake1->length1 - 1]][snake1->y1[snake1->length1 - 1]] == 1) {
		return 0;
	}
	else {
		return 1;
	}

}



int ifdead2(struct snake2* snake2) {
	if (zb[snake2->x2[snake2->length2 - 1]][snake2->y2[snake2->length2 - 1]] == 1) {
		return 0;
	}
	else {
		return 1;
	}

}




int ifdead3(struct snake1* snake1, struct snake2* snake2) {
	for (i = 0; i < snake2->length2 - 1; i++) {
		if (snake1->x1[snake1->length1 - 1] == snake2->x2[i] && snake1->y1[snake1->length1 - 1] == snake2->y2[i]) {
			return 0;
		}
		else
			return 1;
	}

}



int ifdead4(struct snake1* snake1, struct snake2* snake2) {
	for (i = 0; i < snake1->length1 - 1; i++) {
		if (snake2->x2[snake2->length2 - 1] == snake1->x1[i] && snake2->y2[snake2->length2 - 1] == snake1->y1[i]) {
			return 0;
		}
		else
			return 1;
	}

}




//////////////////////////////////////////////////////////////////////////////不贪吃的蛇 




int main() {


	int cjcz, u1 = 0, zj;//成绩个数 
	int zgs = 0;//辅助变量 
	int sw1, sw2, sw3, sw4, sw5, sw6, sw7, sw8, sw9, sw10, sw11, sw12, sw13, sw14, sw15, sw16, sw17, sw18, sw19, sw20;//switch变量 
	int sc1, sc2, sc3, sc4, sc5, sc6, sc7, sc8, sc9, sc10, sc11, sc12, sc14, sc15;//scanf变量 
	int fscx1, fscx2, fscx3, fscx4, fscx5, fscx6, fscx7;
	long long jmxt;//密码加密密钥
	fscx1 = 1;
	fscx2 = 1;
	fscx3 = 1;
	fscx4 = 1;
	fscx5 = 1;
	fscx6 = 1;
	fscx7 = 1;










	///////////////////////////////////////////////////







	for (;;) {
		printf("                                欢迎来到张梓浩服务\n\n");
		printf("                                 程序版本:20.6.25\n\n");
		printf("                               请选择要进入的程序\n");
		printf("                          |     1、成绩管理系统     |\n");
		printf("                          |     2、数据管理系统     |\n");
		printf("                          |     3、字符加密系统     |\n");
		printf("                          |     4、不贪吃的蛇       |\n");
		printf("                          |     5、张梓浩网站       |\n");
		printf("                          |     6、使用说明介绍     |\n");
		printf("                          |     7、高精度乘法运算   |\n");
		printf("                          |     8、智能换序系统     |\n");
		printf("                          |     9、大数据系统       |\n");
		printf("                          |     10、24点自动计算    |\n");
		printf("                          |     11、退出服务程序    |\n\n\n\n\n");
		printf("                                技术支持:张梓浩\n");
		scanf("%d", &sw4);
		switch (sw4) {
		case 1:system("cls");
			float cj1[5000];//成绩管理系统,成绩记录变量
			int geshu;
			char filename[100];
			int tjd[1000];
			int xh[5000], ls[5000];//学号变量，学号输入临时变量 
			int px[5000];//成绩排序变量
			float o1, abc1, ad1, w1, x1;//成绩操作变量 
			int f1, j1, sr;//其余变量 
			int m1, p1, s1, t1, ab1, af1;//其余变量，如for循环,m1定义学号 
			float sc13;//成绩批量修改 
			int fs1, fs2, fs3, fs4, fs5, fs6;//成绩信息统计变量 
			int u2;//姓名个数 
			int pm;
			pm = 1;//第66行，为了牌面工整
			int pl1, pl2, pl3, pl4;//排序变量 
			fs1 = 0;//信息统计变量初始化 
			fs2 = 0;
			fs3 = 0;
			long long zf;//总分变量 
			double ave;//平均成绩变量 
			int cjsr;//姓名个数 
			int pxbl1, pxbl2;//排序变量 
			zf = 0;//总分 
			cjsr = 0;//姓名输入变量
			pxbl1 = 0;// 第64行，成绩排序处
			pxbl2 = 0;//第64行，成绩排序处 
			int cjsr1;//成绩个数  
			cjsr1 = 0;//成绩输入变量 
			char xmcz[100];//姓名查找输入姓名 
			char xmxg[100];//姓名修改输入 
			char xmls[100];//姓名连输处输入,同用于批量修改 
			int tc;//为姓名查找填充缓冲 
			FILE* fout, * fin;
			struct cg {
				char xm[100];//姓名输入 
			}st[5000];

			for (m1 = 0; m1 < 5000; m1++) {
				cj1[m1] = 404;
			}



			///////////////////////////////////////////////////////////////////////////////////////////    



			if (fscx1 == 1) {
				for (;;) {
				kt:
					printf("                               欢迎使用成绩管理系统\n\n");
					printf("                                    张梓浩制作\n\n\n");
					printf("           本程序只适用于单科单次成绩的处理，若有几个成绩，可以重复使用\n\n\n");
					printf("                   请选择想要进入的程序,输入相应数字并按下Enter键\n\n");
					printf("                    |     1、数据输入     |     2、数据导入     |\n");
					printf("                    |     3、数据排序     |     4、数据导出     |\n");
					printf("                    |     5、数据查找     |     6、数据统计     |\n");
					printf("                    |     7、查看留言     |     8、退出系统     |\n");
					printf("                    |     9、生成导入文件(仅限初次使用)         |\n");
					if (pm == 1) {
						printf("\n\n\n\n\n\n\n");
					}
					pm = 2;
					for (m1 = 0; m1 < 5000; m1++) {
						xh[m1] = m1 + 1;
					}//定义学号 
					for (m1 = 0; m1 < 5000; m1++) {
						ls[m1] = 0;
					}//临时变量初始化
					for (m1 = 0; m1 < 5000; m1++) {
						if (cj1[m1] != 404) {
							u1++;
						}
					}


					scanf("%d", &sw1);
					switch (sw1) {
					case 1:printf("请选择输入方式\n\n");
						printf("1、按学号顺序逐个输入数据\n");
						printf("2、多个学号输入同一成绩\n");
						printf("3、连续学号输入同一成绩\n\n\n");
						printf("4、选择学号输入姓名\n");
						printf("5、选择学号输入成绩\n\n");
						printf("在过程中若输入错误可以输入404退出\n\n");
						scanf("%d", &sc2);
						switch (sc2) {


						case 1:


							printf("请输入想要输入的成绩个数\n\n");
							scanf("%d", &sc1);
							sr = 0;
							printf("学号已按默认顺序排列，即第一个姓名对应一号，你无法更改\n\n");
							printf("请按学号顺序输入姓名与成绩\n\n");
							printf("假如有的学号姓名或成绩暂时不知道的，可暂时随便输入，然后再修改\n\n");
							for (; sr < sc1; cjsr++, sr++) {
								printf("请依次输入姓名和成绩\n\n");
								scanf("%d", &tc);
								gets(st[cjsr].xm);
								scanf("%f", &cj1[cjsr]);
								if (cj1[cjsr] == 404) {
									cj1[cjsr] = 0;
									goto kt;
								}
								printf("已输入学号:%d   姓名:%s   成绩:%f\n\n", xh[cjsr], st[cjsr].xm, cj1[cjsr]);
							}
							u2 = cjsr;
							break;



						case 2:
							printf("请输入想输入的成绩个数\n\n");
							scanf("%d", &sc6);
							printf("请依次输入为该成绩的学号\n");
							for (s1 = 0; s1 < sc6; s1++) {
								scanf("%d", &ls[s1]);
								if (ls[s1] == 404) {
									ls[s1] = 0;
									goto kt;
								}
							}
							printf("请输入统一的成绩\n");
							scanf("%f", &o1);
							for (p1 = 0; p1 < 5000; p1++) {
								for (s1 = 0; s1 < sc6; s1++) {
									if (xh[p1] == ls[s1]) {
										cj1[p1] = o1;
										printf("已输入学号%d成绩为%1.1f\n", xh[p1], cj1[p1]);
										printf("请到姓名输入处输入姓名\n\n");
									}
								}
							}
							u1 = cjsr;
							u1 = u1 + sc6;
							cjsr = u1;

							break;




						case 3:
							printf("请输入学号的起始位置:\n");
							scanf("%d%d", &sc7, &sc8);
							zj = sc7;
							printf("请输入统一的成绩:\n");
							scanf("%f", &o1);
							for (; sc7 <= sc8; sc7++) {
								cj1[sc7 - 1] = o1;
								printf("已输入成绩为%1.1f\n", o1);
							}
							for (s1 = 0; s1 < sc8; s1++) {
								xh[s1] = s1 + 1;
							}
							printf("学号已按默认顺序排列\n\n");
							u1 = cjsr;
							u1 = u1 + sc8 - zj + 1;
							cjsr = u1;
							printf("请到姓名输入处输入姓名\n");
							break;





						case 4:



							printf("请输入要输入姓名的学号的个数\n");
							scanf("%d", &sc12);
							printf("请输入要输入姓名的学号\n");
							for (m1 = 0; m1 < sc12; m1++) {
								scanf("%d", &ls[m1]);
								if (ls[m1] == 404) {
									ls[m1] = 0;
									goto kt;
								}
							}
							printf("请依次输入姓名\n");
							for (m1 = 0; m1 < sc12; m1++) {
								scanf("%d", &tc);
								gets(xmls);
								strcpy(st[ls[m1] - 1].xm, xmls);
							}
							u2 = u2 + sc12;
							break;





						case 5:


							printf("请输入想输入的成绩个数\n\n");
							scanf("%d", &sc6);
							printf("请输入要输入成绩的学号\n");
							for (s1 = 0; s1 < sc6; s1++) {
								scanf("%d", &ls[s1]);
								if (ls[s1] == 404) {
									ls[s1] = 0;
									goto kt;
								}
							}
							printf("请按顺序分别输入成绩\n");
							for (m1 = 0; m1 < sc6; m1++) {
								scanf("%f", &sc13);
								cj1[ls[m1] - 1] = sc13;
								printf("已输入学号:%d成绩%f\n", ls[m1], cj1[ls[m1] - 1]);
							}
							break;




						case 404:
							goto kt;
							break;


						default:printf("输入错误\n"); break;


						}
						break;









					case 2:

						printf("请确保导入文件中有数据\n");
						printf("若没有导入文件请点击生成导入文件后退出，即出现\n");
						printf("请输入要读取的数据的个数:\n");
						scanf("%d", &sc11);
						fin = fopen("姓名导入文件.txt", "rb");
						for (af1 = 0; af1 < sc11; af1++) {
							fscanf(fin, "%s", &st[af1].xm);
						}
						fin = fopen("成绩导入文件.txt", "rb");
						for (af1 = 0; af1 < sc11; af1++) {
							fscanf(fin, "%f", &cj1[af1]);
						}
						fin = fopen("名次导入文件.txt", "rb");
						for (af1 = 0; af1 < sc11; af1++) {
							fscanf(fin, "%d", &px[af1]);
						}
						fin = fopen("系统导入文件.txt", "rb");
						fscanf(fin, "%d", &cjsr);
						fscanf(fin, "%d", &cjsr);
						for (af1 = 0; af1 < sc11; af1++) {
							printf("已输入学号:%d   姓名:%s   成绩:%1.1f   名次:%d\n", af1, st[af1].xm, cj1[af1], px[af1]);
						}
						printf("读取成功\n");
						break;








					case 3:


						printf("请输入想要参加排序的成绩个数\n\n");
						scanf("%d", &sc3);
						for (pxbl1 = 0; pxbl1 < sc3; pxbl1++) {
							px[pxbl1] = sc3;
						}
						for (j1 = 1, pxbl1 = 0; j1 <= sc3; j1++) {
							for (pxbl2 = 0; pxbl2 < sc3; pxbl2++) {
								if (cj1[pxbl1] >= cj1[pxbl2] && pxbl2 != pxbl1) {
									px[pxbl1]--;
								}
								else if (cj1[pxbl1] < cj1[pxbl2]) {
									px[pxbl1] = px[pxbl1];
								}
							}
							pxbl1++;
						}
						printf("请选择排序方式\n");
						printf("1、按照升序显示\n");
						printf("2、按照降序显示\n");
						printf("3、直接显示名次\n");
						printf("4、退出\n");
						scanf("%d", &sw6);
						switch (sw6) {
						case 2:for (pl1 = 1; pl1 <= sc3; pl1++) {
							for (pl2 = 0; pl2 < sc3; pl2++) {
								if (px[pl2] == pl1) {
									printf("第%d名学号为%d  姓名为%s   成绩为%1.1f\n", pl1, xh[pl2], st[pl2].xm, cj1[pl2]);
								}
							}
						}break;
						case 1:for (pl3 = sc3; pl3 >= 1; pl3--) {
							for (pl4 = 0; pl4 < sc3; pl4++) {
								if (px[pl4] == pl3) {
									printf("第%d名学号为%d  姓名为%s   成绩为%1.1f\n", pl3, xh[pl4], st[pl4].xm, cj1[pl4]);
								}
							}
						}break;
						case 4:continue; break;
						case 3:
							for (pxbl1 = 0; pxbl1 < sc3; pxbl1++) {
								px[pxbl1] = sc3;
							}
							for (j1 = 1, pxbl1 = 0; j1 <= sc3; j1++) {
								for (pxbl2 = 0; pxbl2 < sc3; pxbl2++) {
									if (cj1[pxbl1] >= cj1[pxbl2] && pxbl2 != pxbl1) {
										px[pxbl1]--;
									}
									else if (cj1[pxbl1] < cj1[pxbl2]) {
										px[pxbl1] = px[pxbl1];
									}
								}
								pxbl1++;
							}
							for (pxbl1 = 0; pxbl1 < sc3; pxbl1++) {
								printf("学号%d  姓名为%s  成绩%1.1f  名次为%d\n\n", xh[pxbl1], st[pxbl1].xm, cj1[pxbl1], px[pxbl1]);
							}break;
						default:printf("输入错误\n"); break;
						}
						break;




					case 4:

						fout = fopen("成绩单.doc", "a+");
						printf("请输入保存的成绩个数:\n\n");
						scanf("%d", &sc9);
						printf("请先去排名次，防止发生输出错误\n");
						printf("输入404退出\n");
						scanf("%d", &sc14);
						if (sc14 == 404) {
							break;
						}
						for (ab1 = 0; ab1 < sc9; ab1++) {
							fprintf(fout, "学号:%d  姓名:%s  成绩:%1.1f  名次:%d\n", xh[ab1], st[ab1].xm, cj1[ab1], px[ab1]);
							printf("已保存学号:%d  姓名:%s  成绩:%1.1f  名次:%d\n", xh[ab1], st[ab1].xm, cj1[ab1], px[ab1]);
						}
						printf("保存成功\n");
						for (ab1 = 0; ab1 < sc9; ab1++) {
							fout = fopen("姓名导入文件.txt", "a+");
							fprintf(fout, "%s\n", st[ab1].xm);
							fout = fopen("姓名导出.doc", "a+");
							fprintf(fout, "%s\n", st[ab1].xm);
							fout = fopen("成绩导入文件.txt", "a+");
							fprintf(fout, "%1.1f\n", cj1[ab1]);
							fout = fopen("成绩导出.doc", "a+");
							fprintf(fout, "%1.1f\n", cj1[ab1]);
							fout = fopen("名次导入文件.txt", "a+");
							fprintf(fout, "%d\n", px[ab1]);
							fout = fopen("名次导出.doc", "a+");
							fprintf(fout, "%d\n", px[ab1]);
						}
						fout = fopen("系统导入文件.txt", "wb");
						fprintf(fout, "%d\n", u1);
						fprintf(fout, "%d\n", u2);
						break;











					case 5:
						printf("请选择查找方式\n");
						printf("1、按学号查找\n");
						printf("2、按成绩查找\n");
						printf("3、按名次查找\n");
						printf("4、按姓名查找\n");
						printf("5、按学号逐个输出\n");
						printf("注：请先去数据排序排名次,否则会发生错误\n");
						scanf("%d", &sw2);
						switch (sw2) {
						case 1:printf("请输入学生学号:\n\n");
							scanf("%d", &sc4);
							cjcz = 0;
							for (m1 = 0; m1 < u1; m1++) {
								if (xh[m1] == sc4) {
									cjcz++;
									printf("学号%d   姓名为%s   成绩为%1.1f   \n\n", sc4, st[m1].xm, cj1[m1]);
								}
							}
							printf("共搜索到%d个成绩\n", cjcz);
							break;
						case 2:printf("请输入学生成绩:\n\n");
							scanf("%f", &abc1);
							cjcz = 0;
							for (m1 = 0; m1 < u1; m1++) {
								if (cj1[m1] == abc1) {
									cjcz++;
									printf("学号%d   姓名为%s   成绩为%1.1f   \n\n", xh[m1], st[m1].xm, abc1);
								}
							}
							printf("共搜索到%d个成绩\n", cjcz);
							break;
						case 3:printf("请输入学生名次:\n\n");
							scanf("%d", &sc5);
							cjcz = 0;
							for (m1 = 0; m1 < u1; m1++) {
								if (px[m1] == sc5) {
									cjcz++;
									printf("学号%d   姓名为%s   成绩为%1.1f\n\n", xh[m1], st[m1].xm, cj1[m1]);
								}
							}
							printf("共搜索到%d个成绩\n", cjcz);
							break;
						case 4:printf("请输入学生姓名:\n\n");
							scanf("%d", &tc);
							gets(xmcz);
							cjcz = 0;
							for (m1 = 0; m1 < u2; m1++) {
								if (strcmp(st[m1].xm, xmcz) == 0) {
									cjcz++;
									printf("学号%d   姓名为%s   成绩为%1.1f  \n\n", xh[m1], xmcz, cj1[m1]);
								}
							}
							printf("共搜索到%d个成绩\n", cjcz);
							break;
						case 5:
							printf("请输入想要读取的成绩个数（按学号顺序读取）\n\n");
							scanf("%d", &sc2);
							for (f1 = 0; f1 < sc2; f1++) {
								printf("学号%d   姓名为%s   成绩为:%1.1f   \n\n", xh[f1], st[f1].xm, cj1[f1]);
							}
							break;

						default:printf("输入错误\n"); break;
						}//第三个switch
						break;








					case 6:printf("该程序会计算出某个分数段的人数，请输入分数段的间隔和试卷最高分\n\n");
						scanf("%d%d", &sc2, &sc3);
						for (t1 = 0; t1 < u1; t1++) {
							zf = zf + cj1[t1];
						}
						ave = zf / u1 * 1.0;
						w1 = cj1[0];
						x1 = cj1[0];
						for (t1 = 1; t1 < u1; t1++) {
							if (cj1[t1] > w1) {
								w1 = cj1[t1];
							}
						}
						for (t1 = 1; t1 < u1; t1++) {
							if (cj1[t1] < x1) {
								x1 = cj1[t1];
							}
						}
						for (t1 = 0; t1 < u1; t1++) {
							for (int tj = sc3; tj >= sc2; tj -= sc2) {
								if (cj1[t1] >= tj - sc2 && cj1[t1] < tj) {
									tjd[tj]++;
								}
							}

						}
						for (t1 = 0; t1 < u1; t1++) {
							if (cj1[t1] == sc3) {
								fs1++;
							}
							if (cj1[t1] >= (sc3 * 9 / 10)) {
								fs2++;
							}
							if (cj1[t1] >= (sc3 * 6 / 10) && cj1[t1] < (sc3 * 9 / 10)) {
								fs3++;
							}
						}
						printf("成绩总分为:%d\n", zf);
						printf("成绩平均分为:%1.1f\n", ave);
						printf("成绩最高分为:%1.1f\n", w1);
						printf("成绩最低分为:%1.1f\n", x1);
						printf("成绩满分人数为:%d\n", fs1);
						printf("成绩优秀人数为:%d\n", fs2);
						printf("成绩及格人数为:%d\n", fs3);

						for (int tj = sc3; tj >= sc2; tj -= sc2) {
							printf("%d分到%d分有%d人\n", tj, tj - sc2, tjd[tj]);
						}

						printf("具体名次请看成绩排序\n");
						break;








					case 7:printf("欢迎使用本程序\n\n");
						printf("此系统由张梓浩制作\n\n");
						printf("共527行，20000个字符\n\n");
						printf("QQ：2021577681\n\n");
						printf("感谢使用本程序\n\n");
						break;



					case 8:printf("欢迎再次使用\n\n");
						printf("感谢使用本程序\n\n");
						Sleep(500);
						return 0;
						break;



					case 9:fout = fopen("姓名导入文件.txt", "wb");
						fout = fopen("成绩导入文件.txt", "wb");
						fout = fopen("名次导入文件.txt", "wb");
						fout = fopen("系统导入文件.txt", "wb");
						fprintf(fout, "%d\n", u1);
						fprintf(fout, "%d\n", u2);
						break;
					default:printf("输入错误\n"); break;
					}//switch
				}//for
				break;
			}
			else {
				printf("程序已被封锁，请退出\n");
				return 0;
			}




			break;
			/////////////////////////////////////////////////////////////////////////////////////////////////







						   //字符加密系统 
		case 3:system("cls");
			if (fscx3 == 1) {
				for (;;) {
					printf("                               欢迎光临字符加密系统\n\n");
					printf("                                此系统由张梓浩制作\n\n");
					printf("注意事项1:请确保程序的保存处有“原文件.txt”,并往里面输入要加密的内容,否则无法加密\n\n");
					printf("注意事项2:解密时,请确保程序的保存处有“加密文件.txt”,否则无法解密\n\n");
					printf("请选择想要进入的程序:\n");
					printf("1、字符加密\n");
					printf("2、字符解密\n");
					printf("3、退出系统\n");
					printf("\n\n\n\n\n\n\n\n\n");
					scanf("%d", &sw5);
					switch (sw5) {
					case 1:char jm1[10000];
						char jm2[10000];
						int i2, x2;
						printf("请输入要加密字符的个数\n");
						scanf("%d", &x2);
						printf("请输入六位加密密钥,不要输入英文\n");
						printf("请记住加密密钥，否则无法成功解密\n");
						scanf("%I64d", &jmxt);
						fin = fopen("原文件.txt", "rb");
						for (i2 = 1; i2 <= x2; i2++) {
							fscanf(fin, "%c", &jm1[i2]);
						}
						for (i2 = 1; i2 <= x2; i2++) {
							jm2[i2] = jm1[i2] + jmxt;
						}
						printf("加密成功,已生成加密文件.txt,请到文件保存处查看\n");
						fout = fopen("加密文件.txt", "wb");
						for (i2 = 1; i2 <= x2; i2++) {
							fprintf(fout, "%d\n", jm2[i2]);
						}
						break;
					case 2:char jm3[1000];
						char jm4[1000];
						int i3, x3;
						printf("请输入要加密的字符个数\n");
						scanf("%d", &x3);
						printf("请输入六位当初加密输入的加密密钥，不要输入英文\n");
						printf("忘记加密密钥者,将无法解密,对不起\n");
						scanf("%I64d", &jmxt);
						fin = fopen("加密文件.txt", "rb");
						for (i3 = 1; i3 <= x3; i3++) {
							fscanf(fin, "%d", &jm3[i3]);
						}
						for (i3 = 1; i3 <= x3; i3++) {
							jm4[i3] = jm3[i3] - jmxt;
							printf("%c", jm4[i3]);
						}
						printf("解密成功,已生成解密文件.txt,请到文件保存处查看\n");
						fout = fopen("解密文件.txt", "wb");
						for (i3 = 1; i3 <= x3; i3++) {
							fprintf(fout, "%c", jm4[i3]);
						}
						break;
					case 3:return 0;
						break;
					default:printf("输入错误\n"); break;
					}//switch
				}//for
			}//if 
			else {
				printf("程序已被封锁，请退出\n");
				return 0;
			}




			break;
			////////////////////////////////////////////////////////////////////////////////






		case 4:system("cls");
			if (fscx4 == 1) {








				FILE* fin;
				FILE* fout;
				fin = fopen("level1.txt", "rb");
				fscanf(fin, "%f", &yf);
				fin = fopen("level21.txt", "rb");
				fscanf(fin, "%d", &yf1);
				fin = fopen("level22.txt", "rb");
				fscanf(fin, "%d", &yf2);
				fin = fopen("level23.txt", "rb");
				fscanf(fin, "%d", &yf3);
				fin = fopen("level3.txt", "rb");
				fscanf(fin, "%d", &yf4);




				fin = fopen("level41.txt", "rb");
				fscanf(fin, "%d", &ys1);
				fin = fopen("level42.txt", "rb");
				fscanf(fin, "%d", &ys2);
				fin = fopen("level.txt", "rb");
				fscanf(fin, "%d", &dj);



				system("color a");



				for (;;) {



					unsigned char ch = 80;
					HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄 
					sfkf = 0;//重要信息初始化 
					sl = 0;
					sw = 0;
					fh = 0;
					z = 0;
					sudu = 0;
					pf = 2;
					zd = 0;
					fhs = 100;
					sd = 0;
					tz = 0;
					nd = 2;
					xs = 5;
					qk = 0;
					fw = 1;
					zs = 0;
					zsfz = 0;
					a = 29;
					b = 4;
					bushu = 0;
					ms = 0;
					yx = 1;
					tg = 0;
					qk2 = 0;
					sw1 = 0;
					fh1 = 0;
					sd1 = 0;
					sd2 = 0;
					sd3 = 0;
					fhcs = 0;





					for (int m = 0; m < 200; m++) {
						for (int n = 0; n < 200; n++) {
							zb[m][n] = 0;
							dl[m][n] = 0;
							zg[m][n] = 0;
						}
					}





					struct Snake s, * snake = &s;
					initsnake(snake);
					struct snake1 s1, * snake1 = &s1;
					initsnake1(snake1);
					struct snake2 s2, * snake2 = &s2;
					initsnake2(snake2);//重要信息初始化


					system("color a");

					cover(hout);//开始界面
					welcome(hout);//欢迎界面 





					if (ds == 1) {
						menu(hout, snake);//菜单选择 
					}
					else {
						menu2(hout, snake1, snake2);
					}





					if (qk == 1) {
						fout = fopen("level1.txt", "wb");
						fprintf(fout, "0");
						fout = fopen("level21.txt", "wb");
						fprintf(fout, "896");
						fout = fopen("level22.txt", "wb");
						fprintf(fout, "640");
						fout = fopen("level23.txt", "wb");
						fprintf(fout, "384");
						fout = fopen("level3.txt", "wb");
						fprintf(fout, "0");
					}




					if (tc == 1) {
						goto tccx;//退出游戏 
					}




					if (ds == 1) {//单人游戏  







						if (sfkf == 1) {
							goto kfms;
						}

						//普通游戏循环 

						system("color a");

						while (1) {
						yx:

							switch (dt) {
							case 1:makeframe1(snake);
								break;
							case 2:makeframe2(snake);
								break;
							case 3:makeframe3(snake);
								break;
							}//地图选择 
							if (ms == 6) {
								system("color 1");
								ms = 100;
								goto xc;
							}
							if (ms == 100) {
								system("color 4");
								ms = 101;
								goto xc;
							}
							if (ms == 101) {
								system("color 5");
								ms = 102;
								goto xc;
							}
							if (ms == 102) {
								system("color 2");
								ms = 103;
								goto xc;
							}
							if (ms == 103) {
								system("color 6");
								ms = 6;
								goto xc;
							}//炫彩模式 
						xc:
							if (zd == 2) {
								snake->x[snake->length - 1] = a;
								snake->y[snake->length - 1] = b;
								ch = getch();
								zd = 0;
							}//迷宫关节点开始 
							if (zd == 1) {//节点开始 

								if (fhs == 1) {
									dyjd = snake->y[snake->length - 1];
									snake->x[snake->length - 1] = 7;
									snake->y[snake->length - 1] = 3;
									switch (dt) {
									case 1:makeframe1(snake);
										break;
									case 2:makeframe2(snake);
										break;
									}
									fhs = 0;
									goto xm;
								}


								if (fhs != 0) {
									switch (dt) {
									case 1:dyjd = 50;
										break;
									case 2:dyjd = 60;
										break;
									}
								}


							xm:
								if (snake->y[snake->length - 1] <= dyjd) {


									if (dl[snake->x[snake->length - 1]][snake->y[snake->length - 1] + 1] == 1
										&& zg[snake->x[snake->length - 1]][snake->y[snake->length - 1] + 1] != 1) {
										snake->y[snake->length - 1] += 1;
										zg[snake->x[snake->length - 1]][snake->y[snake->length - 1]] = 1;
										goto zh;
									}
									for (int e = 0; e < 5; e = e + 2) {
										if (dl[snake->x[snake->length - 1] + e][snake->y[snake->length - 1]] == 1
											&& zg[snake->x[snake->length - 1] + e][snake->y[snake->length - 1]] != 1) {
											snake->x[snake->length - 1] += e;
											zg[snake->x[snake->length - 1]][snake->y[snake->length - 1]] = 1;
											goto zh;
										}
									}
									for (int f = 0; f < 5; f = f + 2) {
										if (dl[snake->x[snake->length - 1] - f][snake->y[snake->length - 1]] == 1
											&& zg[snake->x[snake->length - 1] - f][snake->y[snake->length - 1]] != 1) {
											snake->x[snake->length - 1] -= f;
											zg[snake->x[snake->length - 1]][snake->y[snake->length - 1]] = 1;
											goto zh;
										}
									}

								zh:
									movesnake(hout, snake);
									printsnake(hout, snake);
									goto yx;
								}
								else {
									zd = 0;
									for (int m = 0; m < 200; m++) {
										for (int n = 0; n < 200; n++) {
											zg[m][n] = 0;
										}
									}
									ch = getch();
								}
							}//节点开始游戏  
							j = 0;
							if (kbhit()) {
								ch = getch();
								if (kbhit()) {
									Sleep(20);
									j = 1;
								}
							}//输入 
							//移动蛇 
							switch (ch) {
							case'W':
							case 'w':
							case 72: {
								movesnake(hout, snake);
								snake->y[snake->length - 1] -= 1;
								break;
							}
							case'S':
							case 's':
							case 80: {
								movesnake(hout, snake);
								snake->y[snake->length - 1] += 1;
								break;
							}
							case'A':
							case 'a':
							case 75: {
								movesnake(hout, snake);
								snake->x[snake->length - 1] -= 2;
								break;
							}
							case'D':
							case 'd':
							case 77: {
								movesnake(hout, snake);
								snake->x[snake->length - 1] += 2;
								break;
							}
							}//移动蛇 
							if (ms == 1 || ms == 3) {
								if (yx % 3 == 1) {
									goto tgdy;
								}

							}
							printsnake(hout, snake);
						tgdy:
							yx++;
							bushu++;
							//输出蛇 
							if (ifdead(snake) == 0) {
								break;
							}//死亡判断 

							zsfz++;
							if (zsfz == 2) {
								zs = 0;
							}//补丁 
							if (sl == 1) {
								system("cls");
								goto fs;
							}//胜利后 
							if (j == 0)
								Sleep(snake->speed);
							else
								Sleep(20);//速度控制 

						}//一次游戏循环while
						system("color a");
						system("cls");


						if (sl != 1 && fh == 0 && fhcs != 1) {
						sffh:system("cls");
							printf("\n\n\n\n\n\n\n\n                                   你是否要复活\n");
							printf("\n\n                  1、是                                2、否\n\n");
							scanf("%d", &c3);
							switch (c3) {
							case 1:
								fh = 1;
								fhcs = 1;
								if (ms == -1) {
									ms = 4;
								}
								break;
							case 2:
								break;
							default:
								printf("输入错误，请输入1或2\n\n");
								Sleep(1000);
								goto sffh;
							}//选择复活 
						}

						system("cls");

						if (fh > 0) {
							fh--;
							switch (dt) {
							case 1:
								system("cls");
								zd = 1;
								fhs = 1;
								goto yx;
								break;
								//新手关复活 

							case 2:
								system("cls");
								zd = 1;
								fhs = 1;
								goto yx;
								break;
								//手速关复活 

							case 3:
								if (snake->x[snake->length - 1] <= 28) {
									snake->x[snake->length - 1] = 7;
									snake->y[snake->length - 1] = 3;
									goto hm;
								}
								if (snake->x[snake->length - 1] <= 50) {
									snake->x[snake->length - 1] = 29;
									snake->y[snake->length - 1] = 4;
									goto hm;
								}
								if (snake->x[snake->length - 1] <= 77) {
									snake->x[snake->length - 1] = 51;
									snake->y[snake->length - 1] = 4;
									goto hm;
								}
								if (snake->x[snake->length - 1] > 77) {
									snake->x[snake->length - 1] = 73;
									snake->y[snake->length - 1] = 4;
									goto hm;
								}
							hm:ch = 80;
								zs = 1;
								goto yx;
								break;
								//迷宫关复活 
							}//switch

						}//复活 

					fs:
						sudu = snake->speed;
						z = snake->y[snake->length - 1];//计分 

						system("cls");

						switch (dt) {
						case 1: if (z >= yf) {
							yf = z;
							fout = fopen("level1.txt", "wb");
							fprintf(fout, "%f\n", yf);

						}
							  if (sl == 1) {
								  printf("\n\n\n\n\n\n\n                               你赢了,你的得分是100分");
								  dj += nd;
							  }
							  else
								  printf("\n\n\n\n\n\n\n                    你输了,重新开始吧,你的得分是%f分", floor(z / 118 * 100));

							  printf("\n\n\n\n\n\n\n                             你的最高纪录是%f", floor(yf / 118 * 100));


							  if (sl == 1) {
								  printf("\n\n\n\n\n\n\n                             你成功升级，当前等级:%d级", dj);
							  }
							  break;


						case 2:	switch (xs) {
						case 7:if (sudu <= yf1) {
							yf1 = sudu;
							fout = fopen("level21.txt", "wb");
							fprintf(fout, "%d", yf1);
						}
							  break;
						case 5:
							if (sudu <= yf2) {
								yf2 = sudu;
								fout = fopen("level22.txt", "wb");
								fprintf(fout, "%d", yf2);
							}
							break;
						case 3:
							if (sudu <= yf3) {
								yf3 = sudu;
								fout = fopen("level23.txt", "wb");
								fprintf(fout, "%d", yf3);
							}
							break;
						}

							  printf("\n\n\n\n\n\n\n                      你能达到的速度是%d(最高速度是%d)", 128 * xs - sudu, 127 * xs);

							  switch (xs) {
							  case 7:printf("\n\n\n\n\n\n\n                             你的最高纪录是%d", 128 * xs - yf1);
								  if (128 * xs - sudu == 127 * xs) {
									  dj += 1;
									  printf("\n\n\n\n\n\n\n                         你成功升级，当前等级:%d级", dj);
								  }
								  break;
							  case 5:printf("\n\n\n\n\n\n\n                             你的最高纪录是%d", 128 * xs - yf2);
								  if (128 * xs - sudu == 127 * xs) {
									  dj += 2;
									  printf("\n\n\n\n\n\n\n                         你成功升级，当前等级:%d级", dj);
								  }
								  break;
							  case 3:printf("\n\n\n\n\n\n\n                             你的最高纪录是%d", 128 * xs - yf3);
								  if (128 * xs - sudu == 127 * xs) {
									  dj += 3;
									  printf("\n\n\n\n\n\n\n                         你成功升级，当前等级:%d级", dj);
								  }
								  break;
							  }



							  break;

						case 3: if (bushu >= yf4) {
							yf4 = bushu;
							fout = fopen("level3.txt", "wb");
							fprintf(fout, "%d\n", yf4);
						}

							  printf("\n\n\n\n\n\n\n                                你坚持了%d秒", bushu);

							  printf("\n\n\n\n\n\n\n                             你的最高纪录是%d", yf4);

							  if (sl == 1) {
								  dj += nd;
								  printf("\n\n\n\n\n\n\n                        你成功升级，当前等级:%d级", dj);
							  }
							  break;

						}//输出分数 

						Sleep(2000);

						if (3 == 2) {
						kfms:kf();
							scanf("%c", &c1);
							scanf("%c", &c1);
							system("cls");
						}//开发模式 







					}//单人模式游戏 





















					if (ds == 2) {

					cxks:



						if (qk2 == 1) {
							fout = fopen("level41.txt", "wb");
							fprintf(fout, "0");
							fout = fopen("level42.txt", "wb");
							fprintf(fout, "0");
							qk2 = 0;
						}



						initsnake1(snake1);
						initsnake2(snake2);




						system("cls");
						map(hout);



						if (sd3 == 1) {
							snake1->speed1 = sd1;
							snake2->speed2 = sd2;
							sd3 = 0;
						}



						ch = getch();
						while (1) {


							j = 0;
							if (kbhit()) {
								ch = getch();
								if (kbhit()) {
									Sleep(20);
									j = 1;
								}
							}//输入 
							//移动蛇


							if (sw1 == 0) {

								if (ifdead3(snake1, snake2) == 0 || ifdead4(snake1, snake2) == 0 || ifdead1(snake1) == 0 || ifdead2(snake2) == 0) {
									break;
								}//死亡判断	

							}


							switch (ch) {



							case'W':
							case 'w':
							{

								movesnake1(hout, snake1);
								snake1->y1[snake1->length1 - 1] -= 1;
								printsnake1(hout, snake1);
								if (j == 0)
									Sleep(snake1->speed1);
								else
									Sleep(20);//速度控制 
								break;
							}
							case'S':
							case 's':
							{

								movesnake1(hout, snake1);
								snake1->y1[snake1->length1 - 1] += 1;
								printsnake1(hout, snake1);
								if (j == 0)
									Sleep(snake1->speed1);
								else
									Sleep(20);//速度控制 
								break;
							}
							case'A':
							case 'a':
							{

								movesnake1(hout, snake1);
								snake1->x1[snake1->length1 - 1] -= 2;
								printsnake1(hout, snake1);
								if (j == 0)
									Sleep(snake1->speed1);
								else
									Sleep(20);//速度控制 
								break;
							}
							case'D':
							case 'd':
							{

								movesnake1(hout, snake1);
								snake1->x1[snake1->length1 - 1] += 2;
								printsnake1(hout, snake1);
								if (j == 0)
									Sleep(snake1->speed1);
								else
									Sleep(20);//速度控制 
								break;
							}
							case 72:
							{
								movesnake2(hout, snake2);
								snake2->y2[snake2->length2 - 1] -= 1;
								printsnake2(hout, snake2);
								if (j == 0)
									Sleep(snake2->speed2);
								else
									Sleep(20);//速度控制 
								break;
							}
							case 80:
							{
								movesnake2(hout, snake2);
								snake2->y2[snake2->length2 - 1] += 1;
								printsnake2(hout, snake2);
								if (j == 0)
									Sleep(snake2->speed2);
								else
									Sleep(20);//速度控制 
								break;
							}
							case 75:
							{
								movesnake2(hout, snake2);
								snake2->x2[snake2->length2 - 1] -= 2;
								printsnake2(hout, snake2);
								if (j == 0)
									Sleep(snake2->speed2);
								else
									Sleep(20);//速度控制
								break;
							}
							case 77:
							{
								movesnake2(hout, snake2);
								snake2->x2[snake2->length2 - 1] += 2;
								printsnake2(hout, snake2);
								if (j == 0)
									Sleep(snake2->speed2);
								else
									Sleep(20);//速度控制 
								break;
							}

							}//移动蛇 









						}//while



						system("cls");


						if (ifdead1(snake1) == 0 || ifdead4(snake1, snake2) == 0) {
							printf("\n\n\n\n\n\n\n                                    # 玩家赢了\n\n");
							ys2++;
							Sleep(2000);
						}



						if (ifdead2(snake2) == 0 || ifdead3(snake1, snake2) == 0) {
							printf("\n\n\n\n\n\n\n                                    ^ 玩家赢了\n\n");
							ys1++;
							Sleep(2000);
						}


						if (fh1 != 0) {

							fh1--;
							goto cxks;

						}
						else {

						sffh1:
							system("cls");
							printf("\n\n\n\n\n\n\n\n                                  你是否要复活\n");
							printf("\n\n                  1、是                                2、否\n\n");
							scanf("%d", &c3);
							switch (c3) {
							case 1:
								goto cxks;
								break;
							case 2:
								break;
							default:
								printf("输入错误，请输入1或2\n\n");
								Sleep(1000);
								goto sffh1;
							}//选择复活

						}




						fout = fopen("level41.txt", "wb");
						fprintf(fout, "%d", ys1);
						fout = fopen("level42.txt", "wb");
						fprintf(fout, "%d", ys2);

					}//ds




					fout = fopen("level.txt", "wb");
					fprintf(fout, "%d", dj);






				}//for


			tccx:
				fout = fopen("level.txt", "wb");
				fprintf(fout, "%d", dj);


				return 0;

			}
			else {
				printf("程序已被封锁，请退出\n");
				return 0;
			}




			break;





			/////////////////////////////////////////////////////////////////////////////////////////




		case 5:system("cls");




			int a, b, c, d, i, e, f, g, h, j, k, l, m, n, z, aa, bb, cc, dd;//case 5的变量 
			float  q, r, s, t, u, v, w;//成绩变量 
			double ee, ff;//成绩变量 
			int kk, ll, mm, nn, oo, pp, ww, xx, yy, zzz;
			long long ab, ac, ad, ae;//密码变量 
			int ba, bm, bc, bd, be, bf, bg, bh, bi, bj, bk, bl;//解数学题     
			int zz, af, ah, ai, ak;//开发人员专用内的变量 
			int al, am, an;
			long long uu, vv, qq, rr, o, p, gg, hh, ii, jj;
			i = 0;//记录考试成绩 
			zz = 1; //病毒循环次数 
			pp = 3;//循环次数 
			mm = 0;
			nn = 0;
			o = 1;//帐号 
			p = 1;//密码 
			gg = 2;//帐号 
			hh = 2;//密码 
			ii = 3;//帐号 
			jj = 3;//密码 
			qq = 4;//帐号 
			rr = 4; //密码 
			ll = 1000;//重新登录次数 
			uu = 5;//帐号 
			vv = 5;//密码 
			xx = 0;//判断是否显示正在维修中 
			al = 0;//判断是否显示正在锁定中
			an = 0;//保护系统，判断是否在保护中 
			ad = 1;
			ae = 1;



			if (fscx5 == 1) {
				for (kk = 0; kk < ll; kk++) {
					printf("                                  欢迎来到张梓浩网站\n\n");
					printf("                                此网站由张梓浩精心制作\n\n");
					printf("                                  网站还在不断更新中\n\n");
					printf("                             上一次更新时间：2017年12月3日\n\n");
					printf("                               最近更新时间：2018年2月6日\n\n");
					printf("请依次输入登录帐号和密码\n\n");
					printf("请输入帐号：\n");
					if (pm == 1) {
						printf("\n\n\n\n\n\n\n\n\n\n\n\n");
					}
					pm = 2;
					scanf("%d", &l);
					printf("请输入密码：\n\n");
					scanf("%d", &m);
					if (xx == 1) {
						printf("网站正在维修中，谢谢你的光临\n\n");
						scanf("%d");
					}//
					else if (al == 1) {
						printf("网站已锁定，请退出\n\n");
						printf("欢迎下次光临\n");
						return 0;
					}//
					else if (l == o && m == p) {
						printf("登录成功，张梓浩你好，请选择想要进入的系统\n\n");
					}
					else if (l == gg && m == hh) {
						printf("登录成功，路人甲你好，请选择想要进入的系统\n\n");
					}
					else if (l == ii && m == jj) {
						printf("登录成功，路人乙你好，请选择想要进入的系统\n\n");
					}
					else if (l == qq && m == rr) {
						printf("登录成功，开发人员你好\n\n");
						printf("                             开发人员专用\n\n");
						printf("                          非开发人员请勿登录\n\n");
						printf("                             请勿胡乱输入\n\n");
						printf("                      非专业人员请勿随意修改原程序\n\n");
						printf("请输入登录帐号和密码\n\n");
						printf("请输入帐号\n");
						scanf("%I64d", &ab);
						printf("请输入密码\n");
						scanf("%I64d", &ac);
						if (ab == ad && ac == ae) {
							for (ai = 0; ai < 3; ai++) {
								printf("请选择相应的程序\n\n");
								printf("1、查看当前各变量的值\n\n");
								printf("2、修改用户帐号密码(暂时)\n\n");
								printf("3、查看各板块的循环次数\n\n");
								printf("4、关闭系统，开启维修状态(暂时)\n\n");
								printf("5、锁定网站，禁止登录(暂时)\n\n");
								printf("6、系统监视\n\n");
								printf("7、关闭保护系统(暂时)\n\n");
								scanf("%d", &af);
								switch (af) {
								case 1: printf("zz=%d\n", zz);
									printf("a=%d\n", a);
									printf("b=%d\n", b);
									printf("c=%d\n", c);
									printf("d=%d\n", d);
									printf("e=%d\n", e);
									printf("f=%d\n", f);
									printf("g=%d\n", g);
									printf("h=%d\n", h);
									printf("i=%d\n", i);
									printf("j=%d\n", j);
									printf("l=%d\n", l);
									printf("m=%d\n", m);
									printf("n=%d\n", n);
									printf("o=%d\n", o);
									printf("p=%d\n", p);
									printf("z=%d\n", z);
									printf("aa=%d\n", aa);
									printf("bb=%d\n", bb);
									printf("cc=%d\n", cc);
									printf("dd=%d\n", dd);
									printf("ee=%d\n", ee);
									printf("ff=%d\n", ff);
									printf("gg=%d\n", gg);
									printf("ii=%d\n", ii);
									printf("jj=%d\n", jj);
									printf("zzz=%d\n", zzz);
									printf("kk=%d\n", kk);
									printf("ll=%d\n", ll);
									printf("mm=%d\n", mm);
									printf("nn=%d\n", nn);
									printf("oo=%d\n", oo);
									printf("pp=%d\n", pp);
									printf("qq=%d\n", qq);
									printf("rr=%d\n", rr);
									printf("uu=%d\n", uu);
									printf("vv=%d\n", vv);
									printf("ww=%d\n", ww);
									printf("xx=%d\n", xx);
									printf("yy=%d\n", yy);
									break;

								case 2:printf("请选择要修改的用户\n\n");
									printf("提示：此为暂时更改，永久更改请修改原程序\n\n");
									printf("1、张梓浩\n");
									printf("2、路人甲\n");
									printf("3、路人乙\n");
									printf("4、游客\n");
									scanf("%d", &ah);
									switch (ah) {
									case 1:printf("请输入帐号\n");
										scanf("%d", &o);
										printf("请输入密码\n");
										scanf("%d", &p); break;
									case 2:printf("请输入帐号\n");
										scanf("%d", &ii);
										printf("请输入密码\n");
										scanf("%d", &jj); break;
									case 3:printf("请输入帐号\n");
										scanf("%d", &gg);
										printf("请输入密码\n");
										scanf("%d", &hh); break;
									case 4:printf("请输入帐号\n");
										scanf("%d", &uu);
										printf("请输入密码\n");
										scanf("%d", &vv); break;
									}break;
								case 3:printf("当前重新登录次数为\n\n");
									printf("%d\n\n", ll - 1);
									printf("考试天地循环次数为\n\n");
									printf("%d\n\n", 2);
									printf("其他应用循环次数为\n\n");
									printf("%d\n\n", 2);
									printf("cmd命令循环次数为\n\n");
									printf("%d\n\n", 3);
									printf("其他板块均不循环\n\n");
									printf("更改循环次数请修改原程序\n\n");
									break;

								case 4:printf("请输入1，开启维修状态\n\n");
									printf("想永久开启维修状态，请修改原程序\n\n");
									scanf("%d", &xx);
									break;
								case 5:printf("请输入1，开启锁定状态\n\n");
									printf("想永久开启锁定状态，请修改原程序\n\n");
									scanf("%d", &al); break;
								case 6:printf("当前系统状况为\n\n");
									printf("主板块有\n\n");
									Sleep(1000);
									printf("1、考试天地\n");
									Sleep(1000);
									printf("2、应用程序\n");
									Sleep(1000);
									printf("3、cmd命令\n");
									Sleep(1000);
									printf("4、成绩录入\n");
									Sleep(1000);
									printf("5、成绩查看\n");
									Sleep(1000);
									printf("6、解数学题\n");
									Sleep(1000);
									printf("7、退出网站\n");
									Sleep(1000);
									printf("8、知识天地\n");
									Sleep(1000);
									printf("9、附加功能\n");
									printf("副板块选项共有：");
									Sleep(1000);
									printf("请选择考试科目\n");
									printf("1、英语\n");
									printf("2、数学\n");
									printf("3、语文\n");
									printf("4、退出\n");
									Sleep(1000);
									printf("1、查询考试成绩\n");
									printf("2、查看编者留言\n");
									printf("3、华氏度转摄氏度\n");
									printf("4、字符串加密\n");
									printf("5、锁定鼠标\n");
									printf("6、退出\n");
									Sleep(1000);
									printf("请选择命令\n");
									printf("1、立即关机\n");
									printf("2、取消关机\n");
									printf("3、打开组策略\n");
									printf("4、打开注册表\n");
									printf("5、查看ip地址\n");
									printf("6、设置电脑密码为123456\n");
									printf("7、查看电脑账户信息\n");
									printf("8、打开资源管理器。\n");
									printf("9、注销命令。\n");;
									printf("10、本机用户和组。\n");
									printf("11、本地服务设置。\n");
									printf("12、打开记事本。\n");
									printf("13、退出\n");
									break;
								case 7:printf("关闭保护系统请输入1，想永久关闭请修改原程序\n\n");
									scanf("%d", &an); break;
								default:printf("输入错误\n\n"); break;
								}
							}
						}
						else {
							printf("帐号或密码错误\n\n");
							printf("请不要随意点击\n\n");
							scanf("%d");
							return 0;
							break;
						}//与if相对 
						printf("是否返回主页，是请输入1，不是请输入2退出网站\n\n");
						scanf("%d", &am);
						if (am == 1) {
							printf("请选择想要进入的系统\n\n");
						}
						else {
							printf("欢迎下次光临\n");
							scanf("%d");
							return 0;
						}
					}
					else if (l == uu && m == vv) {
						printf("登录成功，游客你好，请选择想要进入的系统\n\n");
					}//游客帐号 
					else {
						printf("帐号或密码错误\n\n");
						printf("欢迎下次光临\n");
						scanf("%d");
						return 0;
					}



					for (n = 0; n < pp; n++) {
						printf("                                      网站首页\n\n");
						printf("1、考试天地\n");
						printf("2、应用程序\n");
						printf("3、cmd命令\n");
						printf("4、成绩输入\n");
						printf("5、成绩查看\n");
						printf("6、解数学题\n");
						printf("7、知识天地\n");
						printf("8、附加功能\n");
						printf("9、退出网站\n");
						printf("请输入：\n");
						scanf("%d", &k);
						switch (k) {

						case 1:
							for (f = 0; f < 3; f++) {
								printf("                                      考试天地\n\n");
								printf("请选择考试科目,每科均为1道题\n");
								printf("考试成绩请到应用程序处查询\n");
								printf("1、英语\n");
								printf("2、数学\n");
								printf("3、语文\n");
								printf("4、退出\n");
								printf("请输入：\n\n");
								scanf("%d", &a);
								switch (a) {
								case 1:printf("1、I hope you can pass the exam!\n\n");
									printf("1、I hope too 2、I think I can not 3、I hope so\n\n");
									printf("请输入：\n\n");
									scanf("%d", &b);
									if (b == 3) {
										printf("你答对了\n\n");
										i = i + 1;
									}
									else {
										printf("你答错了\n\n");
									}break;
								case 2:printf("1、有一个三角形，它的三边长为7、8、11，这是什么三角形\n\n");
									printf("1、锐角 2、直角 3、钝角\n\n");
									printf("请输入：\n\n");
									scanf("%d", &c);
									if (c == 1) {
										printf("你答对了\n\n");
										i = i + 1;
									}
									else {
										printf("你答错了\n\n");
									}break;
								case 3:printf("1、一笔画的字有多少个\n\n");
									printf("1、1个  2、2个  3、3个\n\n");
									printf("请输入：\n\n");
									scanf("%d", &d);
									if (d == 3) {
										printf("你答对了\n\n");
										i = i + 1;
									}
									else {
										printf("你答错了\n\n");
									}break;
								case 4:if (a == 4) {
									printf("欢迎下次光临\n");
									return 0;
								}
								default:printf("输入错误\n\n");
								}//case 1 switch
							}//case 1 for
							break;

						case 2:
							for (g = 0; g < 2; g++) {
								printf("                                     应用程序\n\n");
								printf("请选择相关内容\n\n");
								printf("1、查询考试成绩\n");
								printf("2、查看编者留言\n");
								printf("3、华氏度转摄氏度\n");
								printf("4、字符串加密\n");
								printf("5、锁定鼠标\n");
								printf("6、退出\n");
								printf("请输入：\n\n");
								scanf("%d", &e);
								switch (e) {
								case 1:printf("你的成绩是:\n\n");
									printf("你答对了%d题\n\n", i); break;
								case 2:printf(" 此网站由张梓浩精心制作，总长度为36000字符,总行数为1100行\n\n"); break;
								case 3:printf("请输入华氏度\n");
									scanf("%lf", &ff);
									ee = (5.0 / 9.0) * (ff - 32);
									printf("摄氏度为%0.2lf\n\n", ee); break;
								case 6:if (e == 6) {
									printf("欢迎下次光临\n");
									return 0;
								}
								case 4:printf("请输入5个字符\n");
									char c1, c2, c3, c4, c5, c6;
									scanf("%c", &c1);
									scanf("%c", &c2);
									scanf("%c", &c3);
									scanf("%c", &c4);
									scanf("%c", &c5);
									scanf("%c", &c6);
									printf("原字符串为%c%c%c%c%c%c\n\n\n", c1, c2, c3, c4, c5, c6);
									c1 += 4;
									c2 += 4;
									c3 += 4;
									c4 += 4;
									c5 += 4;
									c6 += 4;
									printf("加密后为：%c%c%c%c%c%c\n\n\n", c1, c2, c3, c4, c5, c6);
									break;
								case 5:while (1) {
									SetCursorPos(0, 0);
								}
									  break;
								default:printf("输入错误\n\n");
								}
								break;
						case 3:
							for (j = 0; j < 3; j++) {
								printf("                                      cmd命令\n\n");
								printf("请选择命令\n");
								printf("1、立即关机\n");
								printf("2、取消关机\n");
								printf("3、打开组策略\n");
								printf("4、打开注册表\n");
								printf("5、查看ip地址\n");
								printf("6、设置电脑密码为123456\n");
								printf("7、查看电脑账户信息\n");
								printf("8、打开资源管理器。\n");
								printf("9、注销命令。\n");;
								printf("10、本机用户和组。\n");
								printf("11、本地服务设置。\n");
								printf("12、打开记事本。\n");
								printf("13、退出\n");
								printf("请输入：\n\n");
								scanf("%d", &h);
								switch (h) {
								case 1:system("shutdown -s -t 120"); break;
								case 2:system("shutdown -a"); break;
								case 3:system("gpedit.msc"); break;
								case 4:system("regedit"); break;
								case 5:system("ipconfig"); break;
								case 6:system("net user administrator 123456"); break;
								case 7:system("net user administrator"); break;
								case 13:if (h == 13) {
									printf("欢迎下次光临\n");
									return 0;
								}
								case 8:system("explorer"); break;
								case 9:system("logoff"); break;
								case 10:system("lusrmgr.msc"); break;
								case 11:system("services.msc"); break;
								case 12:system("notepad"); break;
								default:printf("输入错误\n\n"); break;
								}//switch
							}//case 3 for
							break;

						case 4:
							printf("                                      成绩录入\n\n");
							printf("优质的成绩服务请到张梓浩成绩管理系统\n");
							printf("这里只能输入七个成绩,为你统计信息\n");
							printf("请输入成绩\n\n");
							scanf("%f", &q);
							scanf("%f", &r);
							scanf("%f", &s);
							scanf("%f", &t);
							scanf("%f", &u);
							scanf("%f", &v);
							scanf("%f", &w);
							printf("各科成绩为：%1.1f\n %1.1f\n %1.1f\n %1.1f\n %1.1f\n %1.1f\n %1.1f\n", q, r, s, t, u, v, w);
							printf("总分为：%2.f\n", q + r + s + t + u + v + w);
							printf("平均分为：%2.f\n", (q + r + s + t + u + v + w) / 7); break;

						case 9:if (k == 9) {
							printf("欢迎下次光临\n");
							scanf("%d");
							return 0;
						}

						case 5:printf("                                      成绩查看\n\n");
							printf("请先去成绩录入板块输入成绩\n\n\n");
							printf("请核实信息是否正确\n\n\n");
							printf("各科成绩为：%1.1f\n %1.1f\n %1.1f\n %1.1f\n %1.1f\n %1.1f\n %1.1\n", q, r, s, t, u, v, w);
							printf("总分为：%2.1f\n", q + r + s + t + u + v + w);
							printf("平均分为：%2.1f\n", (q + r + s + t + u + v + w) / 7); break;

						case 6:printf("                                      解数学题\n\n");
							printf("请选择想要解决的问题\n");
							printf("1、鸡兔同笼问题\n");
							printf("2、牛吃草问题\n");
							scanf("%d", &sw7);
							switch (sw7) {
							case 1:
								printf("请分别输入头数与脚数\n\n\n");
								scanf("%d%d", &aa, &bb);
								cc = (4 * aa - bb) / 2;
								dd = aa - cc;
								if (bb % 2 == 1 || cc < 0 || dd < 0) {
									printf("NO answer\n");
								}
								else {
									printf("鸡数为%d 兔数为%d\n", cc, dd);
								}break;
							case 2:
								printf("请输入整数量\n\n");
								printf("请依次输入几头牛几天吃完草\n\n\n");
								scanf("%d%d", &ba, &bm);
								printf("请再次输入几头牛几天吃完草\n\n\n");
								scanf("%d%d", &bc, &bd);
								printf("问题为X头牛吃草几天吃完\n\n\n");
								printf("请输入牛头数\n\n\n");
								scanf("%d", &bk);
								be = (ba * bm);
								bf = (bc * bd);
								if (be > bf) {
									bg = ((be - bf) / (bm - bd));
								}
								else if (be < bf) {
									bg = ((bf - be) / (bd - bm));
								}
								else {
									printf("没有答案\n\n");
								}
								bh = (1 - bg) * ba * bm;
								bi = bh / (bk - bg);
								printf("以下数据已自动化为整数\n\n");
								printf("草生长速度为%d\n\n", bg);
								printf("原有草数为%d\n\n", bh);
								printf("%d头牛%d天吃完\n\n", bk, bi);
								break;
							default:printf("输入错误\n");
								break;
							}//switch  
							break;

						case 7:printf("                                      知识天地\n\n");
							printf("请选择查看内容\n");
							printf("1、命令提示符\n\n");
							printf("2、C语言运算符介绍\n");
							scanf("%d", &oo);
							switch (oo) {
							case 1:
								printf("1、 gpedit.msc-----组策略。\n");
								printf("2、Nslookup-------IP地址侦测器 \n");
								printf("3、explorer-------打开资源管理器。\n");
								printf("4、logoff---------注销命令。\n");;
								printf("5、lusrmgr.msc----本机用户和组。\n");
								printf("6、services.msc---本地服务设置。\n");
								printf("7、 notepad--------打开记事本。\n");
								break;
							case 2:
								printf("++ 、 -- 、 * 、 & 、 ~ 、!单目运算符\n\n");
								printf(" * 、 / 、%算术运算符\n\n");
								printf("+ 、 -	算术运算符\n\n");
								printf("<< 、 >>位运算符\n\n");
								printf("< 、 <= 、 > 、 >=	关系运算符\n\n");
								printf(" == 、!=关系运算符号\n\n");
								printf(" &	位与\n\n");
								printf(" ^	位异或\n\n");
								printf(" |	位或\n\n");
								printf(" && 逻辑与\n\n");
								printf(" ||逻辑或\n\n");
								printf("  ? 、:条件运算符\n\n");
								printf(" /= 、%= 、 &= 、 |= 、 ^=	赋值运算符\n\n");
								printf(" ,	顺序运算符\n\n"); break;
							default:printf("输入错误\n"); break;
							}//switch
							break;

						case 8:printf("                                       附加功能\n\n");
							printf("请选择想要的功能\n");
							printf("1、无限循环病毒\n");
							printf("2、打开命令提示符(cmd)\n");
							printf("3、打开浏览器\n");
							printf("4、开发人员专用工具\n");
							scanf("%d", &yy);
							switch (yy) {
							case 1:printf("为了安全起见，暂时没有开启无限循环\n");
								printf("若想开启请修改原程序\n");
								while (zz < 5) {    //zz=1
									zz++;
									system("start");
								}//while
								break;
							case 2:system("start"); break;
							case 3:system("start http://hao.360.cn/"); break;
							case 4:printf("                                    开发人员专用\n\n");
								printf("                                 非开发人员请勿登录\n\n");
								printf("                                    请勿胡乱输入\n\n");
								printf("                             非专业人员请勿随意修改原程序\n\n");
								printf("请输入登录帐号和密码\n\n");
								printf("请输入帐号\n");
								scanf("%I64d", &ab);
								printf("请输入密码\n");
								scanf("%I64d", &ac);
								if (an == 1) {
									if (ab == ad && ac == ae) {
										for (ai = 0; ai < 3; ai++) {
											printf("请选择相应的程序\n\n");
											printf("更多程序请登陆开发人员帐号\n\n");
											printf("1、查看当前各变量的值\n\n");
											printf("2、修改用户帐号密码(暂时)\n\n");
											printf("3、查看各板块的循环次数\n\n");
											printf("4、系统监视\n\n");
											scanf("%d", &af);
											switch (af) {
											case 1: printf("zz=%d\n", zz);
												printf("a=%d\n", a);
												printf("b=%d\n", b);
												printf("c=%d\n", c);
												printf("d=%d\n", d);
												printf("e=%d\n", e);
												printf("f=%d\n", f);
												printf("g=%d\n", g);
												printf("h=%d\n", h);
												printf("i=%d\n", i);
												printf("j=%d\n", j);
												printf("l=%d\n", l);
												printf("m=%d\n", m);
												printf("n=%d\n", n);
												printf("o=%d\n", o);
												printf("p=%d\n", p);
												printf("z=%d\n", z);
												printf("aa=%d\n", aa);
												printf("bb=%d\n", bb);
												printf("cc=%d\n", cc);
												printf("dd=%d\n", dd);
												printf("ee=%d\n", ee);
												printf("ff=%d\n", ff);
												printf("gg=%d\n", gg);
												printf("ii=%d\n", ii);
												printf("jj=%d\n", jj);
												printf("zzz=%d\n", zzz);
												printf("kk=%d\n", kk);
												printf("ll=%d\n", ll);
												printf("mm=%d\n", mm);
												printf("nn=%d\n", nn);
												printf("oo=%d\n", oo);
												printf("pp=%d\n", pp);
												printf("qq=%d\n", qq);
												printf("rr=%d\n", rr);
												printf("uu=%d\n", uu);
												printf("vv=%d\n", vv);
												printf("ww=%d\n", ww);
												printf("xx=%d\n", xx);
												printf("yy=%d\n", yy);
												break;



											case 2:printf("请选择要修改的用户\n\n");
												printf("提示：此为暂时更改，永久更改请修改原程序\n\n");
												printf("1、张梓浩\n");
												printf("2、路人甲\n");
												printf("3、路人乙\n");
												printf("4、游客\n");
												scanf("%d", &ah);
												switch (ah) {
												case 1:printf("请输入帐号\n");
													scanf("%d", &o);
													printf("请输入密码\n");
													scanf("%d", &p); break;
												case 2:printf("请输入帐号\n");
													scanf("%d", &ii);
													printf("请输入密码\n");
													scanf("%d", &jj); break;
												case 3:printf("请输入帐号\n");
													scanf("%d", &gg);
													printf("请输入密码\n");
													scanf("%d", &hh); break;
												case 4:printf("请输入帐号\n");
													scanf("%d", &uu);
													printf("请输入密码\n");
													scanf("%d", &vv); break;
												}break;
											case 3:printf("当前重新登录次数为\n\n");
												printf("%d\n\n", ll - 1);
												printf("考试天地循环次数为\n\n");
												printf("%d\n\n", 2);
												printf("其他应用循环次数为\n\n");
												printf("%d\n\n", 2);
												printf("cmd命令循环次数为\n\n");
												printf("%d\n\n", 3);
												printf("其他板块均不循环\n\n");
												printf("更改循环次数请修改原程序\n\n"); break;

											case 4:printf("当前系统状况为\n\n");
												printf("主板块有\n\n");
												Sleep(1000);
												printf("1、考试天地\n");
												Sleep(1000);
												printf("2、应用程序\n");
												Sleep(1000);
												printf("3、cmd命令\n");
												Sleep(1000);
												printf("4、成绩录入\n");
												Sleep(1000);
												printf("5、成绩查看\n");
												Sleep(1000);
												printf("6、解数学题\n");
												Sleep(1000);
												printf("7、退出网站\n");
												Sleep(1000);
												printf("8、知识天地\n");
												Sleep(1000);
												printf("9、附加功能\n");
												printf("副板块选项共有：");
												Sleep(1000);
												printf("请选择考试科目\n");
												printf("1、英语\n");
												printf("2、数学\n");
												printf("3、语文\n");
												printf("4、退出\n");
												Sleep(1000);
												printf("1、查询考试成绩\n");
												printf("2、查看编者留言\n");
												printf("3、华氏度转摄氏度\n");
												printf("4、字符串加密\n");
												printf("5、锁定鼠标\n");
												printf("6、退出\n");
												Sleep(1000);
												printf("请选择命令\n");
												printf("1、立即关机\n");
												printf("2、取消关机\n");
												printf("3、打开组策略\n");
												printf("4、打开注册表\n");
												printf("5、查看ip地址\n");
												printf("6、设置电脑密码为123456\n");
												printf("7、查看电脑账户信息\n");
												printf("8、打开资源管理器。\n");
												printf("9、注销命令。\n");;
												printf("10、本机用户和组。\n");
												printf("11、本地服务设置。\n");
												printf("12、打开记事本。\n");
												printf("13、退出\n");
												break;
											default:printf("输入错误\n\n"); break;
											}//switch
										}//for
									}//帐号密码if 
									else {
										printf("帐号或密码错误\n\n");
										printf("请不要随意点击\n\n");
										scanf("%d");
										return 0;
										break;
									}//else
								}//保护系统if 
								else {
									printf("请登陆开发人员帐号，关闭保护系统\n\n");
									printf("保护系统已启动，为了防止随意登录，请退出\n\n");
									continue;
								}//else
								break;
							default:printf("输入错误\n"); break;
							}//附加功能switch 
							break;
						default:printf("输入错误\n"); break;
							}//应用程序for 
							break;
						}//网站首页switch 
					}//网站首页for 
				}// 网站循环for 
				scanf("%d");
				break;
			}
			else {
				printf("程序已被封锁，请退出\n");
				return 0;
			}



			break;






			//////////////////////////////////////////////////////////////////////////////////////////////////////






		case 6:system("cls");
			if (fscx6 == 1) {
				printf("\n\n\n\n\n\n\n\n");
				puts("说明如下：\n");
				printf("代码总长：150000个字符，编了N小时(100<N<120)\n\n");
				puts("看着屏幕选项，输入相应数字，再按下Enter键，即可进入相应程序\n");
				puts("本程序不可使用鼠标，只能使用键盘，C语言本来就是怎样\n");
				puts("而张梓浩网站中的帐号密码，不知道者给你一个免费帐号，帐号为5，密码为5\n");
				puts("至于你不会看程序里面的提示，那我也没办法\n");
				puts("最后说明一下，本程序由张梓浩一人精心编写，由于技术问题，可能有些漏洞\n");
				puts("还有，千万不要乱输入，特别是输入字母，很严重的\n");
				puts("最后，祝大家使用愉快\n");
				Sleep(60000);
				break;
			}
			else {
				printf("程序已被封锁，请退出\n");
				return 0;
			}


			break;






			////////////////////////////////////////////////////////////////////////////////////////////





		case 11:system("cls");
			printf("欢迎下次光临\n");
			return 0;
			break;





			///////////////////////////////////////////////////////////////////////////////////////////







		case 10:system("cls");


			for (;;) {
				printf("请输入四个数:\n");
				for (i = 0; i < CONT; i++)
				{
					char ch[20], s;
					int a;
					printf("第%d个数:", i + 1);
					scanf("%f", &number[i]);
					a = (int)number[i];
					s = char(a + 48);
					ch[0] = s;
					for (j = 1; j < 20; j++)
					{
						ch[j] = 0;
					}
					strcpy(expression[i], ch);
				}
				printf("\n");
				Find(CONT);
				if (m_judge == true)
				{
					printf("\n\n成功!\n");
					printf("总共的计算方法共有:%d\n", count);
				}
				else
				{
					printf("失败!");
				}

			}/////// 








			break;






			/////////////////////////////////////////////////////////////////////////////////////////////





		case 9:system("cls");


			while (1) {
				printf("                            欢迎使用张梓浩自制大数据系统\n\n\n\n\n\n\n\n");
				printf("使用说明：1、此系统的用途为通过已知的数据来估测下一个未知的数据\n");
				printf("          2、例如：下一次考试的成绩，下一个同学的身高等\n");
				printf("          3、数据必须为具有联系的同类数据，数据必须为随机的，不能经过人工干预\n");
				printf("          4、例如：你不能通过别人的成绩来预测你自己的成绩\n");
				printf("          5、若要预测的下一个数据是一个逼近于极值或为极值的数据，那么误差会很大\n");
				printf("          6、在非特殊情况下，预测的值的误差在±3X以内（X视数据的位数多少而定）\n");
				printf("          7、数据的波动程度越大，结果误差会越大,因为你永远想不到下一秒会发生什么\n\n\n");
				printf("请输入你想要输入的数据个数(5≤数据个数≤100)\n");
				int geshu;
				cin >> geshu;
				int paixu[100];//排序找中位数
				for (int f1 = 0; f1 < 100; f1++) {
					paixu[f1] = geshu;
				}
				printf("请输入数据\n");
				float shuju[100];//可调
				for (int f1 = 0; f1 < geshu; f1++) {
					cin >> shuju[f1];
					printf("你已输入第%d数据:%f\n", f1 + 1, shuju[f1]);
				}
				///////////////////////////////////////输入数据
				float zonghe = 0;
				for (int f1 = 0; f1 < geshu; f1++) {
					zonghe = zonghe + shuju[f1];
				}
				float pingjun = 0;
				pingjun = zonghe / geshu;
				int dayu = 0; int xiaoyu = 0;
				for (int f1 = 0; f1 < geshu; f1++) {
					if (shuju[f1] > pingjun) {
						dayu++;
					}
					else if (shuju[f1] < pingjun) {
						xiaoyu++;
					}
				}//判断是否要去最大最小值
				if (dayu - xiaoyu >= 2 || xiaoyu - dayu >= 2) {//可调
					float zuida = shuju[0];
					float zuixiao = shuju[geshu - 1];
					for (int f1 = 0; f1 < geshu; f1++) {
						if (shuju[f1] >= zuida) {
							zuida = shuju[f1];
						}
						else if (shuju[f1] <= zuixiao) {
							zuixiao = shuju[f1];
						}
					}
					zonghe = zonghe - zuida - zuixiao;
					pingjun = zonghe / (geshu - 2);
				}//去极值过程 
				else {

				}
				///////////////////////////////////////计算平均数
				int zhong = 0;
				float zhongweishu = 0;
				for (int f1 = 0; f1 < geshu; f1++) {
					for (int f2 = 0; f2 < geshu; f2++) {
						if (shuju[f1] > shuju[f2]) {
							paixu[f1]--;
						}
					}

				}
				float chongxin[100];
				for (int f1 = 0; f1 < geshu; f1++) {
					chongxin[f1] = 0;
				}
				int cs = 0;
				for (int f2 = 0; f2 < geshu; f2++) {
					for (int f1 = 0; f1 < geshu; f1++) {
						if (paixu[f1] == f2 + 1) {
							chongxin[cs] = shuju[f1];
							cs++;
						}
					}
				}
				if (geshu % 2 == 1) {//奇数
					zhong = (geshu + 1) / 2;
					zhongweishu = chongxin[zhong - 1];
				}
				else {
					zhong = geshu / 2;
					zhongweishu = (chongxin[zhong - 1] + chongxin[zhong]) / 2;
				}
				///////////////////////////////////////////寻找中位数
				float fangcha = 0;
				float cha[100];
				float he = 0;
				for (int f1 = 0; f1 < geshu; f1++) {
					cha[f1] = (shuju[f1] - pingjun) * (shuju[f1] - pingjun);
					he = he + cha[f1];
				}
				fangcha = he / geshu;
				//////////////////////////////////计算方差
				float jieguo1 = 0;
				float jieguo2 = 0;
				float jieguo3 = 0;
				float jieguo = 0;
				float jieguo4 = 0;
				jieguo1 = pingjun;
				jieguo2 = (pingjun + zhongweishu) / 2;
				jieguo3 = pingjun + fangcha;//可调
				jieguo4 = zhongweishu + fangcha;
				jieguo = (jieguo1 + jieguo2 + jieguo3 + jieguo4) / 4;
				if ((jieguo - pingjun) * (jieguo - pingjun) / geshu <= 1) {//可调
					printf("预测结果为%f\n", jieguo);
				}
				else {
					printf("预测结果为%f\n", jieguo2);
				}
			}


			break;







			/////////////////////////////////////////////////////////////////////////////////////////








		case 7:system("cls");
			int c99;
			char a17[1000], b17[1000];
			int a7[1000], b7[1000], c77[1000];
			long lena, lenb, lenc, i7, j7, x7;//case 7的变量 
			if (fscx7 == 1) {
				printf("                                  高精度乘法运算\n\n");
				printf("                     请保证文档里有乘数1.txt和乘数2.txt这两个文件\n\n");
				printf("                              并在这两个文件里输入乘数\n\n");
				printf("                         结果会输出在乘法结果.txt这个文件中\n");
				printf("                           满足条件输入数字并按Enter键继续\n");
				scanf("%d", &c99);
				FILE* fout, * fin;
				memset(a7, 0, sizeof(a7));
				memset(b7, 0, sizeof(b7));
				memset(c77, 0, sizeof(c77));
				freopen("乘数1.txt", "rb", stdin);
				gets(a17);
				freopen("乘数2.txt", "rb", stdin);
				gets(b17);
				lena = strlen(a17);
				lenb = strlen(b17);
				for (i7 = 0; i7 <= lena - 1; i7++)
					a7[lena - i7] = a17[i7] - 48;
				for (i7 = 0; i7 <= lenb - 1; i7++)
					b7[lenb - i7] = b17[i7] - 48;
				for (i7 = 1; i7 <= lena; i7++) {
					x7 = 0;
					for (j7 = 1; j7 <= lenb; j7++) {
						c77[i7 + j7 - 1] = a7[i7] * b7[j7] + x7 + c77[i7 + j7 - 1];
						x7 = c77[i7 + j7 - 1] / 10; c77[i7 + j7 - 1] %= 10;
					}
					c77[i7 + lenb] = x7;
				}
				lenc = lena + lenb;
				while (c77[lenc] == 0 && lenc > 1)
					lenc--;
				for (i7 = lenc; i7 >= 1; i7--)
					cout << c77[i7];
				cout << endl;
				fout = fopen("乘法结果.txt", "wb");
				for (i7 = lenc; i7 >= 1; i7--)
					fprintf(fout, "%d", c77[i7]);
				return 0;
			}
			else {
				printf("程序已被封锁，请退出\n");
				return 0;
			}


			break;





			///////////////////////////////////////////////////////////////////////////////////////////////////////////////




		case 8:system("cls");
			struct person {
				char xm[10];
				float cj1;
			}xs[70];




			struct student {
				char xm[10];
				float cj1;
			}sc[70];




			int mm1;




			printf("                             欢迎使用智能换序系统(ISS)\n\n\n\n");
			printf("                                请输入密码授权登录\n\n");
			printf("              请将姓名输入在input.txt中，把原顺序成绩输入在input1.txt中\n\n");
			printf("                       然后在output.txt中输入换序后的姓名顺序\n\n");
			scanf("%d", &mm1);
			if (mm1 != 1) {
				return 0;
			}
			else {





				for (;;) {



					system("cls");
					printf("                                    请选择功能:\n\n");
					printf("                                     1、ESS\n\n");
					printf("                                     2、CWS\n\n");
					printf("                                     3、ACS\n\n");
					printf("                                     4、HEL\n\n");
					scanf("%d", &c1);
					switch (c1) {
					case 1:
						fin = fopen("input.txt", "rb");
						for (int f1 = 0; f1 <= 69; f1++) {
							fscanf(fin, "%s", &xs[f1].xm);
						}


						fin = fopen("input1.txt", "rb");
						for (int f1 = 0; f1 <= 69; f1++) {
							fscanf(fin, "%f", &xs[f1].cj1);
						}


						fin = fopen("output.txt", "rb");
						for (int f1 = 0; f1 <= 69; f1++) {
							fscanf(fin, "%s", &sc[f1].xm);
						}


						for (int f1 = 0; f1 <= 69; f1++) {
							if (xs[f1].cj1 < 0 || xs[f1].cj1>120) {
								xs[f1].cj1 = 0;
							}
						}


						for (int f1 = 0; f1 <= 69; f1++) {
							for (int f2 = 0; f2 <= 69; f2++) {
								if (strcmp(sc[f1].xm, xs[f2].xm) == 0) {
									fout = fopen("output1.txt", "a+");
									fprintf(fout, "%1.1f\n", xs[f2].cj1);
								}
							}
						}


						system("cls");
						printf("                                  have finished\n");
						Sleep(1000);
						break;
					case 2:
						fin = fopen("output.txt", "rb");
						for (int f1 = 0; f1 <= 69; f1++) {
							fscanf(fin, "%s", &sc[f1].xm);
						}
						fin = fopen("output1.txt", "rb");
						for (int f1 = 0; f1 <= 69; f1++) {
							fscanf(fin, "%f", &sc[f1].cj1);
						}






						for (int f1 = 0; f1 <= 68; f1 += 2) {
							if (sc[f1].cj1 > sc[f1 + 1].cj1) {
								fout = fopen("compare1.txt", "a+");
								fprintf(fout, "1\n");
								fprintf(fout, "0\n");
							}
							if (sc[f1].cj1 < sc[f1 + 1].cj1) {
								fout = fopen("compare1.txt", "a+");
								fprintf(fout, "0\n");
								fprintf(fout, "1\n");
							}
							if (sc[f1].cj1 == sc[f1 + 1].cj1) {
								fout = fopen("compare1.txt", "a+");
								fprintf(fout, "0\n");
								fprintf(fout, "0\n");
							}

						}
						system("cls");
						printf("                                  have finished\n");
						Sleep(1000);
						break;

					case 3:
						system("cls");
						printf("chose number:\n\n");
						printf("1、CLS\n\n");
						printf("2、CHK\n\n");
						scanf("%d", &c2);
						switch (c2) {
						case 1:
							fout = fopen("input1.txt", "a+");
							fprintf(fout, "0\n");

							fout = fopen("output1.txt", "a+");
							fprintf(fout, "0\n");

						case 2:
							for (int f1 = 0; f1 <= 69; f1++) {
								if (xs[f1].cj1 < 0 || xs[f1].cj1>120) {
									xs[f1].cj1 = 0;
								}
							}
						}
						system("cls");
						printf("                                  have finished\n");
						Sleep(1000);
						break;


					case 4:
						system("cls");
						printf("chose number:\n\n");
						printf("1、ESC\n\n");
						printf("2、TSL\n\n");
						scanf("%d", &c2);
						switch (c2) {
						case 1:
							return 0;
						case 2:
							system("cls");
							printf("ESS:交换顺序系统\n\n");
							printf("CWS:上下比较系统\n\n");
							printf("ACS:自动纠错系统\n\n");
							printf("HEL:疑难帮助系统\n\n");
							printf("CLS:清空数据\n\n");
							printf("CHK:检查数据\n\n");
							printf("ESC:退出\n\n");
							printf("TSL:翻译\n\n");
							scanf("%d", &c2);
							break;
						}
						break;


					}//switch



				}//for



			}//else

			break;







			///////////////////////////////////////////////////////////////////////////////////////






		case 2:system("cls");




			int c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, c16, c17, c18, c19, c20;//case 2的变量 
			float sj[10000];//10000个数据
			int xvh[10000], lsx[10000], mc[10000];// 10000个序号，10000个临时变量,10000个名次 
			float cz1, cz2, cz3, cz4, cz5, cz6, cz7, cz8, cz9, cz10;//数据操作变量
			int h1606, h1609, h1620, h1684, h1685, h1723, h1728, h1729, h0, h1771, h1747, h1755, h1790, h1816, h2014, jj1, jj2;
			int px1, px2, px3, px4;//排序变量 
			int gs, gs1, hhhhh;//数据总数 
			int tg[10000];//跳过已输入的变量 
			c8 = 0;
			int ft;//用于输入tg数组，不可初始化
			ft = 0;
			int zg;//数据总个数 
			zg = 0;
			int zdz;//数据最大值 
			zdz = 0;
			float zzhi, pj;//信息统计变量 

			int zddq, zdsc;//自动读取，自动输出，系统设置变量 
			gs = 0;
			gs1 = 0;
			px1 = 0;
			px2 = 0;
			struct sg {
				char bz[100];
			}su[10000];




			if (fscx2 == 1) {
				fin = fopen("系统文件1.txt", "rb");
				fscanf(fin, "%d", &zddq);
				fin = fopen("系统文件2.txt", "rb");
				fscanf(fin, "%d", &zdsc);
				fin = fopen("数据文件.txt", "rb");
				if (zddq == 1) {
					for (h1816 = 0; h1816 < gs; h1816++) {
						fscanf(fin, "%d", &xvh[h1816]);
						fscanf(fin, "%s", &su[h1816].bz);
						fscanf(fin, "%f", &sj[h1816]);
						fscanf(fin, "%d", &mc[h1816]);
					}
					fscanf(fin, "%d", &zg);
					fscanf(fin, "%d", &zdz);
				}
				fout = fopen("数据记录.doc", "wb");
				for (h1609 = 0; h1609 < 10000; h1609++) {
					tg[h1609] = 0;
				}
				for (h1609 = 0; h1609 < 10000; h1609++) {
					sj[h1609] = 0;
				}
				for (;;) {
					printf("                               欢迎光临数据管理系统\n\n");
					printf("                               由张梓浩提供技术支持\n\n\n");
					printf("                   请选择想要进入的程序,输入相应数字并按下Enter键\n\n");
					printf("  ——————————————————————————————————————\n");
					printf("  1、数据输入  |  2、数据查看  |  3、数据排序  |  4、数据查找  |  5、批量输入\n\n");
					printf("  6、数据统计  |  7、保存数据  |  8、数据修改  |  9、读取数据  |  10、退出系统\n\n");
					printf("  11、选号查看 |  12、批量修改 |  13、数段查找 |  14、选号保存 |  15、选号排序\n\n");
					printf("  16、备注修改 |  17、备注连输 |  18、数据清零 |  19、选号清零 |  20、系统设置\n\n");
					printf("  ——————————————————————————————————————\n");
					for (h1609 = 0; h1609 < 10000; h1609++) {
						xvh[h1609] = h1609 + 1;
					}
					for (h1609 = 0; h1609 < 10000; h1609++) {
						lsx[h1609] = 0;
					}
					if (pm == 1) {
						printf("\n\n\n\n\n\n");
					}
					pm = 2;
					zgs = 0;
					scanf("%d", &sw9);
					switch (sw9) {
					case 1:printf("请输入想要输入的数据个数\n\n");
						scanf("%d", &c1);
						h1606 = 0;
						gs = zdz;
						printf("序号已按顺序排列，即第一个数据对应一号，请勿胡乱输入\n\n");
						printf("假如有的序号的数据或备注暂时没有的，可暂时胡乱输入，然后再去修改\n\n");
						printf("请按顺序输入序号\n\n");
						for (; h1606 < c1; gs++, h1606++, ft++) {
							printf("请依次输入序号，备注和数据\n\n");
							scanf("%d%d", &xvh[gs], &tc);
							scanf("%s", &su[gs].bz);
							scanf("%f", &sj[gs]);
							printf("已输入序号:%d   备注%s   数据:%f\n\n", xvh[gs], su[gs].bz, sj[gs]);
							tg[ft] = gs + 1;
						}//for
						zg = zg + gs - c8;
						printf("当前共有%d个数据\n", zg);
						for (m1 = 0; m1 < 10000; m1++) {
							if (gs >= tg[m1]) {
								zdz = gs;
							}
						}
						break;
					case 2:printf("请输入想要读取的数据个数（按顺序）\n\n");
						scanf("%d", &c2);
						for (h1620 = 0; h1620 < c2; h1620++) {
							printf("序号%d     备注为%s    数据为:%f\n\n", xvh[h1620], su[h1620].bz, sj[h1620]);
						}
						break;
					case 3:printf("请输入想要参加排序的数据个数\n\n");
						scanf("%d", &c3);
						for (px1 = 0; px1 < c3; px1++) {
							mc[px1] = c3;
						}//次序初始化 
						for (jj1 = 1, px1 = 0; jj1 <= c3; jj1++) {
							for (px2 = 0; px2 < c3; px2++) {
								if (sj[px1] >= sj[px2] && px2 != px1) {
									mc[px1]--;
								}
								else if (sj[px1] < sj[px2]) {
									mc[px1] = mc[px1];
								}
							}
							px1++;
						}
						printf("请选择排序方式\n");
						printf("1、升序排列\n");
						printf("2、降序排列\n");
						printf("3、直接排序,按序号顺序输出\n");
						printf("4、退出\n");
						scanf("%d", &sw10);
						switch (sw10) {
						case 2:for (pl1 = 1; pl1 <= c3; pl1++) {
							for (pl2 = 0; pl2 < c3; pl2++) {
								if (mc[pl2] == pl1) {
									printf("第%d个的序号为%d备注为%s数据为%f\n", pl1, xvh[pl2], su[pl2].bz, sj[pl2]);
								}
							}
						}break;
						case 1:for (pl3 = c3; pl3 >= 1; pl3--) {
							for (pl4 = 0; pl4 < c3; pl4++) {
								if (mc[pl4] == pl3) {
									printf("第%d个的序号为%d备注为%s数据为%f\n", pl3, xvh[pl4], su[pl4].bz, sj[pl4]);
								}
							}
						}break;
						case 4:continue; break;
						case 3:
							for (px1 = 0; px1 < c3; px1++) {
								printf("序号%d  备注为%s  数据为%f  次序为%d\n\n", xvh[px1], su[px1].bz, sj[px1], mc[px1]);
							}break;
						default:printf("输入错误\n"); break;
						}
						break;
					case 4:printf("请选择查找方式\n");
						printf("1、按序号查找\n");
						printf("2、按数据查找\n");
						printf("3、按次序查找\n");
						printf("4、按备注查找\n");
						printf("注：按次序查找请先去数据排序区排次序\n");
						scanf("%d", &sw11);
						switch (sw11) {
						case 1:printf("请输入数据序号:\n\n");
							scanf("%d", &c4);
							h1684 = 0;
							for (h1685 = 0; h1685 < zdz; h1685++) {
								if (xvh[h1685] == c4) {
									h1684++;
									printf("序号%d  备注为%s  数据为%f:\n\n", c4, su[h1685].bz, sj[h1685]);
								}
							}
							printf("共搜索到%d个数据\n", h1684);
							break;
						case 2:printf("请输入数据:\n\n");
							scanf("%f", &cz1);
							h1684 = 0;
							for (h1685 = 0; h1685 < zdz; h1685++) {
								if (sj[h1685] == cz1) {
									h1684++;
									printf("序号%d  备注为%s  数据为%f:\n\n", xvh[h1685], su[h1685].bz, cz1);
								}
							}
							printf("共搜索到%d个数据\n", h1684);
							break;
						case 3:printf("请输入数据次序:\n\n");
							scanf("%d", &c5);
							h1684 = 0;
							for (h1685 = 0; h1685 < zdz; h1685++) {
								if (mc[h1685] == c5) {
									h1684++;
									printf("序号%d  备注为%s  数据为%f:\n\n", xvh[h1685], su[h1685].bz, sj[h1685]);
								}
							}
							printf("共搜索到%d个数据\n", h1684);
							break;
						case 4:printf("请输入数据备注:\n\n");
							scanf("%d", &tc);
							gets(xmcz);
							h1684 = 0;
							for (m1 = 0; m1 < gs; m1++) {
								if (strcmp(su[m1].bz, xmcz) == 0) {
									h1684++;
									printf("序号%d  备注为%s  数据为%f:\n\n", xvh[m1], su[m1].bz, sj[m1]);
								}
							}
							printf("共搜索到%d个成绩\n", h1684);
							break;
						}break;
					case 5:printf("请选择批量方式\n");
						printf("1、选择序号输入\n");
						printf("2、按顺序统一输入\n");
						scanf("%d", &sw12);
						switch (sw12) {
						case 1:c20 = 0;
							printf("请输入想输入的数据个数\n\n");
							scanf("%d", &c6);
							printf("请输入序号\n");
							for (h1723 = 0; h1723 < c6; h1723++) {
								scanf("%d", &lsx[h1723]);
								for (m1 = 0; m1 < zg; m1++) {
									if (lsx[h1723] == tg[m1]) {
										zgs++;
									}
								}
							}
							printf("请输入统一的数据\n");
							scanf("%f", &cz2);
							for (h1728 = 0; h1728 < 10000; h1728++) {
								for (h1729 = 0; h1729 < c6; h1729++) {
									if (xvh[h1728] == lsx[h1729]) {
										sj[h1728] = cz2;
										printf("已输入序号%d数据为%f\n", xvh[h1728], sj[h1728]);
									}
								}//for2
							}//for1
							printf("请到备注连输处输入备注\n");
							zg = zg + c6 - zgs;
							printf("当前共有%d个数据\n", zg);
							for (m1 = 0; m1 < c6; ft++, m1++) {
								tg[ft] = lsx[m1];
							}
							for (m1 = 0; m1 < c6; m1++) {
								for (h1728 = 0; h1728 < zg; h1728++) {
									if (lsx[m1] >= tg[h1728]) {
										zdz = lsx[m1];
									}
								}
							}
							break;
						case 2:printf("请输入起始位置:\n");
							scanf("%d%d", &c7, &c8);
							hhhhh = c7;
							printf("请输入统一数据 :\n");
							scanf("%f", &cz3);
							for (; c7 <= c8; c7++) {
								sj[c7 - 1] = cz3;
								for (m1 = 0; m1 < zg; m1++) {
									if (c7 == tg[m1]) {
										zgs++;
									}
								}
							}//for1
							printf("序号已按默认顺序排列\n");
							printf("请到备注连输处输入备注\n");
							zg = zg + c8 - hhhhh + 1 - zgs;
							printf("当前共有%d个数据\n", zg);
							for (; hhhhh <= c8; ft++, hhhhh++) {
								tg[ft] = hhhhh;
							}
							for (m1 = 0; m1 < zg; m1++) {
								if (c8 >= tg[m1]) {
									zdz = c8;
								}
							}
							break;
						}break;
					case 6:for (h1755 = 0; h1755 < 10000; h1755++) {
						zzhi = zzhi + sj[h1755];
					}
						  pj = zzhi / zg * 1.0;
						  cz4 = sj[0];
						  cz5 = sj[0];
						  for (h1755 = 1; h1755 < zdz; h1755++) {
							  if (sj[h1755] > cz4) {
								  cz4 = sj[h1755];
							  }
						  }
						  for (h1755 = 1; h1755 < zdz; h1755++) {
							  if (sj[h1755] < cz5) {
								  cz5 = sj[h1755];
							  }
						  }
						  h1771 = zg / 2;
						  cz6 = cz4 - cz5;
						  printf("数据总数为:%f\n", zzhi);
						  printf("数据平均数为:%f\n", pj);
						  printf("数据最大值为:%f\n", cz4);
						  printf("数据最小值为:%f\n", cz5);
						  printf("数据中位数为:%f\n", sj[h1771 - 1]);
						  printf("数据极差为:%f\n", cz6);
						  printf("数据个数为:%d\n", zg);
						  printf("具体次序请看数据排序\n");
						  break;
					case 7:printf("请输入保存的数据个数:\n\n");
						scanf("%d", &c9);
						printf("请先排次序，防止发生输出错误\n");
						for (h1790 = 0; h1790 < c9; h1790++) {
							fprintf(fout, "序号%d备注为%s数据为%f次序为%d\n", xvh[h1790], su[h1790].bz, sj[h1790], mc[h1790]);
							printf("已保存序号%d备注为%s数据%f次序%d\n", xvh[h1790], su[h1790].bz, sj[h1790], mc[h1790]);
						}
						fprintf(fout, "数据总数%d\n", zg);
						fprintf(fout, "最大值%d\n", zdz);
						printf("保存成功\n");
						fout = fopen("数据文件.txt", "wb");
						for (h1790 = 0; h1790 < c9; h1790++) {
							fprintf(fout, "%d\n", xvh[h1790]);
							fprintf(fout, "%s\n", su[h1790].bz);
							fprintf(fout, "%f\n", sj[h1790]);
							fprintf(fout, "%d\n", mc[h1790]);
						}
						fprintf(fout, "%d\n", zg);
						fprintf(fout, "%d\n", zdz);
						break;
					case 8:printf("请输入要修改数据的序号:\n");
						scanf("%d", &c10);
						printf("请输入修改后的数据:\n");
						scanf("%f", &cz7);
						sj[c10 - 1] = cz7;
						printf("修改成功\n");
						break;
					case 9:printf("请确保你已经保存数据\n");
						printf("请输入要读取的数据个数:\n");
						scanf("%d", &c11);
						for (h1816 = 0; h1816 < c11; h1816++) {
							fscanf(fin, "%d", &xvh[h1816]);
							fscanf(fin, "%s", &su[h1816].bz);
							fscanf(fin, "%f", &sj[h1816]);
							fscanf(fin, "%d", &mc[h1816]);
							printf("已输入序号:%d备注为%s数据:%f次序:%d\n", xvh[h1816], su[h1816].bz, sj[h1816], mc[h1816]);
						}
						fscanf(fin, "%d", &zg);
						fscanf(fin, "%d", &zdz);
						printf("读取成功\n");
						break;
					case 10:fout = fopen("数据记录.doc", "wb");
						if (zdsc == 2) {
							for (h1790 = 0; h1790 < zdz; h1790++) {
								fprintf(fout, "序号%d备注为%s数据为%f次序为%d\n", xvh[h1790], su[h1790].bz, sj[h1790], mc[h1790]);
							}
							fprintf(fout, "数据总数%d\n", zg);
							fprintf(fout, "最大值%d\n", zdz);
							fout = fopen("数据文件.txt", "wb");
							for (h1790 = 0; h1790 < zdz; h1790++) {
								fprintf(fout, "%d\n", xvh[h1790]);
								fprintf(fout, "%s\n", su[h1790].bz);
								fprintf(fout, "%f\n", sj[h1790]);
								fprintf(fout, "%d\n", mc[h1790]);
							}
							fprintf(fout, "%d\n", zg);
							fprintf(fout, "%d\n", zdz);
						}
						printf("欢迎再次光临\n\n");
						printf("感谢使用本系统\n\n");
						Sleep(500);
						return 0; break;
					case 11:printf("请输入要查看的个数\n");
						scanf("%d", &c11);
						printf("请分别输入要查看的序号\n");
						for (m1 = 0; m1 < c11; m1++) {
							scanf("%d", &lsx[m1]);
						}
						for (m1 = 0; m1 < c11; m1++) {
							printf("序号:%d备注为%s数据:%f次序:%d\n", xvh[lsx[m1] - 1], su[lsx[m1] - 1].bz, sj[lsx[m1] - 1], mc[lsx[m1] - 1]);
						}
						break;
					case 12:printf("1、数据批量修改\n");
						printf("2、备注批量修改\n");
						printf("请选择\n");
						scanf("%d", &c12);
						switch (c12) {
						case 1:printf("请输入想修改的数据个数\n\n");
							scanf("%d", &c6);
							printf("请分别输入要修改数据的序号\n");
							for (h1723 = 0; h1723 < c6; h1723++) {
								scanf("%d", &lsx[h1723]);
							}
							printf("请分别输入数据\n");
							for (m1 = 0; m1 < c6; m1++) {
								scanf("%f", &cz7);
								sj[lsx[m1] - 1] = cz7;
								printf("已输入%f\n", sj[lsx[m1] - 1]);
							}break;
						case 2:printf("请输入要修改备注的个数\n");
							scanf("%d", &sc12);
							printf("请输入要修改备注的数据序号\n");
							for (m1 = 0; m1 < sc12; m1++) {
								scanf("%d", &lsx[m1]);
							}
							printf("请依次输入备注\n");
							for (m1 = 0; m1 < sc12; m1++) {
								scanf("%d", &tc);
								gets(xmls);
								strcpy(su[lsx[m1] - 1].bz, xmls);
								printf("已输入%s\n", su[lsx[m1] - 1].bz);
							}
							break;
						}//switch
						break;
					case 13:printf("请按顺序输入两个数，我会为您找到这两个数范围内共有几个数据\n");
						scanf("%f%f", &cz8, &cz9);
						h2014 = 0;
						for (m1 = 0; m1 < 10000; m1++) {
							if (sj[m1] >= cz8 && sj[m1] <= cz9) {
								printf("找到数据，此数据序号为%d  备注为%s  数据为%f\n", xvh[m1], su[m1].bz, sj[m1]);
								h2014++;
							}
						}
						printf("共找到%d个数据\n", h2014);
						break;
					case 14:printf("请输入要保存的个数\n");
						scanf("%d", &c13);
						printf("请输入要保存的数据序号\n");
						for (m1 = 0; m1 < c13; m1++) {
							scanf("%d", &lsx[m1]);
						}
						for (m1 = 0; m1 < c13; m1++) {
							fprintf(fout, "序号%d备注为%s数据为%f次序为%d\n", xvh[lsx[m1] - 1], su[lsx[m1] - 1].bz, sj[lsx[m1] - 1], mc[lsx[m1] - 1]);
							printf("已保存序号%d备注为%s数据%f次序%d\n", xvh[lsx[m1] - 1], su[lsx[m1] - 1].bz, sj[lsx[m1] - 1], mc[lsx[m1] - 1]);
						}
						fprintf(fout, "数据总数%d\n", gs);
						printf("保存成功\n");
						fout = fopen("数据文件.txt", "wb");
						for (m1 = 0; m1 < c13; m1++) {
							fprintf(fout, "%d\n", xvh[lsx[m1] - 1]);
							fprintf(fout, "%s\n", su[lsx[m1] - 1].bz);
							fprintf(fout, "%f\n", sj[lsx[m1] - 1]);
							fprintf(fout, "%d\n", mc[lsx[m1] - 1]);
						}
						fprintf(fout, "%d\n", zg);
						fprintf(fout, "%d\n", zdz);
						break;
					case 15:printf("请输入要排序的个数\n");
						scanf("%d", &c14);
						printf("请依次输入要排序的数据序号\n");
						for (m1 = 0; m1 < c14; m1++) {
							scanf("%d", &lsx[m1]);
						}
						for (px1 = 0; px1 < c14; px1++) {
							mc[lsx[px1] - 1] = c14;
						}//次序初始化 
						for (jj1 = 1, px1 = 0; jj1 <= c14; jj1++) {
							for (px2 = 0; px2 < c14; px2++) {
								if (sj[lsx[px1] - 1] >= sj[lsx[px2] - 1] && lsx[px1] - 1 != lsx[px2] - 1) {
									mc[lsx[px1] - 1]--;
								}
								else if (sj[lsx[px1] - 1] < sj[lsx[px2] - 1]) {
									mc[lsx[px1] - 1] = mc[lsx[px1] - 1];
								}
							}
							px1++;
						}
						printf("请选择排序方式\n");
						printf("1、升序排列\n");
						printf("2、降序排列\n");
						printf("3、直接排序,按序号顺序输出\n");
						printf("4、退出\n");
						scanf("%d", &sw10);
						switch (sw10) {
						case 2:for (pl1 = 1; pl1 <= c14; pl1++) {
							for (pl2 = 0; pl2 < c14; pl2++) {
								if (mc[lsx[pl2] - 1] == pl1) {
									printf("第%d个的序号为%d备注为%s数据为%f\n", pl1, lsx[pl2], su[lsx[pl2] - 1].bz, sj[lsx[pl2] - 1]);
								}
							}
						}break;
						case 1:for (pl3 = c14; pl3 >= 1; pl3--) {
							for (pl4 = 0; pl4 < c14; pl4++) {
								if (mc[lsx[pl4] - 1] == pl3) {
									printf("第%d个的序号为%d备注为%s数据为%f\n", pl3, lsx[pl4], su[lsx[pl4] - 1].bz, sj[lsx[pl4] - 1]);
								}
							}
						}break;
						case 4:continue; break;
						case 3:for (px1 = 0; px1 < c14; px1++) {
							printf("序号%d  备注为%s  数据为%f  次序为%d\n\n", lsx[px1], su[lsx[px1] - 1].bz, sj[lsx[px1] - 1], mc[lsx[px1] - 1]);
						}break;
						default:printf("输入错误\n"); break;
						}
						break;
					case 16:printf("请输入要修改备注的序号:\n");
						scanf("%d", &c15);
						printf("请输入修改后的备注:\n");
						scanf("%d", &tc);
						gets(xmxg);
						strcpy(su[c15 - 1].bz, xmxg);
						printf("修改成功\n");
						break;
					case 17:printf("请输入要输入备注的数据个数\n");
						scanf("%d", &c16);
						printf("请输入要输入备注的序号\n");
						for (m1 = 0; m1 < c16; m1++) {
							scanf("%d", &lsx[m1]);
						}
						printf("请依次输入备注\n");
						for (m1 = 0; m1 < c16; m1++) {
							scanf("%d", &tc);
							gets(xmls);
							strcpy(su[lsx[m1] - 1].bz, xmls);
						}
						break;
					case 18:printf("请输入要清零的数据个数（按顺序）\n");
						scanf("%d", &c17);
						for (m1 = 0; m1 < c17; m1++) {
							sj[m1] = 0;
						}
						printf("清零成功\n");
						break;
					case 19:printf("请输入要清零的个数\n");
						scanf("%d", &c18);
						printf("请分别输入要清零的序号\n");
						for (m1 = 0; m1 < c18; m1++) {
							scanf("%d", &lsx[m1]);
						}
						for (m1 = 0; m1 < c18; m1++) {
							sj[lsx[m1] - 1] = 0;
						}
						printf("清零成功\n");
						break;
					case 20:printf("                                         菜单\n");
						printf("1、每次登录直接读取数据\n");
						printf("2、每次退出时自动保存数据\n");
						printf("3、取消登录直接读取数据\n");
						printf("4、取消退出时自动保存数据\n");
						scanf("%d", &c19);
						switch (c19) {
						case 1:fout = fopen("系统文件1.txt", "wb");
							fprintf(fout, "%d\n", 1);
							printf("设置成功\n");
							break;
						case 2:fout = fopen("系统文件2.txt", "wb");
							fprintf(fout, "%d\n", 2);
							printf("设置成功\n");
							break;
						case 3:fout = fopen("系统文件1.txt", "wb");
							printf("设置成功\n");
							break;
						case 4:fout = fopen("系统文件2.txt", "wb");
							printf("设置成功\n");
							break;
						default:printf("输入错误\n");
							break;
						}
						break;
					default:printf("输入错误\n");
						break;
					}// case 2 switch
				}//case 2 for
				break;
			}
			else {
				printf("程序已被封锁,请退出\n");
				return 0;
			}
			break;


		default:printf("输入错误\n");
			break;


		}//switch，位于第49行 
	}//for，位于第35行 
	return 0;
}//main



