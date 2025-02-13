/*
File Name: testIComparable.cpp
Author: Will St. Onge
Course: CSC 402
Date: 1/2/20
*/

#pragma warning(disable: 26451)

#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include "Wrappers.h"

using namespace std;

// forward declarations for local sort and related functions
void print(const vector<IComparable*>&);
void sort(vector<IComparable*>&);
bool isSorted(const vector<IComparable*>&);

const string SEPARATOR = "===========================================================================";

int main()
{
    // seed the random number generator
    srand(static_cast<unsigned int>(time(NULL)));
    // convenient way to test with different size vectors
    const size_t SIZE = 50;    // should be enough to demonstrate sorting

	// set bool display type
	cout << boolalpha; 

    // TEST CASES FOR STACK_BASED INTEGERS PROVIDED

    cout << endl << "Stack-based Integer constructors, operator=, and << tests:" << endl << SEPARATOR << endl;
    // default construction (value set to zero)
    Integer i1;
    cout << "i1 = " << i1 << endl;
    // non-default construction
    Integer i2(10);
    cout << "i2 = " << i2 << endl;
    // copy constructor
    Integer i3 = i2;
    cout << "i3 = " << i3 << endl;
    // copy assignment operator
    Integer i4;
    i4 = i3;
    cout << "i4 = " << i4 << endl;

    cout << endl << "Stack-based Integer relational operator tests:" << endl << SEPARATOR << endl;
    (i1 < i2) ? cout << "i1 < i2" << endl : cout << "ERROR: i1 <  i2 should be true" << endl;
    (i1 != i2) ? cout << "i1 != i2" << endl : cout << "ERROR: i1 != i2 should be true" << endl;
    (i1 <= i2) ? cout << "i1 <= i2" << endl : cout << "ERROR: i1 <= i2 should be true" << endl;
    (i1 == i1) ? cout << "i1 == i1" << endl : cout << "ERROR: i1 == i1 should be true" << endl;

    (i2 > i1) ? cout << "i2 > i1" << endl : cout << "ERROR: i2 >  i1 should be true" << endl;
    (i2 == i3) ? cout << "i2 == i3" << endl : cout << "ERROR: i2 == i3 should be true" << endl;
    (i2 >= i1) ? cout << "i2 >= i1" << endl : cout << "ERROR: i2 >= i1 should be true" << endl;
    (i3 >= i3) ? cout << "i3 >= i3" << endl : cout << "ERROR: i3 >= i3 should be true" << endl;
    (i4 == i3) ? cout << "i4 == i3" << endl : cout << "ERROR: i4 == i3 should be true" << endl << endl;

	// Test cases for Double
  
	cout << endl << "Stack-based Double constructors, operator=, and << tests:" << endl << SEPARATOR << endl;

	Double d1, d2(2.4), d3 = d2, d4;
	d4 = d3;

	cout << "d1 = " << d1 << "\nd2 = " << d2 << "\nd3 = " << d3 << "\nd4 = " << d4 << endl;

	cout << endl << "Stack-based Double relational operator tests:" << endl << SEPARATOR << endl;
	(d2 > d1) ? cout << "d2 > d1" << endl : cout << "ERROR: d2 > d1 should be true" << endl;
	(d2 == d3) ? cout << "d2 == d3" << endl : cout << "ERROR: d2 == d3 should be true" << endl;
	(d2 >= d1) ? cout << "d2 >= d1" << endl : cout << "ERROR: d2 >= d1 should be true" << endl;
	(d3 >= d3) ? cout << "d3 >= d3" << endl : cout << "ERROR: d3 >= d3 should be true" << endl;
	(d4 == d3) ? cout << "d4 == d3" << endl : cout << "ERROR: d4 == d3 should be true" << endl << endl;

	// Test cases for Character

	cout << endl << "Stack-based Character constructors, operator=, and << tests:" << endl << SEPARATOR << endl;

	Character c1, c2('Z'), c3 = c2, c4;
	c4 = c3;

	cout << "c1 = " << c1 << "\nc2 = " << c2 << "\nc3 = " << c3 << "\nc4 = " << c4 << endl;

	cout << endl << "Stack-based Character relational operator tests:" << endl << SEPARATOR << endl;
	(c2 > c1) ? cout << "c2 > c1" << endl : cout << "ERROR: c2 > c1 should be true" << endl;
	(c2 == c3) ? cout << "c2 == c3" << endl : cout << "ERROR: c2 == c3 should be true" << endl;
	(c2 >= c1) ? cout << "c2 >= c1" << endl : cout << "ERROR: c2 >= c1 should be true" << endl;
	(c3 >= c3) ? cout << "c3 >= c3" << endl : cout << "ERROR: c3 >= c3 should be true" << endl;
	(c4 == c3) ? cout << "c4 == c3" << endl : cout << "ERROR: c4 == c3 should be true" << endl << endl;

    // To support runtime polyporphism, we need to be able to handle IComparable pointers
    //   in addition to stack-allocated instances of IComparable derived classes

	// TEST CASES FOR POLYMORPHIC ICOMPARABLE POINTERS INITIALIZED AS INTEGERS 
	// PROVIDED 

    cout << endl << "Integer test cases using IComparable pointers" << endl << SEPARATOR << endl;
    IComparable* ip1 = new Integer;      // default constructor
    IComparable* ip2 = new Integer(10);
    cout << "*ip1 = " << *ip1 << endl;
    cout << "*ip2 = " << *ip2 << endl;
    (*ip1 < *ip2) ? cout << "*ip1 < *ip2" << endl : cout << "ERROR: *ip1 < *ip2 should be true" << endl;

    cout << endl << "Integer copy construction using IComparable pointers" << endl << SEPARATOR << endl;
    IComparable* ip3 = new Integer(10);
    IComparable* ip4 = new Integer(*ip3);
    cout << "*ip3 = " << *ip3 << endl;
    cout << "*ip4 = " << *ip4 << endl;
    (*ip3 == *ip4) ? cout << "*ip3 == *ip4" << endl : cout << "ERROR: *ip3 == *ip4 should be true" << endl;
    cout << endl;

    cout << endl << "Integer copy assignment operators using IComparable pointers" << endl << SEPARATOR << endl;
    *ip2 = *ip1;
    cout << "*ip1 = " << *ip1 << endl;
    cout << "*ip2 = " << *ip2 << " after copy assignment " << endl;
    (*ip1 == *ip2) ? cout << "*ip1 == *ip2" << endl : cout << "ERROR: *ip1 == *ip2 should be true" << endl;
    cout << endl;

	// Test cases for Double

	cout << endl << "Double test cases using IComparable pointers" << endl << SEPARATOR << endl;
	IComparable* dp1 = new Double;      // default constructor
	IComparable* dp2 = new Double(2.4);
	cout << "*dp1 = " << *dp1 << endl;
	cout << "*dp2 = " << *dp2 << endl;
	(*dp1 < *dp2) ? cout << "*dp1 < *dp2" << endl : cout << "ERROR: *dp1 < *dp2 should be true" << endl;

	cout << endl << "Double copy construction using IComparable pointers" << endl << SEPARATOR << endl;
	IComparable* dp3 = new Double(2.4);
	IComparable* dp4 = new Double(*dp3);
	cout << "*dp3 = " << *dp3 << endl;
	cout << "*dp4 = " << *dp4 << endl;
	(*dp3 == *dp4) ? cout << "*dp3 == *dp4" << endl : cout << "ERROR: *dp3 == *dp4 should be true" << endl;
	cout << endl;

	cout << endl << "Double copy assignment operators using IComparable pointers" << endl << SEPARATOR << endl;
	*dp2 = *dp1;
	cout << "*dp1 = " << *dp1 << endl;
	cout << "*dp2 = " << *dp2 << " after copy assignment " << endl;
	(*dp1 == *dp2) ? cout << "*dp1 == *dp2" << endl : cout << "ERROR: *dp1 == *dp2 should be true" << endl << endl;

	// Test cases for Character

	cout << endl << "Character test cases using IComparable pointers" << endl << SEPARATOR << endl;
	IComparable* cp1 = new Character;      // default constructor
	IComparable* cp2 = new Character('Z');
	cout << "*cp1 = " << *cp1 << endl;
	cout << "*cp2 = " << *cp2 << endl;
	(*cp1 < *cp2) ? cout << "*cp1 < *cp2" << endl : cout << "ERROR: *cp1 < *cp2 should be true" << endl;

	cout << endl << "Character copy construction using IComparable pointers" << endl << SEPARATOR << endl;
	IComparable* cp3 = new Character('Z');
	IComparable* cp4 = new Character(*cp3);
	cout << "*cp3 = " << *cp3 << endl;
	cout << "*cp4 = " << *cp4 << endl;
	(*cp3 == *cp4) ? cout << "*cp3 == *cp4" << endl : cout << "ERROR: *cp3 == *cp4 should be true" << endl;
	cout << endl;

	cout << endl << "Character copy assignment operators using IComparable pointers" << endl << SEPARATOR << endl;
	*cp2 = *cp1;
	cout << "*cp1 = " << *cp1 << endl;
	cout << "*cp2 = " << *cp2 << " after copy assignment " << endl;
	(*cp1 == *cp2) ? cout << "*cp1 == *cp2" << endl : cout << "ERROR: *cp1 == *cp2 should be true" << endl << endl;

	//TEST CASES FOR ALL THREE VARIATIONS OF VECTORS OF ICOMPARABLE POINTERS PROVIDED
    // You just need to get them to run... and they should if the heap-based objects
	// function correctly.  

    cout << endl << "Vector of IComparable pointers initialized with heap-allocated Integers" << endl << SEPARATOR << endl;
    vector<IComparable*> intVector;
    // initialize with random primitive ints & single-arg constructor
    for (int i = 0; i < SIZE; i++)
        intVector.push_back(new Integer(rand()));

    cout << endl << "intVector before sorting:" << endl << SEPARATOR << endl;
    print(intVector);
    cout << boolalpha << "isSorted(intVector)?: " << isSorted(intVector) << endl;

    // local sort function
    sort(intVector);

    cout << endl << "intVector after sorting:" << endl << SEPARATOR << endl;
    print(intVector);
    cout << endl;
    cout << "isSorted(intVector): " << isSorted(intVector) << endl;


    cout << endl << "Vector of IComparable pointers initialized with heap-allocated Doubles" << endl << SEPARATOR << endl;
    vector<IComparable*> doubleVector;
    // initialize with random doubles
    for (int i = 0; i < SIZE; i++)
        doubleVector.push_back(new Double(rand() / 100.0));

    cout << endl << "doubleVector; before sorting:" << endl << SEPARATOR << endl;
    print(doubleVector);
    cout << "isSorted(doubleVector;)? (0 for false, 1 for true): " << isSorted(doubleVector) << endl;
    cout << endl;

    // local sort function
    sort(doubleVector);

    cout << endl << "doubleVector after sorting:" << endl << SEPARATOR << endl;
    print(doubleVector);
    cout << endl;
    cout << "isSorted(doubleVector): " << isSorted(doubleVector) << endl;
    cout << endl;

	vector<IComparable*> charVector;
	// initialize with ASCII characters in the range 65 - 123 only
	for (int i = 0; i < SIZE; i++)
		charVector.push_back(new Character(rand() % 59 + 65));

	cout << endl << "charVector before sorting:" << endl << SEPARATOR << endl;
	print(charVector);
	cout << "isSorted(charVector)? (0 for false, 1 for true): " << isSorted(charVector) << endl;
	cout << endl;

	// local sort function
	sort(charVector);

	cout << endl << "charVector after sorting:" << endl << SEPARATOR << endl;
	print(charVector);
	cout << endl;
	cout << "isSorted(charVector): " << isSorted(charVector) << endl;
	cout << endl;

    delete ip1, ip2, ip3, ip4;
    delete cp1, cp2, cp3, cp4;
    delete dp1, dp2, dp3, dp4;

    for (unsigned int i = 0; i < SIZE; i++) {
        delete intVector[i];
		delete doubleVector[i];
		delete charVector[i];
    }

    return 0;

}


