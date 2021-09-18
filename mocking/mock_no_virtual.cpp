// mocking dependency w/o virtual inheritance
#include <ctime>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>

enum weekDays { SUNDAY = 0, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};

//Dispatcher
struct CalendarImplementation {
    weekDays what_day_is_today();
};

template <typename Calendar>
struct Me
{
    std::unique_ptr<Calendar> calendar = std::make_unique<Calendar>();

    bool can_drink_wine_today()
    {
        const auto today = calendar->what_day_is_today();
        return today == weekDays::FRIDAY || today == weekDays::SATURDAY;
    }
};

class MockCalendarInterface {
    public:
    MOCK_METHOD(weekDays, what_day_is_today, (), ());
};

TEST(MeTest, CanNotDrinkWineOnMonday)
{// ::testing::StrictMock<MockCalendarInterface> creates a class that conforms to that interface
    auto calendar_mock = std::make_unique<::testing::StrictMock<MockCalendarInterface>>();
    EXPECT_CALL(*calendar_mock, what_day_is_today())
        .WillOnce(::testing::Return(weekDays::WEDNESDAY));
    Me unit_under_test{std::move(calendar_mock)};// dependency injection
    // we provide a `unit_under_test` with a calendar instead of just `Me unit_under_test`
    EXPECT_FALSE(unit_under_test.can_drink_wine_today());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

weekDays CalendarImplementation::what_day_is_today()
{
    std::tm time_in{};
    std::time_t time_temp = std::mktime(&time_in);
    const std::tm * time_out = std::localtime(&time_temp);
    return static_cast<weekDays>(time_out->tm_wday);
}

// this test still sucks. What to do is to create a mock
// and inject it into struct Me. DONE!
