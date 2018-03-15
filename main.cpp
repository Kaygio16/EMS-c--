#include <iostream>
#include <conio.h>
#include <stdio.h>
#include<fstream>
#include <iomanip>
#include <windows.h>
using namespace std;
 int i=0;
class Employee
{
public:
    char name[100];
    long int idno;
    char gender;
    char department[100];
    char level;
    int wage;


    void add();
    int calcwage();
    void queryid();
    void queryname();
    void display();
    void edit();
    void delete1();
    int statsmen();
    int statswomen();
    int employees();
    void save();
    void read();
};
void Employee::add()
{
    cout<<"Name: ";
    cin>>name[i];
    cout<<"ID number: ";
    cin>>idno;
    cout<<"Gender(M/F): ";
    cin>>gender;
    cout<<"Department: ";
    cin>>department;
    cout<<"(M=Manager,T=Technician,S=Salesman,SM=SalesManager)"<<endl;
    cout<<"Level(M/T/S/SM): ";
    cin>>level;
}
int Employee::calcwage()
{
    if(level=='M')
        wage=2000;
    else if(level=='S')
        wage=1000;
    else if(level=='T')
        wage=1500;
    else if(level=='SM')
        wage=1200;
}
void Employee::queryid()
{
    int item;
    cout<<"\nEnter Id number to display information: ";
    cin>>item;
    if(item==idno)
        cout <<"NAME\t\t\tID NUMBER\t\tGENDER\t\tDEPARTMENT\t\tLEVEL\t\t  WAGE\n";
        cout << name<<"\t\t\t"<<idno<<"\t\t\t"<<gender<<"\t\t"<<department<<"\t\t\t"<<level<<"\t\t"<<wage<<endl;
}
void Employee::queryname()
{
    char itema[100];
    cout<<"\nEnter name to display information: ";
    cin>>itema;
    if(itema==name)
        cout <<"NAME\t\t\tID NUMBER\t\tGENDER\t\tDEPARTMENT\t\tLEVEL\t\t  WAGE\n";
        cout << name<<"\t\t\t"<<idno<<"\t\t\t"<<gender<<"\t\t"<<department<<"\t\t\t"<<level<<"\t\t"<<wage<<endl;
}
void Employee::display()
{
    cout << name<<"\t\t\t"<<idno<<"\t\t\t"<<gender<<"\t\t"<<department<<"\t\t\t"<<level<<"\t\t"<<wage<<endl;
}
void Employee::edit()
{
    int jobcode;
    cout<<"Enter code you want to Edit: ";
    cin>>jobcode;
   if(jobcode==idno)
        {
            system("cls");
     cout<<"1:Edit Name."<<endl;
     cout<<"2:Edit Id Number."<<endl;
     cout<<"3:Edit Department."<<endl;
     cout<<"4:Edit Level."<<endl;
     cout<<"5:Edit Wage."<<endl;
     cout<<"6:To go back to menu"<<endl;
     cout<<"Enter option: ";
     int option;
     cin>>option;


        if (option==1)
     {
         system("cls");
         cout<<"           Edit name\n";
         cout<<"         ~~~~~~~~~~~~\n";
         cout<<"Enter New Name: ";
         cin>>name;
         cout<<"wait a moment...."<<endl;
         Sleep(500);
         cout<<"New Information Inserted "<<endl;

     }
        else if(option==2)
     {
         system("cls");
         cout<<"          Edit Id Number\n";
         cout<<"          ~~~~~~~~~~~~~~~~\n";
         cout<<"Enter new Id Number: ";
         cin>>idno;
         cout<<"wait a moment...."<<endl;
         Sleep(500);
         cout<<"New Information Inserted "<<endl;
     }
        else if(option==3)
     {
         system("cls");
         cout<<"          Edit Department\n";
         cout<<"         ~~~~~~~~~~~~~~~~~\n";
         cout<<"Enter New Department: ";
         cin>>department;
         cout<<"wait a moment...."<<endl;
         Sleep(500);
         cout<<"New Information Inserted ";
     }
        else if(option==4)
     {
         system("system");
         cout<<"Edit Level"<<endl;
         cout<<"Enter New Level: ";
         cin>>level;
         cout<<"wait a moment...."<<endl;
         Sleep(500);
         cout<<"New Information Inserted ";
     }
        else if(option==5)
        {
            system("cls");
            cout<<"    Edit Wage\n";
             cout<<"   ~~~~~~~~~~~~\n";
             cout<<"Enter new Wage: ";
             cin>> wage;
             cout<<"wait a moment...."<<endl;
             Sleep(500);
             cout<<"New Information Inserted ";
        }
        else return;

 }
     else cout<<"wrong id";
}
void Employee::delete1()
{

}
int Employee::statsmen()
{
    if(gender=='M')
        return 1;
    return 0;
}
int Employee::statswomen()
{
    if(gender=='F')
        return 1;
    return 0;
}
int Employee::employees()
{
    return statsmen() + statswomen();
}
void Employee::save()
{
    ofstream database("information.txt");
    if(!database)
    {
        cout<<"Cant open file!"<<endl;
    }
    else
    {
       database <<"NAME\t\t\tID NUMBER\t\tGENDER\t\tDEPARTMENT\t\tLEVEL\t\t  WAGE\n";
       database << name<<"\t\t\t"<<idno<<"\t\t\t"<<gender<<"\t\t"<<department<<"\t\t\t"<<level<<"\t\t"<<wage<<endl;
    }
    database.close();
}
void Employee::read()
{
    ifstream database("information.txt");
    string data;
    while(!database.eof())
    {
        getline(database,data);
        cout << data << endl;
    }
    database.close();
}
class Manager:public Employee
{
public:
    int countmanager()
    {
        int manager(0);
            if(level=='M')
                return 1;
            return 0;
    }
};
class Technician:public Employee
{
public:

