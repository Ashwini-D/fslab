
#include<stdio.h>
#include<stdlib.h>
//#include<conio>
#include<string.h>
#include<fstream>
#include<iostream>
using namespace std;
#include<iomanip>

void writeLists()
{
	fstream out1,out2;
	int i;
	int m;
	int n;
	char name[20];

	out1.open("file1.txt",ios::out);
	out2.open("file2.txt",ios::out);

	if( (!out1) || (!out2))
	{
		printf("unable to open one of the list files\n");
		//getch();
		exit(0);
	}
	cout<<"enter the number of names you want to enter in file1\n";
	cin>>m;
	cout<<"\nenter the names in ascending order\n";
	for(i=0;i<m;i++)
	{
		cin>>name;
		out1<<name;
		out1<<'\n';
	}
	cout<<"enter the number of names you want to enter in file2\n";
	cin>>n;
	cout<<"\nenter the names in ascending order\n";
	for(i=0;i<n;i++)
	{
		cin>>name;
		out2<<name;
		out2<<'\n';
	}
	out1.close();
	out2.close();
}

int main()
{
	char list1[100][20];
	char list2[100][20];
	int i;
	int j;
	int m;
	int n;
	//clrscr();
	fstream out1,out2,out3;

	writeLists();

	out1.open("file1.txt",ios::in);
	out2.open("file2.txt",ios::in);
	out3.open("file3.txt",ios::out);

	if( (!out1) || (!out2) || (!out3))
	{
		printf("unable to open one of the file");
		//getch();
		exit(0);
	}

	//clrscr();
	m=0;
	n=0;
	printf("LIST-1 CONTENTS\n");

	while( !out1.eof())
	{
		out1.getline(list1[m],20,'\n');
		cout<<list1[m];
		cout<<"\n";
		m++;
	}

	printf("LIST-2 CONTENTS\n");

	while( !out2.eof())
	{
		out2.getline(list2[n],20,'\n');
		cout<<list2[n];
		cout<<"\n";
		n++;
	}
	m--;
	n--;
	i=0;
	j=0;
	cout<<"\nelements common to both files are\n";

	while(i<m && j<n)
	{
		if(strcmp(list1[i],list2[j])==0)
		{
			out3<<list1[i];
			cout<<list1[i]<<"\n";
			out3<<'\n';
			i++;
			j++;
		}
		else if(strcmp(list1[i],list2[j])<0)
		{
			i++;
		}
		else
		{
			j++;
		}
	}
	//getch();
}


