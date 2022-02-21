#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <cstdio>
#include <limits>

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the function you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}


void main()
{
	// Start of the progrm

	int userChoice;
	string name;
	// display the menus option
	do {

		cout << "1: A List of All Items Purchased in a Given Day\n";
		cout << "2: A Number representing Times a Specific Item was Purchased\n";
		cout << "3: A Text-based Histogram \n";
		cout << "4: Exit\n";
		cout << "Enter your selection as a number 1, 2, 3 or 4.\n";

		if (cin >> userChoice)//read user choice
		{

			switch (userChoice) {

			case 1:
				cout << "Produce a list of all items purchased in a given day along with the number of times each item was purchased. \n";

				cout << "\n";
				CallProcedure("freq"); // call frequency function	
				cout << "\n";
				break;
			case 2:
				cout << "Produce a number representing how many times a specific item was purchased in a given day. \n";
				cout << "Please Enter an Item to Search: ";
				cin >> name;
				cout << "\n";
				cout << "The frequency of the " << name << " is : " << callIntFunc("frequency", name) << endl; // call the frequency function	and pass the argument
				cout << "\n";
				break;
			case 3:  // Case produces a text-based histogram fro,
				cout << "Produce a text-based histogram listing all items purchased in a given day, & their frequency.";
				cout << "\n";
				CallProcedure("histogram");// call text-based histogram function	
				cout << "\n";
				break;
			case 4:
				cout << "Thank you";
				break;

			default:
				cout << "Invalid Option, Try again" << endl;
				break;
			}
		}
		// Check for non integer characters
		else
		{
			// Output error message
			cout << "You entered non integer characters" << endl;
			break;
		}
	} while (userChoice != 4); //quit when user picks option 4, loop stops



//Pause the console to allow read
	std::getchar();

}
