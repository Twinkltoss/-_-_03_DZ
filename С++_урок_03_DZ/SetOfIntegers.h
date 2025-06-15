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
		int count = 0;
		for (int i = 0; i < set.size(); i++) {
			if (set[i] == elem) {
				count++;								
			}			
		}
		if (count>0)
		{
			cout << "\nElement ("<<elem<<") already exist in set!";
		}
		else {
			set.push_back(elem);
			cout << "\nElement (" << elem << ") was added to set!";
		}
	}
	void Remove_Element(int elem) {	
		int tmp = 0;
		bool flag = false;
		auto iter = set.begin();
		for (int i = 1; i < set.size(); i++) {
			if (set[i] == elem) {
				tmp = i;
				flag = true;
			}			
		}
		if (flag) {
			set.erase(iter + tmp);
			cout << "\nElement (" << elem << ") was removed!";
		}
		else {
			cout << "\nElement (" << elem << ") don't exist in set!";
		}
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
	void Intersection_Of_Sets(SetOfIntegers& obj,SetOfIntegers& other) {				
		for (int elemObj : obj.set){
			for (int elemOther : other.set){
				if (elemObj == elemOther) {
					set.push_back(elemObj);
				}
			}
		}		
	}
	void Difference_Of_Sets(SetOfIntegers& obj, SetOfIntegers& other) {
		for (int elemObj : obj.set) {
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

	//Zdarova zaebal
};