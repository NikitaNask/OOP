#include <iostream>
#include <map>
#include <string>

#include "Section.hpp"

using namespace std;

void Section::add(string const &name, string const &value) {
	string m_name = Trim(name);
	m_fields[m_name] = Trim(value);
}

string Section::GetValue(string const &name) const {
	return m_fields.at(name);
}

string Section::Trim(string const &value) { // delete space 
	string str = value;
	while (str[0] == ' ')
	{
		str = str.substr(1, str.length() - 1);
	}
	while (str.back() == ' ')
	{
		str = str.substr(0, str.length() - 1);
	}
	return str;
}

bool Section::search(string const &name) { // element check   
	return m_fields.find(name) != m_fields.end();
}
Section::~Section()
{
	m_fields.clear();
}

void Section::Print() {
	for (auto it = m_fields.begin(); it != m_fields.end(); ++it)
	{
		cout << it->first << " = " << it->second << endl;
	}
};
