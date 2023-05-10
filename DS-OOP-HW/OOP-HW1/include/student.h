/* @Author
 * Student Name:  <Serhat Sarı>
 * Student ID : <150200068>
 */
#include <iostream>
#include <string>

class Student {

    public:
        Student(std::string, float,float,float); // Constructor - "Name, GPA, GRE, TOEFL"
        Student(const Student &Student); // Copy constructor
        ~Student(); // Destructor
        void set_name(std::string); // For changing name for the copied student object
        std::string get_name() const; // Name getter
        float get_gpa() const; // Gpa getter
        float get_gre() const; // Gre getter
        float get_toefl() const; // Toefl getter 
        float get_noa() const; // Number of Applications getter
        void increase_noa() const; // Increases the Number of Applications
    private:
        std::string name = ""; 
        mutable float gpa = 0, gre = 0,toefl = 0, NumberOfApplications = 0;
         

};