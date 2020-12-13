#include <iostream>
#include "ReUnit.h"
#include "UnitType.h"
#include "DfaBuilder.h"
using namespace std;
using namespace texting;
int main() {

    std::cout << "Hello, World!" << std::endl;

    ReUnit expression = ReUnit::orGroup(
            {ReUnit::unit("a") ,
             ReUnit::concatGroup({
                 ReUnit::star(ReUnit::unit("b")),
                 ReUnit::unit("d"),
                 ReUnit::optional(ReUnit::unit("c")),
             })
            });
    cout << expression.getExpression() << endl;
    DfaBuilder builder(expression);
    builder.compileToNfa();
    //cout << builder << endl;
    return 0;
}
