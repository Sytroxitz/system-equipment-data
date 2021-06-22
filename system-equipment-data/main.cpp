#include <iostream>
#include <fstream>
#include <string>
#include <wtypes.h>

using namespace std;

int main() {

    fstream startup;
    startup.open("startup.txt", ios::in); //open a file to perform read operation using file object
    if (startup.is_open()) {   //checking whether the file is open
        string tp;
        while (getline(startup, tp)) {  //read data from file object and put it into string.
            cout << tp << "\n";   //print the data of the string
        }
        startup.close();   //close the file object.
    }

    HKEY keyHandle;
    WCHAR rgValue[1024];
    WCHAR fnlRes[1024];
    DWORD size1;
    DWORD Type;

    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion", 0, KEY_QUERY_VALUE | KEY_WOW64_64KEY, &keyHandle) == ERROR_SUCCESS)
    {
        size1 = 1023;
        RegQueryValueExW(keyHandle, L"Productid", NULL, &Type, (LPBYTE)rgValue, &size1);
        swprintf_s(fnlRes, L"Product ID of your Windows system is:: %s", rgValue);
        RegCloseKey(keyHandle);
    }
    else wcscpy_s(fnlRes, L"Couldn't access system information!");

    wcout << fnlRes;

	return 0;

}