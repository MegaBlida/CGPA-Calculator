#include <iostream>
#include "CGPA_HEAD.hpp"
#include <vector>
#include <string>


#include <iostream>
#include "CGPA_HEAD.hpp"
#include <vector>
#include <string>
#include <limits>
#include <regex>
#include <thread> 
#include <chrono>
#include <sstream> 

int num_course;
int i = 0;
int delay = 100;
std::vector<std::string> course_name;
std::string input_course;
char input_grade;
std::vector<char> course_grade;

void printWordsWithDelay(const std::string& text, int delayMs){

  std::istringstream iss(text);
  std::string word;

  while(iss >> word){

    std::cout<< word<<' '<<std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));

  }
  std::cout << std::ends;
}

void get_information(){
    std::string text_1 = "Please write down how many courses you have take:  ";
    printWordsWithDelay(text_1,delay);
    while (!(std::cin >> num_course) || num_course <= 0) {
    std::cout << "Invalid input. Please enter a positive integer for the number of courses: ";
    std::cin.clear(); 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    }

  
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout<<"What was the name of all the courses: ";

    for(int i = 0; i < num_course; i++){
          while(true){
          std::cout<< "\n"<<(i+1)<<".  ";
          std::getline(std::cin, input_course);

          if(std::regex_match(input_course, std::regex("^[A-Za-z ]+$"))){
              course_name.push_back(input_course);
              break;
          } else{
              std::cout << "Invalid input. Please enter a valid course name (letters and spaces only).";
            }
          }
        } 
     



   for (const auto& element : course_name){
      while(true){
        std::cout<<"What grade did you get in "<<element<<": ";
        std::cin>>input_grade;
        
        if(std::cin.fail() ||  std::cin.peek() != '\n'){
          std::cin.clear();
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
         std::cout << "Invalid input. Please enter a single character" << std::endl;
        } else {
           if (input_grade == 'A' || input_grade == 'B' || input_grade == 'C' || 
            input_grade == 'D' || input_grade == 'F') {
            course_grade.push_back(input_grade);
            break;
          } else {
           std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
          std::cout << "Invalid grade. Please enter a valid grade (A, B, C, D, F)." << std::endl;
         }
       }
    }
  }
}


void show_result(){

  double sum_grades;

  std::cout<<"Your Course And Grade \n";
  std::cout<<"*  *  *  *  *  *  *  *  *  *\n";
  for(int i = 0;i < course_name.size();i++){
    std::cout<<course_name[i]<<" "<<course_grade[i]<<"\n";
    std::cout<<"*  *  *  *  *  *  *  *  *  *\n";
  }

  for(const auto& element: course_grade ){

    switch(element){
      case 'A':
      sum_grades = sum_grades + 4.0;
      break;

      case 'B':
      sum_grades = sum_grades + 3.0;
      break;

      case 'C':
      sum_grades = sum_grades + 2.0;
      break;

      case 'D':
      sum_grades = sum_grades + 1.0;
      break;

      case 'F':
      sum_grades = sum_grades + 0;

      default:
      break;
    }
  }

  std::cout<<"Your total GPA is "<< sum_grades<<"\n";
  std::cout<<"Your CGPA is "<<(sum_grades/num_course)<<"\n";

  }
