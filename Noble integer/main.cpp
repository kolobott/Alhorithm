#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>


using namespace std;


int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int main()
{
    vector<int> integers;
    integers.push_back(2);
    integers.push_back(1);
    integers.push_back(3);
    integers.push_back(2);
    integers.push_back(5);
    integers.push_back(10);
    integers.push_back(6);
    integers.push_back(7);
    integers.push_back(9);
    integers.push_back(7);
    sort(integers.begin(), integers.end());
    for(int i = 0; i < integers.size() - 1; i++)
    {
        if(integers[i] == integers[i+1])
            continue;
        if(integers[i] == integers.size() - i - 1)
        {
            cout<<"Finded noble integer.";
            return 0;
        }
    }
    if(integers[integers.size() - 1] == 0)
    {
        cout<<"Finded noble integer.";
        return 0;
    }

    cout<<"Haven\'t finded noble integer"<<endl;
    return 0;
}
