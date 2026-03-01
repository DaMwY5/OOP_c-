#include <iostream>

using namespace std;

class subvector{
    public:
    subvector();
    ~subvector();
    int pop_back();
    bool resize(unsigned int new_capacity);
    void shrink_to_fit();
    bool push_back(int d);
    void clear();
    int _capacity();
    private:
    int *mas;
    unsigned int top; 
    unsigned int capacity;
};

subvector::subvector() {
    this->top = 0;
    this->capacity = 0;
    this->mas = nullptr;
}

int subvector::pop_back(){
  if ((this->top == 0) or (this->mas == NULL)) {
    return 0;
  }
  (this->top) -= 1;
  return this->mas[(this->top)];
}

bool subvector::resize(unsigned int new_capacity){
    if(this->top >= new_capacity){
      return false;
    }
    else{
        int* a = new int[new_capacity];
        for (unsigned int i = 0; i < this->top; i++) {
            a[i] = this->mas[i];
        }
        delete[] this->mas;
        this->mas = a;
        this->capacity = new_capacity;
    }
    return true;
}

void subvector::shrink_to_fit(){
    if (this->top == 0) {
        delete[] this->mas;
        this->mas = nullptr;
        this->capacity = 0;
        return;
    }
    int* a = new int[this->top];
    for (unsigned int i = 0; i < this->top; i++) {
            a[i] = this->mas[i];
        }
    delete[] this->mas;
    this->mas = a;
    this->capacity = this->top;
}

bool subvector::push_back(int d) {
    if (this->capacity == 0) {
        this->capacity = 1;
        this->mas = new int[1];
    }
    else if (this->capacity == this->top) {
        int* a = new int[2*(this->capacity)];
        for (unsigned int i = 0; i < this->top; i++) {
            a[i] = this->mas[i];
        }
        delete[] this->mas;
        this->mas = a;
        this->capacity *= 2;
    }
    this->mas[this->top] = d;
    this->top++;
    return true;
}

void subvector::clear(){
    this ->top = 0;
}

int subvector::_capacity(){
    return this->capacity;
}

subvector::~subvector(){
    this ->top = 0;
    this ->capacity = 0;
    delete [] this->mas;
}

int main(){
    subvector sv;
    sv.push_back(1);
    sv.push_back(2);
    sv.push_back(3);

    cout << sv.pop_back() << endl;
    cout << sv.pop_back() << endl;

    sv.resize(10);

    cout << sv._capacity() << endl;

    sv.shrink_to_fit();

    cout << sv._capacity() << endl;

    sv.clear();
    sv.shrink_to_fit();

    cout << sv._capacity() << endl;
}