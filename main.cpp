#include<iostream>
#include<string>
using namespace std;

class verification
{
private:
    string email[4];
    string password[4];
public:
    verification()
    {
        for(int i=0; i<4; i++)
        {
            email[i]="";
            password[i]="";
        }
    }
    verification(const string e[4], const string p[4])
    {
        for(int i=0; i<4; i++)
        {
            email[i]=e[i];
            password[i]=p[i];
        }
    }
    void set_email()
    {
        email[0] = "sidrarajput@gmail.com";
        password[0] = "sidra2005";
        email[1] = "irajtaimur@gmail.com";
        password[1] = "iraj2006";
        email[2] = "sehrish123@gmail.com";
        password[2] = "sehrish2005";
        email[3] = "sobiakhalid@gmail.com";
        password[3] = "sobia123";
    }
    bool check()
    {
        string e_mail;
        string Password;
        cout<<"Enter your Email to Login : ";
        cin>>e_mail;
        cout<<"Enter your Password to Login : ";
        cin>>Password;
        bool f=0;
        for(int i=0; i<4; i++)
        {
            if((e_mail==email[i]) && (Password==password[i]))
            {
                cout<<"Welcome, You are Member of this Library"<<endl;
                f=1;
            }
        }
        if(f==0)
        {
            cout<<"Invalid data"<<endl;
        }
        return f;
    }
};

class book
{
private:
    int id;
    string title;
    string author;
    int quantity;
public:
    book():id(0),title(""),author(""),quantity(0)
    {}
    book(int i, string t, string a, int q):id(i),title(t),author(a),quantity(q) {}
    string get_title()
    {
        return title;
    }
    void book_info()
    {
        cout<<"Enter ID of book: ";
        cin>>id;
        cout<<"Enter title of book: ";
        cin>>title;
        cout<<"Enter name of author: ";
        cin>>author;
        cout<<"Enter quantity: ";
        cin>>quantity;
        cout<<endl;
    }
    void display()
    {
        cout<<"\n--------------Book List-------------\n";
        cout<<"ID of book\tName of book\tAuthor of book\t\tQuantity\n";
        cout<<id<<"\t\t"<<title<<"\t\t "<<author<<" \t\t"<<quantity<<endl;
    }
};

class library
{
private:
    string name;
    int count;
    book books[50];
public:
    library():name(""),count(0)
    {}
    library(string n):name(n),count(0)
    {}
    void add_books()
    {
        if(count<50)
        {
            books[count].book_info();
            count++;
            cout<<"Books added successfully "<<endl;
        }
        else
            cout<<"Library is full!."<<endl;
    }
    void display()
    {
        for(int i=0;i<count;i++)
            books[i].display();
    }
    void search_book()
    {
        string name;
        cout<<"Enter name of book you want to search: ";
        cin>>name;
        bool f=0;
        for(int i=0;i<count;i++)
        {
            if(books[i].get_title()==name)
            {
                cout<<"Product found "<<endl;
                cout<<"Book issue Successfully! "<<endl;
                books[i].display();
                f=1;
            }
        }
        if(!f)
            cout<<"Book not found "<<endl;
    }
    void updatebook()
    {
        string name;
        cout << "Enter book name to update: ";
        cin >> name;
        bool f = false;
        for (int i = 0; i <count; i++)
        {
            if (books[i].get_title() == name)
            {
                f = true;
                cout << "Product found" << endl;
                books[i].book_info();
                cout << "Product updated successfully!" << endl;
                break;
            }
        }
        if (!f)
        {
            cout << "Product not found!" << endl;
        }
    }
};

class member
{
protected:
    string name;
    int age;
    int id;
public:
    member():name(""),age(0),id(0)
    {}
    member(string n, int a, int i):name(n),age(a),id(i)
    {}
    virtual void input_data()
    {
        cout<<"Enter your Id: ";
        cin>>id;
        cout<<"Enter your Name: ";
        cin>>name;
        cout<<"Enter your Age: ";
        cin>>age;
    }
    virtual void display()
    { }
    virtual ~member() {}
};

