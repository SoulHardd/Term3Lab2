#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

typedef std::string String;

class Student
{
private:
    long id;
    String name;
    String surname;
    double avg_grade;
    String university;

public:
    Student()
    {
        this->id = -1;
        avg_grade = 0;
        name = "";
        surname = "";
        university = "";
    }

    Student(
        long id,
        String name,
        String surname,
        double avg_grade,
        String university)
    {
        this->id = id;
        this->avg_grade = avg_grade;
        this->name = std::move(name);
        this->surname = std::move(surname);
        this->university = std::move(university);
    }

    void Fill(
        long id,
        String name,
        String surname,
        double avg_grade,
        String university)
    {
        this->id = id;
        this->avg_grade = avg_grade;
        this->name = std::move(name);
        this->surname = std::move(surname);
        this->university = std::move(university);
    }

    String getName() const
    {
        return name;
    }

    String getSurname() const
    {
        return surname;
    }

    String getUniversity() const
    {
        return university;
    }

    long getId() const
    {
        return id;
    }

    double getAvgGrade() const
    {
        return avg_grade;
    }

    friend std::ostream &operator<<(std::ostream &os, const Student &s)
    {
        return os << "|id: " << s.getId()
                  << "|name: " << s.getName()
                  << "|surname: " << s.getSurname()
                  << "|university: " << s.getUniversity()
                  << "|average grade: " << s.getAvgGrade() << "|\n";
    }

    friend std::istream &operator>>(std::istream &is, Student &s)
    {
        std::cout << "Id: ";
        is >> s.id;
        std::cout << "Name: ";
        is >> s.name;
        std::cout << "Surname: ";
        is >> s.surname;
        std::cout << "University: ";
        is >> s.university;
        std::cout << "Average grade: ";
        is >> s.avg_grade;
        return is;
    }
};

#endif
