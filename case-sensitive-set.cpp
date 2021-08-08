#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <cctype>
#include <iostream>

using std::vector;
using std::string;
using std::unordered_set;
using std::cout;


static string uppercased(string s)
{
    std::transform(s.begin(), s.end(), s.begin(), [](char c){ return std::toupper(c); });
    return s;
}


namespace {
struct CaseInsensitiveEquality {
    bool operator()(const string &a, const string &b) const
    {
        return uppercased(a) == uppercased(b);
    }
};
}


namespace {
struct CaseInsensitiveHash {
    size_t operator()(const string &s) const
    {
        return std::hash<string>()(uppercased(s));
    }
};
}


int main()
{
    vector<string> names = {
        "john",
        "Jill",
        "jane",
        "Jack",
        "jill",
        "John"
    };

    unordered_set<string> name_set(names.begin(), names.end());
    cout << "name_set:\n";

    for (const string &name : name_set) {
        cout << "  " << name << "\n";
    }

    unordered_set<string, CaseInsensitiveHash, CaseInsensitiveEquality>
      case_insensitive_name_set(names.begin(), names.end());
    
    cout << "\n";
    cout << "case_insensitive_name_set:\n";

    for (const string &name : case_insensitive_name_set) {
        cout << "  " << name << "\n";
    }
}
// https://stackoverflow.com/questions/36058387/how-to-use-unordered-set-with-compare-function