class student:public member
{
private:
    string e_mail;
    string program;
    library l1;
public:
    student():program(""),e_mail("")
    {}
    student(string n,string p,int a,int i, string e):member(n,a,i),program(p),e_mail(e) {}
    void input_data()
    {
        cout<<"Enter your Id: ";
        cin>>id;
        cout<<"Enter your Name: ";
        cin>>name;
        cout<<"Enter your Age: ";
        cin>>age;
        cout<<"Enter your Program: ";
        cin>>program;
        cout<<"Enter your Email: ";
        cin>>e_mail;
    }
    void display()
    {
        cout<<"ID of Student: "<<id<<endl;
        cout<<"Name of Student: "<<name<<endl;
        cout<<"Age of Student: "<<age<<endl;
        cout<<"Program of Student: "<<program<<endl;
        cout<<"E mail of Student: "<<e_mail<<endl;
    }
    void issue_book()
    {
        l1.search_book();
        cout<<"Book issue successfully! "<<endl;
    }
};

class faculty:public member
{
private:
    string department;
    string e_mail;
    library l2;
public:
    faculty():department(""),e_mail("")
    {}
    faculty(string n,string d,int a,int i,string e):member(n,a,i),department(d),e_mail(e) {}
    void input_data()
    {
        cout<<"Enter your Id: ";
        cin>>id;
        cout<<"Enter your Name: ";
        cin>>name;
        cout<<"Enter your Age: ";
        cin>>age;
        cout<<"\nEnter your Department: ";
        cin>>department;
        cout<<"Enter your Email: ";
        cin>>e_mail;
    }
    void display()
    {
        cout<<"ID of Faculty Member: "<<id<<endl;
        cout<<"Name of Faculty Member : "<<name<<endl;
        cout<<"Age of Faculty Member: "<<age<<endl;
        cout<<"Department of Faculty Member: "<<department<<endl;
        cout<<"E mail of faculty: "<<e_mail<<endl;
    }
    void issue_book()
    {
        l2.search_book();
        cout<<"Book issue successfully! "<<endl;
    }
};

int main()
{
    library *p,*p1;
    int choice;
    verification v;
    v.set_email();
    if(!v.check())
    {
        return 0;
    }
    student s;
    member *m=&s;
    faculty f;
    member *m1=&f;
    library l;
    p=&l;
    p1=&l;
    do
    {
        cout<<"\tLibrary Management System\t"<<endl;
        cout<<"1.Add Books to Library"<<endl;
        cout<<"2.Books List of Library"<<endl;
        cout<<"3.Enter Student Detail"<<endl;
        cout<<"4.Enter Faculty Detail"<<endl;
        cout<<"5.Search for book you want to Issue "<<endl;
        cout<<"6.Update Books "<<endl;
        cout<<"7.Program end "<<endl<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            l.add_books();
            cout<<"---------------------------------------------"<<endl;
            break;
        case 2:
            l.display();
            cout<<"---------------------------------------------"<<endl;
            break;
        case 3:
            s.input_data();
            cout<<"---------------------------------------------"<<endl;
            m->display();
            cout<<"---------------------------------------------"<<endl;
            break;
        case 4:
            f.input_data();
            cout<<"---------------------------------------------"<<endl;
            m1->display();
            cout<<"---------------------------------------------"<<endl;
            break;
        case 5:
            l.search_book();
            cout<<"---------------------------------------------"<<endl;
            break;
        case 6:
            l.updatebook();
            cout<<"---------------------------------------------"<<endl;
            break;
        case 7:
            cout<<"Program end! "<<endl;
            break;
        default:
            cout<<"Invalid choice";
        }
    }
    while(choice!=7);
    return 0;
}
