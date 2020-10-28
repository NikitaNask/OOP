#include <iostream>
#include <vector>
#include <string>

class Student {
public:
	std::string name;
	std::string surname;
	std::string university;
	std::string phone;
	// указатель на университет 
	Student(std::string _name, std::string _surname)
		: name(_name)
		, surname(_surname)
	{};

	Student(std::string _name, std::string _surname, std::string _university)
		: name(_name)
		, surname(_surname)
		, university(_university)
	{};

	Student(std::string _name, std::string _surname, std::string _university, std::string _phone)
		: name(_name)
		, surname(_surname)
		, university(_university)
		, phone(_phone)
	{};

	void printStudentInfo() {
		std::cout << "Name: " << this->name << std::endl;
		std::cout << "Surname: " << this->surname << std::endl;
		std::cout << "University: " <<(!this->university.empty() ? this->university : "not set") << std::endl;
		std::cout << "Phone: " <<(!this->phone.empty() ? this->phone : "not set") << std::endl;
	}

	void setPhoneNumber(std::string _phone) {
		this->phone = _phone;
	}

	void setUniversity(std::string _university) {
		this->university = _university;
	}

};

int main() {
	auto Vasya = Student("Vasya", "Pupkin");
	Vasya.setUniversity("ITMO");
	Vasya.printStudentInfo();
	system("pause");
}