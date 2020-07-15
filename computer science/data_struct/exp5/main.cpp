#include <iostream>
#include "tree.h"
#include <sstream>

using namespace std;
int main() {
    auto expression = bnode_fac::build_with_suffix("abcd-*+ef/-");
    bnode_fac::l_print(expression);

    bnode_fac::print_pre_order(expression, "");
    cout << endl;
    bnode_fac::print_mid_order(expression, "");
    cout << endl;
    bnode_fac::print_post_order(expression, "");
    cout << endl;
    bnode_fac::print_mid_expression(expression);
    cout << endl;
    bnode_fac::print_full_mid_expression(expression);
    cout << endl;

    bnode_fac::clear(expression);
    return 0;
}
