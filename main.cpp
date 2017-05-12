#include <iostream>
#include "ControlSystem.h"
#include <memory>
using namespace std;

int main()
{
     unique_ptr<ControlSystem>ptr=make_unique<ControlSystem>();
     ptr->run();
    return 0;
}
