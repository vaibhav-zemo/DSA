#include <iostream>
using namespace std;

class student
{
public:
    int age;
    string name;

    static int rollno;

    student(int age, string name)
    {
        this->age = age;
        this->name = name;
        rollno++;
    }

    void getinfo()
    {
        cout << age << " " << name << endl;
    }
};

int student ::rollno = 0;

int main()
{
    student s1(32, "Vaibhav"), s2(23, "Pathak");
    s1.getinfo();
    cout << student::rollno;

    return 0;
}