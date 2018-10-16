#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Pos{
public:
    int i, j, k;
};
int pi[6] = {0,0,0,0,-1,1};
int pk[6] = {0,0,1,-1,0,0};
int pj[6] = {1,-1,0,0,0,0};
int L, R, C;
Pos start;
Pos endp;

enum{S = 0, E=-1, wall=-10, load = 0};
int map[30][30][30]; // start: marked, end: -1, wall: -10,
bool check(int i, int j, int k)
{
    bool result = true;
    
    if(i < 0 || i >= L)
        result = false;
    if(j < 0 || j >= R)
        result = false;
    if(k < 0 || k >= C)
        result = false;
    
    if(result != false && map[i][j][k] == wall)
        result = false;

    return result;
    
}
int parsing(char x, int &i, int &j, int &k)
{
    int pas = -1;
    switch (x) {
        case '#':
            pas = wall;
            break;
        case '.':
            pas = load;
            break;
        case 'E':
            endp.i = i;
            endp.j = j;
            endp.k = k;
            pas = E;
            break;
        case 'S':
            start.i = i;
            start.j = j;
            start.k = k;
            pas = S;
            break;
        default:
            break;
    }
    return pas;
}
int main()
{
    while(1)
    {
        cin >> L >> R >> C; // floor, sizes
        
        if(L == 0 && R == 0 && C == 0)
            break;
        
        bool Trapped = false;
        char input;
        for(int i = 0; i < L; ++i)
        {
            for(int j = 0; j < R; ++j)
            {
                for(int k = 0; k<C; ++k)
                {
                    cin >> input;
                    map[i][j][k] = parsing(input, i, j, k);
                }
            }
        }
        int count = 0;
        for(int i = 0; i < 6; ++i)
        {
            if(check(endp.i + pi[i], endp.j + pj[i], endp.k + pk[i]))
                count++;
        }
        if(count == 6)
            Trapped = true;
        queue<Pos> que;
        
        count = 1;
        while(1)
        {
            if(map[endp.i][endp.j][endp.k] != E) //findout E
                break;
            if(Trapped)
                break;
            if(count != 1 && que.size() == 0)
                break;
                
            if(count == 1)
            {
                for(int i = 0; i < 6; ++i)
                {
                    int x = start.i + pi[i];
                    int y = start.j + pj[i];
                    int z = start.k + pk[i];
                    if(check(x, y, z) && (map[x][y][z] == load || map[x][y][z] == E))
                    {
                        map[x][y][z] = count;
                        Pos t;
                        t.i = x;
                        t.j = y;
                        t.k = z;
                        que.push(t);
                    }
                }
                count++;
            }
            
            if(que.size() == 0)
                continue;
            
            Pos F = que.front();
            que.pop();
            int step = map[F.i][F.j][F.k];
            step++;
            for(int i = 0; i < 6; ++i)
            {
                int x = F.i + pi[i];
                int y = F.j + pj[i];
                int z = F.k + pk[i];
                if(check(x, y, z) && (map[x][y][z] == load || map[x][y][z] == E))
                {
                    map[x][y][z] = step;
                    Pos t;
                    t.i = x;
                    t.j = y;
                    t.k = z;
                    que.push(t);
                }
            }
        }
        
        if(Trapped || map[endp.i][endp.j][endp.k] == E)
            cout << "Trapped!" << endl;
        else
        {
            cout << "Escaped in " << map[endp.i][endp.j][endp.k] <<" minute(s)." << endl;
        }
    }
    
    return 0;
}
