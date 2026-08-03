#include "Serializer.hpp"

int main()
{
    // 1. Create a Data object
    Data myData;
    myData.name = "42 Student";
    myData.age = 21;

    std::cout << "Original address of myData: " << &myData << std::endl;
    std::cout << "Original Data: " << myData.name << ", " << myData.age << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    // 2. Serialize the pointer to a raw integer
    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "Serialized integer (uintptr_t): " << raw << std::endl;

    // 3. Deserialize the integer back to a pointer
    Data* deserializedPtr = Serializer::deserialize(raw);
    std::cout << "Deserialized address: " << deserializedPtr << std::endl;
    std::cout << "Deserialized Data: " << deserializedPtr->name << ", " << deserializedPtr->age << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    // 4. Prove they are identical
    if (&myData == deserializedPtr) {
        std::cout << "SUCCESS: The pointers match perfectly!" << std::endl;
    } else {
        std::cout << "ERROR: The pointers do not match!" << std::endl;
    }

    return 0;
}
