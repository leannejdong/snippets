
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using std::cin;
using std::cout;
using std::cerr;
using std::vector;
using std::ranges::sort;
using std::ranges::lower_bound;
using std::ranges::transform;

float DotProduct(const vector<float> & dir1, const vector<float> & dir2)
{
    /* Enter your code here. */
}

vector<float> CrossProduct(const vector<float> & dir1, const vector<float> & dir2)
{
	vector<float> cross;
    
    /* Enter your code here. */
    
	return cross;
}

vector<float> Difference(const vector<float> & dir1, const vector<float> & dir2)
{
	vector<float> diff;
    
    /* Enter your code here. */
    
	return diff;
}

// vector<float> Normalise(const vector<float> & dir)
// {
//     /* Enter your code here. */
//      vector<int> tmp(dir), ret(dir.size());
//      sort(tmp);
//     transform(arr.cbegin(), arr.cend(), ret.begin(), [&tmp](float x){
//         return distance(tmp.begin(), lower_bound(tmp, x));
//     });
//      return ret;
// }

vector<float> normalize_array(const vector<float> &arr) {
    vector<float> tmp(arr), ret(arr.size());

    //sort(tmp.begin(), tmp.end());
    sort(tmp);

    transform(arr.cbegin(), arr.cend(), ret.begin(), [&tmp](int x) {
        //return distance(tmp.begin(), lower_bound(tmp.begin(), tmp.end(), x));
        return distance(tmp.begin(), lower_bound(tmp, x));

    });

    return ret;
}

int main() 
{
    for (auto &x : normalize_array({5235, 223, 223, 1000, 10, 10, 40, 40, 40})) {
        cerr << x << ' ';
    }
    // vector<float> position;
	// for (int c = 0; c < 3; c++)
	// {
	// 	float x;
	// 	cin >> x;
	// 	position.push_back(x);
	// }
   // Normalise(position);

	// vector<float> direction;
	// for (int c = 0; c < 3; c++)
	// {
	// 	float x;
	// 	cin >> x;
	// 	direction.push_back(x);
	// }

	// vector<float> target;
	// for (int c = 0; c < 3; c++)
	// {
	// 	float x;
	// 	cin >> x;
	// 	target.push_back(x);
	// }
    
    /* Enter your code here. */
    
    return 0;
}


// https://godbolt.org/z/ojdsnqYhE
