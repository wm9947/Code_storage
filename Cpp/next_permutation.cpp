//#include <vector>
//#include <algorithm>

std::vector<vector<int> > basic_n_permutation(std::vector<int> data);
std::vector<vector<int> > n_permutation(int num, int sel, std::vector<int> data);

std::vector<vector<int> > basic_n_permutation(std::vector<int> data)
{
    std::vector<vector<int> > result;
    do
    {
        result.push_back(data);
    }while(std::next_permutation(data.begin(), data.end());
    
    return result;
}

std::vector<vector<int> > combination_permutation(int num, int sel, std::vector<int> data);
{
    std::vector<vector<int> > result;
    std::vector<bool> v(num);
    std::fill(v.end() - sel, v.end(), true);
    
    do
    {
        std::vector<int> gen;
        for(int i = 0; i < num; i++)
        {
            if(v[i])
            {
                gen.push_back(data[i]);
            }
        }
        result.push_back(gen);
    }while(std::next_permutation(v.begin(), v.end()));
}
