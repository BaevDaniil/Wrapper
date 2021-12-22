#include "Engine/engine.h"
#include <iostream>

class Arithmetic
{
public:
    int sum(int x, int y)
    {
        return x + y;
    }

    int dif(int x, int y)
    {
        return x - y;
    }
};

class Abs {
public:
    int abs(int a) {
        return a < 0 ? -a : a;
    }
};

int main() {
    Arithmetic arf;
    Abs abs;

    Wrapper wrapper1(&arf, &Arithmetic::sum, { {"arg1", 0}, {"arg2", 0} });
    Wrapper wrapper2(&arf, &Arithmetic::dif, { {"arg1", 0}, {"arg2", 0} });
    Wrapper wrapper3(&abs, &Abs::abs, { {"arg", 0} });

    Engine engine;
    engine.register_command("sum", &wrapper1);
    engine.register_command("dif", &wrapper2);
    engine.register_command("abs", &wrapper3);

    std::cout << engine.execute("sum", { {"arg1", 3}, {"arg2", 7} }) << std::endl;
    std::cout << engine.execute("sum", { {"arg1", 3} }) << std::endl;
    std::cout << engine.execute("dif", { {"arg2", 3}, {"arg1", 4} }) << std::endl;
    std::cout << engine.execute("abs", {}) << std::endl;
    std::cout << engine.execute("abs", { {"arg", -5} }) << std::endl;

    return 0;
}