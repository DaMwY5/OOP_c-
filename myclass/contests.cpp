class Storage
{
public:
    unsigned int n;
    int* data;
        // Конструктор хранилища размерности n
    Storage(unsigned int n){
        this->n = n;
        data = new int[n];
        for(int i = 0; i < n; i ++){
            data[i] = i;
        }
    }
    virtual ~Storage() = 0;
    // Добавьте нужный деструктор

    // Получение размерности хранилища
    unsigned getSize(){
        return n;
    }

    // Получение значения i-го элемента из хранилища,
    // i находится в диапазоне от 0 до n-1,
    // случаи некорректных i можно не обрабатывать.
    int getValue(unsigned int j){
        for(unsigned int i = 0; i < n; i ++){
            if(i == j){
                return data[i];
            }
        }
    }

    // Задание значения i-го элемента из хранилища равным value,
    // i находится в диапазоне от 0 до n-1,
    // случаи некорректных i можно не обрабатывать.
    void setValue(unsigned int j, int value){
        for(unsigned int i = 0; i < n; i ++){
            if(i == j){
                data[j] = value;  
            }
        }
    }
};

// Класс TestStorage, наследуется от вашей реализации Storage
class TestStorage : public Storage {
protected:
    // Унаследованная реализация зачем-то хочет выделить ещё памяти. Имеет право.
    int* more_data;

public:
    // В конструкторе память выделяется,
    TestStorage(unsigned int n) : Storage(n) {
        more_data = new int[n];
    }
    // ... а в деструкторе освобождается - всё честно.
    ~TestStorage() {
        delete[] more_data;
    }
};

int main() {
    Storage *ts = new TestStorage(42);
    delete ts;
    return 0;
}