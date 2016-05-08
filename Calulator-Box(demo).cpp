#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define Pi 3.1415926
using namespace std;
ofstream fout;
int tcin(int x)
{
	if(cin.fail()&&!cin.eof())
	{
		cin.clear();
		while(!isspace(cin.get()))
			continue;
	}
	else
	{
		cout<<"I cannot go on!\n";
		exit(1);
	}
	cout<<"Now enter a new number: ";
	cin>>x;
}
int gcd(int a,int b)
{
	if(a%b==0)
		return b;
	return gcd(b,a%b);
}
void Normal()
{
	int a=0,b=0;
	int ans=0;
	char mark;
	scanf("%d%c%d",&a,&mark,&b);
	switch(mark)
	{
		case 43:
			ans=a+b;
			printf("%d%c%d=%d\n",a,mark,b,ans);
			break;
		case 45:
			ans=a-b;
			printf("%d%c%d=%d\n",a,mark,b,ans);
			break;
		case 42:
			ans=a*b;
			printf("%d%c%d=%d\n",a,mark,b,ans);
			break;
		case 47:
			if(b!=0)
			{
				int a1,b1;
				a1=a/gcd(a,b);
				b1=b/gcd(a,b);
				printf("%d/%d(Redution)\n",a1,b1);
			}
			else
				printf("No meaning.\n");
			break;
		default:
			printf("Unable to do that.\n");
	}
}
void Triangle()
{
	int a=0,b=0,c=0,ans=0,p=0;
	scanf("%d%d%d",&a,&b,&c);
	p=(a+b+c)/2;
	ans=sqrt(p*(p-a)*(p-b)*(p-c));
	if(ans<=0)
		printf("Impossible.\n");
	else
		printf("The area of it is %5.f(5 significant digits)\n.",ans);
	printf("again?(y/n)");
}
void Function()
{
	int x1,y1,x2,y2;
	int k=0,b=0;
	printf("Input the first coord.(x,y)\n");
	scanf("%d%d",&x1,&y1);
	printf("Then next.\n");
	scanf("%d%d",&x2,&y2);
	k=(y1-y2)/(x1-x2);
	b=y1-(k*x1);
	if(y1-y2!=0)
	{
		if(k==1)
		{
			if(b>0)
				printf("y=x+%d\n",b);
			if(b<0)
				printf("y=x%d\n",b);
			if(b==0)
				printf("y=x\n");
		}
		else
		{
			if(b>0)
				printf("y=%dx+%d\n",k,b);
			if(b<0)
				printf("y=%dx%d\n",k,b);
			if(b==0)
				printf("y=%dx\n",k);
		}
	}
}
int main()
{
	fout.open("out.txt");
	fout<<"Weclome to use Calculator Box 1.00 demo!"<<endl
		<<"We are trying to make things better"<<endl
		<<"What's new?"<<endl
		<<"*Simple File I/O"<<endl
		<<"*add the power of fraction reduction in normal part"<<endl
		<<"Hope you enjoy it!"<<endl
		<<endl
		<<"Your using record(last one):";
	int c=0;
	while(1)
	{
		printf("                             Calculator Box 1.00  demo                      \n");
		printf("Can I help you?\nList:\n1.Normal\n2.Triangle\n3.function\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				Normal();
				break;
			case 2:
				Triangle();
				break;
			case 3:
				Function();
				break;
			default:
				printf("Missing ability.\n");
		}
		char c2;
		printf("again?\n");
		do
		{
			printf("Please input y or n\n");
			cin>>c2;
		}
		while(c2!='y'&&c2!='n'&&cin.fail());
		if(c2=='n')
			break;
	}
	return 0;
}
