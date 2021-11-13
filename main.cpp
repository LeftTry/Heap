#include "iostream"
#include "vector"

using namespace std;

template <typename T>
class Heap{
    vector<T> heap;
public:
    Heap(vector<T>&);
    vector<T> get_vec();
    void Shift_up(int);
    void Shift_down(int);
    void increaseEl(int, T);
    void decreaseEl(int, T);
    void extractMax();
    template<class Type> friend std::ostream & operator<<(std::ostream&, Heap<Type>);
};

template<typename T>
Heap<T>::Heap(vector<T>& h) {
    heap = h;
}

template<typename T>
void Heap<T>::Shift_up(int index) {
    int i = index;
    while(i > 0){
        int o = i / 2;
        if(i % 2 == 0) o--;
        if(heap[i] > heap[o]){
            T s = heap[o];
            heap[o] = heap[i];
            heap[i] = s;
            i = o;
        }
        else break;
        //cout << "ok";
    }
    cout << i + 1 << endl;
}

template<typename T>
void Heap<T>::increaseEl(int index, T val) {
    heap[index] += val;
}

template<class Type>
std::ostream &operator<<(ostream & out, Heap<Type> h) {
    vector<Type> vec = h.get_vec();
    for(int i = 0;i < vec.size();i++)
        out << vec[i] << " ";
    out << endl;
    return out;
}

template<typename T>
vector<T> Heap<T>::get_vec() {
    return heap;
}

template<typename T>
void Heap<T>::Shift_down(int ind) {
    int i = ind;
    while(i <= heap.size()){
        int o1 = 2 * i + 1;
        int o2 = 2 * i + 2;
        if(o1 >= heap.size()) o1 = -1;
        if(o2 >= heap.size()) o2 = -1;
        if(o1 == -1 && o2 == -1) break;
        int maxind = -1;
        if(o1 == -1 || o2 == -1) maxind = max(o1, o2);
        else{
            if(heap[o1] >= heap[o2]) maxind = o1;
            else maxind = o2;
        }
        if(heap[i] < heap[maxind]){
            T s = heap[maxind];
            heap[maxind] = heap[i];
            heap[i] = s;
            i = maxind;
        }
        else break;
    }
    cout << i + 1 << " ";
}

template<typename T>
void Heap<T>::decreaseEl(int ind, T val) {
    heap[ind] -= val;
}

template<typename T>
void Heap<T>::extractMax() {
    T extracted = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    this->Shift_down(0);
    cout << extracted << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0;i < n;i++) cin >> vec[i];
    Heap<int> h(vec);
    for(int i = 0;i < n - 1;i++) h.extractMax();
    return 0;
}
