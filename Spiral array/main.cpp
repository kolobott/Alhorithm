#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(const vector<vector<int> > &A)
{
    vector<int> result;
    int top = 0;
    int right = A[0].size() - 1;
    int left = 0;
    int bottom = A.size() - 1;
    int direction = 0;
    while( top <= bottom  && left <= right)
    {
        if(direction == 0)
        {
            for( int i = left; i <= right; i++ )
            {
                result.push_back(A[top][i]);
            }
            top++;
        }
        else if(direction == 1)
        {
            for( int i = top; i <= bottom; i++ )
            {
                result.push_back(A[i][right]);
            }
            right--;
        }
        else if(direction == 2)
        {
            for( int i = right; i >= left; i-- )
            {
                result.push_back(A[bottom][i]);
            }
            bottom--;
        }
        else if(direction == 3)
        {
            for( int i = bottom; i >= top; i-- )
            {
                result.push_back(A[i][left]);
            }
            left++;
        }
        direction = (direction+1)%4;

    }
    return result;
}
int main()
{
    vector<vector<int> > A;
    vector<int> result;
    A.resize(3);
    A[0].push_back(1);
    A[1].push_back(2);
    A[2].push_back(3);
    result = spiralOrder(A);
    for( int i = 0; i < result.size(); i++ )
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}
