


#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
#include<string.h>
#include<fstream>
#include<iostream>
using namespace std;
#include<iomanip>

class record
{
	public: 	char age[5];
		char usn[20];
		char name[20];
		char sem[2];
		char branch[5];
}rec[20];

char st_no[5];
int no;

void retrieve_details()
{
	fstream file2;
	char name[20];
	char age[5];
	char usn[20];
	char sem[2];
	char branch[5];
	char ind[5];

	file2.open("record.txt",ios::in);

	for(int i=0;i<no;i++)
	{
		file2.getline(ind,5,'|');
		file2.getline(usn,20,'|');
		file2.getline(name,20,'|');
		file2.getline(age,5,'|');
		file2.getline(sem,5,'|');
		file2.getline(branch,5,'\n');

		if(strcmp(ind,st_no)==0)
		{
			cout<<"\n\t"<<"student details :\n";
			cout<<"\n\tUSN\tNAME\tAGE\tSEM\tBRANCH\n";
			cout<<"\n\t"<<usn<<"\t"<<name<<"\t";
			cout<<age<<"\t"<<sem<<"\t"<<branch<<"\n";
		}
	}
	file2.close();
}

void delete_record(char usno[])
{
	int i;
	fstream file1,file2;
	char name[20];
	char age[5];
	char usn[20];
	char sem[2];
	char branch[5];
	char ind[5];

	file2.open("record.txt",ios::in);

	for(i=0;i<no;i++)
	{
		file2.getline(ind,5,'|');
		file2.getline(usn,20,'|');
		file2.getline(name,20,'|');
		file2.getline(age,5,'|');
		file2.getline(sem,5,'|');
		file2.getline(branch,5,'\n');

		strcpy(rec[i].usn,usn);
		strcpy(rec[i].name,name);
		strcpy(rec[i].age,age);
		strcpy(rec[i].sem,sem);
		strcpy(rec[i].branch,branch);
	}

	int flag=-1;

 	for(i=0;i<no;i++)
	{
		if(strcmp(rec[i].usn,usno)==0)
		{
			flag=i;
		}
	}

	if(flag==-1)
	{
		cout<<"error..! \n";
		return;
	}

	if(flag==(no-1))
	{
		no--;
		cout<<"record deleted !\n";
		return;
	}

	for(i=flag;i<no;i++)
	{
		rec[i]=rec[i+1];
	}
	no--;
	cout<<"\nrecord deleted !\n";
	file2.close();

	file1.open("index.txt",ios::out);
	file2.open("record.txt",ios::out);

	for(i=0;i<no;i++)
	{
		file1<<rec[i].usn<<"|"<<i<<"\n";
		file2<<i<<"|"<<rec[i].usn<<"|"<<rec[i].name<<"|"<<rec[i].age
			   <<"|"<<rec[i].sem<<"|"<<rec[i].branch<<"\n";
	}

	file1.close();
	file2.close();
	return;
}

int main()
{
	fstream file1,file2;
	int choice;
	char rt_usn[20];
	char st_usn[20];
	//char ind[2];
	//char name[20];
	//char age[2];
	//char sem[5];
	//char branch[5];
	int i;
	int flag;
	int flag1;
	//clrscr();

	file1.open("index.txt",ios::out);
	file2.open("record.txt",ios::out);

	if(!file1 || !file2)
	{
		cout<<"file creation error ! \n";
		exit(0);
	}

	for(;;)
	{
		cout<<"\nenter the choice:\n\n";
		cout<<"1 : add record\n";
		cout<<"2 : search record\n";
		cout<<"3 : delete record\n";
		cout<<"4 : display record\n";
		cout<<"5 : exit\n\n";

		cin>>choice;

		switch(choice)
		{
			case 1: 	cout<<"\nenter the no. of students : ";
				cin>>no;
				cout<<"\nenter the details :\n";
				for(i=0;i<no;i++)
				{
					cout<<"\nname :";
					cin>>rec[i].name;
					cout<<"age : ";
					cin>>rec[i].age;
					cout<<"usn : ";
					cin>>rec[i].usn;
					cout<<"sem : ";
					cin>>rec[i].sem;
					cout<<"branch :";
					cin>>rec[i].branch;


					file1<<rec[i].usn<<"|"<<i<<"\n";							      	file2<<i<<"|"<<rec[i].usn<<"|"<<rec[i].name
<<"|"<<rec[i].age<<"|"<<rec[i].sem
<<"|"<<rec[i].branch<<"\n";
				}

				file1.close();
				file2.close();
				break;

			case 2:   cout<<"\nenter the USN of the student record to be searched\n";
				cin>>st_usn;
				file1.open("index.txt",ios::in);
				if(!file1)
				{
					cout<<"error!\n";
					exit(0);
				}
				flag1=0;
				for(i=0;i<no;i++)
				{
					file1.getline(rt_usn,20,'|');
					file1.getline(st_no,4,'\n');
					if(strcmp(st_usn,rt_usn)==0)
					{
						retrieve_details();
						flag1=1;
					}
				}
				if(!flag1)
				{
					cout<<"\nrecord search failed !!\n";
				}
				file1.close();
				break;

case 3: cout<<"\nenter the USN of the student record to be deleted\n\n";
				cin>>st_usn;
				file1.open("index.txt",ios::in);
				if(!file1)
				{
					cout<<"error !\n";
					exit(0);
				}
				flag=0;
				for(i=0;i<no;i++)
				{
					file1.getline(rt_usn,20,'|');
					file1.getline(st_no,4,'\n');
					if(strcmp(st_usn,rt_usn)==0)
					{
						delete_record(rt_usn);
						flag=1;
					}
				}
				if(!flag)
				{
					cout<<"deletion failed!\n";
				}
				file1.close();
				break;

			case 4:	cout<<"\n\tUSN\tNAME\tAGE\tSEM\tBRANCH\t\n";
				for(i=0;i<no;i++)
				{
					cout<<"\n\t"<<rec[i].usn;
					cout<<"\t"<<rec[i].name;
					cout<<"\t"<<rec[i].age;
					cout<<"\t"<<rec[i].sem;
					cout<<"\t"<<rec[i].branch<<"\n";
				}
				break;

			case 5: 	exit(0);

			default:	 cout<<"invalid choice !\n";
				break;
		}
	}
}


