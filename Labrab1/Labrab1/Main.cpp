#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <fstream>

#include "Section.hpp"
#include "MyParcer.hpp"

using namespace std;

void main(void)
{
	MyParcer m_Obj;
	m_Obj.Initialize("C:/lab1.txt");
	if (!m_Obj.IsInicialize()) return;
	m_Obj.Print();

	cout << m_Obj.SearchSection("COMMON") << '\n';
	cout << m_Obj.SearchParam("COMMON", "LogXML") << '\n';
	//cout << m_Obj.GetValue<string>("ADC_DEV", "BufferLenSeconds") << '\n';
	//cout << m_Obj.GetValue<string>("ADC_DEV", "Driver") << '\n';
	cout << m_Obj.GetValueToDouble("ADC_DEV", "BufferLenSeconds") << '\n';
	system("pause");

	MyParcer *m_Obj1=new MyParcer();
	m_Obj1->Initialize("C:/lab1.txt");
	if (!m_Obj1->IsInicialize()) return;
	cout << m_Obj1->SearchSection("COMMON") << '\n';
	cout << m_Obj1->SearchParam("COMMON", "LogXML") << '\n';
	cout << m_Obj1->GetValue<double>("ADC_DEV", "BufferLenSeconds") << '\n';
	cout << m_Obj1->GetValue<string>("ADC_DEV", "Driver") << '\n';
	cout << m_Obj1->GetValueToDouble("ADC_DEV", "BufferLenSeconds") << '\n';
	//delete m_Obj1; //m_Obj1

	system("pause");
}