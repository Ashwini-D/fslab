#include <iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;
fstream f1;
string buffer;
string key;
string value;
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
   void modify(string value);
   int search(string key)
   {       
	        int flag=0;
	   	f1.open("file.txt",ios::in);
                 while(!f1.eof())
	   	{
                        getline(f1,buffer);
	   		pos=f1.tellp();
                        unpack();
	   		if(usn==key)
	   		{
	   			flag=1;
	   			cout<<"search successfull\n";
                                return pos;
	   		}
                }
	   	    if(flag==0)
	   		cout<<"unsuccessfull search";
	   	
	   	
   }
   void display();
};
void student::write()
{
	f1.open("file.txt",ios::out|ios::app);
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
	f1<<buffer;
        
}
void student::unpack()
{
	int i=0;
	f1.open("file.txt",ios::in);
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
void student::modify(string value)
{       string filename;
        int fd;
        int choose;
        student s;
        cout<<"enter the filename";
        cin>>filename;
        pos=search(value);
        if(pos>0)
        {
        cout<<"which field have to be modified 1.usn 2.name 3.sem";
        cin>>choose;
        switch(choose)
        {   
            case 1:cout<<"USN";cin>>usn;break;
            case 2:cout<<"\nNAME";cin>>name;break;
            case 3:cout<<"\nsem";cin>>sem;break;
            default:cout<<"wrong choic:";
        }
        
        f1.open(filename.c_str(),ios::out);
	f1.seekp(pos,ios::beg);
	pack();
	f1.close();
	}
        else
            exit(0);
	
    
}

int main()
{	
        student s1[50];
	int ch,i,j,n;
        cout<<"enter the no. record\n";
	cin>>n;
        for(j=1;j<=2;j++)
        {
	cout <<"enter your choice 1.read 2.search 3.modify\n"<< endl;
	cin>>ch;
	    switch(ch)
	    {
	       case 1:for(i=1;i<=n;i++)
	              {
                       
	    	          s1[i].read();
	    	          f1.open("file.txt",ios::out|ios::app);
		          s1[i].pack();
	                  s1[i].write();
                         
                      }
		      f1.close();
                      
	              break;
	       case 2:cout<<"Enter the key element to be searched";
	              cin>>key;
                      for(i=1;i<=n;i++)
                      pos=s1[i].search(key);
                      break;
               case 3:cout<<"enter the key to be modified\n";
                      cin>>value;
                      s1[i].modify(value);
	       default:exit(0);
	               break;
	     }
         }
}
