/* @Author
 * Student Name:  <Serhat Sarı>
 * Student ID : <150200068>
 */
#include <iostream>
#include <string.h>
#include "student.h"


Student::Student(std::string name, float gpa,float gre ,float toefl){

    this->name = name;
    this->gpa = gpa;
    this->gre = gre;
    this->toefl = toefl;
    std::cout << name << " " << "logged in to the system." << '\n';

}

Student::Student(const Student& student){

    gpa = student.gpa;
    gre = student.gre;
    toefl = student.toefl;
    NumberOfApplications = student.NumberOfApplications;
    name = student.name;
    std::cout << name << " " << "logged in to the system." << '\n';

}

Student::~Student(){

    std::cout << name << " " << "logged out of the system with " << NumberOfApplications << " application(s)." << '\n';

}

void Student::set_name(std::string new_name){

    this-> name = new_name;

}

std::string Student::get_name() const {

    return this-> name;

}

float Student::get_gpa() const { 

    return this->gpa;

}

float Student::get_gre() const {

    return this->gre;

}

float Student::get_toefl() const {

    return this->toefl;

}

float Student::get_noa() const {

    return this->NumberOfApplications;

}

void Student::increase_noa() const {

    this->NumberOfApplications++;

}
  