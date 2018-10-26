#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h>

/*将随机数宏定义*/ 
//ps：rand和srand函数《带你学C带你飞》教程里有教，在函数快查里面 
#define randint ((rand() % 100)+1) 
#define randop (rand() % 4)

/*将操作符号定义为全局变量*/ 
char op[] = { '+', '-', '*', '/' };

/*函数声明*/ 
void Gui(void);
int Gui_Input(void);
int Anwser_Input(void);
int Continue_Input(void);

void EasyMode(void);
void CrazyMode(void);
void HardMode(void);


int main(void)
{
	time_t t;
	
	srand((unsigned)time(&t));//使用当前时间值初始化伪随机数种子序列
	
	while(1)
	{
		Gui();
	 	switch(Gui_Input()) 
		{
			case 1: EasyMode();    break;
			case 2: CrazyMode();   break;
        	case 3: HardMode();    break;
        	case 4: exit(0);       break;
		}
	}
	system("pause");	
	return 0;
}



/*简单模式*/ 
void EasyMode(void)
{
	int num1,num2,tmpnum,result,time=1;
	char symbol;
	
	system("cls");
	while(1)
	{
		num1 = randint;
		num2 = randint;
		symbol = op[randop];
		
		/*生成随机四则运算式*/ 
		switch(symbol)
		{
			case '+': result = num1 + num2; printf("%d + %d = ？\n",num1,num2); break;
			case '*': result = num1 * num2; printf("%d * %d = ？\n",num1,num2); break;
			case '-':
				if(num2>num1)
				{
					tmpnum=num2;
					num2=num1;
					num1=tmpnum;
				}
				result = num1 - num2;
				printf("%d - %d = ？\n",num1,num2);
				break;
		 	case '/':
		 		if(num1%num2==0)
				{
					result = num1/num2;
					printf("%d ÷%d = ？\n",num1,num2);
				}
				else
				{
					continue;
				} 
				break;
		}
	
		/*等待输入，与正确结果result进行比较*/ 
		printf("请输入你的答案：");
		if(Anwser_Input() == result)
		{
			printf("Right！\n");
			printf("Continue?y/n");
			if(Continue_Input() == 'y') 
			{
				time=0;
				continue;
			}  
			else  break;
		}
		else
		{
			/*三次机会检查*/ 
			if(time>=3)
			{
					printf("Wrong！ You have tried 3times！ Test over！ \n");
					break;
			}
			printf("Wrong！ Please try again.\n");
			time++;
		}
	 }
}

/*疯狂模式*/ 
//因为每次要生成十个算式，用一个长度是10的数组存储生成的一组随机数 
void CrazyMode(void)
{
	
	int num1[10],num2[10],tmpnum,i,result[10],input_result[10],time=1,score=0;
	char symbol;
	
	while(1)
	{
		
		for(i=0;i<10;i++)
		{
			num1[i]  = randint;
			num2[i] = randint;
			symbol = op[randop];
			
			/*生成随机四则运算式*/ 
			switch(symbol)
			{
				case '+': result[i] = num1[i] + num2[i]; printf("(%d). %d + %d = ？\n",(i+1),num1[i],num2[i]);  break;
				case '*': result[i] = num1[i] * num2[i]; printf("(%d). %d * %d = ？\n",(i+1),num1[i],num2[i]);  break;
				case '-':
					if(num2[i]>num1[i])
					{
						tmpnum=num2[i];
						num2[i]=num1[i];
						num1[i]=tmpnum;
					}
					result[i] = num1[i] - num2[i];
					printf("(%d). %d - %d = ？\n",(i+1),num1[i],num2[i]);
					break;
			 	case '/':
			 		if(num1[i]%num2[i]==0)
					{
						result[i] = num1[i]/num2[i];
						printf("(%d). %d ÷%d = ？\n",(i+1),num1[i],num2[i]);
					}
					else
					{
						i--;
						continue;
					}
					
					break;
			}
		}
			/*等待输入，与正确结果result进行比较*/ 
			printf("请依次输入你的答案：\n");
			printf("输入第一题答案：");
			for(i=0;i<10;i++) 
			{
				input_result[i] = Anwser_Input();
	       		if( input_result[i] == result[i])
				{
					printf("Right！\n");
					printf("请输入下一题答案：");
					score++;
				}
				else
				{
					printf("Wrong！\n");
					printf("请输入下一题答案：");
				}
			}
			printf("总分：%d 正确率：%f\n",score*10,score/10);
			if(score>=8) break;
        }
}

