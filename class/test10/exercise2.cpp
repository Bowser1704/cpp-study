#include <iostream>
#include <string>
#include <list>
#include <map>
#include <vector>

using namespace std;

class Command {
    private:
        string command;
        int a,b;
    public:
        static map<int,list<int>> Lists;
        Command(string command, int a, int b) : command(command), a(a),b(b) {
        }
        void newList() {
            list<int> l;
            Lists[a] = l;
        }
        void add() {
            Lists[a].push_back(b);
        }
        void merge() {
            Lists[a].sort();
            Lists[b].sort();
            Lists[a].merge(Lists[b]);
            Lists.erase(b);
        }
        void unique() {
            Lists[a].sort();
            Lists[a].unique();
        }
        void out() {
            for (auto i : Lists[a]) {
                cout << i << " ";
            }
            cout << endl;
        }
        void excute() {
            if (command == "new") {
                newList();
            }else if (command == "add") {
                add();
            }else if (command == "merge") {
                merge();
            }else if (command == "unique") {
                unique();
            }else if (command == "out") {
                out();
            }
        }
};
map<int, list<int>> Command::Lists;

int main() {
    int n = 0;
    cin >> n;
    vector<Command> commands;
    for (int i = 0; i < n; i++) {
        string command = "";
        int a=0, b=0;
        cin  >> command >> a;
        if (command == "add" || command == "merge") {
            cin >> b;
        }
        commands.push_back(Command{
            command, a, b
        });
    }
    for (Command command : commands) {
        command.excute();
    }
}

/*
16
new 1
new 2
add 1 1
add 1 2
add 1 3
add 2 1
add 2 2
add 2 3
add 2 4
out 1
out 2
merge 1 2
out 1
out 2
unique 1
out 1
*/