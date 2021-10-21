#include <cstdlib>
#include <optional>

struct Configuration {
    int param1;
    int param2;
};


extern void compute1(int);
extern void compute2(int);
extern std::optional<Configuration> readConfiguration();

static void doComputation(const Configuration &configuration)
{
    compute1(configuration.param1);
    compute2(configuration.param2);
}
/* The static keyword isn't necessary, but I prefer to make
all non-member functions that are only used in a single file.
It avoids accidental conflicts with functions of the same name 
in other source files, and improves link time
*/


int main()
{
    std::optional<Configuration> maybe_configuration = readConfiguration();

    if (!maybe_configuration) {
        return EXIT_FAILURE;
    }

    doComputation(*maybe_configuration);
}
