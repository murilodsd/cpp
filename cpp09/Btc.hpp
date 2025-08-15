#pragma once
#include <iostream>
#include <map>

class Btc
{
	private:
		std::map<std::string, float> btc_map;

	public:
		// Default constructor
		Btc();

		// Copy constructor
		Btc(const Btc &other);

		// Copy assignment operator overload
		Btc &operator=(const Btc &other);

		// Destructor
		~Btc();

		const std::map<std::string, float>& getBtcMap() const;
		void insertValue(std::string, float);
};

#include "Btc.hpp"

// ==================== Constructors ====================
Btc::Btc()
{
}

// ================= Copy Constructor ==================
Btc::Btc(const Btc &other)
:
btc_map(other.btc_map)
{
}

// ========== Copy Assignment Operator Overload ==========
Btc &Btc::operator=(const Btc &other)
{
	if (this != &other)
	{
		btc_map = other.btc_map;
	}
	return *this;
}

// ==================== Destructor =====================
Btc::~Btc()
{
}
// ================= Auxiliar Functions =================

// ================== Member Functions ==================
const std::map<std::string, float>& Btc::getBtcMap() const
{
	return btc_map;
}

void Btc::insertValue(std::string date, float value)
{
	btc_map[date] = value;
}