#include<stdio.h>
#define MAX 1024
int self_ROOF(); 
int Getnumber();
int JPN();
int PPN();
int SUM_PN();
int PutFactor();
int SUMFactor();
int JPerfetnum();
int ResolvePN();
void six();
void Outworing(int F);
void test1()
{/*
	self_ROOF()**���Ŀ¼ 
	Getnumber(int num)**����������� 
	JPN(int num)**�ж����� 
	PPN(a)**��ӡ�ж���� 
	SUM_PN(int n)**����֮�� 
	PutFactor(int num)**������� 
	Jperfetnum(int num)**�ж���ȫ��
	ResolvePN(int num)**�ֽ������� 
	Outworing(int F)**Խ�羯�� 
	six()**�˳����� 
	*/
}

int main()
{
	int F=0,num;
	self_ROOF();

	while(1)
	{
		printf("\n��ѡ��"); 
		scanf("%d",&F);
		switch(F)
		{
			case 1:num=Getnumber();JPN(num);PPN(JPN(num));break;
			case 2:num=Getnumber();SUM_PN(num);break;
			case 3:num=Getnumber();PutFactor(num);break;
			case 4:num=Getnumber();JPerfetnum(num);break;
			case 5:num=Getnumber();ResolvePN(num);break;
			case 6:six();break;
		}
		Outworing(F);

	}
	return 0;

}

int self_ROOF() //roof   ******************do first
{
	printf("\
***�����ж�***\n\
1.�����ж�\n\
2.����֮��\n\
3.��������\n\
4.��ȫ���ж�\n\
5.�������ֽ�\n\
6.�˳�����\n\
#��Э��-Jame��Ʒ\n\
") ;
}

int Getnumber(int num)// get a input number *************for all
{
	printf("���������֣�");
	scanf("%d",&num);
	return num;
}

int JPN(int num) //judge prime number ****************** do 1
{
	int i,a=0;
	for(i=2;i<num-1;i++)
	{
		if((num%i)==0)
		{
			a=1;
		}
	}

	return a;//if is PN a=0//not PN a=1;
}

int PPN(int a)//print judgement *********************do 1
{
	if(a==1)
	{
		printf("������Ĳ�������.\n");
	}
	else
	{
		printf("�������������.\n");
	}
}

int SUM_PN(int num)//sum the pn****************do 2
{
	int i,sum=0;
	for(i=2;i<num+1;i++)
	{
		if(JPN(i)==0)
		{
			sum +=i;
		}
	}
	printf("����֮��Ϊ��%d\n",sum);

}

int PutFactor(int num)//putout factor ***********do 3
{
	int i;
	if(JPN(num)==1)
	{
		printf("����Ϊ��");
		for(i=2;i<num;i++)
		{	
			if(num%i==0)
			{
				printf("%d ",i);
			}
		}
		printf("\n");
	}
	else
	{
		printf("û�г����֣�����һ������.\
(NO divisor! It is a prime number)\n");
	}
	return 0;
}

int SUMFactor(int num)//SUM factor ***************do 3
{
	int i,sum=0;
	if(JPN(num)==1)
	{
		
		for(i=2;i<num;i++)
		{	
			if(num%i==0)
			{
				sum+=i;
			}
		}
		sum+=1;
	}
	return sum;
}

int JPerfetnum(int num)//judge perfet number **********do4
{
	if(JPN(num)==1)
	{
		if(num==SUMFactor(num))
		{
			printf("����һ����ȫ��.\n");
		}
		else
		{
			printf("������һ����ȫ��.\n");
		}
	}
	else
	{
		printf("����һ������.\n");
	}
}

int ResolvePN(int num)//resolve the  no-prime number********do 5
{
	int i;
	if(JPN(num)==1)
	{
		printf("%d=",num);
		for(i=2;i<num;i++)
		{	
			//	printf("for֮�� num %% i = %d\n",num%i);
			if((num%i)==0)
			{
			//	printf("if�ж���ȷ��ʱi = %d num=%d\n",i,num);
				printf("%d*",i);
				num/=i;
			//	printf("if�ж���ȷʱ����ʱ��num = %d\n",num);
				i=2;
			}
			if(JPN(num)==0)
			{
				printf("%d",num);
				break;
			}
			
		}
		printf("\n");
	}
	else 
	{
		printf("����һ������.\n");
	}
}

void six()// just for fun ***************do 6
{
	unsigned V;
	printf("���뾭�������⡢�ӽ��ݺ�������ͬ������˳�.\n\
����Ŀǰ�㲻���˳�.\n");
	printf("�������û��ͬ�⣬�㻹����ѡ��������������\n������ȷ�����˳�.\n\
��������������(����)��");
	scanf("%d",&V);

	printf("������������.ֻ�ܼ�������.\n");
}

void Outworing(int F)//woring OUT F
{
	if(F>6)
	{
		printf("������������.\n");
	}
} 










