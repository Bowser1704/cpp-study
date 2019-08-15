#include <iostream>
#include <map>
#include <string>
using namespace std;
const int maxN = 2010;

map<int, string> intToString;   //id->name
map<string, int> stringToInt;   //name->id
map<string, int> Gang;          //name->menberNum

int G[maxN][maxN] = {0}, weight[maxN] = {0};
int n, k, numPerson = 0;
bool isVisit[maxN] = {false};

void DFS(int nowVisit, int& head, int& numMember, int& totalValue) {
    numMember++;
    isVisit[nowVisit] = true;
    if(weight[nowVisit] > weight[head]) head = nowVisit;
    for (int i=0; i<numPerson; i++){        //all person
        if (G[nowVisit][i] > 0) {
            totalValue += G[nowVisit][i];
            G[nowVisit][i] = G[i][nowVisit] = 0;    //防止重复计算
            if (isVisit[i] == false){
                DFS(i, head, numMember, totalValue);
            }
        }
    }
}

void DFSTrave() {
    for(int i=0; i<numPerson; i++){
        if(isVisit[i] == false){
            int head=i, numMember = 0, totalValue = 0;  //头目，成员数，总边权
            DFS(i, head, numMember, totalValue);    
            if(numMember>2 && totalValue > k) {
                Gang[intToString[head]] = numMember;
            }
        }
    }
}

int change(string str) {
    if (stringToInt.find(str) != stringToInt.end()) {
        return stringToInt[str];
    } else {
        stringToInt[str] = numPerson;
        intToString[numPerson] = str;
        return numPerson++;     
        //i++ return i, ++i return i+1;
        //i++ return i temp, ++i return i itself;
    }
}

int main() {
    int w;
    string str1, str2;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> str1 >> str2 >> w;
        int id1 = change(str1);
        int id2 = change(str2);
        weight[id1] += w;   //点权
        weight[id2] += w;   
        G[id1][id2] += w;   //边权, 本来是有向边，现在抽象成无向边；
        G[id2][id1] += w;
    }
    DFSTrave();
    cout << Gang.size() << endl;
    for (auto it = Gang.begin(); it != Gang.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}