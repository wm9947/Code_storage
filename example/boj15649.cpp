#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<functional>
using namespace std;
int main()
{
    int n, m;
    cin >> n >>m;
    vector<int> data;
    vector<int> check(m, 1);
    for(int i = 0; i < n-m; ++i)
        check.push_back(0);
    sort(check.begin(), check.end());
    
    for(int i = 1; i <= n; ++i)
        data.push_back(i);
    
    set<string> result;
    
    do{
        vector<int> get;
        for(int i = 0; i < n; ++i)
        {
            if(check[i] == 1)
            {
                get.push_back(data[i]);
            }
        }
        do{
            string t = "";
            for(auto x: get)
            {
                t += to_string(x) + " ";
            }
            result.insert(t);
        }while(next_permutation(get.begin(), get.end()));
    }while(next_permutation(check.begin(), check.end()));
    for(auto x: result)
    {
        cout << x << endl;
    }
    return 0;
}