// auxiliary functions for testing sorting on a vector of IComparable pointers
void print(const vector<IComparable*>& v)
{
    // if the vector is larger than a certain size, print only the first
    // ten elements and the last ten
    int size = (int)v.size();
    if (size > 100) {
        for (int i = 0; i < 10; i++)
            cout << *v[i] << "\t";

        cout << " ... " << endl;

        for (int i = 0; i < 10; i++)
            cout << *v[size - (i + 1)] << "\t";

        cout << endl;
    }
    else {
        for (auto item : v)   // auto requires C++11-compliant compiler
            cout << *item << "\t";
        cout << endl;
    }
}

// Selection sort, swapping pointers exclusively 
void sort(vector<IComparable*>& v) {
    int min;
    IComparable* tmp;

    for (unsigned int j = 0; j < v.size(); j++) {
        min = j;
        for (unsigned int i = j + 1; i < v.size(); i++) {
            // NOTE the use of the overloaded < operator
            if (*v[i] < *v[min]) {
                min = i;
            }
        }
        if (min != j) {
            tmp = v[j];
            v[j] = v[min];
            v[min] = tmp;
        }
    }
}

bool isSorted(const vector<IComparable *>& v) {
    bool sorted = true;
    for (unsigned int i = 1; i < v.size(); i++)
        if (*(v[i]) < *(v[i - 1])) {
            sorted = false;
            break;
        }
    return sorted;
}

