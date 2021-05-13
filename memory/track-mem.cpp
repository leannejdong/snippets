#include <iostream>
#include <memory>
#include <string>

struct AllocationMetrics{
    uint32_t totalMemory = 0;
    uint32_t totalFree = 0;
    uint32_t getCurrentUsage() {return totalMemory - totalFree;}
};
static AllocationMetrics s_allocationMetrics;

void* operator new(size_t size)
{
    s_allocationMetrics.totalMemory += size;
    std::cerr << "Allocating " << size << " bytes\n";
    return malloc(size);
}


void operator delete(void* p)
{
    std::cerr << "Deallocating unknown bytes\n";
    free(p);
}
void operator delete(void* p, size_t size)
{
    std::cerr << "Deallocating " << size << " bytes\n";
    s_allocationMetrics.totalFree += size;
    free(p);
    abort();
}

static void PrintMemoryUsage()
{
    std::cerr << "Memory usage: " << s_allocationMetrics.getCurrentUsage() << " bytes\n";
}

struct Object{
    int x, y, z;
};

int main()
{
    PrintMemoryUsage();
    std::string str = "Hello";
    PrintMemoryUsage();

    {
        auto obj = std::make_unique<Object>();
        PrintMemoryUsage();
    }
        PrintMemoryUsage();

}
