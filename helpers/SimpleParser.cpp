#include <cassert>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cerr;


int main()
{
//    int num_lines = 0;

    string text =
        "S 1 DO\n"
        "P 1\n" 
        "0 10 1\n"
        "S 2 CURRENTEDGE\n"
        "1.1\n";

    std::istringstream input_stream(text);// read from a string without writing
    string line;

    while (getline(input_stream, line))
    {
        std::istringstream line_stream(line);
        string word;
        line_stream >> word;

        if (word == "S") {
            // Start of a block;
            int block_number;
            line_stream >> block_number;

            if (!line_stream) {
                assert(false); // not implemented
            }

            string block_type;
            line_stream >> block_type;

            cerr << "Beginning " << block_type << " block.\n";

            if (block_type == "CURRENTEDGE") {
                getline(input_stream, line);
                cerr << "  first input line: " << line << "\n";
            }
        }
        else if (word == "P") {
            int block_number;
            line_stream >> block_number;

            if (!line_stream) {
                assert(false); // not implemented
            }
            
            cerr << "Beginning parameters for block " << block_number << "\n";
            getline(input_stream, line);
            cerr << "  Parameters: " << line << "\n";
        }
        else {
            cerr << "Unknown line: " << line << "\n";
            assert(false); // not implemented
        }
    }
    //std::cout << "Number of lines contain S: " << num_lines;
}
