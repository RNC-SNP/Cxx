#include <iostream>
#include <memory>
#include <vector>

template<typename T>
class Block {
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    Block(std::initializer_list<T> il);

    size_type size() {return data->size();}
    bool empty() {return data->empty();}
    void push_back(T& t) {data->push_back(t);}

    void pop_back();
    T& back();
    T& operator[](size_type i);
private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg);
};

template<typename T>
Block<T>::Block(std::initializer_list<T> il):data(std::make_shared<std::vector<T>>(il)) {
}

template<typename T>
void Block<T>::check(size_type i, const std::string &msg) {
    if(i >= data->size()) {
        throw std::out_of_range(msg);
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
    Block<std::string> block({"Andy", "Bob", "Chris", "Denny", "Emma", "Frank"});
    block.pop_back();
    std::string str = "Rinc";
    block.push_back(str);
    for (int i = 0; !block.empty() && i < block.size(); i++) {
        std::cout << block[i] << std::endl;
    }
    return 0;
}