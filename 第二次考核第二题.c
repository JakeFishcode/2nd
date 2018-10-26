#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h>

/*��������궨��*/ 
//ps��rand��srand����������ѧC����ɡ��̳����н̣��ں���������� 
#define randint ((rand() % 100)+1) 
#define randop (rand() % 4)

/*���������Ŷ���Ϊȫ�ֱ���*/ 
char op[] = { '+', '-', '*', '/' };

/*��������*/ 
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
	
	srand((unsigned)time(&t));//ʹ�õ�ǰʱ��ֵ��ʼ��α�������������
	
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



/*��ģʽ*/ 
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
		
		/*���������������ʽ*/ 
		switch(symbol)
		{
			case '+': result = num1 + num2; printf("%d + %d = ��\n",num1,num2); break;
			case '*': result = num1 * num2; printf("%d * %d = ��\n",num1,num2); break;
			case '-':
				if(num2>num1)
				{
					tmpnum=num2;
					num2=num1;
					num1=tmpnum;
				}
				result = num1 - num2;
				printf("%d - %d = ��\n",num1,num2);
				break;
		 	case '/':
		 		if(num1%num2==0)
				{
					result = num1/num2;
					printf("%d ��%d = ��\n",num1,num2);
				}
				else
				{
					continue;
				} 
				break;
		}
	
		/*�ȴ����룬����ȷ���result���бȽ�*/ 
		printf("��������Ĵ𰸣�");
		if(Anwser_Input() == result)
		{
			printf("Right��\n");
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
			/*���λ�����*/ 
			if(time>=3)
			{
					printf("Wrong�� You have tried 3times�� Test over�� \n");
					break;
			}
			printf("Wrong�� Please try again.\n");
			time++;
		}
	 }
}

/*���ģʽ*/ 
//��Ϊÿ��Ҫ����ʮ����ʽ����һ��������10������洢���ɵ�һ������� 
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
			
			/*���������������ʽ*/ 
			switch(symbol)
			{
				case '+': result[i] = num1[i] + num2[i]; printf("(%d). %d + %d = ��\n",(i+1),num1[i],num2[i]);  break;
				case '*': result[i] = num1[i] * num2[i]; printf("(%d). %d * %d = ��\n",(i+1),num1[i],num2[i]);  break;
				case '-':
					if(num2[i]>num1[i])
					{
						tmpnum=num2[i];
						num2[i]=num1[i];
						num1[i]=tmpnum;
					}
					result[i] = num1[i] - num2[i];
					printf("(%d). %d - %d = ��\n",(i+1),num1[i],num2[i]);
					break;
			 	case '/':
			 		if(num1[i]%num2[i]==0)
					{
						result[i] = num1[i]/num2[i];
						printf("(%d). %d ��%d = ��\n",(i+1),num1[i],num2[i]);
					}
					else
					{
						i--;
						continue;
					}
					
					break;
			}
		}
			/*�ȴ����룬����ȷ���result���бȽ�*/ 
			printf("������������Ĵ𰸣�\n");
			printf("�����һ��𰸣�");
			for(i=0;i<10;i++) 
			{
				input_result[i] = Anwser_Input();
	       		if( input_result[i] == result[i])
				{
					printf("Right��\n");
					printf("��������һ��𰸣�");
					score++;
				}
				else
				{
					printf("Wrong��\n");
					printf("��������һ��𰸣�");
				}
			}
			printf("�ܷ֣�%d ��ȷ�ʣ�%f\n",score*10,score/10);
			if(score>=8) break;
        }
}

