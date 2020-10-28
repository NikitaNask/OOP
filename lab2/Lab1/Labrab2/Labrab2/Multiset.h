#pragma once
#include<vector>
#include<list>
#include<fstream> 
#include<set>
#include <string>
#include <iostream>
using namespace std;

//template<class T>
class StatisticMultiset {
private:
	vector<int> *m_data;
public:
	StatisticMultiset();
	~StatisticMultiset();
	void AddNumsFromFile(const char* filename);

	/*void AddNum(const T&);
	void AddNum(const std::multiset<T>& numbers);
	void AddNum(const std::vector<T>& numbers);
	void AddNum(const std::list<T>& numbers);
	void AddNums(const StatisticMultiset& a_stat_set);
	T GetMax() const;
	T GetMin() const;
	float GetAvg() const;
	int GetCountUnder(float threshold) const;
	int GetCountAbove(float threshold) const;
	*/
};

//template<class T> 
StatisticMultiset::StatisticMultiset() {
	m_data = new vector<int>;
}

//template<class T>
StatisticMultiset::~StatisticMultiset() {
	delete m_data;
}

//template<class T> 
void StatisticMultiset::AddNumsFromFile(const char* filename) {
	ifstream fs;
	try
	{
		fs.open(filename, ifstream::in);
	}
	catch (exception ex) {
		cout << "File not found" << endl;
		return;
	}

	if (fs.good()) {
		cout << "File open" << endl;
	}
	else {
		cerr << "Error while opening file" << endl;
		return;
	}
	string m_CurrentSection = "";
	while (!fs.eof()) {
		string s;
		getline(fs, s);
		m_data->insert(m_data->end(), atoi(s.data()));
		cout << s << endl;
	}
	fs.close();
}

