#include <iostream>
using namespace std;

template <typename T, typename V>  // we use templete so that we don't have to make another class for different data type

class Pair
{
    T x;
    V y;

public:
    void setX(T x)
    {
        this->x = x;
    }
    void setY(V y)
    {
        this->y = y;
    }

    T getX()
    {
        return x;
    }
    V getY()
    {
        return y;
    }
};

int main()
{
    Pair<Pair<int, double>, char> p;
    p.setY('c');

    Pair<int, double> p2;
    p2.setX(23);
    p2.setY(26.34);

    p.setX(p2);

    cout<<p.getX().getX()<<" "<<p.getX().getY()<<" "<<p.getY()<<endl;

    return 0;
}