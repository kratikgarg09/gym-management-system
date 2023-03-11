#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

class alogin
{
    string username;

public:
    int adlogin()
    {
        cout << "*** Enter UserName ***" << endl;
        cin >> username;

        if (username == "admin")
        {
            int p = getadpass();
            if (p == 1)
            {
                cout << "*** Login Successfull ***" << endl;
                return 1;
            }
        }
        else
        {
            cout << "*** Username Not Found ***" << endl;
            adlogin();
            cout << "login failed" << endl;
            return 0;
        }
        return 0;
    }
    int getadpass()
    {
        string pw;
        cout << "*** Enter The Password ***" << endl;
        cin >> pw;

        if (pw == "1234")
        {
            cout << "WELCOME!!" << endl;
            return 1;
        }
        else
        {
            cout << "entered password is incorrect" << endl;
            getadpass();
            return 0;
        }
        return 0;
    }
};

class member
{
    int l, fee;
    string memberName, membership, timings;
    long long int contact;
    void timeSlots()
    {

        int k;
        cout << "please select your preferred timings\npress 1 for: morning 6-7\npress 2 for: morning 7-8\npress 3 for: morning 8-9\n";
        cout << "press 4 for: evening 4-5\npress 5 for: evening 5-6\npress 6 for: evening 6-7\n";
        cin >> k;
        switch (k)
        {
        case 1:
            timings = "6AM-7AM";
            cout << "Your timing is :" << timings << endl;
            break;
        case 2:
            timings = "7AM-8AM";
            cout << "Your timing is :" << timings << "Be motivated and consistent" << endl;
            break;
        case 3:
            timings = "8AM-9AM";
            cout << "Your timing is :" << timings << "Be motivated and consistent" << endl;
            break;
        case 4:
            timings = "4PM-5PM";
            cout << "Your timing is :" << timings << "Be motivated and consistent" << endl;
            break;
        case 5:
            timings = "5PM-6PM";
            cout << "Your timing is :" << timings << "Be motivated and consistent" << endl;
            break;
        case 6:
            timings = "6PM-7PM";
            cout << "Your timing is :" << timings << "Be motivated and consistent" << endl;
            break;
        }
    }

public:
    void createMember()
    {
        int ms;
        string str;
        cout << "Enter the name of member" << endl;
        getline(cin >> ws, str);
        memberName = str;

        cout << "Welcome " << memberName << endl;

        cout << "Enter contact number" << endl;
        cin >> contact;

        cout << "Enter the type of membership" << endl;
        cout << "Press 1 for Gold membership" << endl;
        cout << "Press 2 for Silver membership" << endl;
        cout << "Press 3 for Bronze membership" << endl;
        cin >> ms;
        switch (ms)
        {
        case 1:
        {
            membership = "Gold";
            fee = 3000;
            cout << membership << endl;
            cout << "Your monthly fee would be 3000 Rs." << endl;
            // l = trainee_allotment(membership);
        }
        break;
        case 2:
        {
            membership = "Silver";
            fee = 2000;
            cout << "your monthly fee would be: " << fee << endl;
            // l = trainee_allotment(membership);
        }
        break;
        case 3:
        {
            membership = "Bronze";
            fee = 1000;
            cout << "your monthly fee would be: " << fee << endl
                 << endl;
            // l = trainee_allotment(membership);
        }
        break;
        }
        timeSlots();
    }
    void showMember()
    {
        cout << endl
             << "Name: " << memberName;
        cout << endl
             << "category: " << membership;
        cout << endl
             << "fee: " << fee;
        cout << endl
             << "contact: " << contact;
        cout << endl
             << "timings: " << timings << endl;
    }

    string getName()
    {
        return memberName;
    }

    string getmembership()
    {
        return membership;
    }

    string getTimings()
    {
        return timings;
    }

    int getFee()
    {
        return fee;
    }

    long long int getContact()
    {
        return contact;
    }
};
fstream fp;
member m1;
void save_member()
{
    fp.open("newdata2.dat", ios::out | ios::app);
    m1.createMember();
    fp.write((char *)&m1, sizeof(m1));
    fp.close();
    cout << endl
         << endl
         << "the member has been succesfully added...";
    getchar();
}

void show_all()
{
    system("cls");
    cout << endl
         << "**** RECORDS... ****";
    fp.open("newdata2.dat", ios::in);
    while (fp.read((char *)&m1, sizeof(m1)))
    {
        m1.showMember();
        getchar();
    }
    fp.close();
}

void display_record(string str)
{
    bool found = false;
    fp.open("newdata2.dat", ios::in);
    while (fp.read((char *)&m1, sizeof(m1)))
    {
        if (m1.getName() == str)
        {
            system("cls");
            m1.showMember();
            found = true;
        }
    }
    fp.close();
    if (found == false)
        cout << "\n\nNo record found";
    getchar();
}

