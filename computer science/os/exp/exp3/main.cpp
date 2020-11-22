#include <iostream>
#include "simple_io.h"
#include "re_state.h"

using namespace std;
int main() {
    cout << "welcome to bank's algorithm presentation program" << endl;
    cout << "now input the process count and the resource type count, format as [:p_count :r_count]" << endl;
    int p_count;
    int r_count;
    cin >> p_count >> r_count;
    cout << "now input the each resource count, format as [:(" << r_count << ")r_each_count]" << endl;
    int* r = new int[r_count];
    read(r, r_count);
    cout << "now input the claims matrix, format as [:(" << p_count << "*" << r_count << ")cell]" << endl;
    int* c = new int[p_count * r_count];
    read(c, p_count * r_count);

    re_state state(p_count, r_count, r, c);

    cout << state << endl;
    string s = state.get_state();
    if (s == state.FLEXIBLE || s == state.CLAIM_ERROR) {
        cout << "program finished with error" << endl;
        return 0;
    }

    while (true) {
        cout << "---------------------------------------------" << endl;
        cout << "please distribute resource to a process, format as [:processId, :(" << r_count << ")r_each_count]" << endl;
        int p_index = 0;
        int* data = new int[r_count];
        cin >> p_index;
        for (int i = 0; i < r_count; ++i) {
            cin >> data[i];
        }
        //迁移到一个新的状态
        re_state new_state = state.move(p_index, data);
        string s = new_state.get_state();
        if (s == state.FLEXIBLE || s == state.CLAIM_ERROR) {
            cout << new_state << endl;
            cout << "program finished with error" << endl;
            break;
        } else if (s == state.UNSAFE || s == state.REQUEST_OVERFLOW) {
            cout << new_state << endl;
            cout << "action rollback" << endl;
            cout << state << endl;
            cout << "move to unsafe state, please re input" << endl;
        } else if(s == state.FINISH) {
            cout << new_state << endl;
            cout << "program successfully finished";
            break;
        } else {
            cout << new_state << endl;
            cout << "move successfully" << endl;
            state = new_state;
        }
    }

    return 0;
}
