#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

struct Node
{
    char name[15];
   long int year;
    float marks;
    struct Node *next;
};
struct Node *start=0;//Global declaration
class Data_collect
{
public:
  struct Node *Create_Node()
    { struct Node *h1;

    h1=(struct Node *)malloc(sizeof(struct Node));
        cout<<"Enter your name: ";
        cin>>h1->name;
        cout<<"Enter your passing year: ";
        cin>>h1->year;
        cout<<"Enter your marks of class 12th or equivalent: ";
        cin>>h1->marks;
        cout<<h1->name<<" "<<h1->year<<" "<<h1->marks<<endl;
        h1->next=0;
    return h1;
    }
    admission()
    {
        struct Node *k1,*k2;
        k1=Create_Node();
        if(start==0)
        {
            start=k1;
        }
        else
        { k2=start;
         while(k2->next!=0)
         {
             k2=k2->next;
         }
         k2->next=k1;
        }

    }
   void admission_delete()
    { struct Node *l1,*l2,*l3; string nameyour;
     cout<<"Enter your Name: ";
     cin>>nameyour;
     if(start==0)
        cout<<"There is no any node to delete."<<endl;
     else
     {
         if(start->next==0)
         {
             free(start);
             start=0;
             cout<<"Your admission is delete."<<endl;
         }
         else
         {
             l1=start;
             while(l1->next->name!=nameyour)
             {
                 l1=l1->next;
             }
             l2=l1->next;
             l3=l2->next;
             l1->next=l3;
             l2->next=0;
             free(l2);
             cout<<"Your admission is delete."<<endl;
         }
     }

    }
    void selec_list()
    {

    }
  void  Display()
    {

    }
};
class loginP
{
    public:
        Data_collect obj; int cho;

    string UserName,Email; long int Password;
  void  sign()
    {
    cout<<"Enter your User Name:: ";
        cin>>UserName;
    cout<<"Enter your Email:: ";
    cin>>Email;
    cout<<"Enter your Password:: ";
    cin>>Password;
    fstream file;
    file.open("sign.txt",ios::out|ios::app);
    file<<UserName<<" "<<Email<<" "<<Password;
    cout<<"Sign-Up Successfully.....!"<<endl;
    cout<<"Name: "<<UserName<<" "<<"Email: "<<Email<<" "<<"Password: "<<" "<<Password<<endl;
    file.close();
    cout<<"......College Admission......."<<endl;
    cout<<"\n 1. Admission.........";
    cout<<"\n 2. Admission delete..";
    cout<<"\n 3. Selected Students list....";
    cout<<"\nEnter your choice: ";
    cin>>cho;
    switch(cho)
    {
case 1:
    {
        obj.admission();
        break;
    }
case 2:
    {
        obj.admission_delete();
        break;
    }
case 3:
    {
        obj.selec_list();
        break;
    }
    }
    }
  void login()
  {
      fstream file;
      string SearchName; long int SearchPass;
    file.open("sign.txt",ios::in);
    while(!file.eof())
    {
    file>>UserName>>Email>>Password;
    }
    cout<<".......Login......."<<endl;
   cout<<"Enter your User Name:: ";
   cin>>SearchName;
   cout<<"Enter your Password:: ";
   cin>>SearchPass;

   if(SearchName==UserName)
   {
       if(SearchPass==Password)
       {
           cout<<"Account Login Successfully......!"<<endl;
           cout<<"Email Id:: "<<Email<<endl;
           cout<<".....College Admission......"<<endl;
           cout<<"\n 1. Admission.........";
           cout<<"\n 2. Admission delete..";
           cout<<"\n 3. Selected Students list....";
           cout<<"\nEnter your choice: ";
           cin>>cho;
            switch(cho)
    {
case 1:
    {
        obj.admission();
        break;
    }
case 2:
    {
        obj.admission_delete();
        break;
    }
case 3:
    {
        obj.selec_list();
        break;
    }
    }
       }
       else
       {
           cout<<"Wrong Password.......!"<<endl;
       }
   }
   else
   {
       cout<<"Wrong User Name......!"<<endl;
   }
   }
  void forget()
  {
    string SearchName,SearchEmail;
    cout<<"Enter your User Name:: ";
    cin>>SearchName;
    cout<<"Enter your Email:: ";
    cin>>SearchEmail;
    if(SearchName==UserName)
    {
        if(SearchEmail==Email)
        {
            cout<<"Account has Found.......!"<<endl;
         cout<<"Your Password is: "<<Password<<endl;
        }

        else
        {
            cout<<"Wrong Password.......!"<<endl;
        }
        }
        else
       {
       cout<<"Wrong Email.....!"<<endl;
       }
       cout<<"......College Admission......."<<endl;
    cout<<"\n 1. Admission.........";
    cout<<"\n 2. Admission delete..";
    cout<<"\n 3. Selected Students list....";
    cout<<"\nEnter your choice: ";
    cin>>cho;
    switch(cho)
    {
case 1:
    {
        obj.admission();
        break;
    }
case 2:
    {
        obj.admission_delete();
        break;
    }
case 3:
    {
        obj.selec_list();
        break;
    }
    }
 }
  void Exit()
   {
   exit(0);
   }
};
int main()
{
    loginP obj;
    int choice;
   cout<<"1.Sign-Up------"<<endl;
   cout<<"2.Login--------"<<endl;
   cout<<"3.Forget Password----------"<<endl;
   cout<<"4.Exit-----"<<endl;
   while(1)
  {cout<<"Enter Your Choice----: ";
   cin>>choice;
   switch(choice)
   {
   case 1:
    {
      obj.sign();
      break;
    }
   case 2:
    {
     obj.login();
     break;
    }
   case 3:
    {
     obj.forget();
     break;
    }
   case 4:
    {
     obj.Exit();
     break;
    }
   }
  }
    getch();
}

