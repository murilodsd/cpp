#include <string>
#include <iostream>

class Person
{
	private:
		std::string	_name;
		int		_age;

	public:
		Person() : _name(""), _age(0) {};
		Person(const std::string &name, int age) : _name(name), _age(age) {};
		Person& operator=(const Person& other) {if (this != &other) {_age = other._age; _name = other._name;} return (*this);}
		~Person() {};
		const std::string& get_name() const {return _name;}
		int get_age() const {return _age;}

		bool operator<(const Person& other_person) const { return (_age < other_person._age); }
		bool operator>(const Person& other_person) const { return (_age > other_person._age); }
};

std::ostream& operator<<(std::ostream& cout, const Person& person)
{
	cout << "name " << person.get_name() << ", age = " << person.get_age();
	return (cout);
}
