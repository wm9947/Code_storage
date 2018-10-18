#include<iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    
    int result = N;
    int count = 0;
    while(1)
    {
        int data[2];
        if(result < 10)
        {
            data[0] = 0;
            data[1] = result;
        }
        else
        {
            data[1] = result % 10;
            data[0] = result / 10;
        }
        result = data[1]*10 + (data[0]+data[1]) % 10;
        count++;
        
        if(result == N)
            break;
    }
    cout << count;
    return 0;
}
