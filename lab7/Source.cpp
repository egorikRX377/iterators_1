#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>	
#include <list>
#include <memory>
#include <algorithm>
#include <functional>
#include <array>

#include <set>
#include <map>

#include <unordered_map>
#include <unordered_set>

using namespace std;


namespace filePATHS
{
	const string studPATH = "students.txt";
}

class Student
{
protected:
	string name;
	int age;
	int course;
	double averageRating;
public:
	Student() : name("unknown"), age(-1), course(-1), averageRating(-1) {}
	Student(string name, int age, int course, double averageRating) : name(name), age(age), course(course), averageRating(averageRating) {}

	Student(const Student& other) : name(other.name), age(other.age), course(other.course), averageRating(other.averageRating) {}
	Student& operator=(const Student& other)
	{
		name = other.name;
		age = other.age;
		course = other.course;
		averageRating = other.averageRating;
		return *this;
	}
	~Student() {}
	Student(Student&& other) noexcept
	{
		name = other.name;
		age = other.age;
		course = other.course;
		averageRating = other.averageRating;

		other.name = "";
		other.age = 0;
		other.course = 0;
		other.averageRating = 0;
	}
	Student& operator=(Student&& other) noexcept
	{
		if (this != &other)
		{
			name = other.name;
			age = other.age;
			course = other.course;
			averageRating = other.averageRating;

			other.name = "";
			other.age = 0;
			other.course = 0;
			other.averageRating = 0;
		}
		return *this;
	}

	string getName() { return name; }
	int getAge() { return age; }
	int getCourse() { return course; }
	double getAverageRating() { return averageRating; }

	void setName(string name) { this->name = name; }
	void setAge(int age) { this->age = age; }
	void setCourse(int course) { this->course = course; }
	void setAverageRating(double averageRating) { this->averageRating = averageRating; }

	friend bool operator<(const shared_ptr<Student>& student1, const shared_ptr<Student>& student2)
	{
		return student1->name < student2->name;
	}
	friend bool operator==(const shared_ptr<Student>& student1, const shared_ptr<Student>& student2)
	{
		if (student1->averageRating == student2->averageRating && student1->name == student2->name && student1->course == student2->course && student1->averageRating == student2->averageRating)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend ostream& operator<<(ostream& buf, const shared_ptr<Student>& student)
	{
		buf << student->name << ' ' << student->age << ' ' << student->course << ' ' << student->averageRating << endl;
		return buf;
	}
	friend istream& operator>>(istream& buf, shared_ptr<Student>& student)
	{
		buf >> student->name >> student->age >> student->course >> student->averageRating;
		return buf;
	}
};


using studentMap = map<shared_ptr<Student>, string>;
using mStudentMap = multimap<shared_ptr<Student>, string>;
using UnMStudentMap = unordered_multimap<shared_ptr<Student>, string>;


using studentSet = set<shared_ptr<Student>>;
using mStudentSet = multiset<shared_ptr<Student>>;
using UnMStudentSet = unordered_multiset<shared_ptr<Student>>;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	shared_ptr<Student> student1 = make_shared<Student>("Егор", 18, 2, 8.5);
	shared_ptr<Student> student2 = make_shared<Student>("Павел", 20, 4, 7);
	shared_ptr<Student> student3 = make_shared<Student>("Алёна", 17, 1, 7.7);

	shared_ptr<Student> student4 = make_shared<Student>("Егор", 18, 2, 8.5);


	//=============================================================================================//
	//=============================================MAP=============================================//
	studentMap studMAP;
	studMAP.insert(make_pair(student1, "бюджет"));
	studMAP.insert(make_pair(student2, "платная"));
	studMAP.insert(make_pair(student3, "бюджет"));

	studMAP.insert(make_pair(student4, "бюджет"));

	studentMap::iterator outputIter = studMAP.begin();
	while (outputIter != studMAP.end())
	{
		cout << outputIter->first;
		cout << "Форма обучения: " << outputIter->second << endl;
		outputIter++;
	}


	studentMap::iterator mapIter;
	mapIter = studMAP.find(make_shared<Student>("Егор", 18, 2, 8.5));

	if (mapIter != studMAP.end())
	{
		cout << "===============================" << endl;
		cout << mapIter->first;
		cout << "Форма обучения: " << mapIter->second << endl;
		cout << "===============================" << endl;
	}
	else
	{
		cout << "Студент не найден!" << endl;
	}

	mStudentMap mStudMAP;
	mStudMAP.insert(make_pair(student1, "бюджет"));
	mStudMAP.insert(make_pair(student2, "платная"));
	mStudMAP.insert(make_pair(student3, "бюджет"));

	mStudMAP.insert(make_pair(student4, "бюджет"));

	cout << endl;

	mStudentMap::iterator mOutputIter = mStudMAP.begin();
	while (mOutputIter != mStudMAP.end())
	{
		cout << mOutputIter->first;
		cout << "Форма обучения: " << mOutputIter->second << endl;
		mOutputIter++;
	}

	UnMStudentMap unordered_multi_StudentMAP;
	unordered_multi_StudentMAP.insert(make_pair(student1, "бюджет"));
	unordered_multi_StudentMAP.insert(make_pair(student2, "платная"));
	unordered_multi_StudentMAP.insert(make_pair(student3, "бюджет"));

	unordered_multi_StudentMAP.insert(make_pair(student4, "бюджет"));

	cout << endl << endl;
	UnMStudentMap::iterator unMOutputIter = unordered_multi_StudentMAP.begin();
	while (unMOutputIter != unordered_multi_StudentMAP.end())
	{
		cout << unMOutputIter->first;
		cout << "Форма обучения: " << unMOutputIter->second << endl;
		unMOutputIter++;
	}

	//=============================================================================================//



	//=============================================================================================//
	//==============================================SET============================================//
	studentSet studSet;

	studSet.insert(student1);
	studSet.insert(student2);
	studSet.insert(student3);

	studSet.insert(student4);

	studentSet::iterator iter1 = studSet.begin();

	cout << endl << endl;
	while (iter1 != studSet.end())
	{
		cout << (*iter1);
		iter1++;
	}
	cout << endl;

	cout << "Первый студент найден в множестве: " << studSet.count(student1) << endl;


	studSet.erase(student3);

	iter1 = studSet.begin();
	cout << endl << endl;
	cout << "После удаления: " << endl;
	while (iter1 != studSet.end())
	{
		cout << (*iter1);
		iter1++;
	}
	cout << endl;


	UnMStudentSet studBASE;
	studBASE.insert(studSet.begin(), studSet.end());

	studBASE.erase(student3);
	studBASE.insert(student4);

	UnMStudentSet::iterator sIter = studBASE.begin();
	cout << endl << endl;
	while (sIter != studBASE.end())
	{
		cout << (*sIter);
		sIter++;
	}
	//=============================================================================================//
	return 0;
}