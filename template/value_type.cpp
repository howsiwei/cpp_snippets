#include <vector>
using namespace std;

template<typename C>
using Value_type = typename C::value_type;     // the type of C's elements

template<typename Container>
void algo(Container& c)
{
    vector<Value_type<Container>> vec;        // keep results here
    // ...
    vector<typename Container::value_type> vec2;        // keep results here
}
