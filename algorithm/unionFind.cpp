#include <iostream>
const int maxN = 100;

int fa[maxN];
int find(int x) {
    //一行并查集
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void unionSet(int x, int y) {
    x = find(x);
    y = find(y);
    if (x==y) {
        return;
    }
    fa[y] = x;
}
int main() {

}