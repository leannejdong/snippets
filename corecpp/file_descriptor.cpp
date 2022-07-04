#include <unistd.h>
#include <fcntl.h>
#include <utility>
#include <optional>
#include <fmt/core.h>

template <typename Resource, typename Cleanup>
class resource_owner
{
public:
    resource_owner() = default;

    resource_owner(Resource &&resource)
        : m_resource(std::move(resource))
    {
    }

    resource_owner(resource_owner&& other) noexcept
    {
        std::swap(m_resource, other.m_resource);
    }

    resource_owner& operator=(resource_owner&& other) noexcept
    {
        reset();
        std::swap(m_resource, other.m_resource);
        return *this;
    }

    void reset() noexcept
    {
        if (m_resource.has_value())
        {
            Cleanup()(m_resource.value());
            m_resource.reset();
        }
    }

    ~resource_owner() 
    {
        reset();
    }

private:
    resource_owner(const resource_owner&) = delete;
    resource_owner& operator=(const resource_owner&) = delete;

    std::optional<Resource> m_resource;
};

using close_file_descriptor = decltype([](int descriptor)
{
    if (descriptor >= 0)
    {
        close(descriptor);
    }      
});

using file_descriptor = resource_owner<int, close_file_descriptor>;

int main()
{
    {
        file_descriptor fd = open("/dev/zero", O_RDONLY);
        file_descriptor fd2;
        fd2 = std::move(fd);
        file_descriptor fd3 = std::move(fd2);
    }
}
//-std=c++20 -O2 -Wconversion -Wsign-conversion -Werror -Wall -Wpedantic
//https://godbolt.org/z/jxo5Kc4do
