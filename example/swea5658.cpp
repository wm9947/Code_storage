//보물상자 비밀번호
// name of variable is quite messy
// first time I tried to use sort for the oreder password data to find out target data
// use set<string, greater<string> > can make order as I wanted
//
#include<set>
#include<iostream>
#include<vector>
#include<algorithm>
#include <queue>
#include <functional>
#include <stack>
using namespace std;
int main()
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int num;
        int target_k;
        
        cin >> num >> target_k;
        
        string O_data = "";
        cin >> O_data;
        set<string, greater<string>> s_list;
        string data = O_data;
        queue<char> Oque;
        for(auto x: data)
        {
            Oque.push(x);
        }
        queue<char> que = Oque;
        string compare = "";

        do{
            compare = "";
            queue<char> nextque = que;
            while(!que.empty())
            {
                string temp = "";
                for(int i = 0; i < num/4; ++i)
                {
                    temp += que.front();
                    que.pop();
                }
                compare += temp;
                s_list.insert(temp);
            }
            nextque.push(nextque.front());
            nextque.pop();
            que = nextque;

        }while(que != Oque);
        
        int count = 1;
        long result = 0;
        stack<char> sta;
        for(auto x: s_list)
        {
            if(count == target_k)
            {
                for(auto y: x)
                {
                    sta.push(y);
                }
                break;
            }
            count++;
        }
        int cal = 1;
        while(!sta.empty())
        {
            int temp = 0;
            if(sta.top() >= 'A')
            {
                temp = sta.top() - 'A' + 10;
            }
            else
            {
                temp = sta.top() - '0';
            }
            result += temp * cal;
            cal *= 16;
            sta.pop();
        }
        cout << "#" << test_case << " " << result << endl;
    }
    return 0;
}
