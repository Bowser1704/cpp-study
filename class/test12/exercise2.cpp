#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;

void initStopWords();
void readFile(string filename);

set<string> stopWords;
map<string, int> strNum;
multimap<int, string, greater<>> numStr;

int main() {
    initStopWords();

    string filename = "exercise2.txt";
    readFile(filename);

    int count = 0;
    for (auto it = numStr.begin(); count < 20 && it != numStr.end(); it++) {
        cout << it->second << ": " << it->first << endl;
        count++;
    }
}

void initStopWords() {
    FILE *fp = fopen("stopwords.txt", "r");
    char line[40];
    while (fscanf(fp, "%s\n", line) != EOF) {
        stopWords.insert(line);
    }
}

void readFile(string filename) {
    FILE *fp = fopen(filename.c_str(), "r");
    char line[40];
    while (fscanf(fp, "%s ", line) != EOF) {
        string str(line);
        char back = str.back();
        if (back == '.' || back == ',' || back == '!' || back == '?')
            str.pop_back();

        //tolower
        transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return tolower(c); });

        auto isStop = stopWords.find(str);
        if (isStop == stopWords.end())
            strNum[str]++;
    }

    for (auto it : strNum) {
        numStr.insert(make_pair(it.second, it.first));
    }
}