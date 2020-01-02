/*
File Name: IComparable.h
Author: Will St. Onge
Course: CSC 402
Date: 1/2/20
*/

#pragma once

#include <iostream>

using namespace std;

class IComparable {
public:
	// TODO: provide a suitable destructor
	~IComparable() { };

	// Virtual functions
	virtual IComparable& operator=(const IComparable& rhs)
	{
		return *this;
	}
	virtual int compare(const IComparable& icmp) const = 0;
	virtual void print(ostream& out = cout) const = 0;

	// Operator overrides using the abstract function compare
	virtual bool operator==(const IComparable& rhs) const 
	{
		return (compare(rhs) == 0);
	}

	virtual bool operator<(const IComparable& rhs) const
	{
		return (compare(rhs) == -1);
	}

	virtual bool operator>(const IComparable& rhs) const
	{
		return (compare(rhs) == 1);
	}

	virtual bool operator!=(const IComparable& rhs) const
	{
		return (compare(rhs) != 0);
	}

	virtual bool operator<=(const IComparable& rhs) const
	{
		return (compare(rhs) != 1);
	}

	virtual bool operator>=(const IComparable& rhs) const
	{
		return (compare(rhs) != -1);
	}
};

// Non member insertion operator override
ostream& operator<<(ostream& out, const IComparable& rhs)
{
	// Calls the rhs' print function. Should go to a dirived class if called properly, else will print nothing.
	rhs.print(out);
	return out;
}