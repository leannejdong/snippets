#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int countWords(std::string x)
{
    int cnt = 0;
    char prev = ' ';

    for (size_t i = 0; i < x.size(); i++)
    {
        if(x[i] != ' '&& prev == ' ') cnt++;
        prev = x[i];
    }
    return cnt;
}

int wordlength(std::string line)
{
    std::vector<std::string> words;
    std::istringstream line_stream(line);
    std::string word;
    while(line_stream >> word )
    {
        words.push_back(word);
    }
    double sum = 0;
    for (size_t i = 0; i < words.size(); ++i)
    {
        std::cout << words[i] << " has size " << sizeof(words[i]) << "\n";
        std::cout << words[i] << " has size " << (words[i]).size() << "\n";
    }
    return 0;

}

int main()
{
    std::string teststr = "S 2 CURRENTEDGE";
    std::cout << countWords(teststr) << "\n";
    wordlength(teststr);

}
