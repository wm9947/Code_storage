#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    vector<int> data(9, 0);
    for(int i = 0; i<9; i++)
    {
        cin >> data[i];
    }
    vector<int> set(7, 1);
    for(int i=0; i<2; ++i)
        set.push_back(0);
    sort(data.begin(), data.end());
    sort(set.begin(), set.end());
    
    do{
        int sum = 0;
        for(int i = 0; i< 9; ++i)
        {
            if(set[i] == 1)
                sum += data[i];
        }
        if(sum == 100)
        {
            for(int i = 0; i< 9; ++i)
            {
                if(set[i] == 1)
                    cout << data[i] << "\n";
            }
            break;
        }
    }while(next_permutation(set.begin(), set.end()));
    return 0;
}
