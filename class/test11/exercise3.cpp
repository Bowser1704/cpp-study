#include <iostream>
#include <set>
using namespace std;

multiset<int> numset;
set<int> recordSet;

struct Command {
    string command;
    int argv;
};

void excute(Command& cmd) {
    if (cmd.command == "add") {
        numset.insert(cmd.argv);
        recordSet.insert(cmd.argv);
        cout << numset.size() << endl;
    } else if (cmd.command == "del") {
        cout << numset.count(cmd.argv) << endl;
        numset.erase(cmd.argv);
    } else if (cmd.command == "ask") {
        auto ask = recordSet.find(cmd.argv);
        if (ask != recordSet.end())
            cout << 1 << " ";
        else
            cout << 0 << " ";
        int count = numset.count(cmd.argv);
        cout << count << endl;
    }
}

int main() {
    int n;
    cin >> n;
    Command cmd[n];
    for (int i = 0; i < n; i++) {
        cin >> cmd[i].command >> cmd[i].argv;
    }
    for (int i = 0; i < n; i++) {
        excute(cmd[i]);
    }
    return 0;
}

/*----------------------------------------------------------------
7
add 1
add 1
ask 1
ask 2
del 2
del 1
ask 1
*/