void edit_member()
{
    string str;
    bool found = false;
    system("cls");
    cout << endl
         << endl
         << "\tPlease Enter The Member Name: ";
    getline(cin >> ws, str);
    fp.open("newdata2.dat", ios::in | ios::out);

    while (fp.read((char *)&m1, sizeof(m1)) && found == false)
    {
        m1.showMember();
        if (m1.getName() == str)
        {
            m1.showMember();
            cout << "\nPlease Enter The New details of the member: " << endl;
            m1.createMember();
            int pos = 1 * sizeof(m1);
            fp.seekp(pos, ios::cur);
            fp.write((char *)&m1, sizeof(m1));
            cout << endl
                 << endl
                 << "\t Record Successfully Updated...";
            found = true;
        }
    }
    fp.close();
    if (found == false)
        cout << endl
             << endl
             << "Record Not Found...";
    getchar();
}

void delete_member()
{
    string str;
    system("cls");
    cout << endl
         << endl
         << "Please Enter The Member Name: ";
    getline(cin >> ws, str);
    fp.open("newdata2.dat", ios::in | ios::out);
    fstream fp2;
    fp2.open("Temp2.dat", ios::out);
    fp.seekg(0, ios::beg);
    while (fp.read((char *)&m1, sizeof(m1)))
    {
        if (m1.getName() != str)
        {
            fp2.write((char *)&m1, sizeof(m1));
        }
    }
    fp2.close();
    fp.close();
    remove("newdata2.dat");
    rename("Temp2.dat", "newdata2.dat");
    cout << endl
         << endl
         << "\tRecord Deleted...";
    getchar();
}

void fitness()
{
    char ch;
    system("cls");
    cout << "displaying fitness tips..." << endl;
    fp.open("tips.txt", fstream ::in);

    while (fp >> noskipws >> ch)
        cout << ch;
    fp.close();
    cout << endl;
}

void fnManage()
{
    
    system("cls");
    int option;
    member m1;
    cout << "\t***********************************************";
    cout << "\n\tPress 1 for CREATE MEMBER";
    cout << "\n\tPress 2 for DISPLAY ALL RECORDS";
    cout << "\n\tPress 3 for SEARCH FOR A PARTICULAR RECORD ";
    cout << "\n\tPress 4 for EDIT MEMBER DETAILS";
    cout << "\n\tPress 5 for DELETE MEMBER";
    cout << "\n\tPress 6 for fitness tips...";
    cout << "\n\tPress 7 for GO BACK TO MAIN MENU";
    cout << "\n\t**********************************************";
    cout << "\n\n\tOption: ";
    cin >> option;
    switch (option)
    {
    case 1:
    {
        system("cls");
        save_member();
        cout <<endl << endl<< "If you want to go to main menu press 1" << endl;
        int v;
        cin >> v;
        if (v == 1)
        {
            fnManage();
        }
        else{
            break;
        }
    }
    break;

    case 2:
    {
        show_all();
        cout <<endl << endl<< "If you want to go to main menu press 1" << endl;
        int v;
        cin >> v;
        if (v == 1)
        {
            fnManage();
        }
        else{
            break;
        }
    }
    break;

    case 3:
    {
        system("cls");
        string st;
        cout << "\n\n\tPlease Enter The member Name: ";
        getline(cin >> ws, st);
        display_record(st);
        cout <<endl << endl<< "If you want to go to main menu press 1" << endl;
        int v;
        cin >> v;
        if (v == 1)
        {
            fnManage();
        }
        else{
            break;
        }
    }
    break;

    case 4:
    {
        edit_member();
        cout <<endl << endl<< "If you want to go to main menu press 1" << endl;
        int v;
        cin >> v;
        if (v == 1)
        {
            fnManage();
        }
        else{
            break;
        }
    }
    break;

    case 5:
    {
        delete_member();
        cout <<endl << endl<< "If you want to go to main menu press 1" << endl;
        int v;
        cin >> v;
        if (v == 1)
        {
            fnManage();
        }
        else{
            break;
        }
    }
    break;

    case 6:
    {
        fitness();
        cout <<endl << endl<< "If you want to go to main menu press 1" << endl;
        int v;
        cin >> v;
        if (v == 1)
        {
            fnManage();
        }
        else{
            break;
        }
    }
    break;

    case 7:
    {
        system("cls");
        fnManage();
    }
    break;

    default:
        fnManage();
    }
}

int main()
{
    int k;
    alogin ad;
    k = ad.adlogin();
    system("cls");

    if (k == 1)
    {
        fnManage();
    }

    return 0;
}