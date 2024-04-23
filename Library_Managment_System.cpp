#include <iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
using namespace std;

class Login
{   
    private:
    string username;
    string password;
    public:
    Login(string username,string password)
    {
        this -> username = username ;
        this -> password = password ;
    }

    bool verify(string use ,string pwd)
    {
        return(username==use && password==pwd);
    }

};

class BookEntry
{
    private:
    string bookName;
    string bookAuthor;
    string publisher;
    long long ISBN;
    int edition;
    int publishYear;
    int numberOfBooks;
    
    public:
    BookEntry(){} //Default constructer call
    
    void registerBook() 
    {
      cout<<"\nEnter the number of Books this time:";
      cin>>numberOfBooks;

        for (int i = 0; i < numberOfBooks; ++i)
        {
            cout << "\n==============================="<<endl;
            cout << "\tEnter Book Details"<<endl;
            cout << "===============================\n"<<endl;
            cin.get();
            cout << "Enter the Name of the Book: ";
            getline(cin,bookName);
            cout<<"Enter the Author of the Book: ";
            getline(cin,bookAuthor);
            cout << "Enter the Publisher: ";
            getline(cin,publisher);
            cout << "Enter the ISBN number of the Book: ";
            cin >> ISBN;
            cout << "Enter the Edition (numbers only): ";
            cin >> edition;
            cout<<endl;

        }
    }

    void printData()
    {
        cout <<"=========================================\n";
        cout<<"\tBooks in Library\n";
        cout<<"==========================================\n";
       

        for(int i = 0 ; i < numberOfBooks ; i++)
        {
            cout<<"Name of the Book        : "<<bookName<<endl;
            cout<<"Author of the Book      : "<<bookAuthor<<endl;
            cout<<"Publis by               : "<<publisher<<endl;
            cout<<"ISBN number of the Book : "<<ISBN<<endl;
            cout<<"Edition                 : "<<edition<<endl;
            cout<<endl;
        }
        cout<<"Your Book has been registered successfully\n"<<endl;
       
    }

    void saveBookDataToFile(const string &filename)
    {
        ofstream outputFile(filename,ios::app);

        if(!outputFile.is_open())
        {
            cout << "Failed to open the file: " << filename << endl;
        }

        outputFile << "Books in Library\n";
        outputFile << "=========================================\n";

        for(int i = 0 ; i < numberOfBooks ; i++)
        {
            outputFile<<"Name of the Book        : "<<bookName<<endl;
            outputFile<<"Author of the Book      : "<<bookAuthor<<endl;
            outputFile<<"Publis by               : "<<publisher<<endl;
            outputFile<<"ISBN number of the Book : "<<ISBN<<endl;
            outputFile<<"Edition                 : "<<edition<<endl;
            outputFile<<endl;
        }

        cout << "Books data saved to file: " << filename << endl;

        outputFile.close();
        
    }

    ~BookEntry()
    {
        cout<<"Destroy memory of object in class BookEnter!!"<<endl;
    }
};   

class StudentEntry
{
private:
    string studentName;
    string studentAddress;
    string studentEmail;
    int studentID;

public:
    StudentEntry()
    {
        studentName='\0';
        studentAddress='\0';
        studentEmail='\0';
        studentID=0;
    }
    StudentEntry(string  studentName,string studentAddress,string studentEmail,int memberID)
    {
        this-> studentName = studentName;
        this->studentAddress=studentAddress;
        this->studentEmail=studentEmail;
        this->studentID=studentID;

    }

    StudentEntry(StudentEntry &tob)
    {
        tob. studentName = studentName;
        tob.studentAddress=studentAddress;
        tob.studentEmail=studentEmail;
        tob.studentID=studentID;

    } 

    void saveStudentDataToFile(const string &filename)
    {
        ofstream outputFile(filename, ios::app);

        if (!outputFile.is_open())
        {
            cout << "Failed to open the file: " << filename << endl;
            
        }

        outputFile << "Student Details\n";
        outputFile << "=========================================\n";
        outputFile << "Name: " << studentName << endl;
        outputFile << "Address: " << studentAddress << endl;
        outputFile << "Email: " << studentEmail << endl;
        outputFile << "Student ID: " << studentID << endl;
        outputFile << "--------------------------------------" << endl;

        cout << "Student data saved to file: " << filename << endl;

        outputFile.close();
    }



    friend ostream& operator << (ostream &,StudentEntry &);
    friend istream& operator >> (istream &,StudentEntry &);

    ~StudentEntry()
    {
        cout << "Destroy memory of object of class StudentEntery!! "<<endl;
    }
};

istream& operator >>(istream &in,StudentEntry &m)
{
    cin.get();
    cout<<"Enter the Name of the Student : ";
    getline(in,m.studentName);
    cout<<"Enter the Address of the Student : ";
    getline(in,m.studentAddress);
    cout<<"Enter the Email of the Student : ";
    in >> m.studentEmail;
    cout << "Enter the Student ID: ";
    in >> m.studentID;
    cout<<endl;
    
    return in;
}

ostream& operator <<(ostream &out,StudentEntry &n)
{
    out<<"Name       : " << n.studentName<< endl;
    out<<"Address    : " << n.studentAddress << endl;
    out<<"Email      : " << n.studentEmail << endl;
    out<<"Student ID : " <<n.studentID << endl;
    out<<endl;
   
    return out;
}


int main()
{
    Login user("admin","password123");
    BookEntry Book;
    StudentEntry S;

    string inputusername;
    string inputpassword;
    char choise; 

    cout << "\n==============================="<<endl;
    cout << "Library Management Login :"<<endl;
    cout << "===============================\n"<<endl;
    
    cout<<"Enter the username :";
    cin>>inputusername;

    cout<<"Enter the password :";
    cin>>inputpassword;

    if(user.verify(inputusername,inputpassword))
    {
        cout<<"\n    Login successful!! \n"<<endl;
    }
    else
    {
        cout<<"\n  Login failed. Invalid username or password." <<endl;
        cout<<"Try Again !! \n"<<endl;
        exit(0);
    }
    

    while (true)
    {
        cout<< "==============================="<<endl;
        cout<< "      Choose below Option"<<endl;
        cout<< "===============================\n"<<endl;
        cout<< "1. To make an Entry of Book"<<endl;
        cout<< "2. To Issue Book "<<endl;
        cout<< "3. Register a Student Information "<<endl;
        cout<< "0. Press zero(0) to exit \n"<<endl;
        cout<<"Enter the Option : ";
        cin >> choise;


        switch (choise)
        {
        case '0':
                cout<<"\nCode exit.......!\n"<<endl;
                exit(0);    
        case '1': 
                Book.registerBook();
                Book.printData();
                Book.saveBookDataToFile("book_data.txt");
                break;
        case '2':
                
                cout << "\n       Issuing the book...! \n"<<endl;
                
                break;
        case '3':
                cout << "\n==============================="<<endl;
                cout << "      Enter Student Details"<<endl;
                cout << "===============================\n"<<endl;
                cin>>S;
                cout<< "\n========================================="<<endl;
                cout<< "       Student Details"<<endl;
                cout<< "=========================================\n"<<endl;
                cout<<S;
                S.saveStudentDataToFile("StudentData.txt");
                break;
        default:
                cout << "\n       Invalid option..............\n"<<endl;
                break;
        }
    }

    return 0;
}