#include<stdio.h>
#include<windows.h>
int main() {
	float cj[500][50];//成绩管理系统,成绩记录变量
	int px[500][50];//成绩排序变量  //先人再成绩 
	struct cg1 {
		char mz[10];//成绩名称输入 
	}cjm[500];
	struct cg {
		char xm[100];//姓名输入 
	}st[500];
	int xh[500], ls[500];//学号变量，学号输入临时变量 
	int us[500];//每个成绩的个数 








	float o1, abc1, ad1;//成绩操作变量 
	int f1, j1, sr;//其余变量 
	int m1, p1, s1, t1, ab1, af1;//其余变量，如for循环
	int sw1, sw2, sw3, sw4, sw5, sw6, sw7, sw8, sw9, sw10, sw11, sw12, sw13, sw14, sw15, sw16, sw17, sw18, sw19, sw20;//switch变量 
	int sc1, sc2, sc3, sc4, sc5, sc6, sc7, sc8, sc9, sc10, sc11, sc12, sc14, sc15, sc99;//scanf变量   
	int cs = 0;//查找失败判断 



	int cjcz;//查找出的成绩个数
	int u = 0;//数据总数 
	int xhs = 0, xms = 0;//学号个数，姓名个数 
	int fsd = 0;//分数段人数 
	int un = 0;//多少个有效分数  
	int unz[500];//每个人有多少个有效分数  







	int pm;
	pm = 1;//为了牌面工整
	int pl1, pl2, pl3, pl4;//排序变量 
	int au = 0;//自动导入成绩 
	int kg = 0;//导出分析结果  
	int yc = 0;//控制次数









	float zf = 0;//总分变量 
	double ave;//平均成绩变量 
	int pxbl1, pxbl2;//排序变量 
	float w1, x1;//最高分最低分 
	int mf;//满分分数 
	int fs1 = 0, fs2 = 0, fs3 = 0;//满分人数 
	float fl1 = 0, fl2 = 0, fl3 = 0;//满分率 
	float jt[500];//学生进退 
	int jtp[500];//进退排序 
	float mzf[500];//每个人的总分 




	pxbl1 = 0;// 成绩排序处
	pxbl2 = 0;//成绩排序处  
	char xmcz[100];//姓名查找输入姓名 
	char xmxg[100];//姓名修改输入 
	char xmls[100];//姓名连输处输入,同用于批量修改 
	int tc;//为姓名查找填充缓冲 
	FILE* fout, * fin;





	for (m1 = 0; m1 < 500; m1++) {
		for (p1 = 0; p1 < 50; p1++) {
			cj[m1][p1] = 404;
		}

	}//定义成绩 

	for (m1 = 0; m1 < 500; m1++) {
		xh[m1] = 505;
	}//定义学号


	for (m1 = 0; m1 < 500; m1++) {
		st[m1].xm[0] = 'x';
	}


	for (m1 = 0; m1 < 500; m1++) {
		for (p1 = 0; p1 < 50; p1++) {
			px[m1][p1] = 0;
		}

	}


	fin = fopen("自动导入文件.txt", "rb");
	fscanf(fin, "%d", &au);


	if (au == 1) {
		fin = fopen("系统导入文件.txt", "rb");
		fscanf(fin, "%d", &u);
		fscanf(fin, "%d", &un);
		sc11 = u;
		sc5 = un;
		fin = fopen("学号导入文件.txt", "rb");
		for (af1 = 0; af1 < sc11; af1++) {
			fscanf(fin, "%d", &xh[af1]);
		}
		fin = fopen("姓名导入文件.txt", "rb");
		for (af1 = 0; af1 < sc11; af1++) {
			fscanf(fin, "%s", &st[af1].xm);
		}
		fin = fopen("成绩导入文件.txt", "rb");
		for (m1 = 0; m1 < sc5; m1++) {
			for (af1 = 0; af1 < sc11; af1++) {
				fscanf(fin, "%f", &cj[af1][m1]);
			}
		}
		fin = fopen("名次导入文件.txt", "rb");
		for (m1 = 0; m1 < sc5; m1++) {
			for (af1 = 0; af1 < sc11; af1++) {
				fscanf(fin, "%d", &px[af1][m1]);
			}
		}
		fin = fopen("成绩名称导入文件.txt", "rb");
		for (m1 = 0; m1 < 50; m1++) {
			fscanf(fin, "%s", &cjm[m1].mz);
		}


	}




	for (;;) {
	kt:
		system("color a");
		system("cls");
		printf("                               欢迎使用成绩分析系统\n\n");
		printf("                                    张梓浩制作\n\n\n");
		printf("              本程序主要是用于成绩的分析，而不仅仅用于成绩的记录与查看\n\n");
		printf("                   请选择想要进入的程序,输入相应数字并按下Enter键\n\n");
		printf("               |     1、成绩手动输入     |     2、文件导入成绩     |\n");
		printf("               |     3、保存导出成绩     |     4、查看学生成绩     |\n");
		printf("               |     5、进行成绩分析     |     6、程序使用说明     |\n");
		printf("               |     7、退出分析系统     |     8、生成导入文件     |\n");
		printf("               |     9、系统设置                                   |\n");

		if (pm == 1) {
			printf("\n\n\n\n\n\n\n");
		}
		pm = 2;



		if (yc == 0) {
			if (kg == 1) {
				fout = fopen("成绩分析结果.doc", "wb");
				yc = 1;
			}
		}






		u = 0;//数据总数 
		un = 0;
		xhs = 0, xms = 0;//学号个数，姓名个数 
		for (m1 = 0; m1 < 500; m1++) {
			us[m1] = 0;
			unz[m1] = 0;
		}


		for (m1 = 0; m1 < 500; m1++) {
			jt[m1] = 0;
			jtp[m1] = 0;
			mzf[m1] = 0;
		}


		for (m1 = 0; m1 < 500; m1++) {
			ls[m1] = 0;
		}//临时变量初始化





		for (m1 = 0; m1 < 500; m1++) {
			for (p1 = 0; p1 < 50; p1++) {
				if (cj[m1][p1] != 404) {
					us[m1]++;
				}
			}

		}
		u = us[0];
		for (m1 = 0; m1 < 500; m1++) {
			if (u < us[m1]) {
				u = us[m1];
			}
		}




		for (m1 = 0; m1 < 500; m1++) {
			if (xh[m1] != 505) {
				xhs++;
			}
		}




		for (m1 = 0; m1 < 500; m1++) {
			if (st[m1].xm[0] != 'x') {
				xms++;
			}
		}


		if (xhs > u) {
			u = xhs;
		}
		if (xms > u) {
			u = xms;
		}//计算数据个数 



		for (m1 = 0; m1 < 500; m1++) {
			for (p1 = 0; p1 < 50; p1++) {
				if (cj[m1][p1] != 404) {
					unz[m1]++;
				}
			}

		}
		un = unz[0];
		for (m1 = 0; m1 < 500; m1++) {
			if (un < unz[m1]) {
				un = unz[m1];
			}
		}





		sc3 = u;
		for (sc5 = 0; sc5 < un; sc5++) {

			for (pxbl1 = 0; pxbl1 < sc3; pxbl1++) {
				px[pxbl1][sc5] = sc3;
			}
			for (j1 = 1, pxbl1 = 0; j1 <= sc3; pxbl1++, j1++) {
				for (pxbl2 = 0; pxbl2 < sc3; pxbl2++) {
					if (cj[pxbl1][sc5] >= cj[pxbl2][sc5] && pxbl2 != pxbl1) {
						px[pxbl1][sc5]--;
					}
					else if (cj[pxbl1][sc5] < cj[pxbl2][sc5]) {
						px[pxbl1][sc5] = px[pxbl1][sc5];
					}
				}
			}


		}
		scanf("%d", &sw1);
		switch (sw1) {
		case 1:////////////////////////////////////////////////////////////////////
			system("cls");
			printf("请选择输入方式\n\n");
			printf("本系统总共可以存储500个学生的信息，每个学生50个成绩\n");
			printf("若在输入过程中出现错误，请先全部输入完再选9进行修改\n\n");
			printf("1、输入成绩名称\n\n");
			printf("2、按顺序输入学生学号\n");
			printf("3、按顺序输入学生姓名\n");
			printf("4、按顺序输入同一个成绩\n");
			printf("5、按顺序输入每个人所有的成绩\n");
			printf("6、按顺序一次性输入所有信息\n\n");
			printf("7、多个学号输入同一成绩\n");
			printf("8、多个序号输入同一成绩\n\n");
			printf("9、输入姓名或学号或序号或成绩更改信息\n");
			printf("10、输入姓名或学号或序号或成绩删除该学生信息\n");
			printf("11、删除某一次成绩\n\n");
			printf("12、退出\n\n");
			scanf("%d", &sc2);
			switch (sc2) {











			case 1:


				system("cls");
				printf("你想要输入第几个成绩的名称：(1-50)\n\n");
				scanf("%d", &sc1);

				printf("请输入名称\n\n");
				scanf("%d", &tc);
				gets(cjm[sc1 - 1].mz);
				printf("已输入名称:%s\n\n", cjm[sc1 - 1].mz);
				break;


			case 2:

				system("cls");
				printf("你想要输入多少个人的学号：(最多500个)\n\n");
				scanf("%d", &sc1);
				printf("请按顺序输入，一一对应\n\n");
				printf("假如有的学号暂时不知道，可暂时输入505，然后再修改,切勿留空\n\n");
				printf("请输入从第几个人开始输入：(1-500)\n\n");
				scanf("%d", &sc2);
				sr = sc2 - 1;

				for (m1 = 0; m1 < sc1; m1++, sr++) {

					printf("请输入学号\n\n");
					scanf("%d", &xh[sr]);

					printf("已输入学号:%d\n\n", xh[sr]);
				}
				break;




			case 3:

				system("cls");
				printf("你想要输入多少个人的姓名：(最多500个)\n\n");
				scanf("%d", &sc1);
				printf("请按顺序输入，一一对应\n\n");
				printf("假如有的名字暂时不知道，可暂时输入x，然后再修改,切勿留空\n\n");
				printf("请输入从第几个人开始输入：(1-500)\n\n");
				scanf("%d", &sc2);
				sr = sc2 - 1;

				for (m1 = 0; m1 < sc1; m1++, sr++) {

					printf("请输入姓名\n\n");
					scanf("%d", &tc);
					gets(st[sr].xm);
					printf("已输入姓名:%s\n\n", st[sr].xm);
				}
				break;



			case 4:





				system("cls");
				printf("你想要输入多少个人的成绩：(最多500个)\n\n");
				scanf("%d", &sc1);
				printf("你想要输入他们第几个成绩（1-50）：\n\n");
				scanf("%d", &sc2);
				printf("请按顺序输入成绩,一一对应\n\n");
				printf("假如有的成绩暂时不知道，可暂时输入404，然后再修改,切勿留空\n\n");
				printf("请输入从第几个人开始输入：(1-500)\n\n");
				scanf("%d", &sc5);
				sr = sc5 - 1;

				for (m1 = 0; m1 < sc1; m1++, sr++) {


					printf("请输入成绩\n\n");
					scanf("%f", &cj[sr][sc2 - 1]);
					printf("已输入%s成绩:%1.1f\n\n", cjm[sc2 - 1].mz, cj[sr][sc2 - 1]);



				}
				break;



			case 5:


				system("cls");
				printf("你想要输入多少个人的成绩：(最多500个)\n\n");
				scanf("%d", &sc1);
				printf("请按顺序输入成绩,一一对应\n\n");
				printf("假如有的成绩暂时不知道，可暂时输入404，然后再修改,切勿留空\n\n");
				printf("请输入从第几个人开始：(1-500)\n\n");
				scanf("%d", &sc2);
				sr = sc2 - 1;
				printf("一个学生你要输入多少个成绩：\n\n");
				scanf("%d", &sc5);
				printf("你要从学生的第几个成绩输起：\n\n");
				scanf("%d", &sc6);
				p1 = sc6 - 1;



				for (m1 = 0; m1 < sc1; m1++, sr++) {
					p1 = sc6 - 1;
					for (s1 = 0; s1 < sc5; s1++, p1++) {
						printf("请输入第%d人的第%d个成绩\n\n", sr + 1, p1 + 1);
						scanf("%f", &cj[sr][p1]);
						printf("已输入%s成绩:%1.1f\n\n", cjm[p1].mz, cj[sr][p1]);
					}

				}
				break;




			case 6:

				system("cls");
				printf("你想要输入多少人的信息：(最多500个)\n\n");
				scanf("%d", &sc1);
				printf("请按顺序输入学号，姓名与各个成绩\n\n");
				printf("假如有的学号姓名或成绩暂时不知道的，可暂时输入505,x,404，然后再修改,切勿留空\n\n");
				printf("请输入从第几个人开始输入：(1-500)\n\n");
				scanf("%d", &sc2);
				printf("一个学生你要输入多少个成绩：\n\n");
				scanf("%d", &sc5);
				printf("你要从学生的第几个成绩输起：\n\n");
				scanf("%d", &sc6);
				sr = sc2 - 1;
				p1 = sc6 - 1;


				for (m1 = 0; m1 < sc1; m1++, sr++) {
					p1 = sc6 - 1;
					printf("请输入学号\n\n");
					scanf("%d", &xh[sr]);
					printf("请输入姓名\n\n");
					scanf("%d", &tc);
					gets(st[sr].xm);





					for (s1 = 0; s1 < sc5; s1++, p1++) {
						printf("请按顺序输入第%d个成绩\n\n", p1 + 1);
						scanf("%f", &cj[sr][p1]);

					}

					printf("已输入学号:%d  姓名:%s  ", xh[sr], st[sr].xm);
					p1 = sc6 - 1;
					for (s1 = 0; s1 < sc5; s1++, p1++) {
						printf("%s成绩:%1.1f  ", cjm[p1], cj[sr][p1]);
					}
					printf("\n\n");


				}
				break;


			case 7:


				system("cls");
				printf("你想输入多少个人的成绩：(最多500个)\n\n");
				scanf("%d", &sc6);
				printf("你想要输入他们的第几个成绩：（1-50）\n\n");
				scanf("%d", &sc2);
				printf("请依次输入为该成绩的学生的学号：\n");
				printf("前提是已经录入学号，学号未录入将按默认为404\n\n");
				for (s1 = 0; s1 < sc6; s1++) {
					scanf("%d", &ls[s1]);

				}
				printf("请输入统一的成绩：\n\n");
				scanf("%f", &o1);
				for (p1 = 0; p1 < u; p1++) {
					for (s1 = 0; s1 < sc6; s1++) {
						if (xh[p1] == ls[s1]) {
							cj[p1][sc2 - 1] = o1;
							printf("已输入学号%d的%s成绩为%1.1f\n\n", xh[p1], cjm[sc2 - 1].mz, cj[p1][sc2 - 1]);
						}
					}
				}
				printf("未录入姓名请到姓名输入处输入姓名\n\n");
				break;






			case 8:

				system("cls");
				printf("你想输入多少个人的成绩：(最多500个)\n\n");
				scanf("%d", &sc6);
				printf("你想要输入第几个成绩：（1-50）\n\n");
				scanf("%d", &sc2);
				printf("请依次输入为该成绩的学生的序号：\n\n");
				for (s1 = 0; s1 < sc6; s1++) {
					scanf("%d", &ls[s1]);

				}
				printf("请输入统一的成绩：\n\n");
				scanf("%f", &o1);
				for (s1 = 0; s1 < sc6; s1++) {
					cj[ls[s1] - 1][sc2 - 1] = o1;
					printf("已输入学号%d的%s成绩为%1.1f\n\n", xh[ls[s1] - 1], cjm[sc2 - 1].mz, cj[ls[s1] - 1][sc2 - 1]);
				}

				printf("未录入姓名请到姓名输入处输入姓名\n\n");

				break;



			case 9:


				system("cls");
				printf("1、按姓名查找\n");
				printf("2、按学号查找\n");
				printf("3、按序号查找\n");
				printf("4、按成绩查找\n");
				scanf("%d", &sc12);
				switch (sc12) {




				case 1:



					system("cls");
					printf("请输入学生姓名:\n\n");
					scanf("%d", &tc);
					gets(xmcz);
					for (m1 = 0; m1 < u; m1++) {
						if (strcmp(st[m1].xm, xmcz) == 0) {
							goto next1;

						}
					}
					goto out1;
				next1:
					system("cls");
					printf("请输入要更改什么\n");
					printf("1、学号\n");
					printf("2、成绩\n");
					scanf("%d", &sc1);
					switch (sc1) {

					case 1:


						printf("请输入学号\n\n");
						scanf("%d", &xh[m1]);
						printf("已输入学号:%d  姓名:%s\n\n", xh[m1], st[m1].xm);
						goto end;
						break;


					case 2:
						printf("你想要输入第几个成绩：（1-50）\n\n");
						scanf("%d", &sc2);
						printf("请输入成绩\n\n");
						scanf("%f", &cj[m1][sc2 - 1]);
						printf("已输入学号:%d  姓名:%s  %s成绩%d:%1.1f\n\n", xh[m1], st[m1].xm, cjm[sc2 - 1].mz, sc2, cj[m1][sc2 - 1]);
						goto end;
						break;

					default:printf("输入错误\n");
						printf("输入任意数按下Enter键继续......\n\n");
						scanf("%d", &sc99);
						break;

					}//

				out1:
					printf("查找失败\n\n");
				end:
					break;

				case 2:


					system("cls");
					printf("请输入学生学号:\n\n");
					scanf("%d", &sc4);



					for (m1 = 0; m1 < u; m1++) {
						if (xh[m1] == sc4) {
							goto next2;

						}
					}
					goto out2;

				next2:
					system("cls");
					printf("请输入要更改什么\n");
					printf("1、姓名\n");
					printf("2、成绩\n");
					scanf("%d", &sc1);
					switch (sc1) {

					case 1:


						printf("请输入姓名\n\n");
						scanf("%d", &tc);
						gets(st[m1].xm);
						printf("已输入学号:%d  姓名:%s\n\n", xh[m1], st[m1].xm);
						goto end1;
						break;


					case 2:

						printf("你想要输入第几个成绩：（1-50）\n\n");
						scanf("%d", &sc2);
						printf("请输入成绩\n\n");
						scanf("%f", &cj[m1][sc2 - 1]);
						printf("已输入学号:%d  姓名:%s  %s成绩%d:%1.1f\n\n", xh[m1], st[m1].xm, cjm[sc2 - 1].mz, sc2, cj[m1][sc2 - 1]);
						goto end1;
						break;

					default:printf("输入错误\n");
						printf("输入任意数按下Enter键继续......\n\n");
						scanf("%d", &sc99);
						break;

					}//

				out2:
					printf("查找失败\n\n");
				end1:
					break;

				case 3:


					system("cls");
					printf("请输入想要输入信息的序号\n\n");
					scanf("%d", &sc1);


					system("cls");
					printf("请输入要更改什么\n");
					printf("1、姓名\n");
					printf("2、学号\n");
					printf("3、成绩\n");
					scanf("%d", &sc5);





					switch (sc5) {

					case 1:


						printf("请输入姓名\n\n");
						scanf("%d", &tc);
						gets(st[sc1 - 1].xm);
						printf("已输入学号:%d  姓名:%s\n\n", xh[sc1 - 1], st[sc1 - 1].xm);
						break;






					case 2:


						printf("请输入学号\n\n");
						scanf("%d", &xh[sc1 - 1]);
						printf("已输入学号:%d  姓名:%s\n\n", xh[sc1 - 1], st[sc1 - 1].xm);
						break;

					case 3:

						printf("你想要输入第几个成绩：（1-50）\n\n");
						scanf("%d", &sc2);
						printf("请输入成绩\n\n");
						scanf("%f", &cj[sc1 - 1][sc2 - 1]);
						printf("已输入学号:%d  姓名:%s  %s成绩%d:%1.1f\n\n", xh[sc1 - 1], st[sc1 - 1].xm, cjm[sc2 - 1].mz, sc2, cj[sc1 - 1][sc2 - 1]);
						break;

					default:printf("输入错误\n");
						printf("输入任意数按下Enter键继续......\n\n");
						scanf("%d", &sc99);
						break;
					}//



					break;






				case 4:
					m1 = 0; cs = 0;
					printf("请输入按哪个成绩查找\n\n");
					scanf("%d", &sc1);
					printf("请输入学生成绩:\n\n");
					scanf("%f", &abc1);
					for (; m1 < u; m1++) {

						if (cj[m1][sc1 - 1] == abc1) {
							goto next;
						}
					back:;
					}
					goto out;
				next:
					printf("该学生序号为%d\n\n", m1 + 1);
					Sleep(500);
					system("cls");
					printf("请输入要更改什么\n");
					printf("1、姓名\n");
					printf("2、学号\n");
					printf("3、成绩\n");
					scanf("%d", &sc5);
					switch (sc5) {

					case 1:


						printf("请输入姓名\n\n");
						scanf("%d", &tc);
						gets(st[m1].xm);
						printf("已输入学号:%d  姓名:%s\n\n", xh[m1], st[m1].xm);
						cs++;
						goto back;
						break;





					case 2:

						printf("请输入学号\n\n");
						scanf("%d", &xh[m1]);
						printf("已输入学号:%d  姓名:%s\n\n", xh[m1], st[m1].xm);
						cs++;
						goto back;
						break;


					case 3:

						printf("你想要输入第几个成绩：（1-50）\n\n");
						scanf("%d", &sc2);
						printf("请输入成绩\n\n");
						scanf("%f", &cj[m1][sc2 - 1]);
						printf("已输入学号:%d  姓名:%s  %s成绩%d:%1.1f\n\n", xh[m1], st[m1].xm, cjm[sc2 - 1].mz, sc2, cj[m1][sc2 - 1]);
						cs++;
						goto back;
						break;

					default:printf("输入错误\n");
						printf("输入任意数按下Enter键继续......\n\n");
						scanf("%d", &sc99);
						break;

					}//

				out:;
					if (cs == 0) {
						printf("查找失败\n\n");
					}



					break;

				default:printf("输入错误\n");
					printf("输入任意数按下Enter键继续......\n\n");
					scanf("%d", &sc99);
					break;



				}
				break;// 







			case 10:


				system("cls");
				printf("1、按姓名查找\n");
				printf("2、按学号查找\n");
				printf("3、按序号查找\n");
				printf("4、按成绩查找\n");
				scanf("%d", &sc12);
				switch (sc12) {




				case 1:



					system("cls");
					printf("请输入学生姓名:\n\n");
					scanf("%d", &tc);
					gets(xmcz);
					for (m1 = 0; m1 < u; m1++) {
						if (strcmp(st[m1].xm, xmcz) == 0) {
							goto nexta;

						}
					}
					goto outa;
				nexta:
					printf("已删除学号:%d  姓名:%s\n\n", xh[m1], st[m1].xm);
					for (p1 = m1; p1 < u - 1; p1++) {
						xh[p1] = xh[p1 + 1];
						strcpy(st[p1].xm, st[p1 + 1].xm);
						for (ab1 = 0; ab1 < un; ab1++) {
							cj[p1][ab1] = cj[p1 + 1][ab1];
							px[p1][ab1] = px[p1 + 1][ab1];
						}
					}
					xh[u - 1] = 505;
					strcpy(st[u - 1].xm, st[u + 1].xm);
					for (ab1 = 0; ab1 < un; ab1++) {
						cj[u - 1][ab1] = 404;
						px[u - 1][ab1] = 0;
					}
					goto enda;

				outa:
					printf("查找失败\n\n");
				enda:
					break;

				case 2:


					system("cls");
					printf("请输入学生学号:\n\n");
					scanf("%d", &sc4);



					for (m1 = 0; m1 < u; m1++) {
						if (xh[m1] == sc4) {
							goto nextb;

						}
					}
					goto outb;

				nextb:



					printf("已删除学号:%d  姓名:%s\n\n", xh[m1], st[m1].xm);
					for (p1 = m1; p1 < u - 1; p1++) {
						xh[p1] = xh[p1 + 1];
						strcpy(st[p1].xm, st[p1 + 1].xm);
						for (ab1 = 0; ab1 < un; ab1++) {
							cj[p1][ab1] = cj[p1 + 1][ab1];
							px[p1][ab1] = px[p1 + 1][ab1];
						}

					}
					xh[u - 1] = 505;
					strcpy(st[u - 1].xm, st[u + 1].xm);
					for (ab1 = 0; ab1 < un; ab1++) {
						cj[u - 1][ab1] = 404;
						px[u - 1][ab1] = 0;

					}





					goto endb;

				outb:
					printf("查找失败\n\n");
				endb:
					break;

				case 3:


					system("cls");
					printf("请输入想要删除信息的序号\n\n");
					scanf("%d", &sc1);
					m1 = sc1 - 1;
					printf("已删除学号:%d  姓名:%s\n\n", xh[m1], st[m1].xm);
					for (p1 = m1; p1 < u - 1; p1++) {
						xh[p1] = xh[p1 + 1];
						strcpy(st[p1].xm, st[p1 + 1].xm);
						for (ab1 = 0; ab1 < un; ab1++) {
							cj[p1][ab1] = cj[p1 + 1][ab1];
							px[p1][ab1] = px[p1 + 1][ab1];
						}
					}
					xh[u - 1] = 505;
					strcpy(st[u - 1].xm, st[u + 1].xm);
					for (ab1 = 0; ab1 < un; ab1++) {
						cj[u - 1][ab1] = 404;
						px[u - 1][ab1] = 0;
					}





					break;






				case 4:
					m1 = 0; cs = 0;
					printf("请输入按哪个成绩查找\n\n");
					scanf("%d", &sc1);
					printf("请输入学生成绩:\n\n");
					scanf("%f", &abc1);
					for (; m1 < u; m1++) {

						if (cj[m1][sc1 - 1] == abc1) {
							goto nextc;
						}
					backc:;
					}
					goto outc;
				nextc:
					printf("该学生学号:%d  姓名:%s\n\n", xh[m1], st[m1].xm);
					printf("是否要删除，输入404跳过该生，搜索下一个学生:\n");
					printf("输入任意数按Enter键删除\n\n");
					scanf("%d", &sc5);
					if (sc5 == 404) {
						cs++;
						goto outc;
					}
					printf("已删除学号:%d  姓名:%s\n\n", xh[m1], st[m1].xm);
					for (p1 = m1; p1 < u - 1; p1++) {
						xh[p1] = xh[p1 + 1];
						strcpy(st[p1].xm, st[p1 + 1].xm);
						for (ab1 = 0; ab1 < un; ab1++) {
							cj[p1][ab1] = cj[p1 + 1][ab1];
							px[p1][ab1] = px[p1 + 1][ab1];
						}
						cs++;

					}
					xh[u - 1] = 505;
					strcpy(st[u - 1].xm, st[u + 1].xm);
					for (ab1 = 0; ab1 < un; ab1++) {
						cj[u - 1][ab1] = 404;
						px[u - 1][ab1] = 0;
					}
					goto backc;
				outc:;
					if (cs == 0) {
						printf("查找失败\n\n");
					}



					break;

				default:printf("输入错误\n");
					printf("输入任意数按下Enter键继续......\n\n");
					scanf("%d", &sc99);
					break;



				}
				break;// 







			case 11:
				system("cls");
				printf("请输入要删除哪一个成绩:\n\n");
				scanf("%d", &sc12);
				for (m1 = 0; m1 < u; m1++) {
					cj[m1][sc12 - 1] = 404;
					px[m1][sc12 - 1] = 0;
				}
				cjm[sc12 - 1].mz[0] = '\0';
				for (ab1 = sc12 - 1; ab1 < un - 1; ab1++) {
					strcpy(cjm[ab1].mz, cjm[ab1 + 1].mz);
					for (m1 = 0; m1 < u; m1++) {
						cj[m1][ab1] = cj[m1][ab1 + 1];
						px[m1][ab1] = px[m1][ab1 + 1];
					}

				}
				strcpy(cjm[un - 1].mz, cjm[un].mz);
				for (ab1 = 0; ab1 < u; ab1++) {
					cj[ab1][un - 1] = 404;
					px[ab1][un - 1] = 0;
				}
				printf("已删除\n\n");




				break;




			case 12:break;


			default:printf("输入错误\n"); break;


			}
			printf("输入任意数按下Enter键继续......\n\n");
			scanf("%d", &sc99);
			break;








		case 2://////////////////////////////////////////////////////////////////////
			system("cls");
			fin = fopen("系统导入文件.txt", "rb");
			fscanf(fin, "%d", &u);
			fscanf(fin, "%d", &un);
			sc11 = u;
			sc5 = un;
			printf("请在导入文件中输入数据\n");
			printf("若没有导入文件请点击生成导入文件后退出，即出现\n");
			printf("若已经导出成绩则导入文件中已有成绩\n");
			printf("默认导入所有有效成绩\n\n");
			printf("输入任意数字按Enter继续，输入404退出\n");
			scanf("%d", &sc14);
			if (sc14 == 404) {
				break;
			}
			fin = fopen("学号导入文件.txt", "rb");
			for (af1 = 0; af1 < sc11; af1++) {
				fscanf(fin, "%d", &xh[af1]);
			}
			fin = fopen("姓名导入文件.txt", "rb");
			for (af1 = 0; af1 < sc11; af1++) {
				fscanf(fin, "%s", &st[af1].xm);
			}
			fin = fopen("成绩导入文件.txt", "rb");
			for (m1 = 0; m1 < sc5; m1++) {
				for (af1 = 0; af1 < sc11; af1++) {
					fscanf(fin, "%f", &cj[af1][m1]);
				}
			}



			fin = fopen("名次导入文件.txt", "rb");
			for (m1 = 0; m1 < sc5; m1++) {
				for (af1 = 0; af1 < sc11; af1++) {
					fscanf(fin, "%d", &px[af1][m1]);
				}
			}




			fin = fopen("成绩名称导入文件.txt", "rb");
			for (m1 = 0; m1 < 50; m1++) {
				fscanf(fin, "%s", &cjm[m1].mz);
			}



			for (af1 = 0; af1 < sc11; af1++) {
				printf("已输入学号:%d  姓名:%s  ", xh[af1], st[af1].xm);
				for (m1 = 0; m1 < sc5; m1++) {
					printf("%s成绩%d:%1.1f  ", cjm[m1].mz, m1 + 1, cj[af1][m1]);
				}
				printf("\n\n");
			}


			printf("读取成功\n");
			printf("输入任意数按下Enter键继续......\n\n");
			scanf("%d", &sc99);
			break;






		case 3:////////////////////////////////////////////////////////////// 
			system("cls");







			printf("默认保存所有成绩\n");
			sc2 = un;
			printf("输入任意数字按Enter继续，输入404退出\n");
			scanf("%d", &sc14);
			if (sc14 == 404) {
				break;
			}




			fout = fopen("学号导入文件.txt", "wb");
			fout = fopen("姓名导入文件.txt", "wb");
			fout = fopen("成绩导入文件.txt", "wb");
			fout = fopen("名次导入文件.txt", "wb");
			fout = fopen("成绩单.doc", "wb");
			fout = fopen("系统导入文件.txt", "wb");
			fout = fopen("成绩名称导入文件.txt", "wb");
			fout = fopen("系统导入文件.txt", "wb");
			fout = fopen("成绩单.doc", "a+");




			for (m1 = 0; m1 < u; m1++) {
				fprintf(fout, "学号:%d 姓名:%s ", xh[m1], st[m1].xm);
				printf("学号:%d 姓名:%s ", xh[m1], st[m1].xm);
				for (p1 = 0; p1 < sc2; p1++) {
					fprintf(fout, "%s成绩%d:%1.1f  ", cjm[p1].mz, p1 + 1, cj[m1][p1]);
					fprintf(fout, "名次:%d  ", px[m1][p1]);
					printf("%s成绩%d:%1.1f  ", cjm[p1].mz, p1 + 1, cj[m1][p1]);
					printf("名次:%d  ", px[m1][p1]);
				}
				fprintf(fout, "\n\n");
				printf("\n\n");
			}
			printf("保存成功\n");





			fout = fopen("学号导入文件.txt", "a+");
			for (m1 = 0; m1 < u; m1++) {
				fprintf(fout, "%d\n", xh[m1]);
			}



			fout = fopen("姓名导入文件.txt", "a+");
			for (m1 = 0; m1 < u; m1++) {
				fprintf(fout, "%s\n", st[m1].xm);
			}



			fout = fopen("成绩导入文件.txt", "a+");
			for (m1 = 0; m1 < sc2; m1++) {
				for (af1 = 0; af1 < u; af1++) {
					fprintf(fout, "%1.1f\n", cj[af1][m1]);
				}
			}

			fout = fopen("名次导入文件.txt", "a+");
			for (m1 = 0; m1 < sc2; m1++) {
				for (af1 = 0; af1 < u; af1++) {
					fprintf(fout, "%d\n", px[af1][m1]);
				}
			}



			fout = fopen("系统导入文件.txt", "a+");
			fprintf(fout, "%d\n", u);
			fprintf(fout, "%d\n", un);

			fout = fopen("成绩名称导入文件.txt", "a+");
			for (m1 = 0; m1 < 50; m1++) {
				fprintf(fout, "%s\n", cjm[m1].mz);
			}






			printf("输入任意数按下Enter键继续......\n\n");
			scanf("%d", &sc99);
			break;











		case 4://////////////////////////////////////////////////////////////////////
			system("cls");
			printf("请选择查找方式\n");
			printf("1、按学号查找\n");
			printf("2、按成绩查找\n");
			printf("3、按名次查找\n");
			printf("4、按姓名查找\n");
			printf("5、按序号查找\n");
			printf("6、按序号逐个输出\n");
			printf("7、按名次逐个输出\n");
			printf("8、按学号逐个输出\n");
			printf("9、退出\n\n");
			scanf("%d", &sw2);
			system("cls");
			switch (sw2) {
			case 1:printf("请输入学生学号:\n\n");
				scanf("%d", &sc4);
				if (sc4 > u) {
					printf("学生不存在\n\n");
					break;
				}
				sc2 = un;
				for (m1 = 0; m1 < u; m1++) {
					if (xh[m1] == sc4) {
						printf("学号:%d 姓名:%s ", xh[m1], st[m1].xm);
						for (p1 = 0; p1 < sc2; p1++) {
							printf("%s成绩%d:%1.1f  ", cjm[p1].mz, p1 + 1, cj[m1][p1]);
							printf("名次:%d  ", px[m1][p1]);
						}
						printf("\n\n");
					}
				}
				printf("输入任意数按下Enter键继续......\n\n");
				scanf("%d", &sc99);
				break;
			case 2:printf("请输入要查看哪个成绩\n\n");
				scanf("%d", &sc2);
				if (sc2 > un) {
					printf("该成绩不存在\n\n");
					printf("输入任意数按下Enter键继续......\n\n");
					scanf("%d", &sc99);
					break;
				}
				printf("请输入学生成绩:\n\n");
				scanf("%f", &abc1);
				sc5 = un;
				cjcz = 0;
				for (m1 = 0; m1 < u; m1++) {


					if (cj[m1][sc2 - 1] == abc1) {
						cjcz++;


						printf("学号:%d 姓名:%s ", xh[m1], st[m1].xm);
						for (p1 = 0; p1 < sc5; p1++) {
							printf("%s成绩%d:%1.1f  ", cjm[p1].mz, p1 + 1, cj[m1][p1]);
							printf("名次:%d  ", px[m1][p1]);
						}
						printf("\n\n");
					}


				}





				printf("共搜索到%d个成绩\n", cjcz);
				printf("输入任意数按下Enter键继续......\n\n");
				scanf("%d", &sc99);
				break;




			case 3:printf("请输入要查看哪个成绩\n\n");
				scanf("%d", &sc2);
				if (sc2 > un) {
					printf("该成绩不存在\n\n");
					printf("输入任意数按下Enter键继续......\n\n");
					scanf("%d", &sc99);
					break;
				}
				printf("请输入学生名次:\n");
				scanf("%d", &sc5);
				sc1 = un;
				cjcz = 0;




				for (m1 = 0; m1 < u; m1++) {
					if (px[m1][sc2 - 1] == sc5) {
						cjcz++;
						printf("学号:%d 姓名:%s ", xh[m1], st[m1].xm);
						for (p1 = 0; p1 < sc1; p1++) {
							printf("%s成绩%d:%1.1f  ", cjm[p1].mz, p1 + 1, cj[m1][p1]);
							printf("名次:%d  ", px[m1][p1]);
						}
						printf("\n\n");
					}
				}



				printf("共搜索到%d个成绩\n", cjcz);
				printf("输入任意数按下Enter键继续......\n\n");
				scanf("%d", &sc99);
				break;





			case 4:printf("请输入学生姓名:\n\n");
				scanf("%d", &tc);
				gets(xmcz);
				sc1 = un;
				for (m1 = 0; m1 < u; m1++) {
					if (strcmp(st[m1].xm, xmcz) == 0) {
						printf("学号:%d 姓名:%s ", xh[m1], st[m1].xm);
						for (p1 = 0; p1 < sc1; p1++) {
							printf("%s成绩%d:%1.1f  ", cjm[p1].mz, p1 + 1, cj[m1][p1]);
							printf("名次:%d  ", px[m1][p1]);
						}
						printf("\n\n");
					}
				}
				printf("输入任意数按下Enter键继续......\n\n");
				scanf("%d", &sc99);
				break;







			case 5:printf("请输入序号:\n\n");
				scanf("%d", &sc5);
				if (sc5 > u) {
					printf("该学生不存在\n\n");
					printf("输入任意数按下Enter键继续......\n\n");
					scanf("%d", &sc99);
					break;
				}
				sc1 = un;
				sc5 = sc5 - 1;
				printf("学号:%d 姓名:%s ", xh[sc5], st[sc5].xm);
				for (p1 = 0; p1 < sc1; p1++) {
					printf("%s成绩%d:%1.1f  ", cjm[p1].mz, p1 + 1, cj[sc5][p1]);
					printf("名次:%d  ", px[sc5][p1]);
				}
				printf("\n\n");
				printf("输入任意数按下Enter键继续......\n\n");
				scanf("%d", &sc99);
				break;




			case 6:

				printf("因程序窗口限制，若成绩或人数过多，可能无法显示所有成绩\n\n");
				printf("此时请分段输入浏览，如1-35，36-70\n\n");
				printf("请输入查看哪个序号到哪个序号的成绩:\n\n");
				scanf("%d", &sc3);
				scanf("%d", &sc5);
				if (sc3 > sc5) {

					sc9 = sc3;
					sc3 = sc5;
					sc5 = sc9;
				}
				if (sc3 > u) {
					printf("该学生不存在\n\n");
					printf("输入任意数按下Enter键继续......\n\n");
					scanf("%d", &sc99);
					break;
				}
				if (sc5 > u) {
					sc5 = u;
				}
				sc1 = un;
				for (; sc3 <= sc5; sc3++) {
					printf("学号:%d 姓名:%s ", xh[sc3 - 1], st[sc3 - 1].xm);
					for (p1 = 0; p1 < sc1; p1++) {
						printf("%s成绩%d:%1.1f  ", cjm[p1].mz, p1 + 1, cj[sc3 - 1][p1]);
						printf("名次:%d  ", px[sc3 - 1][p1]);
					}
					printf("\n\n");
				}
				printf("输入任意数按下Enter键继续......\n\n");
				scanf("%d", &sc99);
				break;




			case 7:
				printf("请输入要查看哪个成绩\n\n");
				scanf("%d", &sc2);
				if (sc2 > un) {
					printf("该成绩不存在\n\n");
					printf("输入任意数按下Enter键继续......\n\n");
					scanf("%d", &sc99);
					break;
				}

				printf("因程序窗口限制，若成绩或人数过多，可能无法显示所有成绩\n\n");
				printf("此时请分段输入浏览，如1-35，36-70\n\n");
				printf("请输入查看哪个名次到哪个名次的成绩:\n\n");
				scanf("%d", &sc3);
				scanf("%d", &sc5);
				if (sc3 > sc5) {

					sc9 = sc3;
					sc3 = sc5;
					sc5 = sc9;
				}
				sc1 = un;

				for (; sc3 <= sc5; sc3++) {


					for (m1 = 0; m1 < u; m1++) {
						if (px[m1][sc2 - 1] == sc3) {
							printf("学号:%d 姓名:%s ", xh[m1], st[m1].xm);
							for (p1 = 0; p1 < sc1; p1++) {
								printf("%s成绩%d:%1.1f  ", cjm[p1].mz, p1 + 1, cj[m1][p1]);
								printf("名次:%d  ", px[m1][p1]);
							}
							printf("\n\n");
						}
					}
				}






				printf("输入任意数按下Enter键继续......\n\n");
				scanf("%d", &sc99);
				break;






			case 8:
				printf("因程序窗口限制，若成绩或人数过多，可能无法显示所有成绩\n\n");
				printf("此时请分段输入浏览，如1-35，36-70\n\n");
				printf("请输入查看哪个学号到哪个学号的成绩:\n\n");
				scanf("%d", &sc3);
				scanf("%d", &sc5);
				if (sc3 > sc5) {

					sc9 = sc3;
					sc3 = sc5;
					sc5 = sc9;
				}
				if (sc3 > u) {
					printf("该学生不存在\n\n");
					printf("输入任意数按下Enter键继续......\n\n");
					scanf("%d", &sc99);
					break;
				}
				if (sc5 > u) {
					sc5 = u;
				}
				for (ab1 = sc3; ab1 <= sc5; ab1++) {
					for (m1 = 0; m1 < u; m1++) {
						if (xh[m1] == ab1) {
							printf("学号:%d 姓名:%s ", xh[m1], st[m1].xm);
							for (p1 = 0; p1 < un; p1++) {
								printf("%s成绩%d:%1.1f  ", cjm[p1].mz, p1 + 1, cj[m1][p1]);
								printf("名次:%d  ", px[m1][p1]);
							}
							printf("\n\n");



						}
					}

				}
				printf("输入任意数按下Enter键继续......\n\n");
				scanf("%d", &sc99);
				break;














			case 9:break;





			default:printf("输入错误\n");
				printf("输入任意数按下Enter键继续......\n\n");
				scanf("%d", &sc99);
				break;
			}//第三个switch
			break;







		case 5:
			system("cls");
			printf("请选择分析内容\n\n");
			printf("若要导出分析结果文件，请选择10进行设置,默认不导出分析结果文件\n\n");
			printf("1、计算某个成绩某分数段的人数\n");
			printf("2、计算班级平均分，最高分，优秀率等数据\n");
			printf("3、各个成绩之间对比,计算进退情况并排名\n");
			printf("4、计算个人所有成绩的总分及总分排名\n");
			printf("5、对各个成绩进行排序\n");
			printf("6、查看某个成绩某个名次段的学生\n");
			printf("7、查看某个成绩前几名的学生\n");
			printf("8、查看某个成绩某个分数段的学生\n");
			printf("9、查看某个成绩某个分数以上的学生\n");
			printf("10、导出分析结果\n\n");
			printf("11、退出\n\n");
			scanf("%d", &sw2);
			system("cls");
			switch (sw2) {
			case 1:
				if (kg == 1) {
					fout = fopen("成绩分析结果.doc", "a+");
					fprintf(fout, "\n\n");
				}

				fsd = 0;
				system("cls");
				printf("请输入要查看哪个成绩\n\n");
				scanf("%d", &sc2);
				if (sc2 > un) {
					printf("该成绩不存在\n\n");
					break;
				}
				printf("该程序会计算出某个分数段的人数及谁在该分数段，请输入从多少分到多少分\n\n");
				scanf("%d%d", &sc8, &sc9);
				if (sc8 > sc9) {
					sc3 = sc8;
					sc8 = sc9;
					sc9 = sc3;
				}
				sc5 = -1; sc6 = -1;
				for (m1 = 0; m1 < u; m1++) {
					if (cj[m1][sc2 - 1] >= sc8 && cj[m1][sc2 - 1] <= sc9) {
						sc5 = px[m1][sc2 - 1]; sc6 = px[m1][sc2 - 1];
					}
				}


				for (m1 = 0; m1 < u; m1++) {
					if (cj[m1][sc2 - 1] >= sc8 && cj[m1][sc2 - 1] <= sc9) {
						if (px[m1][sc2 - 1] > sc5) {
							sc5 = px[m1][sc2 - 1];
						}
						if (px[m1][sc2 - 1] < sc6) {
							sc6 = px[m1][sc2 - 1];
						}

					}
				}
				for (p1 = sc6; p1 <= sc5; p1++) {
					for (m1 = 0; m1 < u; m1++) {
						if (px[m1][sc2 - 1] == p1) {
							if (kg == 1) {
								fprintf(fout, "学号:%d 姓名:%s %s成绩为:%1.1f\n", xh[m1], st[m1].xm, cjm[sc2 - 1].mz, cj[m1][sc2 - 1]);
							}
							printf("学号:%d 姓名:%s %s成绩为:%1.1f\n", xh[m1], st[m1].xm, cjm[sc2 - 1].mz, cj[m1][sc2 - 1]);
							fsd++;
						}

					}
				}
				printf("总共有%d人\n\n", fsd);




				break;



			case 2:
				if (kg == 1) {
					fout = fopen("成绩分析结果.doc", "a+");
					fprintf(fout, "\n\n");
				}
				system("cls");
				printf("请输入要查看哪个成绩的数据\n\n");
				scanf("%d", &sc2);
				if (sc2 > un) {
					printf("该成绩不存在\n\n");
					break;
				}
				printf("请输入满分是多少分\n\n");
				scanf("%d", &mf);
				system("cls");

				zf = 0;
				w1 = 0;
				x1 = 0;
				ave = 0;
				for (m1 = 0; m1 < u; m1++) {
					if (cj[m1][sc2 - 1] != 404) {
						zf = zf + cj[m1][sc2 - 1];
					}

				}
				ave = zf / u;

				for (m1 = 0; m1 < u; m1++) {
					if (cj[m1][sc2 - 1] != 404) {
						w1 = cj[m1][sc2 - 1];
						x1 = cj[m1][sc2 - 1];
						goto under4;
					}
				}
			under4:
				for (m1 = 0; m1 < u; m1++) {
					if (cj[m1][sc2 - 1] != 404) {
						if (cj[m1][sc2 - 1] > w1) {
							w1 = cj[m1][sc2 - 1];
						}
						if (cj[m1][sc2 - 1] < x1) {
							x1 = cj[m1][sc2 - 1];
						}
					}
				}
				fs1 = 0; fs2 = 0; fs3 = 0;
				for (m1 = 0; m1 < u; m1++) {
					if (cj[m1][sc2 - 1] != 404) {
						if (cj[m1][sc2 - 1] == mf) {
							fs1++;
						}
					}

				}
				for (m1 = 0; m1 < u; m1++) {
					if (cj[m1][sc2 - 1] != 404) {
						if (cj[m1][sc2 - 1] >= mf * 9 / 10) {
							fs2++;
						}
					}

				}
				for (m1 = 0; m1 < u; m1++) {
					if (cj[m1][sc2 - 1] != 404) {
						if (cj[m1][sc2 - 1] >= mf * 6 / 10) {
							fs3++;
						}
					}

				}
				fl1 = 0; fl2 = 0; fl3 = 0;
				fl1 = fs1 * 100 / u;
				fl2 = fs2 * 100 / u;
				fl3 = fs3 * 100 / u;
				printf("成绩总分为:%1.1f\n", zf);
				printf("成绩平均分为:%1.1f\n", ave);
				printf("成绩最高分为:%1.1f\n", w1);
				printf("成绩最低分为:%1.1f\n", x1);
				printf("成绩满分人数为:%d\n", fs1);
				printf("成绩优秀人数为:%d\n", fs2);
				printf("成绩及格人数为:%d\n", fs3);
				printf("成绩满分率为:%1.1f\n", fl1);
				printf("成绩优秀率为:%1.1f\n", fl2);
				printf("成绩及格率为:%1.1f\n", fl3);
				if (kg == 1) {
					fprintf(fout, "成绩总分为:%1.1f\n", zf);
					fprintf(fout, "成绩平均分为:%1.1f\n", ave);
					fprintf(fout, "成绩最高分为:%1.1f\n", w1);
					fprintf(fout, "成绩最低分为:%1.1f\n", x1);
					fprintf(fout, "成绩满分人数为:%d\n", fs1);
					fprintf(fout, "成绩优秀人数为:%d\n", fs2);
					fprintf(fout, "成绩及格人数为:%d\n", fs3);
					fprintf(fout, "成绩满分率为:%1.1f\n", fl1);
					fprintf(fout, "成绩优秀率为:%1.1f\n", fl2);
					fprintf(fout, "成绩及格率为:%1.1f\n", fl3);
				}

				break;



			case 3:
				if (kg == 1) {
					fout = fopen("成绩分析结果.doc", "a+");
					fprintf(fout, "\n\n");
				}
				system("cls");
				printf("请输入要将哪两个成绩进行比较(先输入现在的成绩再输入以前的成绩)\n\n");
				scanf("%d", &sc1);
				scanf("%d", &sc2);
				if (sc2 > un || sc1 > un) {
					printf("某成绩不存在\n\n");
					break;
				}
				for (m1 = 0; m1 < 500; m1++) {
					jt[m1] = cj[m1][sc1 - 1] - cj[m1][sc2 - 1];
				}



				for (pxbl1 = 0; pxbl1 < u; pxbl1++) {
					jtp[pxbl1] = u;
				}
				for (j1 = 1, pxbl1 = 0; j1 <= u; pxbl1++, j1++) {
					for (pxbl2 = 0; pxbl2 < u; pxbl2++) {
						if (jt[pxbl1] >= jt[pxbl2] && pxbl2 != pxbl1) {
							jtp[pxbl1]--;
						}
						else if (jt[pxbl1] < jt[pxbl2]) {
							jtp[pxbl1] = jtp[pxbl1];
						}
					}
				}
				for (pl1 = 1; pl1 <= u; pl1++) {
					for (pl2 = 0; pl2 < u; pl2++) {
						if (jtp[pl2] == pl1) {

							printf("学号为%d 姓名为%s %s成绩为%1.1f %s成绩为%1.1f 进步了%1.1f分 排%d名\n", xh[pl2], st[pl2].xm, cjm[sc1 - 1].mz, cj[pl2][sc1 - 1], cjm[sc2 - 1].mz, cj[pl2][sc2 - 1], jt[pl2], pl1);
							if (kg == 1) {
								fprintf(fout, "姓名为%s 现成绩为%1.1f 原成绩为%1.1f 进步%1.1f分 %d名\n", st[pl2].xm, cj[pl2][sc1 - 1], cj[pl2][sc2 - 1], jt[pl2], pl1);
							}





						}

					}
				}
				break;




			case 4:
				if (kg == 1) {
					fout = fopen("成绩分析结果.doc", "a+");
					fprintf(fout, "\n\n");
				}
				for (m1 = 0; m1 < u; m1++) {
					for (p1 = 0; p1 < un; p1++) {
						mzf[m1] += cj[m1][p1];
					}
				}


				for (pxbl1 = 0; pxbl1 < u; pxbl1++) {
					jtp[pxbl1] = u;
				}
				for (j1 = 1, pxbl1 = 0; j1 <= u; pxbl1++, j1++) {
					for (pxbl2 = 0; pxbl2 < u; pxbl2++) {
						if (mzf[pxbl1] >= mzf[pxbl2] && pxbl2 != pxbl1) {
							jtp[pxbl1]--;
						}
						else if (mzf[pxbl1] < mzf[pxbl2]) {
							jtp[pxbl1] = jtp[pxbl1];
						}
					}
				}
				for (pl1 = 1; pl1 <= u; pl1++) {
					for (pl2 = 0; pl2 < u; pl2++) {
						if (jtp[pl2] == pl1) {
							if (kg == 1) {
								fprintf(fout, "学号为%d 姓名为%s 总分为%1.1f 排%d名\n", xh[pl2], st[pl2].xm, mzf[pl2], pl1);
							}
							printf("学号为%d 姓名为%s 总分为%1.1f 排%d名\n", xh[pl2], st[pl2].xm, mzf[pl2], pl1);
						}

					}
				}



				break;















			case 5:






				system("cls");
				printf("请输入想要排序第几个成绩\n\n");
				scanf("%d", &sc5);




				system("cls");
				printf("请选择排序方式\n");
				printf("1、按照升序显示\n");
				printf("2、按照降序显示\n");
				printf("3、直接显示名次\n");
				printf("4、退出\n");
				scanf("%d", &sw6);
				switch (sw6) {
				case 2:
					for (pl1 = 1; pl1 <= sc3; pl1++) {
						for (pl2 = 0; pl2 < sc3; pl2++) {
							if (px[pl2][sc5 - 1] == pl1) {
								printf("第%d名学号为%d  姓名为%s   %s成绩为%1.1f\n", pl1, xh[pl2], st[pl2].xm, cjm[sc5 - 1].mz, cj[pl2][sc5 - 1]);
							}

						}
					}


					break;




				case 1:


					for (pl3 = sc3; pl3 >= 1; pl3--) {
						for (pl4 = 0; pl4 < sc3; pl4++) {
							if (px[pl4][sc5 - 1] == pl3) {
								printf("第%d名学号为%d  姓名为%s   %s成绩为%1.1f\n", pl3, xh[pl4], st[pl4].xm, cjm[sc5 - 1].mz, cj[pl4][sc5 - 1]);
							}
						}
					}
					break;



				case 4:continue; break;






				case 3:






					for (pxbl1 = 0; pxbl1 < sc3; pxbl1++) {
						printf("学号%d  姓名为%s  %s成绩为%1.1f  名次为%d\n\n", xh[pxbl1], st[pxbl1].xm, cjm[sc5 - 1].mz, cj[pxbl1][sc5 - 1], px[pxbl1][sc5 - 1]);
					}

					break;


				default:printf("输入错误\n"); break;
				}








				break;//case5		



			case 6:



				if (kg == 1) {
					fout = fopen("成绩分析结果.doc", "a+");
					fprintf(fout, "\n\n");
				}
				system("cls");
				printf("请输入要查看哪个成绩\n\n");
				scanf("%d", &sc2);
				if (sc2 > un) {
					printf("该成绩不存在\n\n");
					break;
				}
				printf("请输入查看哪个名次到哪个名次的成绩:\n\n");
				scanf("%d", &sc3);
				scanf("%d", &sc5);
				if (sc3 > sc5) {
					sc9 = sc3;
					sc3 = sc5;
					sc5 = sc9;
				}
				for (; sc3 <= sc5; sc3++) {


					for (m1 = 0; m1 < u; m1++) {
						if (px[m1][sc2 - 1] == sc3) {
							printf("学号:%d 姓名:%s ", xh[m1], st[m1].xm);
							printf("%s成绩:%1.1f  ", cjm[sc2 - 1].mz, cj[m1][sc2 - 1]);
							printf("名次:%d  ", px[m1][sc2 - 1]);
							printf("\n");
							if (kg == 1) {
								fprintf(fout, "学号:%d 姓名:%s ", xh[m1], st[m1].xm);
								fprintf(fout, "%s成绩:%1.1f  ", cjm[sc2 - 1].mz, cj[m1][sc2 - 1]);
								fprintf(fout, "名次:%d  ", px[m1][sc2 - 1]);
								fprintf(fout, "\n");
							}
						}
					}
				}



				break;//case6


			case 7:
				if (kg == 1) {
					fout = fopen("成绩分析结果.doc", "a+");
					fprintf(fout, "\n\n");
				}
				system("cls");
				printf("请输入要查看哪个成绩\n\n");
				scanf("%d", &sc2);
				if (sc2 > un) {
					printf("该成绩不存在\n\n");
					break;
				}
				printf("请输入查看前多少名的学生:\n\n");
				sc3 = 1;
				scanf("%d", &sc5);

				for (; sc3 <= sc5; sc3++) {


					for (m1 = 0; m1 < u; m1++) {
						if (px[m1][sc2 - 1] == sc3) {
							printf("学号:%d 姓名:%s ", xh[m1], st[m1].xm);
							printf("%s成绩:%1.1f  ", cjm[sc2 - 1].mz, cj[m1][sc2 - 1]);
							printf("名次:%d  ", px[m1][sc2 - 1]);
							printf("\n");
							if (kg == 1) {
								fprintf(fout, "学号:%d 姓名:%s ", xh[m1], st[m1].xm);
								fprintf(fout, "%s成绩:%1.1f  ", cjm[sc2 - 1].mz, cj[m1][sc2 - 1]);
								fprintf(fout, "名次:%d  ", px[m1][sc2 - 1]);
								fprintf(fout, "\n");
							}
						}
					}
				}



				break;//case7




			case 8:


				if (kg == 1) {
					fout = fopen("成绩分析结果.doc", "a+");
					fprintf(fout, "\n\n");
				}
				fsd = 0;
				system("cls");
				printf("请输入要查看哪个成绩\n\n");
				scanf("%d", &sc2);
				if (sc2 > un) {
					printf("该成绩不存在\n\n");
					break;
				}
				printf("请输入要查看从多少分到多少分的学生\n\n");
				scanf("%d%d", &sc8, &sc9);
				if (sc8 > sc9) {
					sc3 = sc8;
					sc8 = sc9;
					sc9 = sc3;
				}
				sc5 = -1; sc6 = -1;
				for (m1 = 0; m1 < u; m1++) {
					if (cj[m1][sc2 - 1] >= sc8 && cj[m1][sc2 - 1] <= sc9) {
						sc5 = px[m1][sc2 - 1]; sc6 = px[m1][sc2 - 1];
					}
				}


				for (m1 = 0; m1 < u; m1++) {
					if (cj[m1][sc2 - 1] >= sc8 && cj[m1][sc2 - 1] <= sc9) {
						if (px[m1][sc2 - 1] > sc5) {
							sc5 = px[m1][sc2 - 1];
						}
						if (px[m1][sc2 - 1] < sc6) {
							sc6 = px[m1][sc2 - 1];
						}

					}
				}
				for (p1 = sc6; p1 <= sc5; p1++) {
					for (m1 = 0; m1 < u; m1++) {
						if (px[m1][sc2 - 1] == p1) {
							if (kg == 1) {
								fprintf(fout, "学号:%d 姓名:%s %s成绩为:%1.1f\n", xh[m1], st[m1].xm, cjm[sc2 - 1].mz, cj[m1][sc2 - 1]);
							}
							printf("学号:%d 姓名:%s %s成绩为:%1.1f\n", xh[m1], st[m1].xm, cjm[sc2 - 1].mz, cj[m1][sc2 - 1]);
							fsd++;
						}

					}
				}
				if (fsd == 0) {
					printf("该分数段没有学生\n\n");
				}


				break;







			case 9:



				if (kg == 1) {
					fout = fopen("成绩分析结果.doc", "a+");
					fprintf(fout, "\n\n");
				}
				fsd = 0;
				system("cls");
				printf("请输入要查看哪个成绩\n\n");
				scanf("%d", &sc2);
				if (sc2 > un) {
					printf("该成绩不存在\n\n");
					break;
				}
				printf("请输入满分是多少分\n\n");
				scanf("%d", &sc9);
				printf("请输入要查看多少分以上的学生\n\n");
				scanf("%d", &sc8);



				sc5 = -1; sc6 = -1;
				for (m1 = 0; m1 < u; m1++) {
					if (cj[m1][sc2 - 1] >= sc8 && cj[m1][sc2 - 1] <= sc9) {
						sc5 = px[m1][sc2 - 1]; sc6 = px[m1][sc2 - 1];
					}
				}


				for (m1 = 0; m1 < u; m1++) {
					if (cj[m1][sc2 - 1] >= sc8 && cj[m1][sc2 - 1] <= sc9) {
						if (px[m1][sc2 - 1] > sc5) {
							sc5 = px[m1][sc2 - 1];
						}
						if (px[m1][sc2 - 1] < sc6) {
							sc6 = px[m1][sc2 - 1];
						}

					}
				}
				for (p1 = sc6; p1 <= sc5; p1++) {
					for (m1 = 0; m1 < u; m1++) {
						if (px[m1][sc2 - 1] == p1) {
							if (kg == 1) {
								fprintf(fout, "学号:%d 姓名:%s %s成绩为:%1.1f\n", xh[m1], st[m1].xm, cjm[sc2 - 1].mz, cj[m1][sc2 - 1]);
							}
							printf("学号:%d 姓名:%s %s成绩为:%1.1f\n", xh[m1], st[m1].xm, cjm[sc2 - 1].mz, cj[m1][sc2 - 1]);
							fsd++;
						}

					}
				}



				if (fsd == 0) {
					printf("该分数段没有学生\n\n");
				}


				break;


			case 10:
				printf("输入1打开导出分析结果，每次分析时会将本次分析结果导出\n\n");
				printf("输入0关闭导出分析结果，默认为关闭状态\n\n");
				scanf("%d", &kg);
				if (kg == 0) {
					printf("已关闭\n\n");
				}
				if (kg == 1) {
					printf("已打开\n\n");
				}
				if (kg != 1 && kg != 0) {
					printf("输入无效\n\n");
					kg = 0;
				}
				break;
			case 11:break;
			default:printf("输入错误\n");
				break;



			}





			printf("输入任意数按下Enter键继续......\n\n");
			scanf("%d", &sc99);
			break;







		case 6:system("cls");
			printf("欢迎使用本程序\n\n");
			printf("请选择想要进入的程序,输入相应数字并按下Enter键即可\n\n");
			printf("本程序总共可以记录500个学生，每个学生50个成绩\n\n");
			printf("本程序主要是用于成绩的分析，而不是成绩的记录与保存\n\n");
			printf("第一次导入成绩时请先生成导入文件，然后将成绩复制粘贴到成绩导入文件.txt里\n\n");
			printf("成绩的格式为一个成绩换一行再到下一个（即一列下来），一列为一个班的某一次成绩\n\n");
			printf("若有多次成绩可以接在上一次成绩的末尾，注意换行，每次成绩的个数需一致，若有空位用404补齐\n\n");
			printf("在姓名导入文件.txt中复制粘贴姓名，也是一列下来，一个名字换一行再到下一个\n\n");
			printf("姓名的个数要和每次成绩的个数相同，若有空位用x补齐，姓名的顺序要和成绩的顺序一一对应\n\n");
			printf("在学号导入文件.txt中复制粘贴学号，格式同成绩和姓名，要和姓名一一对应，若有空位用0补齐\n\n");
			printf("然后在系统导入文件.txt中输入姓名个数，换行，再输入成绩个数，即有多少次成绩\n\n");
			printf("名次导入文件.txt不用管，不要输入任何东西\n");
			printf("若成绩在Excel里从Excel里一列一列地复制粘贴过来即可，这就是格式，姓名、学号、成绩要一一对应\n\n");
			printf("在没有输入任何信息时，学号默认为505，姓名默认为x，成绩默认为404\n\n");
			printf("如果已经导出成绩，下一次直接选择成绩导入即可，无需自己再进行复制粘贴操作\n\n");
			printf("若已经设置自动导入，下一次直接打开程序就已经有成绩在里面了\n\n");
			printf("不要随意更改导出的文件，不然下一次导入会出现错误\n\n");
			printf("每一次默认导出所有的信息，如果有哪个信息不要，请删除\n\n");
			printf("只要不导出保存成绩，所有的更改在下一次打开时无效\n\n");
			printf("请不要在选择功能输入时输入字母，不然会出现问题，请根据程序里的提示操作\n\n");
			printf("输入任意数按下Enter键继续......\n\n");
			scanf("%d", &sc99);
			break;

		case 7:printf("欢迎再次使用\n\n");
			printf("感谢使用本程序\n\n");
			Sleep(500);
			return 0;
			break;
		case 8:fout = fopen("学号导入文件.txt", "wb");
			fout = fopen("姓名导入文件.txt", "wb");
			fout = fopen("成绩导入文件.txt", "wb");
			fout = fopen("名次导入文件.txt", "wb");
			fout = fopen("系统导入文件.txt", "wb");
			fout = fopen("成绩名称导入文件.txt", "wb");
			printf("已生成\n\n");
			printf("输入任意数按下Enter键继续......\n\n");
			scanf("%d", &sc99);
			break;
		case 9:system("cls");
			printf("请选择设置\n\n");
			printf("1、开启或关闭自动导入成绩（默认关闭）\n");
			printf("2、系统初始化，清零所有信息\n");
			printf("3、退出\n\n");
			scanf("%d", &sw2);
			switch (sw2) {
			case 1:system("cls");
				printf("请输入0或1（0关闭，1开启）\n\n");
				scanf("%d", &au);
				if (au == 1) {
					printf("已开启\n\n");
					fout = fopen("自动导入文件.txt", "wb");
					fprintf(fout, "%d\n", au);
				}
				if (au != 1 && au != 0) {
					printf("输入无效\n\n");
					au = 0;
				}
				if (au == 0) {
					printf("已关闭\n\n");
				}

				break;
			case 2:system("cls");
				printf("已清零\n\n");
				for (m1 = 0; m1 < 500; m1++) {
					for (p1 = 0; p1 < 50; p1++) {
						cj[m1][p1] = 404;
					}

				}

				for (m1 = 0; m1 < 500; m1++) {
					xh[m1] = 505;
				}


				for (m1 = 0; m1 < 500; m1++) {
					st[m1].xm[0] = 'x';
				}


				for (m1 = 0; m1 < 500; m1++) {
					for (p1 = 0; p1 < 50; p1++) {
						px[m1][p1] = 0;
					}

				}
				break;
			case 3:break;
			default:printf("输入错误\n");

				break;
			}
			printf("输入任意数按下Enter键继续......\n\n");
			scanf("%d", &sc99);
			break;
		default:printf("输入错误\n"); break;
		}//switch
	}//for
	return 0;
}
