#include <iostream>
#include <algorithm>

template <typename T>
class CustomVector {
    private:
        T* data;                                        //Pointer to dynamically allocated array
        size_t capacity;                                //Total number of elements array can hold before reallocation
        size_t size;                                    //Current number of elements the array is having

    public:
        //Constructor which initialize the capacity of dynamic arrar
        CustomVector(size_t initialCapacity = 10) : capacity(initialCapacity), size(0) {
            data = new T[capacity];
        }

        //Destructor
        ~CustomVector() {
            delete[] data;
        }

        //Following the rule of Three(Five/Zero)
        //We should create a copy constructor and copy assignment operator
        //Copy Constructor
        CustomVector(const CustomVector& other) : capacity(other.capacity), size(other.size) {
            data = new T[capacity];
            std::copy(other.data, other.data + size, data);
        }

        //Copy assignment operator
        CustomVector& operator=(const CustomVector& other) {
            if (this != other) {
                delete[] data;
                capacity = other.capacity;
                size = other.size;
                data = new T[capacity];
                std::copy(other.data, other.data + size, data);
            }
            return *this;
        }

        //Move constructor(move semantics)
        CustomVector(CustomVector&& other) noexcept : data(other.data), capacity(other.capacity), size(other.size) {
            other.data = nullptr;
            other.capacity = 0;
            other.size = 0;
        }

        //Move assignment operator
        CustomVector& operator=(CustomVector&& other) noexcept {
            if(this != &other) {
                delete[] data;
                data = other.data;
                capacity = other.capacity;
                size = other.size;
                other.data = nullptr;
                other.capacity = 0;
                other.size = 0;
            }
            return *this;
        }
        void push_back(const T& value) {
            if(size == capacity) {
                resize(capacity * 2);
            }
            data[size++] = value;
        }

        size_t getSize() const{
            return size;
        }

        T& operator[](size_t index) {
            if(index >= size) {
                throw std::out_of_range("Index out of bound\n");
            }
            return data[index];
        }

        const T& operator[](size_t index) const {
            if(index >= size) {
                throw std::out_of_range("Index out of bound\n");
            }
            return data[index];
        }

        //Very crucial function to make sure that
        //vector remains dynamic
        void resize(size_t newCapacity) {
            T* newData = new T[newCapacity];
            std::copy(data, data + size, newData);
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }

        //Remove the last element
        void pop_back() {
            if(size > 0) {
                size--;
            }
        }

        //Clear the vector;
        void clear() {
            size = 0;
        }

        //Check if the vector is empty or not?
        bool empty() const {
            return size == 0; 
        }
};

int main() {
    CustomVector<int> vec;
    vec.push_back(10);
    vec.push_back(11);
    vec.push_back(12);

    for(int i = 0; i < vec.getSize(); i++) {
        std::cout << vec[i] << " ";
    }
}