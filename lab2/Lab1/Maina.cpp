#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <fstream>

#include "Section.hpp"

using namespace std;

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
	T GetValue(string const &section, string const &param) const;
};



void Section::add(string const &name, string const &value) {
	string m_name = Trim(name);
	m_fields[m_name] = Trim(value);
}

string Section::GetValue(string const &name) const {
	cerr << "Section::GetValue\n";
	cerr << "Param: " << name << "\n\n";
	return m_fields.at(name);
}

string Section::Trim(string const &value) {
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

bool Section::search(string const &name) {
	return m_fields.find(name) != m_fields.end();
}
Section::~Section()
{
	m_fields.clear();
}

MyParcer::~MyParcer() {
	m_data.clear();
};

void MyParcer::Initialize(const char* filename_cstr) {
	ifstream fs;
	try
	{
		fs.open(filename_cstr, ifstream::in);
		m_IsInicialize = true;
	}
	catch (exception ex) {
		cout << "File not found" << endl;
		m_IsInicialize = false;
		return;
	}

	if (fs.good()) {
		cout << "File open" << endl;
	}
	else {
		cerr << "Error while opening file" << endl;
	}
	string m_CurrentSection = "";
	while (!fs.eof()) {
		string s;
		getline(fs, s);
		if (IsSection(s))
		{
			m_CurrentSection = GetSectionNameOfString(s);
			m_data[m_CurrentSection] = new Section();
		}

		else {
			int m_LenParamName = s.find('=', 0);
			if (m_LenParamName > 0) {
				string param, value;
				param = s.substr(0, m_LenParamName);

				if (s.find(';', m_LenParamName)>0)
					value = s.substr(m_LenParamName + 1, s.find(';', m_LenParamName) - m_LenParamName - 1);
				else
					value = s.substr(m_LenParamName + 1, s.length() - m_LenParamName);
				m_data[m_CurrentSection]->add(param, value);
				cout << param << '=' << value << '\n';
			}
			else {
			}
		}
	}
	fs.close();
}

string MyParcer::GetSectionNameOfString(const string &str) {
	string s = str.substr(1, str.length() - 2);
	return s;
}

bool MyParcer::IsInicialize()
{
	return  m_IsInicialize;
};

bool MyParcer::SearchSection(string const &section_name) {
	return m_data.find(section_name) != m_data.end();
}

bool MyParcer::SearchParam(string const &section, std::string const &param)
{
	if (SearchSection(section))
		return m_data.at(section)->search(param);
	return false;
}


bool MyParcer::IsSection(const string &str) {
	if (str[0] == '['&& str.back() == ']')
		return true;
	return false;
};

template <typename T>
T MyParcer::GetValue(string const &section, string const &param) const {
	stringstream ss;
	ss << m_data.at(section)->GetValue(param);
	T ans;
	ss >> ans;
	return ans;
};




void main(void)
{
	MyParcer m_Obj;
	m_Obj.Initialize("C:/lab1.txt");
	if (!m_Obj.IsInicialize()) return;
	cout << m_Obj.SearchSection("COMMON") << '\n';
	cout << m_Obj.SearchParam("COMMON", "LogXML") << '\n';
	cout << m_Obj.GetValue<double>("ADC_DEV", "BufferLenSeconds") << '\n';
//	cout << m_Obj.GetValue<string>("ADC_DEV", "Driver") << '\n';
	//m_Obj.Print();  // обработка исключения с типом данных 


	system("pause");
	return;
}