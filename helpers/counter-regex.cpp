#include <iostream>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <regex>
#include <map>

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
{ // first we count the number of words in the string
    const std::regex re(R"([\w]+)");
    const std::string teststr = "S 2 CURRENTEDGE";
    std::map<char, size_t> counter{};
    std::for_each(teststr.begin(), teststr.end(), [&counter](const char c) 
    { if(std::isalpha(c)) counter[std::tolower(c)]++; });

    std::cout << "The number of words: "
    << std::distance(std::sregex_token_iterator(teststr.begin(), teststr.end(), re, 1),
     std::sregex_token_iterator())
     << "\n\nCount of chars: \n\n";
    
// next we count the number of occurence of each letter in the string

 // show char count on display
    for(const auto& [character, count] : counter)
    {
        std::cout << character << " -> " << count << "\n";
    }
    return 0;
}
