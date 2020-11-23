#include <cassert>
#include <cmath>
#include <sstream>
#include <iostream>


static void printFractionOn(std::ostream &stream, float value)
{
   // Implement here
   int denominator = 1000;
   auto numerator = denominator*value;
  // value = numerator/denominator;
   stream << numerator << "/" << denominator;
}


int main()
{
    std::ostringstream stream;
    printFractionOn(stream, 0.001);
    std::string result = stream.str();
    std::string expected_result = "1/1000";
    std::cerr << "result:          " << result << "\n";
    std::cerr << "expected_result: " << expected_result << "\n";
    assert(result == "1/1000");
}
