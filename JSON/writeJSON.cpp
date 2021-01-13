#include <iostream>
#include <string>
#include <json.hpp>

using std::cerr;
using std::string;

int main()
{
    using json = nlohmann::json;

    json j = {
  {"pi", 3.141},
  {"happy", true},
  {"name", "Niels"},
  {"nothing", nullptr},
  {"answer", {
    {"everything", 42}
  }},
  {"list", {1, 0, 2}},
  {"object", {
    {"currency", "USD"},
    {"value", 42.99}
  }}
};

   cerr << "j=";
   cerr.width(4);
   cerr << j<<"\n";
}
