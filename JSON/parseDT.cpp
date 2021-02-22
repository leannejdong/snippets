// out of dated!
#include <iostream>
#include <string>
#include <json.hpp>
#include <fstream>
#include <iomanip>
using std::cerr;
using std::string;

int main()
{
    using nlohmann::json;

    // read a JSON file
    std::ifstream i("m2.json");
    if (!i) {
        std::cerr << "Unable to open m2.json\n";
        return EXIT_FAILURE;
    }
    json j;
    i >> j;

    // write to another file
    std::ofstream o("outputs/m2DT.json");
    o << std::setw(4) << j << "\n";
}