/*����ģʽ*/
//�ж��������ȼ�ʹ��Ƕ�׵�if���ж��������ȼ����кܶ��������� 
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
				printf("%d %c %d %c %d = ��\n",num1,symbol[0],num2,symbol[1],num3);
			}
			else if(symbol[1] == '-')
			{
				result = num1 + num2 - num3;
				if(result>0) printf("%d %c %d %c %d = ��\n",num1,symbol[0],num2,symbol[1],num3);
				else continue;
			}
			else if(symbol[1] == '*')
			{
				result = num1 + num2 * num3;
				printf("%d %c %d %c %d = ��\n",num1,symbol[0],num2,symbol[1],num3);
			}
			else if(symbol[1] == '/')
			{
				result = num1 + num2 / num3;
				if(num2%num3==0)  printf("%d %c %d %c %d = ��\n",num1,symbol[0],num2,symbol[1],num3);
				else continue;
			}
		}
		
		else if(symbol[0] == '-')
		{
			if(symbol[1] == '+')
			{
				result = num1 - num2 + num3;
				if(result>0)  printf("%d %c %d %c %d = ��\n",num1,symbol[0],num2,symbol[1],num3);
				else continue;
			}
			else if(symbol[1] == '-')
			{
				result = num1 - num2 - num3;
				if(result>0)  printf("%d %c %d %c %d = ��\n",num1,symbol[0],num2,symbol[1],num3);
				else continue;
			}
			else if(symbol[1] == '*')
			{
				result = num1 - num2 * num3;
				if(result>0)  printf("%d %c %d %c %d = ��\n",num1,symbol[0],num2,symbol[1],num3);
				else continue;
			}
			else if(symbol[1] == '/')
			{
				result = num1 - num2 / num3;
				if(result>0 && num2%num3==0)  printf("%d %c %d %c %d = ��\n",num1,symbol[0],num2,symbol[1],num3);
				else continue;
			}
		}
		
		else if(symbol[0] == '*')
		{
			if(symbol[1] == '+')
			{
				result = num1 * num2 + num3;
				printf("%d %c %d %c %d = ��\n",num1,symbol[0],num2,symbol[1],num3);
				
			}
			else if(symbol[1] == '-') 
			{
				result = num1 * num2 - num3;
				if(result>0)  printf("%d %c %d %c %d = ��\n",num1,symbol[0],num2,symbol[1],num3);
				else continue;
			}
			else if(symbol[1] == '*')
			{
				result = num1 * num2 * num3;
				printf("%d %c %d %c %d = ��\n",num1,symbol[0],num2,symbol[1],num3);
			}
			else if(symbol[1] == '/')
			{
				result = num1 * num2 / num3;
				if(num2%num3==0)  printf("%d %c %d %c %d = ��\n",num1,symbol[0],num2,symbol[1],num3);
				else continue;
			}
		}
		
		else if(symbol[0] == '/')
		{
			if(symbol[1] == '+')
			{
				result = num1 / num2 + num3;
				if(num1%num2==0)  printf("%d %c %d %c %d = ��\n",num1,symbol[0],num2,symbol[1],num3);
				else continue;
			}
			else if(symbol[1] == '-')
			{
				result = num1 / num2 - num3;
				if(num1%num2==0 && result ==0)  printf("%d %c %d %c %d = ��\n",num1,symbol[0],num2,symbol[1],num3);
				else continue;
			}
			else if(symbol[1] == '*')
			{
				result = num1 / num2 * num3;
				if(num1%num2==0)  printf("%d %c %d %c %d = ��\n",num1,symbol[0],num2,symbol[1],num3);
				else continue;
			}
			else if(symbol[1] == '/')
			{
				result = num1 / num2 / num3;
				if(num1%num2==0 && (num1/num2)%num3==0)  printf("%d %c %d %c %d = ��\n",num1,symbol[0],num2,symbol[1],num3);
				else continue;
			}
		}
		printf("��������Ĵ𰸣�");
		if(Anwser_Input() == result)
		{
			printf("Right��\n");
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
					printf("Wrong�� You have tried 3times�� Test over�� \n");
					break;
			}
			printf("Wrong�� Please try again.\n");
			time++;
		}
	}	
}

void Gui(void)
{
	printf("====��������CAIϵͳ====\n");
	printf("1.��ģʽ\n"); 
	printf("2.���ģʽ\n");
	printf("3.����ģʽ\n");
	printf("4.�˳�����\n"); 
	printf("��ѡ��"); 
}



/*�����ݴ�������뺯��*/ 
int Gui_Input(void)
{
	int num,flag;
	char ch;
	
	flag = scanf("%d",&num);
	system("cls");
	while ((ch = getchar()) != EOF && ch != '\n')//��ͣ��ʹ��getchar()��ȡ�������ַ���ֱ����ȡ��c�ǡ�\n�����ļ���β��EOFΪֹ
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
		printf("����������������룡\n");
		return 0;
	}
 
}

/*�����ݴ�������뺯��*/ 
int Anwser_Input(void)
{
	int num,flag;
	char ch;
	
	flag = scanf("%d",&num);
	system("cls");
	while ((ch = getchar()) != EOF && ch != '\n')//��ͣ��ʹ��getchar()��ȡ�������ַ���ֱ����ȡ��c�ǡ�\n�����ļ���β��EOFΪֹ
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

/*�����ݴ�������뺯��*/ 
int Continue_Input(void)
{
	char num,flag,ch;

	
	flag = scanf("%c",&num);
	system("cls");
	while ((ch = getchar()) != EOF && ch != '\n')//��ͣ��ʹ��getchar()��ȡ�������ַ���ֱ����ȡ��c�ǡ�\n�����ļ���β��EOFΪֹ
	{
		flag = 0;
	}
	
	if((flag!=0 && num == 'y') || (flag!=0 && num == 'n'))
	{
		return num;
	} 
	else 
	{
		printf("����������������룡\n");
		return 0;
	}
}

