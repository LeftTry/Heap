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
    while(i >= heap.size()){
        int o1 = 2 * i + 1;
        int o2 = 2 * i + 2;
        if(o1 == -1 && o2 == -1) break;
        if(o1 >= heap.size()) o1 = -1;
        if(o2 >= heap.size()) o2 = -1;
        if(o1 != -1 && heap[i] < heap[o1]){
            if(heap[o2] > heap[i] && heap[o2] > heap[o1]){
                T s = heap[o2];
                heap[o2] = heap[i];
                heap[i] = s;
                i = o2;
            }
            else{
                T s = heap[o1];
                heap[o1] = heap[i];
                heap[i] = s;
                i = o1;
            }
        }
        else if(o2 != -1 && heap[i] < heap[o2]){
            T s = heap[o2];
            heap[o2] = heap[i];
            heap[i] = s;
            i = o2;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0;i < n;i++) cin >> vec[i];
    Heap<int> h(vec);
    int t;
    cin >> t;
    while(t != 0) {
        t--;
        int ind, val;
        cin >> ind >> val;
        ind--;
        h.increaseEl(ind, val);
        //cout << ind;
        h.Shift_up(ind);
        //cout << "ok";
    }
    cout << h;
    return 0;
}
