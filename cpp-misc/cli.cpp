#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <cassert>

int main(int argc, char *raw_argv[]) {
    using namespace std;

    vector<string> const args { raw_argv+1, raw_argv+argc };

    assert(args.size() < 1 || args[0] == "--input1");
    assert(args.size() < 3 || args[2] == "--input2");

    if (args.size() > 4) {
        std::string const& csv1 = args[1];
        std::string const& csv2 = args[3];

        std::string date = args.size() > 4? args[4] : "(unspecified)";
        std::cout <<  "Arguments received: " << csv1 << ", " << csv2 << " date:" << date << "\n";
    }
}
