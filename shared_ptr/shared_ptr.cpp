#include <iostream>
#include <memory>
using namespace std;

int main()
{
    {
        auto p = make_shared<int>(42);
        {
            {
                auto q = p;
                auto r = q;
                q = nullptr;
                q.reset();
                cout << *r << '\n';
            }
        }
        cout << p.use_count() << '\n';
        cout << *p << '\n';
    }
    {
        auto p = make_shared<pair<int, int>>(1, 2);
        auto q = shared_ptr<int>{p, &p->second};
        cout << p.use_count() << '\n';
        cout << sizeof(p) << '\n';
        cout << sizeof(q) << '\n';
        cout << p.owner_before(q) << '\n';
    }
    return 0;
}
