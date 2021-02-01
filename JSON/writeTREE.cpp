// Wrote tree to JSON (Hard-coded)

#include <iostream>
#include <string>
#include <json.hpp>

using std::cerr;
using std::string;

int main()
{
    using json = nlohmann::json;

    json j = { 
  {"id", 1},
  {"name", "Apple"},
  {"data", "{}"},
  {"children", {
      {{"id", 2},
      {"name", "Bee"},
      {"data", "{}"}
      },
      {{"id", "3"},
      {"name", "Cafe"},
      {"data", "{}"}}
  }},
};

   cerr << "j=";
   cerr.width(4);
   cerr << j <<"\n";
}

/* Input: tree data
 * Output: tree JSON schema/file
 * Rule: 
 * 1-1 correspondance between tree node and JSON object. Every JSON object represents a tree node.
 * Every object in JSON that corresponds to a node in the tree has an 'id' number
 * The root of the tree is a single dictionary object. None-root node is of array type,
 * (aka dictionary object). The top level object children has 4 members,
 * "children": value has type array
 * "data": value has type string
 * "id": value has type number
 * "name" : value has type string
 */
