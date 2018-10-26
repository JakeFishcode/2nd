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
	self_ROOF()**输出目录 
	Getnumber(int num)**获得输入数字 
	JPN(int num)**判定素数 
	PPN(a)**打印判定结果 
	SUM_PN(int n)**素数之和 
	PutFactor(int num)**输出因子 
	Jperfetnum(int num)**判断完全数
	ResolvePN(int num)**分解质因数 
	Outworing(int F)**越界警告 
	six()**退出程序 
	*/
}

int main()
{
	int F=0,num;
	self_ROOF();

	while(1)
	{
		printf("\n请选择："); 
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
***素数判定***\n\
1.素数判定\n\
2.素数之和\n\
3.计算因子\n\
4.完全数判定\n\
5.质因数分解\n\
6.退出程序\n\
#电协人-Jame出品\n\
") ;
}

int Getnumber(int num)// get a input number *************for all
{
	printf("请输入数字：");
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
		printf("你输入的不是素数.\n");
	}
	else
	{
		printf("你输入的是素数.\n");
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
	printf("素数之和为：%d\n",sum);

}

int PutFactor(int num)//putout factor ***********do 3
{
	int i;
	if(JPN(num)==1)
	{
		printf("因子为：");
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
		printf("没有除数字！它是一个素数.\
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
			printf("它是一个完全数.\n");
		}
		else
		{
			printf("它不是一个完全数.\n");
		}
	}
	else
	{
		printf("它是一个素数.\n");
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
			//	printf("for之后 num %% i = %d\n",num%i);
			if((num%i)==0)
			{
			//	printf("if判断正确此时i = %d num=%d\n",i,num);
				printf("%d*",i);
				num/=i;
			//	printf("if判断正确时，此时的num = %d\n",num);
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
		printf("它是一个素数.\n");
	}
}

void six()// just for fun ***************do 6
{
	unsigned V;
	printf("必须经过李银库、钟杰州和刘奕娜同意才能退出.\n\
所以目前你不能退出.\n");
	printf("如果他们没有同意，你还可以选择现在输入密码\n输入正确才能退出.\n\
现在请输入密码(数字)：");
	scanf("%d",&V);

	printf("您的输入有误.只能继续程序.\n");
}

void Outworing(int F)//woring OUT F
{
	if(F>6)
	{
		printf("您的输入有误.\n");
	}
} 










