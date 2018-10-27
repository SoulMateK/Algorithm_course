#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int sz, num = 0; 
    cin >> sz;
    vector<vector<int>> arr(sz+1, vector<int>(sz, 0));
    while(num < sz * sz) {
        cin >> arr[num/sz+1][num%sz];
        num++;
    }
    
    for(int i = 2; i <= sz; i++)
    {
        for(int j = 0; j < sz; j++)
        {
            arr[i][j] = arr[i][j] + arr[i-1][j];
        }   
    }

    int res, flag = 1;
    
    for(int i = 0; i < sz; i++)
    {
        for(int j = i+1; j <= sz; j++)
        {
            int temp = 0, sum = 0;
            for(int k = 0; k < sz; k++)
            {
                sum += arr[j][k] - arr[i][k];
                temp = max(temp, sum);
                sum = max(sum, 0);
            }
            
            if (flag) {
                res = temp;
                flag = 0;
            }
            else
            {
                if (temp > res) res = temp;
            }
            
        }
    }
    cout << res;
    return 0;
}
