#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    string name, dob, bloodGroup, address, yearClass, mobile;
    int *rollNo;
    int division;

public:
    friend class Faculty;

    Student()
    {
        rollNo = new int;
        *rollNo = 1;
        division = 1;
        name = bloodGroup = dob = address = yearClass = mobile = "";
    }

    ~Student()
    {
        delete rollNo;
    }

    void add()
    {
        cout << "\nEnter Student Information: ";
        cout << "\nEnter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Roll number: ";
        cin >> *rollNo;
        cout << "Enter Year (SE/TE/BE): ";
        cin >> yearClass;
        cout << "Enter Division (1/2/3/4): ";
        cin >> division;
        cout << "Enter Date of Birth: ";
        cin >> dob;
        cout << "Enter Blood Group: ";
        cin >> bloodGroup;
        cout << "Enter Mobile number: ";
        cin >> mobile;
        cout << "Enter address: ";
        cin >> address;
    }

    void display()
    {
        cout << "\n-------------------------------------------" << endl;
        cout << "\nName                      : " << name;
        cout << "\nRoll No.                  : " << *rollNo;
        cout << "\nYear (SE/TE/BE)           : " << yearClass;
        cout << "\nDivision (1/2/3/4)        : " << division;
        cout << "\nDate of Birth             : " << dob;
        cout << "\nBlood Group               : " << bloodGroup;
        cout << "\nMobile Number             : " << mobile;
        cout << "\nAddress                   : " << address;
        cout << "\n-------------------------------------------" << endl;
    }

    static void header()
    {
        cout << "\n* * * Student Information System * * *\n";
    }
};

class Faculty
{
private:
    int id;

public:
    Faculty()
    {
        id = 0;
    }

    Faculty(const Faculty &f1)
    {
        id = f1.id;
    }

    void display(Student &obj, int f_d)
    {
        try
        {
            if (obj.division == f_d)
            {
                obj.display();
            }
            else
            {
                throw(obj.division);
            }
        }
        catch (int x)
        {
            cout << "\nInvalid Division: You are not teaching to this division." << endl;
        }
    }
};

int main()
{
    Student st[5];
    Faculty f;
    int ch = 0, count = 0;

    do
    {
        cout << "\n* * * * Student Information System * * * *\n";
        cout << "\n* * * Menu * * *\n";
        cout << "1. Add Information\n";
        cout << "2. Display Information\n";
        cout << "3. Faculty wise Information\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            st[count].add();
            count++;
            break;

        case 2:
            for (int j = 0; j < count; j++)
            {
                Student::header();
                st[j].display();
            }
            break;

        case 3:
            int f_div;
            cout << "\nEnter Division of faculty: ";
            cin >> f_div;
            for (int j = 0; j < count; j++)
            {
                cout << "\n* * * Student Information System (Faculty RAK) * * *\n";
                f.display(st[j], f_div);
            }
            break;

        case 4:
            exit(0);
            break;
        }
    } while (ch != 4);

    return 0;
}
