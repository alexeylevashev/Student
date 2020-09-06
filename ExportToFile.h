#pragma once

#include <fstream>
#include <string>
#include "ClassStudent.h"

using namespace std;

void ExportToFile(string path, string str) {
    ofstream file;
    file.open(path, ios::out | ios::trunc);
    if (!file.is_open()) {
// TODO создать исключения, если файл не открылся
    } else{
        file << str << endl;
        file.close();
    }
}

void Export(Student students[], const int size)
{
    string temp;
for (int i=0; i<size;i++){
    // lastName;firstName;date...
    temp+=students[i].lastName + ";";
    temp+=students[i].firstName + ";";
    temp+=to_string(students[i].dateBirth.day) + "." + to_string(students[i].dateBirth.month) + "." + to_string(students[i].dateBirth.year) + ";";
    temp+=to_string(students[i].GetAge()) + ";";
    temp+=students[i].faculty + ";";
    temp+=students[i].group + ";";
    temp+=to_string(students[i].stage) + ";";
    temp+=to_string(students[i].study) + "\n";

}
ExportToFile("student.csv", temp);
}