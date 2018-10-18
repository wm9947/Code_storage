#include<iostream>
#include<vector>
using namespace std;
enum{empty = '.', load = 'X'};

int main()
{
    int N;
    cin >> N;
    vector<vector<char> > data(N+2, vector<char>(N+2, 1));
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= N; ++j)
        {
            cin >> data[i][j];
        }
    }
    int result = 0;
    for(int i = 1; i <= N; ++i)
    {
        int count = 0;
        for(int j = 1; j <= N+1; ++j)
        {
            if(data[i][j] == empty)
                count++;
            else if(data[i][j] == load)
            {
                if(count >= 2)
                    result++;
                count = 0;
            }
        }
        if(count >= 2)
            result++;
    }
    cout << result << " ";
    result = 0;
    for(int i = 1; i <= N+1; ++i)
    {
        int count = 0;
        for(int j = 1; j <= N; ++j)
        {
            if(data[j][i] == empty)
                count++;
            else if(data[j][i] == load)
            {
                if(count >= 2)
                    result++;
                count = 0;
            }
        }
        if(count >= 2)
            result++;
    }
    cout << result;
    return 0;
}
