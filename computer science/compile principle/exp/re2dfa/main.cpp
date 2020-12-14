#include <iostream>
#include "ReUnit.h"
#include "UnitType.h"
#include "NfaBuilder.h"
#include "SortedSet.h"
using namespace std;
using namespace texting;
using namespace util;
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
    NfaBuilder builder(expression);
    DfaBuilder builder1 = builder.compileToDfa();
    builder1.compile();

    return 0;
}
