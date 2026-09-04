#include "Serializer.hpp"

int main()
{
	Data myData;
	myData.name = "abderrahman";
	myData.age = 25;

	std::cout << "Original address of myData: " << &myData << std::endl;
	std::cout << "Original Data: " << myData.name << ", " << myData.age << std::endl;
	std::cout << std::endl;

	uintptr_t raw = Serializer::serialize(&myData);
	std::cout << "Serialized integer (uintptr_t): " << raw << std::endl;

	Data* deserializedPtr = Serializer::deserialize(raw);
	std::cout << "Deserialized address: " << deserializedPtr << std::endl;
	std::cout << "Deserialized Data: " << deserializedPtr->name << ", " << deserializedPtr->age << std::endl;
	std::cout << std::endl;

	if (&myData == deserializedPtr)
		std::cout << "SUCCESS: The pointers match perfectly!" << std::endl;
	else
		std::cout << "ERROR: The pointers do not match!" << std::endl;
	return 0;
}
