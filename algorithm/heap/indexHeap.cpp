template <typename T>
class IndexHeap {
   private:
    T* data;
    int* indexes;
    int* reverse;
    int count;
    int capacity;

    //上浮，如果大于父节点，就交换
    void shiftUp(int k) {
        while (k > 1 && data[indexes[k / 2]] < data[indexes[k]]) {
            swap(indexes[k / 2], indexes[k]);
            reverse[indexes[k / 2]] = k/2;
            reverse[indexes[k]] = k;
            k /= 2;
        }
    }

    //下浮，如果大于子节点，交换
    void shiftDown(int fa) {
        //如果，还有子节点的话。
        while (2 * fa <= count) {
            int j = 2*fa;
            if (j+1 <= count && data[indexes[j]] < data[indexes[j+1]]) {
                j++;
            }

            if (data[indexes[j]] <= data[indexes[fa]]) {
                break;
            }

            swap(indexes[j], indexes[fa]);
            reverse[indexes[fa]] = fa;
            reverse[indexes[j]] = j;
            fa = j;
        }
    }

   public:
    IndexHeap(int capacity) : capacity(capacity){
        //0 是不用的，浪费一个空间。
        data = new T[capacity + 1];
        indexes = new int[capacity + 1];
        reverse = new int[capacity + 1];
        for (int i = 0; i <= capacity； i++) {
            reverse[i] = 0;
        }
        count = 0;
    }

    ~IndexHeap() {
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    }

    //插入操作，对于用户来说，是从0开始，但是我们的heap,0是弃用的。
    void insert(int i, T value) {
        assert(count + 1 <= capacity);
        assert(i+1 >= 1 && i+1 <= capacity);

        data[++i] = value;
        indexes[++count] = i;
        reverse[i] = count;

        shiftUp(count);
    }

    T extractMax() {
        assert(count > 0);

        T ret = data[indexes[1]];

        swap(indexes[1], indexes[count]);
        reverse[indexes[1]] = 1;
        reverse[indexes[count--]] = 0;
        shiftDown(1);

        return ret;
    }

    bool contain(int i) {
        assert(i+1 >= 1 && i <= capacity);
        return reverse[i+1] != 0;
    }
    void change(int i, T value) {
        assert(contain(i));
        
        data[++i] = value;

        int j = reverse[i];
        shiftup(j);
        shiftDown(j);
    }
};