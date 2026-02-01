#include "Serializer.hpp"

int main()
{
    Data data;

    data.value = 42;
    data.name = "Ghost FLT";
    data.score = 99.5f;

    uintptr_t raw = Serializer::serialize(&data);
    Data* ptr = Serializer::deserialize(raw);

    std::cout << "Original address : " << &data << std::endl;
    std::cout << "Deserialized ptr : " << ptr << std::endl;

    std::cout << "\nData content after deserialization:\n";
    std::cout << "value : " << ptr->value << std::endl;
    std::cout << "name  : " << ptr->name << std::endl;
    std::cout << "score : " << ptr->score << std::endl;

    return 0;
}
