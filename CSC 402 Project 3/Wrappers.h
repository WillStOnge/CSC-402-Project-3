/*
File Name: Wrappers.h
Author: Will St. Onge
Course: CSC 402
Date: 1/2/20
*/

#pragma once

#include "IComparable.h"

class Integer : public IComparable
{
public:
	// Constructors can accept a primitve int, another Integer, or an instance of IComparable.
	Integer(const int i = 0) : value(i) { }
	Integer(const Integer& i) : value(i.value) { }
	Integer(const IComparable& rhs) : value(dynamic_cast<const Integer&>(rhs).value) { } // RTTI

	// Copy assignment operator override.
	IComparable& operator=(const IComparable& other)
	{
		// RTTI
		const Integer* temp = dynamic_cast<const Integer*>(&other);

		// If the pointer is valid, the cast succeeded so we can use the value. Else we assign the default value for an Integer
		if (temp)
			value = temp->value;
		else
			value = 0;

		return *this;
	}

	// Override of the compare function
	int compare(const IComparable& rhs) const
	{
		// RTTI
		int other = dynamic_cast<const Integer&>(rhs).value;

		// Return a 1, 0, or -1 if the number is greater than, equal to, or less than respectively.
		if (value == other)
			return 0;
		return (value > other) ? 1 : -1;
	}
	
	// Override of the print function
	void print(ostream& out = cout) const 
	{
		out << value;
	}

private:
	int value;
};

class Double : public IComparable
{
public:
	// Constructors can accept a primitve double, another Double, or an instance of IComparable.
	Double(const double i = 0.0) : value(i) { }
	Double(const Double& i) : value(i.value) { }
	Double(const IComparable& rhs) : value(dynamic_cast<const Double&>(rhs).value) { } // RTTI

	// Copy assignment operator override.
	IComparable& operator=(const IComparable& other)
	{
		// RTTI
		const Double* temp = dynamic_cast<const Double*>(&other);

		// If the pointer is valid, the cast succeeded so we can use the value. Else we assign the default value for an Double
		if (temp)
			value = temp->value;
		else
			value = 0;

		return *this;
	}

	// Override of the compare function
	int compare(const IComparable& rhs) const
	{
		// RTTI
		double other = dynamic_cast<const Double&>(rhs).value;

		// Return a 1, 0, or -1 if the number is greater than, equal to, or less than respectively.
		if (value == other)
			return 0;
		return (value > other) ? 1 : -1;
	}

	// Override of the print function
	void print(ostream& out = cout) const
	{
		out << value;
	}

private:
	double value;
};

class Character : public IComparable
{
public:
	// Constructors can accept a primitve int, another Integer, or an instance of IComparable.
	Character(const char i = '?') : value(i) { }
	Character(const Character& i) : value(i.value) { }
	Character(const IComparable& rhs) : value(dynamic_cast<const Character&>(rhs).value) { } // RTTI

	// Copy assignment operator override.
	IComparable& operator=(const IComparable& other)
	{
		// RTTI
		const Character* temp = dynamic_cast<const Character*>(&other);

		// If the pointer is valid, the cast succeeded so we can use the value. Else we assign the default value for an Integer
		if (temp)
			value = temp->value;
		else
			value = 0;

		return *this;
	}

	// Override of the compare function
	int compare(const IComparable& rhs) const
	{
		// RTTI
		char other = dynamic_cast<const Character&>(rhs).value;

		// Return a 1, 0, or -1 if the number is greater than, equal to, or less than respectively.
		if (value == other)
			return 0;
		return (value > other) ? 1 : -1;
	}

	// Override of the print function
	void print(ostream& out = cout) const
	{
		out << value;
	}

private:
	char value;
};