// Find smallest positive integer that does not occur in a given sequence
#include<vector>
#include<algorithm>
#include<iostream>

using std::vector;

int solution(vector<int>& Vec)
{
    //Sort and remove duplicates: Method 1
    std::sort(Vec.begin(), Vec.end());
    Vec.erase(std::unique(Vec.begin(), Vec.end()), Vec.end());

    //Sort and remove duplicates: Method 2
    // std::set<int> s(Vec.begin(), Vec.end());
    // Vec.assign(s.begin(), s.end());


    //Remove all ints < 1
    vector<int> vec;
    vec.reserve(Vec.size());
    for(const auto& el : Vec)
    {
        if(el>0)
            vec.push_back(el);
    }

    //Edge case: All ints were < 1 or all ints were > 1
    if(vec.size()==0 or vec.at(0) != 1)
        return 1;

    //Edge case: vector contains only one element
    if(vec.size()==1)
        return (vec.at(0)!=1 ? 1 : 2);

    for(size_t i=0; i < vec.size(); ++i)
    {
        if(vec.at(i) != int(i+1))
            return vec.at(i-1)+1;
    }
    return vec.back()+1;
}

int main()
{
    vector<int> vec {-1, 2, 3, 4, 7};
    std::cout << solution(vec) << "\n";
}
