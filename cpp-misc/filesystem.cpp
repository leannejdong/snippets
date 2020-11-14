#include <iostream>
#include <filesystem>

int main()
{
  std::filesystem::path folderpath = "/home/leanne/Dev/projects/";
  if (std::filesystem::exists(folderpath))
  {
    std::cout << "The path: " << folderpath << " exists.";
  }
  else
  {
    std::cout << "The path: " << folderpath << " does not exist.";
  }
  /*Now we iterate over folder elements, we use the std::filesystem::directory_iterator iterator
   * and print them out with .path() member function.*/
  auto myfolder = "/home/leanne/Dev/";
  for (auto el : std::filesystem::recursive_directory_iterator(myfolder))
  {
    std::cout << el.path() << '\n';
  }
}

