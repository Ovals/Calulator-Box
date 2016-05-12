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
fstream fin;
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
int Redution(int a,int b,bool x)
{
	if(x==1)
	{
		if(a%b==0)
		{
			printf("%d\n",(a/b));
			fout<<a/b<<endl;
		}
		else if(b!=0)
		{
			int a1,b1;
			a1=a/gcd(a,b);
			b1=b/gcd(a,b);
			printf("%d/%d\n",a1,b1);
			fout<<a1<<'/'<<b1<<endl;
		}
		else
		{
			printf("No meaning!\n");
		}
	}
	return a/b;
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
			fout<<a<<mark<<b<<'='<<ans<<endl;
			break;
		case 45:
			ans=a-b;
			printf("%d%c%d=%d\n",a,mark,b,ans);
			fout<<a<<mark<<b<<'='<<ans<<endl;
			break;
		case 42:
			ans=a*b;
			printf("%d%c%d=%d\n",a,mark,b,ans);
			fout<<a<<mark<<b<<'='<<ans<<endl;
			break;
		case 47:
			fout<<a<<mark<<b<<'=';
			ans=Redution(a,b,1);
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
		printf("The area of it is %3.f(3 significant digits)\n.",ans);
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
			{
				printf("y=");
				Redution((y1-y2),(x1-x2),1);
				printf("x+%d\n",k,b);
			}
			if(b<0)
			{
				printf("y=");
				Redution((y1-y2),(x1-x2),1);
				printf("x%d\n",k,b);
			}
			if(b==0)
			{
				printf("y=");
				Redution((y1-y2),(x1-x2),1);
				printf("x\n",k);
			}
		}
	}
}
int main()
{
	fout.open("Record.txt");
	fout<<"Weclome to use Calculator Box 0.30 (demo)!"<<endl
	    <<"We are trying to make things better"<<endl
	    <<"What's new?"<<endl
	    <<"*Simple File I/O"<<endl
	    <<"*add the power of fraction reduction in normal & function part"<<endl
	    <<"*add the Record.txt"<<endl
	    <<"Hope you enjoy it!"<<endl
	    <<endl<<endl
	    <<"Your using record(last one):"<<endl;
	int c=0;
	printf("                             Calculator Box 0.30(demo)                      \n");
	while(1)
	{
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
			printf("Please input 'y' or 'n'\n");
			getchar();
		}
		while(scanf("%c",&c2)==1&&c2!='y'&&c2!='n');
		if(c2=='n')
		{
			printf("Bye.");
			fout<<"(Successfully)"<<endl;
			break;
		}
	}
	return 0;
}
