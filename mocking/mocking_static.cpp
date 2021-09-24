
// mocking with static polymorphism
#include <cassert>
#include <vector>

using std::vector;

namespace example4 {
    void doStuffWith(vector<double> &values, bool &simulate_more)
    {
        if (values[0] < 0) {
            simulate_more = false;
        }
    }

    template <typename Model>
    class Simulator {
        Model* model;
    public:
        Simulator(Model* model) : model(model) {} //<--- inject dependency on Model


        void inner_loop() {
            bool simulate_more = true;
            vector<double> values(model->size());

            while (simulate_more) {
                for (size_t i = 0; i < model->size(); ++i) {
                    values[i] = model->getValue(i);
                }

                doStuffWith(values, simulate_more);
            }
        }
    };

    class MockModel {
    public:
        int n_get_value_calls = 0;
        int n_size_calls = 0;

        double getValue(size_t i)
        {
            switch (n_get_value_calls++) {
                case 0:
                    assert(i == 0);
                    return 1;
                case 1:
                    assert(i == 1);
                    return 2;
                case 2:
                    assert(i == 0);
                    return -1;
                case 3:
                    assert(i == 1);
                    return 2;
            }
            assert(false);
        }

        size_t size()
        {
            switch (n_size_calls++) {
                case 0: return 2;
                case 1: return 2;
                case 2: return 2;
                case 3: return 2;
                case 4: return 2;
                case 5: return 2;
                case 6: return 2;
            }

            assert(false);
        }
    };

    void test_inner_loop() {
        MockModel model;
        Simulator simulator(&model);
        simulator.inner_loop();
        assert(model.n_size_calls == 7);
        assert(model.n_get_value_calls == 4);
    }
}



int main() {
    example4::test_inner_loop();
}

/*
Basically, the idea of unit testing callback is
a mechanism allows us to check if the callback is called in a right way.
If the callback needs to return value to the caller, how do we provide them?
use a mock (a test only component) that implement in such a way to enable verification of the callback code.
*/

// see also https://blog.knatten.org/tag/static-polymorphism/ mocking in general
// mocking with interfaces https://compiler-explorer.com/z/19Yqojxfb
// https://compiler-explorer.com/z/Tjh7vqv9T
