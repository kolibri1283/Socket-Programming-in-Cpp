#include <vector>
#include <cstdint>
#include <cstring>
#include <type_traits>
#ifndef MESSAGE_H
#define MESSAGE_H



struct Message {
    char message[50];
    char name[30];
    char surname[30];
    int age;
    double height;
    bool IsActive;
};

template <typename T>
std::vector<uint8_t>  serialize(const T &obj){
    std::vector<uint8_t>  buffer(sizeof(T));
    std::memcpy(buffer.data(),&obj,sizeof(T));
    return buffer;
}

template <typename T>
T deserialize(const std::vector<uint8_t>& buffer) {
    T obj;
    std::memcpy(&obj, buffer.data(), sizeof(T));
    return obj;
}
#endif

