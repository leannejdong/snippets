#include <unistd.h>
#include <linux/limits.h>
#include <iostream>

void getwd()
{
    char path[PATH_MAX];
    std::cout << "working directory: " << getcwd(path, sizeof path) << "\n";
}

int main()
{
    getwd();
}
