# Custom Vector Implementation

A C++ implementation of a custom vector class that mimics the functionality of std::vector. This implementation includes:

- Dynamic resizing
- Copy and move semantics
- Exception handling
- Basic vector operations (push_back, pop_back, clear, etc.)

## Features

- Template-based implementation
- Rule of Five compliance
- Dynamic memory management
- Bounds checking
- Move semantics support

## Usage

```cpp
CustomVector<int> vec;
vec.push_back(10);
vec.push_back(11);
vec.push_back(12);

// Access elements
for(int i = 0; i < vec.getSize(); i++) {
    std::cout << vec[i] << " ";
}
```

## Requirements

- C++11 or later
- Standard C++ library

## License

MIT License 