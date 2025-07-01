#include "Serializer.hpp"
#include "data.hpp"
#include <stdint.h>
#include <iostream>

int main()
{
	std::cout << "=== CPP06 Exercise 01: Serialization ===" << std::endl;
	
	// Create a Data structure
	Data originalData;
	originalData.value = 42;
	originalData.name = "Test Data";
	
	std::cout << "Original Data address: " << &originalData << std::endl;
	std::cout << "Original Data value: " << originalData.value << std::endl;
	std::cout << "Original Data name: " << originalData.name << std::endl;
	
	std::cout << "\n--- Serialization Process ---" << std::endl;
	
	// Serialize the Data pointer to uintptr_t
	uintptr_t serialized = Serializer::serialize(&originalData);
	std::cout << "Serialized value (uintptr_t): " << serialized << std::endl;
	
	std::cout << "\n--- Deserialization Process ---" << std::endl;
	
	// Deserialize back to Data pointer
	Data* deserializedData = Serializer::deserialize(serialized);
	std::cout << "Deserialized Data address: " << deserializedData << std::endl;
	
	std::cout << "\n--- Verification ---" << std::endl;
	
	// Verify that the deserialized pointer points to the original object
	if (deserializedData == &originalData)
	{
		std::cout << "SUCCESS: Deserialized pointer matches original address!" << std::endl;
		std::cout << "Deserialized Data value: " << deserializedData->value << std::endl;
		std::cout << "Deserialized Data name: " << deserializedData->name << std::endl;
	}
	else
	{
		std::cout << "ERROR: Deserialized pointer does not match original address!" << std::endl;
	}
	
	return 0;
}