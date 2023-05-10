/* @Author
 * Student Name:  <Serhat Sarı>
 * Student ID : <150200068>
 */
#include <stdlib.h>
#include <iostream>
#include "university.h"

University::University(std::string name, float gpa , float gre, float toefl , float bias , std::string country){

    this-> university_name = name; 
    this-> weight_gpa = gpa; 
    this-> weight_gre = gre;
    this-> weight_toefl = toefl;
    this-> bias = bias;
    this-> country = country; 

}

void University::evaluate_student(const Student& student){

    student.increase_noa();

    total = weight_gpa*student.get_gpa() + weight_gre*student.get_gre() + weight_toefl*student.get_toefl() + bias;

    if(total >= 0){
        std::cout << student.get_name() << "" << " is admitted to " << university_name << "." << '\n';
    }
    else{
        std::cout << student.get_name() << "" << " is rejected from " << university_name << "." << '\n';
    }
   

}