         int countTechnician()
    {
        int technician(0);
            if(level=='T')
                return 1;
            return 0;
    }
};
class SalesMen:public Employee
{
public:

    int countSalesmen()
    {
        int salesmen(0);
            if(level=='S')
                return 1;
            return 0;
    }
};
class SalesManager:public Employee
{
public:

    int countSalesmanager()
    {
        int salesmanager(0);
            if(level=='SM')
                return 1;
            return 0;
    }

};


int main()
{
    Employee obj;
    Manager obj1;
Technician obj2;
SalesMen obj3;
SalesManager obj4;
    char c;
    do
{
    system("cls");
    cout << "\n\t\t\t #EMPLOYEE INFORMATION MANAGEMENT SYSTEM# ";
    cout << "\n\t\t\t*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << "\n\n";
cout << "\nA:Initialize Employee Information System ";
cout << "\nB:Query Employee information system ";
cout << "\nC:Diplay Employee Information ";
cout << "\nD:Edit Employee Information ";
cout << "\nE:Delete Employee Information";
cout << "\nF:Perform a statictic survey on Employee Information";
cout << "\nG:Save Employee Information";
cout << "\nH:Read employee Information ";
cout << "\nQ:Quit";
cout << "\nEnter your choice: ";
cin >> c;
    switch (c)
{
        case 'A':
        case 'a':
    system("cls");
    cout << "             BUILD EMPLOYEE INFORMATION\n";
    cout << "             ~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    int num;
    cout<<" Enter number of entries: ";
    cin>>num;
    for(int i=0;i<=num-1;i++)
        {
        obj.add();
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        }
        cout << "\nInformation inserted\n";
        obj.save();
Sleep(500);
break;


case 'B':
case'b':
    system("cls");
int x;
cout << "\n    Query Employee information system ";
cout << "\n    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
cout << "\nIf you want to search with help of name then press 1 ";
cout << "\nIf you want to search with help of number then press 2";
cout << "\nPress 3 to return to main menu";
cout << "\nEnter option: ";
cin >> x;
{if (x == 1)
{
    system("cls");
cout << "\n                SEARCH by name";
cout << "\n               ~~~~~~~~~~~~~~~~";
for(int i=0;i<=num-1;i++)
{
    obj.calcwage();
    obj.queryname();
}
cout<<"wait a moment...."<<endl;
Sleep(1000);
cout <<" Press one to return to main menu: ";
int b;
cin >> b;
 if(b==1)
break;
}
else if(x==2)
{
    system("cls");
cout << "\n                Search by ID number";
cout << "\n               ~~~~~~~~~~~~~~~~~~~~~~";
for(int i=0;i<=num-1;i++)
{
    obj.calcwage();
    obj.queryid();
}
cout<<"wait a moment...."<<endl;
Sleep(1000);
cout <<" Press one to return to main menu: ";
int b;
cin >> b;
 if(b==1)
    break;
}
else break;
}

case 'C':
case'c':
    //display information.
    system("cls");
    cout <<"NAME\t\t\tID NUMBER\t\tGENDER\t\tDEPARTMENT\t\tLEVEL\t\t  WAGE\n";
    for(int i=0;i<=num-1;i++)
        {
            obj.calcwage();
            obj.display();
        }
cout <<" Press one to return to main menu: ";
int y;
cin >> y;
 if(y==1)
    break;
 Sleep(1000);

 case'D':
case 'd':
    system("cls");
cout << "\n                   Edit Employee Information ";
cout << "\n                   ~~~~~~~~~~~~~~~~~~~~~~~~~\n";
cout<<"Enter code to allow edit"<<endl;
     cout<<": ";
     int jobcode;
     cin>>jobcode;
for(int i=0;i<=num-1;i++)
{
   obj.edit();
   obj.save();
}
cout<<"wait a moment...."<<endl;
Sleep(1000);
cout <<" Press one to return to main menu: ";
int b;
cin >> b;
 if(b==1)
break;

case 'E':
case 'e':
    system("cls");
cout << "\n                   Delete Employee Information";
cout << "\n                   ~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
/*cout<<"Enter Id to delete entry: ";
    cin>>idno;
    int del;
    for(int i=0;i<=num-1;i++)
    {
        obj.delete1();
        obj.save();
    }
cout << "\nAction Has been Processed\n";
cout<<"wait a moment...."<<endl;
Sleep(1000);
cout <<" Press one to return to main menu: ";
int c;
cin >> c;
 if(c==1)
break;*/

case 'F':
case 'f':
    system("cls");
cout << "\n                   Conduct a survey on Employee Information";
cout << "\n                   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
int h;
cout << "\n1)To search for number of Men and Women.";
cout << "\n2)To search for number of Employees.";
cout << "\n3)To search for managers/technicians/Salesmen/Salesmanagers. ";
cout << "\n4)To return to main menu. ";
cout << "\nEnter option: ";
cin >> h;

   if(h==1)
    {
        system("cls");
        int men(0);
        int women(0);
        obj.display();
        for(int i=0;i<=num-1;i++){
        if(obj.statsmen()){
            men++;}}
        cout << "There are " << men << " men." << endl;
         for(int i=0;i<=num-1;i++){
        if(obj.statswomen()){
            women++;}}
        cout << "There are " << women << " women."<<endl;
        cout <<" Press one to return to main menu: ";
           int d;
           cin >> d;
           if(d==1)
          break;
    }
     else if(h==2)
    {
          system("cls");
        int men(0);
        int women(0);
        obj.display();
        for(int i=0;i<=num-1;i++){
        if(obj.statsmen())
            men++;}
        cout << "There are " << men << " men." << endl;
         for(int i=0;i<=num-1;i++){
        if(obj.statswomen())
            women++;}
        cout << "There are " << women << " women."<<endl;
        cout << "Therefore there are " << obj.employees() <<" employees."<<endl;
        cout <<" Press one to return to main menu: ";
           int d;
           cin >> d;
           if(d==1)
          break;
    }
    else if(h==3)
    {
        system("cls");
        obj.display();
        int manager(0);
        int technician(0);
        int salesmen(0);
        int salesmanager(0);
         for(int i=0;i<=num-1;i++){
        if(  obj1.countmanager()){
            manager++;}}
        cout << "There are " << manager << " Managers."<<endl;
        for(int i=0;i<=num-1;i++){
        if( obj2.countTechnician()){
            technician++;}}
        cout << "There are " << technician << " Technicians."<<endl;
        for(int i=0;i<=num-1;i++){
        if(obj3.countSalesmen()){
            salesmen++;}}
        cout << "There are " << salesmen << " Salesmen."<<endl;
         for(int i=0;i<=num-1;i++){
        if(obj4.countSalesmanager()){
            salesmanager++;}}
        cout << "There are " << salesmanager << " Salesmanagers."<<endl;
         cout <<" Press one to return to main menu: ";
           int d;
           cin >> d;
           if(d==1)
          break;

    }

    else break;

case 'G':
case 'g':
    system("cls");
    obj.calcwage();
    obj.save();
     cout << "saving file wait a moment......"<<endl;
     Sleep(100);
     int s;
     cout << "press 1 to return to main menu: ";
     cin>>s;
     if(s==1)
     break;

case'H':
case 'h':
    system("cls");
    cout<<" Read File!"<<endl;
     obj.calcwage();
     obj.read();
     Sleep(500);
     cout << "press 1 to return to main menu: ";
     int l;
     cin>>l;
     if(l==1)
        break;

case 'Q':
exit(0);


    }
}while(c!=0);

return 0;
}
