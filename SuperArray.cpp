// File: SuperArray
// Created by Hugo Valle on 10/31/2017.
// Copyright (c) 2017 WSU
//

#include <cstring>
#include "SuperArray.h"
/*!
 * Constructor
 * @param begIndex User's low index
 * @param capacity Maximum array capacity
 */
SuperArray::SuperArray(const int begIndex, const unsigned int capacity)
{
	/* This is declaring a local variable, if you have data member
     * called int* arr, the code on line ## will NOT refer to the data
     * member, instead you created a second arr pointer, and this
     * second pointer dies and is lost forever when the constructor ends
     */
	arr = new int[capacity];
	SuperArray::capacity = capacity;
	SuperArray::lowIndex = begIndex;
	SuperArray::highIndex = begIndex + capacity - 1;
	// Other info below
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
* Obtaining The low index of the super array
* @param returning the low index
*/
int SuperArray::getLowIndex() const
{
	return lowIndex;
}
/*!
* Obtaining The high index of the super array
* @param returning the high index of the super array
*/
int SuperArray::getHighIndex() const
{
	return highIndex;
}
/*!
* Obtaining The length of the super array
* @param returning the lenth of the super array
*/
unsigned int SuperArray::length() const
{
	return capacity;
}
/*!
* Index operator overload
* @param index User's index notation
* @return Actual index notation
*/
int &SuperArray::operator[](const int index)
{
	int realIndex = index - lowIndex;

	if (index < lowIndex)
		throw("Invalid index request, too low");
	if (index > highIndex)
		throw("Invalid index request, too high");

	return arr[realIndex];
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*!
 * Class Destructor
 */
SuperArray::~SuperArray()
{
	delete[] arr;
}


/*!
 * Convert int array to string.
 * Note: You do not need to modify this function
 * @param obj Instance of SuperArray to convert to string
 * @return string form of array
 */
string arrayToString(const SuperArray& obj)
{
	stringstream ss;

	for (int i = 0; i < obj.capacity; i++)
	{
		//cout << obj.arr[i] << " i " << i<<endl;
		ss << obj.arr[i] << " ";
	}
	string str = ss.str();
	size_t found;
	found = str.find_last_not_of(" ");
	if (found != string::npos)
		str.erase(found + 1);
	else
		str.clear();            // str is all whitespace

	return str;
}

void SuperArray::resize(const int begIndex, const unsigned int capacity2)
{
	/*int *p = new int[capacity];
    for(int i = begIndex; i < lowIndex; i++)
    {
        p[i] = '0';
		//cout << p[i];
    }
    for(int i = lowIndex; i <= highIndex; i++)
    {
        p[i] = arr[i];
    }
	*arr = *p;
	delete[] p;
	cout << lowIndex << " = LowIndex; " << highIndex << " = HighIndex; " << capacity << " = Capacity.";
	for(int i = lowIndex, j = 0; i <= highIndex; i++, j++)
	{
		p[i] = arr[i];
	}
	lowIndex = begIndex;
	/*highIndex = begIndex + capacity - 1;
	SuperArray::capacity = capacity;
	*arr = *p;
	delete[] p;*/

	int *p = new int[capacity2];

	int templow = lowIndex, tempHigh = highIndex;
	//cout << endl << endl << "low and high:  " << lowIndex << ","<< highIndex << "," << capacity2 << endl ;
	for(int i = 0; i < lowIndex; i++) *(p+i) = 0;

	templow = (lowIndex-(begIndex));
	tempHigh = (highIndex-(begIndex));

	for(int i = templow, j=0; i <= tempHigh; i++, j++)
	{
		p[i] = arr[j];
	}

	for(int i = 0; i < capacity2; i++)*(arr+i) = *(p+i);
	//memcpy(p, arr, capacity2);

	//cout << "P[5] = " << p[5] << endl;
	//cout << "P = ";
	//for(int i = 0; i < capacity2; i++)
	//{
	//	cout << *(p+i) << ",";
	//}
	//cout << endl;
	*arr = *p;
	//cout << "Arr = ";
	//for(int i = 0; i < capacity2; i++)
	//{
	//	cout << *(arr+i) << ",";
	//}
	delete[] p;

	lowIndex = begIndex;
	SuperArray::capacity = capacity2;
	highIndex = begIndex + capacity2 - 1;
	//cout << endl << "End function" << endl;
}
