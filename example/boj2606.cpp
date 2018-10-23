//바이러스
//to find out the group, make a connection with MAP stl
//insert to queue to visit same group (BFS)

#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int qurey;
    cin >> qurey;
    int count = 0;
    
    
    map<int, vector<int>, less<int> > data;
    
    vector<int> visited(N+1, 0);
    
    int input1, input2;
    for(int i = 0; i < qurey; ++i)
    {
        cin >> input1 >> input2;
        data[input1].push_back(input2);
        data[input2].push_back(input1);
    }
    count = 0;
    queue<int> que;
    que.push(1);
    visited[1]++;
    while(1)
    {
        if(que.empty())
            break;
        vector<int>::iterator it;
        int num = que.front();
        for(it = data[num].begin(); it != data[num].end(); it++)
        {
            if(visited[*it] == 0)
            {
                que.push(*it);
                visited[*it] = 1;
                count++;
            }
        }
        que.pop();
    }
    cout << count;

    return 0;
}
