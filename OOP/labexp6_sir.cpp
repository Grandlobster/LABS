#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class student{
    public:
        int rollno;
        string name;
        char mob[20];
        bool operator == (const student &student1){
            return (rollno == student1.rollno);
        }
        friend ostream &operator<<(ostream &in, const student &k);
        friend istream &operator>>(istream &in, student &k);
};

ostream &operator<<(ostream &out, const student &k){
    out << "\n" << k.rollno << "\t\t" << k.name << "\t\t" << k.mob;
    return out;
}

istream &operator>>(istream &in, student &k){
    cout << "\nEnter Roll No.: ";
    in >> k.rollno;
    cout << "\nEnter Name: ";
    in >> k.name;
    cout << "\nEnter mob no.: ";
    in >> k.mob;
    return in;
}

vector<student> read(){
    int n;
    student k;
    vector<student> j;

    cout << " \nEnter total no of students: ";
    std::cin >> n;

    for (int i = 0; i < n; i++){
        std::cin >> k;
        j.push_back(k);
    }
    return j;
}

void printfunction(const student &k){
    cout << k;
}

void print(const vector<student> &j){
    cout << "\n\t Roll no \t Name\t\t mobile Number";
    for_each(j.begin(), j.end(), printfunction);
}

void search(vector<student> &j){
    student k;

    cout << "\nEnter student roll no to search: ";
    cin >> k.rollno;
    cout << "\n\n\t\t Roll No\t\t Name\t\t Date of Birth";
    vector<student>::iterator p;
    
    p = find(j.begin(), j.end(), k);

    if (p != j.end())
        cout << *p;

    else
        cout << "\nNot found";
}

bool sort_func(const student &x, const student &y){
    return (x.rollno < y.rollno);
}

void sort(vector<student> &j){
    sort(j.begin(), j.end(), sort_func);
}

int main(){
    vector<student> s;
    int ch;

    do
    {

        cout << "\n\n\t\t * Personal Record Database *";
        cout << "\n 1. Create Record";
        cout << "\n 2. Display Record";
        cout << "\n 3. Search Record";
        cout << "\n 4. Sort Record";
        cout << "\n 5. Quit menu";
        cout << "\n------------------------------";
        cout << "\n Enter your choice:";
        cin >> ch;

        switch (ch){
            case 1:
                s = read();
                break;
            
            case 2:
                print(s);
                break;

            case 3:
                search(s);
                break;

            case 4:
                sort(s);
                print(s);
                break;
        }

    } while (ch!=5);
    return 0;
}
