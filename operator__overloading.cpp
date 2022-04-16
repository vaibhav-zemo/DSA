#include <iostream>
using namespace std;

class fraction
{
private:
    int num;
    int demo;

public:
    fraction(int num, int demo)
    {
        this->num = num;
        this->demo = demo;
    }

    void getinfo() const
    {
        cout << num << " " << demo << endl;
    }

    void simplify()
    {
        for (int i = this->demo; i >= 2; i--)
        {
            if (this->num % i == 0 && this->demo % i == 0)
            {
                this->num /= i;
                this->demo /= i;
            }
        }
    }

    fraction operator+(fraction &f)
    {
        int demo_ans = this->demo * f.demo;
        int num_ans = this->num * f.demo + f.num * this->demo;
        fraction fnew(num_ans, demo_ans);
        fnew.simplify();
        return fnew;
    }

    fraction operator*(fraction &f)
    {
        int demo_ans = this->demo * f.demo;
        int num_ans = this->num * f.num;
        fraction fn(num_ans, demo_ans);
        fn.simplify();
        return fn;
    }

    fraction &operator++()
    {
        this->num += this->demo;
        simplify();
        return *this;
    }

    fraction operator++(int)
    {
        fraction fn(this->num,this->demo);
        this->num += this->demo;
        simplify();
        return fn;
    }

    fraction &operator+=(fraction &f)
    {
        this->num = this->num * f.demo + f.num * this->demo;
        this->demo = this->demo * f.demo;
        // this->demo = demo_ans;
        // this->num = num_ans;
        simplify();
        return *this;
    }
};

int main()
{
    fraction f1(10, 2), f2(2, 10);
    f1.getinfo();
    f2.getinfo();
    fraction f3 = f1++;
    f1.getinfo();
    f3.getinfo();

    return 0;
}