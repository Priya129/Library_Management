#include <iostream>
#include <stdlib.h> // system("cls")
#include <conio.h>  //getch()
#include <iomanip> // output manipulation like setw
#include <cstring> //string function
#include <fstream>   //file handling
#include <windows.h> // goto function and sleep function
using namespace std;
char mypassword[10]={"admin"};
char mypassword2[10]={"librarian"};
char mypassword3[10]={"student"};
void password()
{
system("cls");
char ch, pwd[10];
cout<<"Enter Password:";
int a=0;
while(ch!=13)      //    ASCII value of enter 
{
	ch=getch();
	if(ch!=13 && ch!=8)  
	{// 13 =enter   8= backspace
	cout<<"*";
	pwd[a]=ch;
	a++;
	}
}
pwd[a]='\0';
if(strcmp(pwd,mypassword)==0)
{
	
	cout<<"\nPassword Match!!"<<endl;
	
	cout<<"Press any key to continue.....";
	getch();


}
else{
	
	cout<<"\nWarning Incorrect Password!!!";
	getch();
	password();
}

}
void password2()
{
system("cls");
char ch, pwd[10];
cout<<"Enter Password:";
int a=0;
while(ch!=13)
{
	ch=getch();
	if(ch!=13 && ch!=8)  
	{// 13 =enter and 8 =backspace
	cout<<"*";
	pwd[a]=ch;
	a++;
	}
}
pwd[a]='\0';
if(strcmp(pwd,mypassword2)==0)
{
	
	cout<<"\nPassword Match!!"<<endl;
	
	cout<<"Press any key to continue.....";
	getch();


}
else{
	
	cout<<"\nWarning Incorrect Password!!!";
	getch();
	password2();

}



}
void password3()
{
system("cls");
char ch, pwd[10];
cout<<"Enter Password:";
int a=0;
while(ch!=13)
{
	ch=getch();
	if(ch!=13 && ch!=8)  
	{// 13 =enter and 8 =backspace
	cout<<"*";
	pwd[a]=ch;
	a++;
	}
}
pwd[a]='\0';
if(strcmp(pwd,mypassword3)==0)
{
	
	cout<<"\nPassword Match!!"<<endl;
	
	cout<<"Press any key to continue.....";
	getch();


}
else{
	
	cout<<"\nWarning Incorrect Password!!!";
	getch();
	password3();
}
}
COORD c = {0, 0};
void gotoxy(int x, int y)
{
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
class book
{
protected:
	char bno[6];
	char name[25];
	char aname[30];

public:
	void create_book()
	{
		cout << "\n\nEnter the Book Number" << endl;
		cin >> bno;
		cin.ignore();
		cout << "\n\nEnter the Book Name" << endl;
		gets(name);
		cout << "\n\nEnter the Author Name" << endl;
		gets(aname);
	}
	void show_book()
	{
		cout << "\n\nThe Book Number:\n"<< bno << endl;
		cout << "\n\nThe Book Name:" << endl;
		puts(name);
		cout << "\n\nThe Author Name:" << endl;
		puts(aname);
	}

	void modify_book()
	{
		cout << "\n\nThe Book Number:\n" << bno;
		cin.ignore();
		cout << "\n\nModify Book Name: ";
		gets(name);
		cout << "\n\nModify Author's Name of Book : ";
		gets(aname);
	}

	char *retbno()
	{
		return bno;
	}

	void report()
	{
		cout << bno << setw(40) << name << setw(40) << aname << endl;
	}
};
class student : public book
{
	char admno[6];
    char stbno[6];
	int token;

public:
	void create_student()
	{
		system("cls");
		cout << "\nNEW STUDENT ENTRY...\n";
		cout << "\nEnter The admission no. ";
		cin >> admno;
		cin.ignore();
		cout << "\n\nEnter The Name of The Student ";
		gets(name);
		token = 0;
		stbno[0] = '\0';
		cout << "\n\nStudent Record Created..";
	}

	void show_student()
	{
		cout << "\nAdmission no. : " << admno;
		cout << "\nStudent Name : ";
		puts(name);
		cout << "\nNo of Book issued : " << token;
		if (token == 1)
			cout << "\nBook No " << stbno;
	}

	void modify_student()
	{
		cout << "\nAdmission no. : " << admno;
		cout << "\nModify Student Name : ";
		gets(name);
	}

	char *retadmno()
	{
		return admno;
	}

	char *retstbno()
	{
		return stbno;
	}
     

	int rettoken()
	{
		return token;
	}

	void addtoken()
	{
		token = 1;
	}

	void resettoken()
	{
		token = 0;
	}

	void getstbno(char t[])
	{
		strcpy(stbno, t);
	}

	void report()
	{
		cout << "\t" << admno << setw(30) << name << setw(30) <<token<< endl;
	}
	
}; //class ends here
//File handling starts from here
fstream fp1,fp2;
book b;
student s;
void add_book()
{
	char ch;
	ofstream fp("Book.txt",ios::out|ios::app);        //opening file using constructor
	do
	{
         system("cls");
		b.create_book();
		fp.write((char*)&b,sizeof(book));
		cout<<"\n\nDo you want to add more record..(y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}
void write_student()
{
	char ch;
	ofstream fp1("Student.txt",ios::out|ios::app);
	do
	{
		s.create_student();
		fp1.write((char*)&s,sizeof(student));
		cout<<"\n\ndo you want to add more record..(y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp1.close();
}
void display_spb(char n[])
{
	cout<<"\nBOOK DETAILS\n";
	int flag=0;
	fp1.open("Book.txt",ios::in);
	while(fp1.read((char*)&b,sizeof(book)))
	{
		if(strcmpi(b.retbno(),n)==0)
		{
			b.show_book();
		 	flag=1;
		}
	}
	
	fp1.close();
	if(flag==0)
		cout<<"\n\nBook does not exist";
	getch();
}
void display_sps(char n[])
{
	cout<<"\nSTUDENT DETAILS\n";
	int flag=0;
	fp2.open("Student.txt",ios::in);
	while(fp2.read((char*)&s,sizeof(student)))
	{
		if((strcmpi(s.retadmno(),n)==0))
		{
			s.show_student();
			flag=1;
		}
	}
	
	fp2.close();
	if(flag==0)
    		cout<<"\n\nStudent does not exist";
 	getch();
}
void modify_book()
{
	char n[6];
	int found=0;
	system("cls");
	cout<<"\n\n\tMODIFY BOOK REOCORD.... ";
	cout<<"\n\n\tEnter The book no. of The book:\n";
	cin>>n;
	fp1.open("Book.txt",ios::in|ios::out);
	while(fp1.read((char*)&b,sizeof(book)) && found==0)
	{
		if(strcmpi(b.retbno(),n)==0)
		{
			b.show_book();
			cout<<"\nEnter The New Details of book"<<endl;
			b.modify_book();
			int pos=-1*sizeof(b);
		    	fp1.seekp(pos,ios::cur);
		    	fp1.write((char*)&b,sizeof(book));
		    	cout<<"\n\n\t Record Updated";
		    	found=1;
		}
	}

    	fp1.close();
    	if(found==0)
    		cout<<"\n\n Record Not Found ";
    	getch();
}
void modify_student()
{
	char n[6];
	int found=0;
	system("cls");
	cout<<"\n\n\tMODIFY STUDENT RECORD... ";
	cout<<"\n\n\tEnter The admission no. of The student";
	cin>>n;
	fp2.open("Student.txt",ios::in|ios::out);
	while(fp2.read((char*)&s,sizeof(student)) && found==0)
	{
		if(strcmpi(s.retadmno(),n)==0)
		{
			s.show_student();
			cout<<"\nEnter The New Details of student"<<endl;
			s.modify_student();
			int pos=-1*sizeof(s);
			fp2.seekp(pos,ios::cur);
			fp2.write((char*)&s,sizeof(student));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}
	
	fp2.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
	getch();
}
void delete_student()
{
	char n[6];
	int flag=0;	
	system("cls");
    	cout<<"\n\n\n\tDELETE STUDENT...";
    	cout<<"\n\nEnter The admission no. of the Student You Want To Delete : ";
    	cin>>n;
    	fp2.open("Student.txt",ios::in|ios::out);
    	fstream fp3;
    	fp3.open("Temp.txt",ios::out);
    	fp2.seekg(0,ios::beg);
    	while(fp2.read((char*)&s,sizeof(student)))
	{
		if(strcmpi(s.retadmno(),n)!=0)
	     		fp3.write((char*)&s,sizeof(student));
		else
	   		flag=1;
	}
    	
	fp2.close();
    	fp3.close();
    	remove("Student.txt");
    	rename("Temp.txt","Student.txt");
    	if(flag==1)
     		cout<<"\n\n\tRecord Deleted ..";
    	else
     		cout<<"\n\nRecord not found";
    	getch();
}
void delete_book()
{
	char n[6];
	int set=0;
	system("cls");
	cout<<"\n\n\n\tDELETE BOOK ...";
	cout<<"\n\nEnter The Book no. of the Book You Want To Delete : ";
	cin>>n;
	fp1.open("Book.txt",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.txt",ios::out);
	fp1.seekg(0,ios::beg);
	while(fp1.read((char*)&b,sizeof(book)))
	{
		if(strcmpi(b.retbno(),n)!=0)  
		{
			fp2.write((char*)&b,sizeof(book));
		}
		else
		{
			set=1;
		}
	}
    	
	fp2.close();
    	fp1.close();
    	remove("Book.txt");
    	rename("Temp.txt","Book.txt");
        if (set==1)
    	cout<<"\n\n\tRecord Deleted .."; 
		else
		cout<<"\n\n\tRecord Not Found..";
        getch();
}
void display_alls()
{
	system("cls");
     	fp2.open("Student.txt",ios::in);
     	if(!fp2)
     	{
       		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
       		getch();
       		return;
     	}

	cout<<"\n\n\t\tSTUDENT LIST\n\n";
	cout<<"============================================================================\n";
	cout<<"Admission No."<<setw(30)<<"Name"<<setw(30)<<"Book Issued\n";
	cout<<"============================================================================\n";

	while(fp2.read((char*)&s,sizeof(student)))
	{
		s.report();
	}
     	
	fp2.close();
	getch();
}
void display_allb()
{
	system("cls");
	fp1.open("Book.txt",ios::in);
	if(!fp1)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
       		getch();
       		return;
     	}

	cout<<"\n\n\t\tBook LIST\n\n";
	cout<<"===================================================================================\n";
	cout<<"Book Number"<<setw(30)<<"Book Name"<<setw(30)<<"Author\n";
	cout<<"===================================================================================\n";

	while(fp1.read((char*)&b,sizeof(book)))
	{
		b.report();
	}
     	fp1.close();
     	getch();
}
void book_issue()
{
	char sn[6],bn[6];
	int found=0,flag=0;
	system("cls");
	cout<<"\n\nBOOK ISSUE ...";
	cout<<"\n\nEnter The student's admission no.";
	cin>>sn;
	fp2.open("Student.txt",ios::in|ios::out);
    	fp1.open("Book.txt",ios::in|ios::out);
            
    	while(fp2.read((char*)&s,sizeof(student)) && found==0)
       	{
		if(strcmpi(s.retadmno(),sn)==0)
		{
			found=1;
			if(s.rettoken()==0)
			{
		      		cout<<"\n\nEnter the book no. ";
				cin>>bn;
				while(fp1.read((char*)&b,sizeof(book))&& flag==0)
				{
			   		if(strcmpi(b.retbno(),bn)==0)
					{
						b.show_book();
						flag=1;
						s.addtoken();
						s.getstbno(b.retbno());
       						int pos=-1*sizeof(s);
						fp2.seekp(pos,ios::cur);
				        fp2.write((char*)&s,sizeof(student));
						cout<<"\n\n Book issued successfully....\n\nPlease submit within 15 days otherwise fine Rs. 1 for each day after 15 days\n\nThank you!!!";
					}
		    		}
					
		  		if(flag==0)
		    			cout<<"Book no does not exist...";
			}
	    		else
		  		cout<<"You have not returned the last book...";

		}
	}
      	if(found==0)
		cout<<"Student record not exist...";
	getch();
  	fp2.close();
  	fp1.close();
	  
}
void book_deposit()
{
    char sn[6],bn[6];
    int found=0,flag=0,day,fine;
    system("cls");
    cout<<"\n\nBOOK DEPOSIT ...";
    cout<<"\nEnter The students admission no."<<endl;
    cin>>sn;
    fp2.open("Student.txt",ios::in|ios::out);
    fp1.open("Book.txt",ios::in|ios::out);
    while(fp2.read((char*)&s,sizeof(student)) && found==0)
       {
	    if(strcmpi(s.retadmno(),sn)==0)
	    {
		    found=1;
		    if(s.rettoken()==1)
		    {
			while(fp1.read((char*)&b,sizeof(book))&& flag==0)
			{
			   if(strcmpi(b.retbno(),s.retstbno())==0)
			{
				b.show_book();
				s.show_student();
				flag=1;
				cout<<"\n\nBook deposited in no. of days"<<endl;
				cin>>day;
				if(day>15)
				{
				   fine=(day-15)*1;
				   cout<<"\n\nFine has to deposited Rs."<<fine;
				}
					s.resettoken();
					int pos=-1*sizeof(s);
					fp2.seekp(pos,ios::cur);
					fp2.write((char*)&s,sizeof(student));
					cout<<"\n\n\t Book deposited successfully....\n\n\t Thank you!!";
			}
		    }
		  if(flag==0)
		    cout<<"Book no does not exist";
		      }
		 else
			cout<<"No book is issued..please check!!";
		}
	   }
      if(found==0)
	cout<<"Student record not exist...";
	getch();
  fp2.close();
  fp1.close();
  }
void administratormenu()
{
	system("cls");
	char op;
	cout<<"\n\n\tADMINISTRATOR MENU"<<endl;
	cout<<"\n\n\t1.ADD BOOK"<<endl;
    cout<<"\n\n\t2.DELETE BOOK"<<endl;
	cout<<"\n\n\t3.MODIFY BOOKS"<<endl;
	cout<<"\n\n\t4.DISPLAY BOOKS RECORD"<<endl;
	cout<<"\n\n\t5.RETURN TO MAIN MENU"<<endl;
	cout<<"\n\n\tPlease enter your choice (1-5)"<<endl;
	cin>>op;
	switch(op)
	{
		case '1':
		system("cls");
		add_book();
		break;
		case '2':
		system("cls");
		delete_book();
		break;
		case '3':
		system("cls");
		modify_book();
		break;
		case '4':
		system("cls");
		display_allb();
		break;
		case '5': 
		return;
      	default:cout<<"INVALID OPTION!!!";

	}
	administratormenu();
	
	}
void librarianmenu()
	{     

		system("cls");
		char ch2;
		cout<<"\n\n\tLIBRARIAN MENU"<<endl;
		cout<<"\n\n\t1.BOOK ISSUE"<<endl;
		cout<<"\n\n\t2.BOOK DEPOSIT"<<endl;
		cout<<"\n\n\t3.CREATE STUDENT RECORD"<<endl;
		cout<<"\n\n\t4.MODIFY STUDENT RECORD"<<endl;
		cout<<"\n\n\t5.DELETE STUDENT RECORD"<<endl;
		cout<<"\n\n\t6.DISPLAY ALL STUDENTS RECORDS"<<endl;
		cout<<"\n\n\t7.RETURN TO MAIN MENU"<<endl;
		cout<<"\n\n\tPlease enter your choice (1-7)"<<endl;
		cin>>ch2;
		switch(ch2)
		{
			case '1':
			system("cls");
			book_issue();
			break;
			case '2':
			book_deposit();
			break;
			case '3':
			write_student();
			break;
			case '4':
			modify_student();
			break;
			case '5':
			delete_student();
			break;
			case '6':
			display_alls();
			break;
			case '7':
			return;
			break;
			default:
			cout<<"INVALID OPTION!!!";


		}
		
      librarianmenu();
	}
void studentmenu()
{
	system("cls");
	char ch3;
	cout<<"\n\n\tSTUDENT MENU"<<endl;
	cout<<"\n\n\t1.DISPLAY SPECIFIC STUDENT RECORD"<<endl;
    cout<<"\n\n\t2.DISPLAY SPECIFIC BOOK"<<endl;
	cout<<"\n\n\t3.DISPLAY ALL BOOKS"<<endl;
	cout<<"\n\n\t4.RETURN TO MAIN MENU"<<endl;
	cout<<"\n\n\tPlease enter your choice (1-4)"<<endl;
	cin>>ch3;
	switch(ch3)
	{
		case '1':
		char num[6];
	       		system("cls");
	       		cout<<"\n\n\tPlease Enter The Admission No. ";
	       		cin>>num;
	       		display_sps(num);
	       		break;
		
		case '2':
		
	       		char n[6];
	       		system("cls");
	       		cout<<"\n\n\tPlease Enter The book No. ";
	       		cin>>n;
	       		display_spb(n);
	       		break;
		case '3':
		system("cls");
		display_allb();
		break;
		case '4': 
		return;
		break;
      	default:cout<<"INVALID OPTION";

	}
	 studentmenu();
	}
void start()

{
	system("cls");
	gotoxy(50, 5);
	cout << "LIBRARY";
	gotoxy(50, 8);
	cout << "MANAGEMENT";
	gotoxy(50, 11);
	cout << "SYSTEM";
	gotoxy(44,14);
	cout<<"Using C++ Language  "<<endl;
	char str[50] = "Developer: Apeksha Ghimire and Priya Chapagain";
	int i = 0, j;
	gotoxy(10, 20);
	for (j = 1; j <= 10; j++)
	{
		Sleep(100);
		cout << "*";
	}
	for (j = 0; j < strlen(str); j++)
	{
		Sleep(100);
		cout << str[j];
	}
	for (j = 1; j <= 10; j++)
	{
		Sleep(100);
		cout << "*";
	}

	getch();
}
int main()
{
	system("cls");
	char ch;
	start();
	do
	{
		cout << "\n\n\tMain Menu" << endl;
		cout << "\n\n\t1. ADMINISTROR MENU" << endl;
		cout << "\n\n\t2. LIBRARIAN MENU" << endl;
		cout << "\n\n\t3. STUDENT MENU" << endl;
		cout << "\n\n\t4. EXIT" << endl;
		cout << "\n\n\tPlease select your option from (1-4)" << endl;
		cin >> ch;
		switch (ch)
		{
		case '1':
		    system("cls");
			password();
			administratormenu();
			break;
		case '2':
		    system("cls");
			password2();
			librarianmenu();
			break;
		case '3':
		     system("cls");
			 password3();
			 studentmenu();
			break;
		case '4':
			exit(0);
			break;
		default:
			cout << "Invalid choice, Try Again";
		}

	} while (ch != 4);
	return 0;
}
