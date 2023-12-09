//
//  main.cpp
//  Take Home Exam 1
//
//  Created by Osman Berk An on 18.10.2022.
//

// Osman Berk An

#include <iostream>
#include <string>
using namespace std;

int main()
{
    
    string name;
    float midterm_grade;
    float final_grade;
    float weighted_exam_avr;
    float hw1, hw2, hw3, hw4, hw5;
    float hw_avg;
    float ratio;
    float hw_grade;
    float quiz1, quiz2, quiz3, quiz4;
    float quiz_grade;
    float sum_of_three_highest_quizzes = 0.0;
    float course_numeric_grade;

    
    cout << "The purpose of this program is to calculate your CS201 grade. What is your name? ";
    cin >> name;
    
    
    cout << "Hello " << name << "," << " what are your midterm and final exam grades? ";
    cin >> midterm_grade >> final_grade;
    
    
    weighted_exam_avr = ((0.30*midterm_grade) + (0.35*final_grade)) / 0.65;
    if ( weighted_exam_avr < 30 )
    {
        cout << name << ", your weighted exam average is less than 30, you will fail the course!" << endl;
    }
    
    else if ( weighted_exam_avr >= 30 )
    {
        
        cout << "What are the grades of your 5 homework? ";
        cin >> hw1 >> hw2 >> hw3 >> hw4 >> hw5;
        hw_avg = (hw1 + hw2 + hw3 + hw4 + hw5) / 5;
        ratio = hw_avg / weighted_exam_avr;
        
        if ( ratio <=2 )
        {
            hw_grade = hw_avg;
            cout << "You'll get all the points earned from homework!" << endl;
        }
                
        else if ( ratio > 2 && ratio < 3 )
        {
            hw_grade = hw_avg * (3 - ratio);
            cout << "You'll get " << hw_grade << " from the points earned from homework!" << endl;
        }
                
        else
        {
            hw_grade = 0;
            cout << "You'll get NONE of the points earned from homework!" << endl;
                    
        }

        cout << "What are the grades of your 4 quizzes? If any, enter your grade as 0 for missed quizzes. ";
        cin >> quiz1 >> quiz2 >> quiz3 >> quiz4;
        
        if ( quiz1 <= quiz2 && quiz1 <= quiz3 && quiz1 <= quiz4 )
            sum_of_three_highest_quizzes = quiz2 + quiz3 + quiz4;
        if ( quiz2 <= quiz1 && quiz2 <= quiz3 && quiz2 <= quiz4)
            sum_of_three_highest_quizzes = quiz1 + quiz3 + quiz4;
        if ( quiz3 <= quiz1 && quiz3 <= quiz2 && quiz3 <= quiz4)
            sum_of_three_highest_quizzes = quiz1 + quiz2 + quiz4;
        if ( quiz4 <= quiz1 && quiz4 <= quiz2 && quiz4 <= quiz3)
            sum_of_three_highest_quizzes = quiz1 + quiz2 + quiz3;
        
        quiz_grade = sum_of_three_highest_quizzes / 30 * 100;
        
        
            
            
            
        
        
        
        course_numeric_grade = (quiz_grade * 0.10) + (hw_grade * 0.25) + (midterm_grade * 0.30) + (final_grade * 0.35);
        
        cout << name <<  ", your grade for CS201 is: " << course_numeric_grade << endl;
    }
            
            
            
            
            
            
            
            
            
    return 0;
}

