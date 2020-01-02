/*
File Name: testIComparable.cpp
Author: Dr. Aziz 
Course/Project: CSC 402/502, Project3
Purpose:  Test driver for Integer objects.
          You must provide the test cases as needed for Double and Character objects.
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
    (i4 == i3) ? cout << "i4 == i3" << endl : cout << "ERROR: i4 == i3 should be true" << endl;

    cout << endl;

	// TODO:  Implement the same kind of test cases for individual 
    //   stack-allocated Doubles and Characters
   // You do not have to cover every function, but include multiple types of 
   // constructors, a sampling of the relational operators, and operator<<
  
















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



    // TODO:  Implement the same kind of test cases for individual IComparable pointers initialized as 
    //   heap-allocated Doubles and Characters
	// You do not have to cover every function, but include multiple types of 
	// constructors, a sampling of the relational operators, and operator<<


















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




    // to avoid memory leaks, delete any of your individual Integer*, Character*, and Double* objects
    delete ip1, ip2, ip3, ip4;

    // Do a similar cleanup for any vector<Icomparable*> data structures you might have created
	// Note that it's not as simple as delete[] with a primitive array! 
    for (unsigned int i = 0; i < SIZE; i++) {
        delete intVector[i];

    }

    cin.get();
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

