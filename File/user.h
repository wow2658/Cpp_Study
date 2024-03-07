#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class User
{
private:
	int num;
	string name;
	string tel;
	string email;
public:
	int getNum()
	{
		return this->num;
	}
	void set_user(int num, string name, string tel, string email)
	{
		this->num = num;
		this->name = name;
		this->tel = tel;
		this->email = email;
	}
	void printUser()
	{
		cout << "번호\t\t이름\t\t전화번호\t\t이메일주소" << endl;
		cout << this->num << "\t\t" << this->name << "\t\t" << this->tel << "\t\t" << this->email << endl;
	}

};