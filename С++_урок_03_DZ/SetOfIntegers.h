#pragma once
#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;


class SetOfIntegers {
	vector<int> set;
public:
	SetOfIntegers(initializer_list<int> list) :set(list) {
		Doubless();
	}
	SetOfIntegers() :SetOfIntegers({}) {}
	SetOfIntegers(SetOfIntegers& other) :set{ other.set } {}
	void Doubless() {
		vector<int> tmp;
		for (int i = 0; i < set.size(); i++) {	
			int count = 0;
			for (int j = 0; j < i; j++) {
				if (set[j] == set[i]) {
					count++;
					break;
				}
			}
			if (count==0) {
				tmp.push_back(set[i]);
			}
		}
		set = tmp;
	}
	void Add_Element(int elem) {
		bool flag= false;
		for (int i = 0; i < set.size(); i++) {
			if (set[i] == elem) {
				flag =true;								
			}			
		}
		if (!flag)set.push_back(elem);
	}
	void Remove_Element(int elem) {	
		int tmp = 0;
		bool flag = false;
		auto iter = set.begin();
		for (int i = 0; i < set.size(); i++) {
			if (set[i] == elem) {
				tmp = i;
				flag = true;
			}			
		}
		if (flag)set.erase(iter + tmp);		
	}
	bool Comparison_Of_Sets(SetOfIntegers& other) {
		if (this->set.size() != other.set.size())return false;
		for (int i = 0; i < set.size(); i++) {
			bool flag = false;
			for (int j = 0; j < set.size(); j++){
				if (this->set[i] == other.set[j]) {
					flag = true;
					break;
				}
			}
			if (!flag)return false;
		}
		return true;
	}
	void Union_Of_Sets(SetOfIntegers& other) {		
		for (auto& i : other.set){
			set.push_back(i);
		}
		Doubless();
	}
	void Intersection_Of_Sets(SetOfIntegers& other) {				
		for (int elemObj : set){
			for (int elemOther : other.set){
				if (elemObj == elemOther) {
					set.push_back(elemObj);
				}
			}
		}		
	}
	void Difference_Of_Sets(SetOfIntegers& other) {
		for (int elemObj :set) {
			bool flag = false;
			for (int elemOther : other.set) {
				if (elemObj == elemOther) {
					flag = true;
					break;
				}				
			}
			if(!flag)set.push_back(elemObj);
		}
	}
	bool Membership_Element(int elem) {
		for (int setElem : set){
			if (setElem == elem) {
				return true;
			}
		}
		return false;
	}
	void PrintSet() {
		cout << endl;
		if (!set.empty()) {
			for (int n : set) {
				cout << n << "  ";
			}
			cout << endl;
		}		
		else cout << "Set of intrgers is empty!"<< endl;;
	}
	SetOfIntegers operator+(int elem) {
		Add_Element(elem);
		return *this;
	}
	SetOfIntegers operator+=(int elem) {
		Add_Element(elem);		
		return *this;
	}	
	SetOfIntegers operator+(SetOfIntegers& other) {
		Union_Of_Sets(other);
		return *this;
	}
	SetOfIntegers operator+=(SetOfIntegers& other) {
		Union_Of_Sets(other);
		return *this;
	}
	SetOfIntegers operator-(int elem) {
		Remove_Element(elem);
		return *this;
	}
	SetOfIntegers operator-=(int elem) {
		Remove_Element(elem);
		return *this;
	}
	SetOfIntegers operator-=(const SetOfIntegers& other) {
		for (const auto& el : other.set) {
			Remove_Element(el);
		}
		return *this;
	}
	SetOfIntegers operator-(const SetOfIntegers& other) {
		SetOfIntegers result = *this;
		result -= other;
		return result;
	}
	SetOfIntegers operator*=(SetOfIntegers& other) {
		vector<int>tmp;
		for (int elemObj : set) {
			for (int elemOther : other.set) {
				if (elemObj == elemOther) {
					tmp.push_back(elemObj);
				}
			}
		}
		set = tmp;
		return *this;
	}
	SetOfIntegers operator*(SetOfIntegers& other) {
		SetOfIntegers temp = *this;
		temp *= other;
		return temp;
	}
	bool operator==(SetOfIntegers& other) {
		return Comparison_Of_Sets(other);
	}
	friend ostream& operator<<(ostream& os, const SetOfIntegers& other) {
		os << "{ ";
		for (size_t i = 0; i < other.set.size(); ++i) {
			os << other.set[i];
			if (i != other.set.size() - 1) {
				os << ", ";
			}
		}
		os << " }";
		return os;
	}
	friend istream& operator>>(std::istream& is, SetOfIntegers& other) {
		int element;
		char ch;
		other.set.clear();		
		is >> ch;
		if (ch != '{') {
			is.setstate(std::ios::failbit);
			return is;
		}		
		while (is >> element) {
			other += element; 
			is >> ch;
			if (ch == '}') break;
			if (ch != ',') {
				is.setstate(std::ios::failbit);
				break;
			}
		}
		return is;
	}	
};