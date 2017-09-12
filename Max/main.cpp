#include <iostream>

using namespace std;



int sign( int x )
{
    return x >> 31;
}
int myMax( int a, int b)
{
    int t[2];
    t[0] = a;
    t[1] = b;
    return t[sign(a - b) * -1];
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "Max = " << myMax(a, b) << endl;
    return 0;
}
