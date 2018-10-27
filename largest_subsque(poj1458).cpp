#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string a, b;
    while(cin >> a >> b) {
        vector<vector<int>> res(a.size() + 1, vector<int>(b.size() + 1, 0));
        
        for(int i = 0; i < a.size(); i++)
        {
            
            for(int j = 0; j < b.size(); j++)
            {
                
                if (a[i] == b[j]) {
                    res[i+1][j+1] = res[i][j] + 1;
                }1
                else
                {
                    res[i+1][j+1] = max(res[i+1][j], res[i][j+1]);
                }
            }
            
        }
        cout << res[a.size()][b.size()] << endl;
    }
    return 0;
}