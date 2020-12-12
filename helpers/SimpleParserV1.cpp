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
    int num_lines = 0;

    string text =
        "S 1 DO\n"
        "P 1\n" 
        "0 10 1\n"
        "S 2 CURRENTEDGE\n"
        "1.1\n"
        "P 2\n"
        "1 %Amp\n"
        "S 3 RESISTEDGE\n"
        "P 3\n"
        "1 %Ohm\n"
        "S 4 VERTEX\n"
        "2 3 4\n";

    std::istringstream input_stream(text);// read from a string without writing
    string line;
    string word;

    while (getline(input_stream, line))
    {        
        std::istringstream line_stream(line);
        if(isdigit(line_stream.peek())) {
            int number;
            line_stream >> number;
            cerr << "Got number: "<< number << "\n";
        }
        else {
            string word;
            line_stream >> word;
            if (word == "S") {
                int block_number;
                line_stream >> block_number;
                if (!line_stream) {
                    assert(false);
                }
                string block_type;
                line_stream >> block_type;
                cerr << "Beginning " << block_type << " block.\n";
                cerr << "Block number is " << block_number << " \n";


                if (block_type == "CURRENTEDGE") {
                    getline(input_stream, line);
                    cerr << " first input line: " << line << "\n";
                }
            }
            else if (word == "P") {
                int block_number;
                line_stream >> block_number;
                if (!line_stream) {
                    assert(false);
                }
                cerr << "Beginning parameters for block" << block_number << " block.\n";
                getline(input_stream, line);
                cerr << " Parameters: " << line << "\n";

            }
             else {
             cerr << "Unknown line: " << line << "\n";
             assert(false);
         }

        }
    }

  
  
}
