#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H
#include "iostream"
#include "vector"

using namespace std;

template <typename T>
class Heap{
    vector<T> heap;
public:
    Heap(vector<T>&);
    void Shift_up(int);
    void increaseEl(int, T);
};

template<typename T>
Heap<T>::Heap(vector<T>& h) {
    heap = h;
}

template<typename T>
void Heap<T>::Shift_up(int index) {
    int i = index;
    while(i != 0){
        int o = i / 2;
        if(i % 2 != 0) o++;
        if(heap[i] > heap[o]){
            T s = heap[o];
            heap[o] = heap[i];
            heap[i] = s;
            i = o;
        }
    }
}

template<typename T>
void Heap<T>::increaseEl(int index, T val) {
    heap[index] += val;
}

#endif //HEAP_HEAP_H
