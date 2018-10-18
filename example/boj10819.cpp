#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> data(N,0);
    for(int i=0; i<N; i++)
    {
        cin >> data[i];
    }
    sort(data.begin(), data.end()); //next_permutation: should use after data has sorted.
    int max = 0;
    do{
        int sum = 0;
        for(int i = 0; i < N-1; ++i)
        {
            sum+= abs(data[i] - data[i+1]);
        }
        if(max < sum)
            max = sum;
    }while(next_permutation(data.begin(), data.end()));
    cout << max;
    return 0;
}
