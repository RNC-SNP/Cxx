#include <iostream>
#include <memory>
#include <vector>

using namespace std;

template<typename T>
class Block {
public:
    typedef T value_type;
    typedef typename vector<T>::size_type size_type;

    Block(initializer_list<T> il);

    size_type size() {return data->size();}
    bool empty() {return data->empty();}
    void push_back(T& t) {data->push_back(t);}

    void pop_back();
    T& back();
    T& operator[](size_type i);
private:
    shared_ptr<vector<T>> data;
    void check(size_type i, const string &msg);
};

template<typename T>
Block<T>::Block(initializer_list<T> il):data(make_shared<vector<T>>(il)) {
}

template<typename T>
void Block<T>::check(size_type i, const string &msg) {
    if(i >= data->size()) {
        throw out_of_range(msg);
    }
}

template<typename T>
T& Block<T>::back() {
    check(0, "empty");
    return data->back();
}

template<typename T>
T& Block<T>::operator[](size_type i) {
    check(i, "out of range");
    return (*data)[i];
}

template<typename T>
void Block<T>::pop_back() {
    check(0, "empty");
    data->pop_back();
}


int main (int argc, char **argv) {
    Block<string> block({"Andy", "Bob", "Chris", "Denny", "Emma", "Frank"});
    block.pop_back();
    string str = "Rinc";
    block.push_back(str);
    for (int i = 0; !block.empty() && i < block.size(); i++) {
        cout << block[i] << endl;
    }
    return 0;
}