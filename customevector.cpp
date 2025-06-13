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
            if (this != &other) {
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
    vec.push_back(20);
    vec.push_back(30);

    std::cout << "Vector elements: ";
    for (size_t i = 0; i < vec.getSize(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Size of vector: " << vec.getSize() << std::endl;

    vec.pop_back();
    std::cout << "Size of vector after pop_back: " << vec.getSize() << std::endl;
    
    CustomVector<int> vec2 = vec; // Copy constructor
    std::cout << "Vector elements in vec2: ";
    for (size_t i = 0; i < vec2.getSize(); ++i) {
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl;
    
    CustomVector<int> vec3;
    vec3 = vec; // Copy assignment operator
    std::cout << "Vector elements in vec3: ";
    for (size_t i = 0; i < vec3.getSize(); ++i) {
        std::cout << vec3[i] << " ";
    }
    std::cout << std::endl;
    
    CustomVector<int> vec4 = std::move(vec); // Move constructor
    std::cout << "Vector elements in vec4: ";
    for (size_t i = 0; i < vec4.getSize(); ++i) {
        std::cout << vec4[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Size of vector vec after move: " << vec.getSize() << std::endl;
    
    CustomVector<int> vec5;
    vec5 = std::move(vec2); // Move assignment operator
    std::cout << "Vector elements in vec5: ";
    for (size_t i = 0; i < vec5.getSize(); ++i) {
        std::cout << vec5[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Size of vector vec2 after move: " << vec2.getSize() << std::endl;
    
    vec5.clear();
    std::cout << "Size of vector vec5 after clear: " << vec5.getSize() << std::endl;
    std::cout << "Is vec5 empty?: " << vec5.empty() << std::endl;

    return 0;
}