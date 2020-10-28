#pragma once
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Section
{
public:
	map <string, string>	m_fields;
	void add(string const &name, string const &value);

	string GetValue(string const &name) const;
	string Trim(string const &value);

	bool search(string const &name);
	~Section();
	void Print();

};
