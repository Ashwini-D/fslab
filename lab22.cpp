#include <iostream>
#include <algorithm>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;
fstream f1;
string buffer;
string key;
int flag;
int pos;
class student
{
   string usn,name;
   string sem;
public:
   void read();
   void pack();
   void unpack();
   void write();
   int search(string key)
   {       
	   int pos=0,flag=0;
	   	f1.open("fil.txt",ios::in);
	   	while(!f1.eof())
	   	{

	   		pos=f1.tellp();
	   		unpack();
	   		if(usn==key)
	   		{
	   			flag=1;
	   			return pos;
	   		}
                }
	   	    if(flag==0)
	   		cout<<"not there";
	   	
	   	return flag;
   }
   void display();
};
void student::write()
{
	f1.open("fil.txt",ios::out|ios::app);
	f1>>buffer;
	f1.close();
}

void student::pack(void)
{

	//string buffer;
	//stringstream ss;
	//int sem=10;
	//ss<<sem;
	//string s=ss.str();
    buffer=usn+"|"+name+"|"+sem;
	buffer.resize(100,'$');
	f1>>buffer;
        
}
void student::unpack(void)
{
	int i=0;
	f1.open("fil.txt",ios::in);
	while(!buffer[i]=='|')
	{
		usn+=buffer[i++];

	}
        i++;
        while(!buffer[i]=='|')
	{
		name+=buffer[i++];
	}
        i++;
	while(!buffer[i]=='|')
	{
		sem+=buffer[i++];
	}
        i++;
        
}
void student::read(void)
{
	cout<<"enter the student usn,name,sem";
	cin>>usn>>name>>sem;
}

int main()
{	
        student s1[50];
	int ch,i,j,n;
        cout<<"enter the no. record\n";
	cin>>n;
        for(j=1;j<=2;j++)
        {
	cout <<"enter your choice 1.read 2.search\n"<< endl;
	cin>>ch;
	    switch(ch)
	    {
	       case 1:for(i=1;i<=n;i++)
	              {
                       
	    	          s1[i].read();
	    	          f1.open("fil.txt",ios::out|ios::app);
		          s1[i].pack();
	                  s1[i].write();
                          s1[i].unpack();
                      }
		      f1.close();
                      
	              break;
	       case 2:cout<<"Enter the key element to be searched";
	              cin>>key;
                      for(i=1;i<=n;i++)
                      pos=s1[i].search(key);
                      cout<<"The pos of the key is:%d",pos;
	              if(pos==0)
	              {
	            	  cout<<"key is not present in record\n";
	              }
	              break;
	       default:exit(0);
	               break;
	     }
         }
}
