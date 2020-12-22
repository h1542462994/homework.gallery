#include <iostream>
#include "ReUnit.h"
#include "UnitType.h"
#include "NfaBuilder.h"
#include "SortedSet.h"
#include "ReBuilder.h"
using namespace std;
using namespace texting;
using namespace util;
int main() {
    // std::cout << "Hello, World!" << std::endl;

    // phase 1: to define a string (regularExpressionFormat), and builder
    //string exp = "a|b(a|b*dc?)(c|e)";
    string exp = "(a|b)*dc?";
    cout << "expression: " << exp << endl;
    ReBuilder reBuilder(exp);

    // phase 2: string -> ReUnit(treeType)
    NfaBuilder nfaBuilder = reBuilder.compileToReUnit();

    // phase 3: ReUnit(treeType) -> nfa(vector<Edge>)
    DfaBuilder dfaBuilder = nfaBuilder.compileToNfa();

    // phase 4: nfa(vector<Edge>) -> dfa(vector<Edge>)aaaaaaaaaaaa
    ReMatcher reMatcher = dfaBuilder.compileToDfa();



//    ReUnit reNode = ReUnit::orGroup(
//            {ReUnit::unit("a") ,
//             ReUnit::concatGroup({
//                 ReUnit::star(ReUnit::unit("b")),
//                 ReUnit::unit("d"),
//                 ReUnit::optional(ReUnit::unit("c")),
//             })
//            });
//    cout << reNode.getExpression() << endl;
//    NfaBuilder builder(reNode);
//    DfaBuilder reBuilder = builder.compileToNfa();
//    ReMatcher reMatcher = reBuilder.compileToDfa();

    return 0;
}
