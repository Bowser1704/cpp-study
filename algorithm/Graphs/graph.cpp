//链式前向星
const int MAXN = 1024;
template <typename T>
class adjacentLinkList {
    public:
        struct Edge {
            int to;     //这条边的下一个节点
            T value;  //权值
            int last;   //与此边，同出发点u的上一条边的索引，在edge边数组中的索引
        }edge[MAXN];
        int head[MAXN]; //记录某个点的最后一条边的索引，在edge边数组中的下标。
        int cnt;        //记录有多少个边,cnt为最近空着的那条边，可以直接拿来用。
    public:
        void add(int u, int v, T value) {
            edge[cnt].value = value;
            edge[cnt].to = v;
            edge[cnt].last = head[u];
            head[u] = cnt++;
        }
};