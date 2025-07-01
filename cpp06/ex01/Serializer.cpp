/**
 * @brief Pseudo-serialization utility class for demonstration purposes
 * 
 * This is not a real serializer implementation. It only demonstrates basic
 * pointer-to-integer conversion using reinterpret_cast. A true serialization
 * system would convert object data into a portable format (like JSON, XML, 
 * or binary) that can be stored or transmitted and later reconstructed.
 * 
 * This class provides simple conversion between Data pointers and their
 * memory addresses represented as integers, which is useful for educational
 * purposes but should not be used for actual data persistence or transmission.
 * 
 * @note The serialized uintptr_t values are only valid within the same
 *       program execution context and cannot be used across different
 *       program runs or systems.
 */
#include "Serializer.hpp"
#include "data.hpp"



// ==================== Constructors ====================
Serializer::Serializer()
{
}

// ================= Copy Constructor ==================
Serializer::Serializer(const Serializer &other)
{
	(void)other;
}

// ========== Copy Assignment Operator Overload ==========
Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return *this;
}

// ==================== Destructor =====================
Serializer::~Serializer()
{
}
// ================= Auxiliar Functions =================

// ================== Member Functions ==================
uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}