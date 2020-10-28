#pragma once
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>

#include "Section.hpp"

using namespace std;

class MyParcer {
private:
	map <std::string, Section*> m_data;
	bool				m_IsInicialize;
protected:
	bool IsSection(const string &str);
public:
	~MyParcer();
	void Initialize(const char* filename_cstr);

	bool IsInicialize();

	bool SearchSection(string const &section_name);

	bool SearchParam(string const &section, std::string const &param);

	string GetSectionNameOfString(const string &str);

	template <typename T>
	T GetValue(string const &section, string const &param) const;

	double MyParcer::GetValueToDouble(string const &section, string const &param);

	void MyParcer::Print();
};

MyParcer::~MyParcer() {
	for (auto it = m_data.begin(); it != m_data.end(); ++it)
	{
		//удаляю секции
		delete it->second;
	}
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
			}
		}
	}
	fs.close();
}
//trim [ ]
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

	double MyParcer::GetValueToDouble(string const &section, string const &param){
	string str=m_data.at(section)->GetValue(param);
	double res=0;
	try {
		res = stod(str);
	}
	catch (const std::invalid_argument&) {
		cout << "Error convert to double " << str << '\n';
	}
	catch (const std::out_of_range&) {
		cout << "Error convert to double " << str << '\n';
	}
	return res;
};


	void MyParcer::Print() {
		for (auto it = m_data.begin(); it != m_data.end(); ++it)
		{
			cout << "Name section [" << it->first <<"]"<< endl;

			Section *sec = it->second;
			sec->Print();
		}
	};
