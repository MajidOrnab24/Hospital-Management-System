#include <iostream>
#include"doctor.h"
#include<windows.h>
#include<fstream>
using namespace std;

void print()
{
    cout << "***************************** HOSPITAL MANAGEMENT SYSTEM***************************************"
         "\n'a' -- FOR THE ADMIN PANEL"
         "\n'p' -- FOR PATIENTS MENU"
         "\n'd' -- FOR DOCTOR MENU"
         "\n'l' -- FOR LAB TEST"
         "\n'w' -- FOR ADMISSION IN A WARD"
         "\n's' -- FOR SAVING ALL DOCTOR DATA"
         "\n'r' -- FOR READING ALL DOCTOR DATA"
         "\n'x' -- exit"
         "\nEnter selection: ";

}
void printDept()
{

    for(int i=0; i<12; i++)
    {
        cout<<"Department no: "<<i+1<<"  & Name: "<<deptartment[i]<<endl;
    }
    cout<<"Enter Department No of the Department required: ";

}

int main()
{
    admin a;
    //a.setAdata();
   ifstream file2;
    file2.open("Admin.txt",ios::binary);
    file2.seekg(0);
    file2.read((char*)&a,sizeof(a));
    file2.close();
ofstream file1;
    char ch;
    while(true)
    {
        system("cls");
        print();
        cin >> ch;
        switch(ch)
        {
        case 'a':
            system("cls");
            a.ad=1;
            if(a.ad==0)
            {
                a.verify();
            }

            if(a.ad==1)
            {
                system("cls");
                file1.open("Admin.txt",ios::trunc|ios::binary);
                a.ad=0;
                file1.write((char*)&a,sizeof(a));
                file1.close();
                a.ad=1;
                a.showdata();
                cout<<"Enter Choice: "<<"\nPRESS 1 FOR HIRING A DOCTOR"<<"\nPRESS 2 FOR SACKING A DOCTOR"<<
                    "\nPRESS 3 FOR INCREASING OR DECREASING WARDS"<<"\nPRESS 4 FOR INCREASING OR DECREASING BEDS IN ALL WARDS"
                    <<"\nPRESS 5 FOR LOOKING UP ALL INFO ABOUT A DOCTOR"<<"\nPRESS 6 FOR LOOKING UP ALL INFO ABOUT A PATIENT"
                    <<"\nPRESS 7 FOR KNOWING TOTAL INCOME OF HOSPITAL"<<endl;
                int adminC;
                cin>>adminC;
                switch(adminC)
                {
                case 1:
                    system("cls");
                    doctor::add();
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    doctor::sack();
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    doctor::WardInDe();
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    doctor::BedInDe();
                    system("pause");
                    break;
                case 5:
                    system("cls");
                    doctor::display();
                    system("pause");
                    break;
                case 6:
                    system("cls");
                    lookUpPat();
                    system("pause");
                    break;
                case 7:
                    system("cls");
                    cout<<"Total income till date: "<<doctor::moneyAmount()<<" tk"<<endl;
                    system("pause");
                    break;
                default:
                    cout << "\nUnknown command";

                }
            }
            break;
        case 'd':
            system("cls");
//            for(int i=0; i<pat.size(); i++) for checking if info are
//            {
//                pat[i]->showPdetails();
//            }
            cout<<"Enter Doctor ID: ";
            int Did;
            cin>>Did;
            doctor::searchAllpatientsOfDoc(Did);
            break;
        case 'w':
            system("cls");
            doctor::assignWardBed();
            break;
        case 's':
            doctor::write();
            PatWrite();
            a.totalAmoney=doctor::moneyAmount();
            //ofstream file1;
            file1.open("Admin.txt",ios::trunc|ios::binary);
            a.ad=0;
            file1.write((char*)&a,sizeof(a));
            file1.close();
            system("pause");
            break;
        case 'r':
            doctor::deleteArr();
            doctor::read();
            doctor::setMoneyAmount(a.totalAmoney);
            PatRead();
            doctor::patToDocPatients();
            system("pause");
            break;
        case 'l':
            system("cls");
            doctor::assignLab();
            break;
        case 'x':
            system("cls");
            doctor::write();
            PatWrite();
            system("pause");
            exit(0);
            break;
        default:
            cout << "\nUnknown command"<<endl;
            system("pause");
            break;
        case 'p':
            int flag,d;
            int k=0;
            system("cls");
            cout<<"ENTER DOCTOR TYPE: "<<"\nPRESS 1 FOR PHYSICIAN"<<"\nPRESS 2 FOR DOCTOR OF EMERGENCY MEDICINE"<<
                "\nPRESS 3 FOR INDOOR DOCTOR"<<"\nPRESS 4 FOR SURGEON"<<endl;
            cin>>flag;
            switch(flag)
            {
            case 1:
                printDept();
                cin>>d;
                doctor::searchD_ID(d,flag);
                k=1;
                break;
            case 2:
                printDept();
                cin>>d;
                doctor::searchD_ID(d,flag);
                k=1;
                break;
            case 3:
                printDept();
                cin>>d;
                doctor::searchD_ID(d,flag);
                k=1;
                break;
            case 4:
                printDept();
                cin>>d;
                doctor::searchD_ID(d,flag);
                k=1;
                break;
            default:
                cout << "\nUnknown command\n";
                system("pause");
                break;
            }

            break;


        }
    }
    return 0;
}
