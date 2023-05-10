/* @Author
 * Student Name:  <Serhat Sarı>
 * Student ID : <150200068>
 */
#include <iostream>
#include <string>
#include <stdlib.h>
#include "student.h"

class University{

    public:
        University(std::string, float, float ,float ,float, std::string = ""); // Constructor, Country name is empty for default.
        void evaluate_student(const Student&) ; // Evaluate student function.
    private:
        std::string university_name = "", country = "";
        float weight_gpa, weight_gre, weight_toefl, bias;  // Random values between 1 and 10
        mutable float total = 0; // Total value for evaluating a student.
};