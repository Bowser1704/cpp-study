#ifndef CIRCULAR_QUEUE
#define CIRCULAR_QUEUE

template <typename T>
class CircularQueue {
    private:
        T* items = nullptr;
        size_t capacity = 0;
        size_t head = 0;
        size_t tail = 0;
    public:
        CircularQueue() = delete;
        CircularQueue(const size_t size) : capacity(size) { 
            items = new T[capacity];
        }
        ~CircularQueue() {
            delete[] items;
        }
        void enqueue(const T item) {
            if ((tail+1)%capacity != head) {
                items[tail] = item;
                tail = (tail+1)%capacity;
            }
        }
        void dequeue() {
            if (head != tail) {
                head = (head + 1)%capacity;
            }
        }
        T dehead() const { 
            if (head != tail) {
                return items[head];
            }
        }
};

#endif