/*困难模式*/
//判断运算优先级使用嵌套的if，判断运算优先级还有很多其他方法 
void HardMode(void)
{
	int num1,num2,num3,tmpnum,result,time=1;
	char symbol[2];
	
	while(1)
	{
		
		num1 = randint;
		num2 = randint;
		num3 = randint;
		symbol[0] = op[randop];
		symbol[1] = op[randop];
	 	
		 if(symbol[0] == '+')
		{
			if(symbol[1] == '+')
			{
				result = num1 + num2 + num3;
				printf("%d %c %d %c %d = ？\n",num1,symbol[0],num2,symbol[1],num3);
			}
			else if(symbol[1] == '-')
			{
				result = num1 + num2 - num3;
				if(result>0) printf("%d %c %d %c %d = ？\n",num1,symbol[0],num2,symbol[1],num3);
				else continue;
			}
			else if(symbol[1] == '*')
			{
				result = num1 + num2 * num3;
				printf("%d %c %d %c %d = ？\n",num1,symbol[0],num2,symbol[1],num3);
			}
			else if(symbol[1] == '/')
			{
				result = num1 + num2 / num3;
				if(num2%num3==0)  printf("%d %c %d %c %d = ？\n",num1,symbol[0],num2,symbol[1],num3);
				else continue;
			}
		}
		
		else if(symbol[0] == '-')
		{
			if(symbol[1] == '+')
			{
				result = num1 - num2 + num3;
				if(result>0)  printf("%d %c %d %c %d = ？\n",num1,symbol[0],num2,symbol[1],num3);
				else continue;
			}
			else if(symbol[1] == '-')
			{
				result = num1 - num2 - num3;
				if(result>0)  printf("%d %c %d %c %d = ？\n",num1,symbol[0],num2,symbol[1],num3);
				else continue;
			}
			else if(symbol[1] == '*')
			{
				result = num1 - num2 * num3;
				if(result>0)  printf("%d %c %d %c %d = ？\n",num1,symbol[0],num2,symbol[1],num3);
				else continue;
			}
			else if(symbol[1] == '/')
			{
				result = num1 - num2 / num3;
				if(result>0 && num2%num3==0)  printf("%d %c %d %c %d = ？\n",num1,symbol[0],num2,symbol[1],num3);
				else continue;
			}
		}
		
		else if(symbol[0] == '*')
		{
			if(symbol[1] == '+')
			{
				result = num1 * num2 + num3;
				printf("%d %c %d %c %d = ？\n",num1,symbol[0],num2,symbol[1],num3);
				
			}
			else if(symbol[1] == '-') 
			{
				result = num1 * num2 - num3;
				if(result>0)  printf("%d %c %d %c %d = ？\n",num1,symbol[0],num2,symbol[1],num3);
				else continue;
			}
			else if(symbol[1] == '*')
			{
				result = num1 * num2 * num3;
				printf("%d %c %d %c %d = ？\n",num1,symbol[0],num2,symbol[1],num3);
			}
			else if(symbol[1] == '/')
			{
				result = num1 * num2 / num3;
				if(num2%num3==0)  printf("%d %c %d %c %d = ？\n",num1,symbol[0],num2,symbol[1],num3);
				else continue;
			}
		}
		
		else if(symbol[0] == '/')
		{
			if(symbol[1] == '+')
			{
				result = num1 / num2 + num3;
				if(num1%num2==0)  printf("%d %c %d %c %d = ？\n",num1,symbol[0],num2,symbol[1],num3);
				else continue;
			}
			else if(symbol[1] == '-')
			{
				result = num1 / num2 - num3;
				if(num1%num2==0 && result ==0)  printf("%d %c %d %c %d = ？\n",num1,symbol[0],num2,symbol[1],num3);
				else continue;
			}
			else if(symbol[1] == '*')
			{
				result = num1 / num2 * num3;
				if(num1%num2==0)  printf("%d %c %d %c %d = ？\n",num1,symbol[0],num2,symbol[1],num3);
				else continue;
			}
			else if(symbol[1] == '/')
			{
				result = num1 / num2 / num3;
				if(num1%num2==0 && (num1/num2)%num3==0)  printf("%d %c %d %c %d = ？\n",num1,symbol[0],num2,symbol[1],num3);
				else continue;
			}
		}
		printf("请输入你的答案：");
		if(Anwser_Input() == result)
		{
			printf("Right！\n");
			printf("Continue?y/n");
			if(Continue_Input() == 'y')  
			{
				time=0;
				continue;
			} 
			else  break;
		}
		else
		{
			if(time>=3)
			{
					printf("Wrong！ You have tried 3times！ Test over！ \n");
					break;
			}
			printf("Wrong！ Please try again.\n");
			time++;
		}
	}	
}

void Gui(void)
{
	printf("====四则运算CAI系统====\n");
	printf("1.简单模式\n"); 
	printf("2.疯狂模式\n");
	printf("3.困难模式\n");
	printf("4.退出程序\n"); 
	printf("请选择："); 
}



/*带有容错检查的输入函数*/ 
int Gui_Input(void)
{
	int num,flag;
	char ch;
	
	flag = scanf("%d",&num);
	system("cls");
	while ((ch = getchar()) != EOF && ch != '\n')//不停地使用getchar()获取缓冲中字符，直到获取的c是“\n”或文件结尾符EOF为止
	{
		flag = 0;
	}
	
	//fflush(stdin);
	
	if((flag!=0 && num==1) || (flag!=0 && num==2) || (flag!=0 && num==3) || (flag!=0 && num==4))
	{	
		return num;
	}
	else 
	{
		printf("输入错误，请重新输入！\n");
		return 0;
	}
 
}

/*带有容错检查的输入函数*/ 
int Anwser_Input(void)
{
	int num,flag;
	char ch;
	
	flag = scanf("%d",&num);
	system("cls");
	while ((ch = getchar()) != EOF && ch != '\n')//不停地使用getchar()获取缓冲中字符，直到获取的c是“\n”或文件结尾符EOF为止
	{
		flag = 0;
	}
	
	if(flag!=0)
	{
 		return num;
	} 
	else 
	{
		return 0;
	}
}

/*带有容错检查的输入函数*/ 
int Continue_Input(void)
{
	char num,flag,ch;

	
	flag = scanf("%c",&num);
	system("cls");
	while ((ch = getchar()) != EOF && ch != '\n')//不停地使用getchar()获取缓冲中字符，直到获取的c是“\n”或文件结尾符EOF为止
	{
		flag = 0;
	}
	
	if((flag!=0 && num == 'y') || (flag!=0 && num == 'n'))
	{
		return num;
	} 
	else 
	{
		printf("输入错误，请重新输入！\n");
		return 0;
	}
}

