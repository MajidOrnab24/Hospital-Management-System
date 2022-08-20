#include<iostream>
#include <stdio.h>
#include<conio.h>
#include <typeinfo>
#include <string.h>
#include<string>
#include <vector>
using namespace std;
const int MAXM = 1000;
const int len= 32;
const int MAX = 100;
enum patient_type {p_p,p_e,p_i,p_s};
using namespace std;
enum IN
{
    IN_BACK = 8,
    IN_RET = 13
};
string takePasswdFromUser(char asterisk = '*')
{
    string password= "";
    char c_input;
    while (true)
    {
        c_input = _getch();
        if (c_input == IN::IN_RET)
        {
            cout << endl;
            return password;
        }
        else if (c_input == IN::IN_BACK && password.length() != 0)
        {
            password.pop_back();
            cout << "\b \b";
            continue;
        }
        else if (c_input == IN::IN_BACK && password.length() == 0)
        {
            continue;
        }
        password.push_back(c_input);
        cout << asterisk;
    }
}
enum bloodgrp_type
{
    A_pos,
    A_neg,
    B_pos,
    B_neg,
    AB_pos,
    AB_neg,
    o_pos,
    o_neg
};
typedef char option2[32];
option2 bloodgrp[]=
{
    "A+",
    "A-",
    "B+",
    "B-",
    "AB+",
    "AB-",
    "O+",
    "O-"
};
enum deptartment_no
{
    Cardiology,
    Medicine,
    Surgery,
    Neurosurgery,
    ENT,
    Darmatology,
    Paediatrics,
    Gynaecology,
    Nephrology,
    Orthopaedic,
    Neurology,
    Endocrinology
};
typedef char option[32];
option deptartment[]=
{
    "Cardiology",
    "Medicine",
    "Surgery",
    "Neurosurgery",
    "ENT",
    "Darmatology",
    "Paediatrics",
    "Gynaecology",
    "Nephrology",
    "Orthopaedic",
    "Neurology",
    "Endocrinology"
};
typedef char option3[32];
option3 week[]=
{
    "Saturday",
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday"
};
typedef char option4[32];
option4 timeslot[]=
{
    "10:00 AM",
    "10:20 AM",
    "10:40 AM",
    "11:00 AM",
    "11:20 AM",
    "11:40 AM",
    "12:00 PM",
    "12:20 PM",
    "12:40 PM",
    "06:00 PM",
    "06:20 PM",
    "06:40 PM",
    "07:00 PM",
    "07:20 PM",
    "07:40 PM",
    "08:00 PM",
    "08:20 PM",
    "08:40 PM"
};
typedef char option5[32];
option5 timeslot1[]=
{
    "09:00 AM",
    "10:00 AM",
    "11:00 AM",
    "12:00 PM",
    "01:00 PM",
    "02:00 PM",
    "03:00 PM",
    "04:00 PM",
    "05:00 PM",
    "06:00 PM",
    "07:00 PM",
    "08:00 PM",
};
typedef char option5[32];
option5 timeslot2[]=
{
    "09:00 PM",
    "10:00 PM",
    "11:00 PM",
    "12:00 AM",
    "01:00 AM",
    "02:00 AM",
    "03:00 AM",
    "04:00 AM",
    "05:00 AM",
    "06:00 AM",
    "07:00 AM",
    "08:00 AM",
};
class admin
{
private:
    char a_name[len],a_address[len],username[len],password[len];

public:
    admin() {};
    ~admin() {};
    int ad=0;
    int totalAmoney=0;
    void setAdata()
    {
        strncpy(a_name, "190041205 & 190041203", len);
        strncpy(a_address, "IUT,Boardbazar,Gazipur", len);
        strncpy( password, "hmspass", len);
        strncpy(username, "admin", len);
    }
    void showdata()
    {
        cout<<"Admin name: "<<a_name<<"\nAddress: "<<a_address<<endl;
    }
    void forgot()
    {
        char temp[len],temp2[len];
        cout<<"Enter New Username :";
        cin>>temp;
        strcpy(username,temp);
        cout<<"Enter New Passsword :";
        cin>>temp2;
        strcpy(password,temp2);
    }
    void verify()
    {
        int a,b,c;
        char temp[len],temp2[len];
        string input;
        while(true)
        {
            cout<<"*****************************************ADMIN PANEL****************************************************"<<endl;
            cout<<"Username : ";
            cin>>temp;
            a=strcmp(username,temp);
            cout<<"Password : ";
            input=takePasswdFromUser();
            strcpy(temp2, input.c_str());
            //cin>>temp2;
            b=strcmp(password,temp2);
            if(a==0&&b==0)
            {
                ad=1;
                break;
            }
            else
            {
                cout<<"Wrong username or password"<<endl;
                cout<<"Press 1 to try again\n"<<"Press 2 to return to mainmenu\n"<<"Press 3 to change Username & Password "<<endl;
                cin>>c;
                switch(c)
                {
                case 1:
                    cout<<"Try again please"<<endl;
                    system("cls");
                    break;
                case 2:
                    return;
                    break;
                case 3:
                    system("cls");
                    this->forgot();
                    break;
                }
            }
        }
    }
};
class patient
{
protected:
    char p_name[len],address[len],surgery[len],accident[len];
    int age;
    char blood_grp[len];
    char phone_no[len];
    static int pn;

public:
    patient() {};
    ~patient() {};
    int pWard=0,pBed=0;
    int totalPayment=0;
    static void setPcount(int);
    char dayName[len],timeslotName[len],currDoc[len];
    int d,t,patientID,DocterID;
    virtual patient_type get_Ptype();
    int labCount=0;
    char labTest[len][len];
    virtual void setP_data()
    {
        cout<<"\nEnter patient's name: ";
        cin.ignore();
        cin.getline(p_name,len);
        cout<<"Enter patient's address: ";
        cin.getline(address,len);
        cout<<"Enter patient's phone number: ";
        cin.getline(phone_no,len);
        cout<<"Enter patient's age: ";
        cin>>age;
        cout<<"Select Blood Group for patient: \n";
        for(int i=0; i<8; i++)
        {
            cout<<"Press  "<<i+1<<" for Blood Group :"<<bloodgrp[i]<<endl;
        }
        int a;
        cin>>a;
        strcpy(blood_grp,bloodgrp[a-1]);
        patientID=pn+1+190000;
        patient::pn++;
        cout<<"Enter Working day number of Doctor for Appintment: ";
        cin>>d;
        cout<<"Enter Timeslot for appointment: ";
        cin>>t;


    }
    virtual void showPdetails()
    {
        cout<<"\nPatient ID:"<<patientID<<"\nName: "<<p_name<<"\nAddress: "<<address<<"\nBlood Group:"<<blood_grp<<"\nPhone Number: "<<
            phone_no<<"\nAge: "<<age<<endl;
        if(labCount==0)
        {
            cout<<"No lab test done";
        }
        else
        {
            cout<<"Lab Test: ";
            for(int i=0; i<labCount; i++)
            {
                cout<<"\nName of Lab Test: "<<labTest[i];
            }
        }
        cout<<"\nCurrent Appointment:"<<"\nName: "<<currDoc<<"\nDoctor ID: "<<DocterID<<"\nAppointment Day: "<<dayName<<
            "\nTimeslot: "<<timeslotName<<endl;
    }
};
int patient::pn;
void patient::setPcount(int a)
{
    patient::pn=a;
}
class indoorPatient: public patient
{
protected:

public:
    indoorPatient() {};
    ~indoorPatient() {};
    void setP_data()
    {
        patient::setP_data();

    }
    void showPdetails()
    {
        patient::showPdetails();
        cout<<"Admitted to:-"<<endl;
        cout<<"Ward no: "<<pWard<<"  & Bed:"<<pBed<<endl;
    }


};
class regularPatient: public patient
{
protected:
public:
    regularPatient() {};
    ~regularPatient() {};
    void setP_data()
    {
        patient::setP_data();

    }


};
class emergencyPatient: public patient
{
protected:
public:
    emergencyPatient() {};
    ~emergencyPatient() {};
    void setP_data()
    {
        cout<<"Enter type of accident: ";
        cin.ignore();
        cin.getline(accident,len);
        patient::setP_data();

    }
    void showPdetails()
    {
        cout<<"Accident: "<<accident<<endl;
        patient::showPdetails();
    }

};
class forSurgeryPatient: public patient
{
protected:
public:
    forSurgeryPatient() {};
    ~forSurgeryPatient() {};
    void setP_data()
    {
        patient::setP_data();
        cout<<"Enter Name of surgery: ";
        cin.getline(surgery,len);
    }
    void showPdetails()
    {
        patient::showPdetails();
        cout<<"Surgery Name: "<<surgery<<endl;
    }

};
patient_type patient::get_Ptype()
{
    if( typeid(*this) == typeid(regularPatient) )
        return p_p;
    else if( typeid(*this)==typeid(emergencyPatient) )
        return p_e;
    else if( typeid(*this)==typeid(indoorPatient) )
        return p_i;
    else if( typeid(*this)==typeid(forSurgeryPatient) )
        return p_s;
    else
    {
        cerr << "\n Error patient type";
        exit(1);
    }
    return p_p;
};
