#include <iostream>

class test5
{
public:
    test5(): data(new float[10]){
        std::cout << "\tnew " << data << std::endl;
        for (int i = 0; i < 10; i++)
            data[i] = float(i);
    }

    ~test5(){
        std::cout << "\tdelete[] " << data << std::endl;
        delete[] data;
    }

    // copy constructor
    test5(const test5& t) : data(new float[10]){
        std::cout << "\tcopy " << data << std::endl;
        std::copy(t.data, t.data + 10, data);
    }

    // copy operator
    test5& operator=(const test5& t){
        std::cout << "\tassign " << data << std::endl;
        std::copy(t.data, t.data + 10, data);
        return *this;
    }

    // move constructor
    test5(test5&& t): data(new float[10]){
        delete[] data;
        data = t.data;
        std::cout << "\tmove_new " << data << std::endl;
        t.data = nullptr;
    }
    // move operator
    test5& operator=(test5&& t){
        delete[] data;
        data = t.data;
        std::cout << "\tmove_assign " << data << std::endl;
        t.data = nullptr;
        return *this;
    }

private:
    float* data;
};

int main()
{
    std::cout << "Test 5" << std::endl;

    test5 rule5;
    test5 rule5move = std::move(rule5);
    // rule5 = std::move(rule5move);

    return 0;
}
