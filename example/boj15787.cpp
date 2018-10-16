//To improve this code
// use bit operator
#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;
class Data{
public:
    vector<bool> sit;
    Data()
    {
        for(int i=0; i < 20; ++i)
            sit.push_back(false);
    }
    void pushR()
    {
        sit.insert(sit.begin(), false);
        sit.erase(sit.end()-1);
    }
    void pushL()
    {
        sit.push_back(false);
        sit.erase(sit.begin());
    }
    void in(int pos)
    {
        sit[pos-1] = true;
    }
    void out(int pos)
    {
        sit[pos-1] = false;
    }
};
int main()
{
    int NT, NF;
    cin >> NT >> NF;
    
    map<int, Data> list;
    int order, num, nsit;
    for(int i = 0; i < NF; ++i)
    {
        cin >> order;
        if(order <=2)
        {
            cin >> num >> nsit;
            if(order == 1)
            {
                list[num].in(nsit);
            }
            else
            {
                list[num].out(nsit);
            }
        }
        else{
            cin >> num;
            if(order == 3)
            {
                list[num].pushR();
            }
            else
            {
                list[num].pushL();
            }
        }
    }
    
    set<vector<bool>> result;
    for(auto x: list)
    {
        result.insert(x.second.sit);
    }
    vector<bool> empty_(20, false);
    
    if(list.size() < NT)
        result.insert(empty_);

    cout << result.size() << endl;
    
    
    return 0;
}
