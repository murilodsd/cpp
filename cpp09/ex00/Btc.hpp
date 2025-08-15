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