#include <iostream>
#include <cmath>
#include <vector>


using namespace std;


//Professional's solution
vector<int> maxset(vector<int> Vec) {
        int N = Vec.size();

        long long mx_sum = 0;
        long long cur_sum = 0;
        int mx_range_left = -1;
        int mx_range_right = -1;
        int cur_range_left = 0;
        int cur_range_right = 0;

        while(cur_range_right < N) {
            if(Vec[cur_range_right] < 0) {
                cur_range_left = cur_range_right + 1;
                cur_sum = 0;
            } else {
                cur_sum += (long long)Vec[cur_range_right];
                if(cur_sum > mx_sum) {
                    mx_sum = cur_sum;
                    mx_range_left = cur_range_left;
                    mx_range_right = cur_range_right + 1;
                } else if(cur_sum == mx_sum) {
                    if(cur_range_right + 1 - cur_range_left > mx_range_right - mx_range_left) {
                        mx_range_left = cur_range_left;
                        mx_range_right = cur_range_right + 1;
                    }
                }
            }
            cur_range_right++;
        }
        vector<int> ans;
        if(mx_range_left == -1 || mx_range_right == -1)
                return ans;

        for(int i = mx_range_left; i < mx_range_right; ++i)
                ans.push_back(Vec[i]);
        return ans;
}
// My Solution
int main()
{
    vector<int> A;
    vector<int> result;
    vector<int> result1;
    long long sum = 0;
    long long sum2 = sum;
    A.push_back(15);
    A.push_back(15);
    A.push_back(-3);
    A.push_back(-1);
    A.push_back(3);
    A.push_back(-4);
    A.push_back(10);
    A.push_back(20);
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] >= 0)
        {
            sum += A[i];
            result.push_back(A[i]);
        }
        else
        {
            if( sum > sum2)
            {
                sum2 = sum;
                result1.resize(result.size());
                result1 = result;
                result.resize(0);
                sum = 0;
            }
            else if ( sum == sum2)
            {
                if( result.size() > result1.size())
                {
                    result1.resize(result.size());
                    result1 = result;

                }
                sum = 0;
                result.resize(0);
            }
            else
            {
                sum = 0;
                result.resize(0);
            }
        }
    }
    if(sum > sum2)
    {
        result1.resize(result.size());
        result1 = result;
        result.resize(0);
        sum = 0;
    }
    else if ( sum == sum2)
    {
        if( result.size() > result1.size())
        {
            result1.resize(result.size());
            result1 = result;

        }
        sum = 0;
        result.resize(0);
    }
    for(int i = 0; i < result1.size(); i++)
    {
        cout<<result1[i]<<" ";
    }
    cout<<endl;
    return 0;
}
