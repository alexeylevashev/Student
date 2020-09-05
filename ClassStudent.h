#pragma once

#include <string>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

class Student {
public:
    string lastName; //Фамилия
    string firstName; //Имя
    Date dateBirth; //Дата рождения
    string faculty; //Факультет
    string group; //Группа
    int stage; //Курс
    bool study; //Учится?
    void SetAge(int age); //Установка занчения возраста
    int GetAge(); //Получение значения возраста
    static const int SIZE = 4;
    int marks[SIZE]; // Массив с оценками за 4 семестра
    void SetMarks(int mark, int semester); //Ввод оценок
    float GetAverMark(); //Получение средней оценки
private:
    int age; //Возраст
    float averMark; //Средняя оценка
};

void Student::SetAge(int age) {
    if (age <= 10 || age > 80) {
        throw -1;
    } else {
        this->age = age;
    }
}

int Student::GetAge() {
    return age;
}

void Student::SetMarks(int mark, int semester) {
    if (mark <= 0 || mark > 5) {
        throw -2;
    } else {
        marks[semester-1] = mark;
    }
}

float Student::GetAverMark() {
    int tempMark = 0;
    for (int i = 0; i < SIZE; ++i) {
        tempMark += marks[i];
    }
    averMark = tempMark / 4;
    return averMark;
}