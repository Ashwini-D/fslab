#include <iostream>
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
   void search(string key)
   {       
	        int flag=0;
	   	f1.open("fil.txt",ios::in);
                f1.seekg(0);
                 while(!f1.eof())
	   	{
                        getline(f1,buffer,'$');
	   		pos=f1.tellp();
                        unpack();
	   		if(usn==key)
	   		{
	   			flag=1;
	   			cout<<"search successfull\n"<<pos-100;
                                
	   		}
                }
	   	    if(flag==0)
	   		cout<<"unsuccessfull search";
	   	
	   	f1.close();
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
        buffer=usn+"|"+name+"|"+sem+"$";
	f1<<buffer;
        
}
void student::unpack()
{
	int i=0;
	f1.open("fil.txt",ios::in);
	while(!buffer[i]=='|')
	{
		usn+=buffer[i++];
                i++;
	}
        
        while(!buffer[i]=='|')
	{
		name+=buffer[i++];
                i++;
	}
        
	while(!buffer[i]=='|')
	{
		sem+=buffer[i++];
                i++;
	}
        
}
void student::read(void)
{
	cout<<"enter the student usn,name,sem";
	cin>>usn>>name>>sem;
}

int main()
{	
        student s1[50];
        student s;
	int ch,i,j,n;
        cout<<"enter the no. of records";
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
                         
                      }
		      f1.close();
                      
	              break;
	       case 2:cout<<"Enter the key element to be searched";
	              cin>>key;
                      s.search(key);
                      break;
	       default:exit(0);
	               break;
	     }
         }
}
