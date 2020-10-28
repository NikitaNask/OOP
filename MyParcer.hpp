#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <fstream>

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

};


class MyParcer {
private:
	map <std::string, Section *> m_data;
	bool				m_IsInicialize;
public:
	~MyParcer();
	void Initialize(const char* filename_cstr);

	bool IsSection(const string &str);
	bool IsInicialize();

	bool SearchSection(string const &section_name);

	bool SearchParam(string const &section, std::string const &param);

	string GetSectionNameOfString(const string &str);

	template <typename T>
	T GetValue(string const &section, string const &param);
};
