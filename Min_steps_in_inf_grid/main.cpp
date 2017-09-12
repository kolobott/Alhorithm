#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;


// Proffesional's solution
int coverPoints(vector<int> x, vector<int> y) {
            if (x.size() <= 1) return 0;
            assert(x.size() == y.size());
            int ans = 0;
            for (int i = 1; i < x.size(); i++) {
                ans += max(abs(x[i] - x[i-1]), abs(y[i] - y[i-1]));
            }
            return ans;
}


// My solution
int main()
{
    vector<int> X(11);
    vector<int> Y(11);
    X[0] = -15;
    X[1] = 6;
    X[2] = -5;
    X[3] = -2;
    X[4] = 5;
    X[5] = -5;
    X[6] = -12;
    X[7] = -7;
    X[8] = 8;
    X[9] = 11;
    X[10] = -5;
    Y[0] = -11;
    Y[1] = 5;
    Y[2] = 4;
    Y[3] = -13;
    Y[4] = -11;
    Y[5] = 4;
    Y[6] = 7;
    Y[7] = 14;
    Y[8] = -4;
    Y[9] = -15;
    Y[10] = 4;
    int x = X[0];
    int y = Y[0];
    int steps = 0;
    int i = 1;
    while( x != X[X.size() - 1] || y != Y[Y.size() -1] || i != X.size())
    {
         if ( x == X[i] )
         {
            if( y < Y[i] )
            {

                steps += abs(Y[i] - y);
                y = Y[i];
                cout<<x<<" "<<y<<" "<<steps<<endl;

            }
            else
            {

                steps += abs(y - Y[i]);
                y = Y[i];
                cout<<x<<" "<<y<<" "<<steps<<endl;
            }
            i++;

         }
         else if ( y == Y[i])
         {
            if( x < X[i] )
            {

                steps += abs(X[i] - x);
                x=X[i];
                cout<<x<<" "<<y<<" "<<steps<<endl;
            }
            else
            {

                steps+=abs(x - X[i]);
                x=X[i];
                cout<<x<<" "<<y<<" "<<steps<<endl;
            }
            i++;
         }
         else
         {
            if( x < X[i] && y < Y[i])
            {
                if( abs(X[i] - x) < abs( Y[i] - y) )
                {
                    steps += abs(X[i] - x);
                     y += abs(X[i] - x);
                    x = X[i];

                }
                else
                {
                    steps += abs(Y[i] - y);
                    x += abs(Y[i] - y);
                    y = Y[i];

                }
               cout<<x<<" "<<y<<" "<<steps<<endl;
            }
            else if ( x < X[i] && y > Y[i] )
            {
                if( abs(X[i] - x) < abs(y - Y[i]))
                {
                    steps += abs(X[i] - x);
                    y -= abs(X[i] - x);
                    x = X[i];

                }
                else
                {
                    steps += abs(y - Y[i]);
                    x += abs(y - Y[i]);
                    y = Y[i];

                }

                cout<<x<<" "<<y<<" "<<steps<<endl;
            }
            else if( x > X[i] && y > Y[i] )
            {
                if( abs(x - X[i]) < abs( y - Y[i]) )
                {
                    steps += abs(x - X[i]);
                     y -= abs(x - X[i]);
                    x = X[i];

                }
                else
                {
                    steps += abs(y - Y[i]);
                     x -= abs(y - Y[i]);
                    y = Y[i];

                }

                cout<<x<<" "<<y<<" "<<steps<<endl;
            }
            else
            {
                if( abs(x - X[i]) < abs(Y[i] - y))
                {
                    steps += abs(x - X[i]);
                    y += abs(x - X[i]);
                    x = X[i];

                }
                else
                {
                    steps += abs(Y[i] - y);
                    x -= abs(Y[i] - y);
                    y = Y[i];

                }

                cout<<x<<" "<<y<<" "<<steps<<endl;
            }
         }
    }
    cout<<steps<<endl;
    return 0;
}
