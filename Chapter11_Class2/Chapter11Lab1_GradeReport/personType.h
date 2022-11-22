/*
David Garrett
Chapter 11 Lab 1 GradeReport
11-21-22
*/

#pragma once

#ifndef H_personType
#define H_personType
#include <string>
#include <iostream>
using namespace std;

class personType
{
public:
	void print() const; // Prints Name
	void setName(string first, string last); // Mutator
	string getFirstName() const; // Accessor
	string getLastName() const; // Accessor
	personType(string first = "", string last = ""); // Constructor
private:
	string firstName;
	string lastName;
};

#endif