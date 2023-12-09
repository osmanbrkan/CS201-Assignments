//
//  main.cpp
//  Take Home Exam 2
//
//  Created by Osman Berk An on 3.11.2022.
//
// OSMAN BERK AN 28849 CS201 HOMEWORK2

#include <iostream>
#include <string>
#include <cmath>
#include "strutils.h"
using namespace std;

bool input_check(string math_expression, int num1, int num2, int num3) // check syntax of mathematical expression   5+7=12  4-+3=1
{
    string s1, s2,s3;
    if (math_expression.find("=") == -1)
    {
        return false;
    }
    if (math_expression.find("+") == -1&& math_expression.find("-")==-1)
        return false;

    if (math_expression.find("+") ==-1 && math_expression.find("=")==-1 && math_expression.find("-")==-1)
    {
        return false;
    }
    if (math_expression.find("=") < math_expression.find("+") && math_expression.find("=") < math_expression.find("-"))
    {
        return false;
    }
   

    s1 = itoa(num1);
    s2 = itoa(num2);
    s3 = itoa(num3);
   
    
    if (s1.length()+s2.length()+s3.length()+2 != math_expression.length())
        return false;
    
    return true;
}
    
void question_parse(string math_expression, int &num1, int &num2, int &num3, string &op )    // 21+5=26
{
   
    
    int no1, no2, no3;
    string  stringtemp,  string_L, string_R,string_E;
    
    
    no3 = math_expression.find("="); // = in bulunduğu index
    
    stringtemp  = math_expression.substr(0,no3);   // 21+5=26   stringtemp = 21+5
    string_E = math_expression.substr(no3+1);    // string_E = 26
    
    no1 = stringtemp.find("+");  // soldan ilk + nın indexi
    no2 = stringtemp.find("-");  // soldan ilk - nin indexi
    if ((no2<no1 && no2!=-1) || no1==-1)
    {
        no1=no2;
    }
    string_L = stringtemp.substr(0,no1);  // num1 = string_L
    string_R = stringtemp.substr(no1+1,stringtemp.length());   // num2 = string_R
    if (string_L.length() == 0)
    {
        no1 = string_R.find("+");
        no2 = string_R.find("-");
        if ((no2<no1 && no2 != -1) || no1 == -1)
        {
            no1=no2;
        }
        string_L = stringtemp.substr(0,no1+1);   //num1 = string_L
        string_R = string_R.substr(no1+1);       //num2 = string_R
    }
    op = math_expression.substr(string_L.length(),1);
    
    

    num1 = atoi(string_L);// -198+-3 =
    num2 = atoi(string_R);
    num3 = atoi(string_E);

    
}

bool check_result(int &num1, int &num2, int &num3,int &result, string op  ) // 21+5 = 26 // 26-5 = 21
{
    if (op == "+")
    {
        if ( num3 != (num1 + num2)){
            result = (num1 + num2);
            return false;
        }
        else{
            return true;
        }
    }
    else if (op == "-")
    {
        if ( num3 != (num1 - num2))
        {
            result = num1-num2;
            return false;
        }
        else{
            return true;
        }
    }
    else{
        return false;
    }
    

}





int main()
{
    
    
    string expression1, expression2, expression3, expression4, op,joker;
    int num1, num2, num3, point, joker_counter,result;
    point = 0;
    joker_counter = 0 ;
        
// expression1
    
    cout << "Please enter question #1 and its answer: ";
    cin >> expression1;
    question_parse(expression1, num1, num2, num3, op );
    input_check(expression1,num1,num2,num3);
    check_result( num1, num2, num3,result, op);
    if (input_check(expression1,num1,num2,num3) == false)
    {
        cout << "Wrong input format! You got -10 penalty points for this math expression." << endl << endl;
        point = point-10;
    }
    else if ( input_check(expression1,num1,num2,num3) == true && check_result(num1,num2,num3,result,op) == true)
    {
        point= point + 25;
        cout << "Correct answer! You got 25 points for this math expression." << endl << endl;
    }
    else if ( input_check(expression1,num1,num2,num3) == true && check_result( num1, num2, num3,result, op) == false && joker_counter == 0)
    {
        cout << "Wrong!" << endl;
        cout << "Would you like to use your joker option to correct the answer? ";
        cin >> joker ;
        if ( LowerString(joker) == "no")
        {
            
            cout << "Sorry! The answer should have been: " << result << ". You got 0 points for this math expression." << endl << endl;
        }
        else if ( LowerString(joker) == "yes")
        {
            joker_counter = 1;
            cout << "Please enter the expression again: " ;
            cin >> expression1;
            question_parse(expression1, num1, num2, num3, op );
            if ( input_check(expression1,num1,num2,num3) == true && check_result(num1,num2,num3,result,op) == true)
            {
                cout << "Correct answer! You got 25 points for this joker option." << endl << endl;
                point = point + 25;
            }
            else if (input_check(expression1,num1,num2,num3) == false )
            {
                cout << "Wrong input format! You got -10 penalty points for this joker option." << endl << endl;
                point = point-10;
            }
            else if (input_check(expression1,num1,num2,num3) == true && check_result(num1, num2, num3,result,op) == false)
            {
                cout << "Sorry! The answer should have been: " << result << ". You got -10 penalty points for this joker option." << endl << endl;
                point = point-10;
            }
        }
        
        
    }
    else if  ( input_check(expression1,num1,num2,num3) == true && check_result(num1, num2, num3,result, op) == false && joker_counter == 1)
    {
        cout << "Sorry! The answer should have been: " << result << ". You got 0 points for this math expression." << endl << endl;
    }
    
    
//expression2
    
    cout << "Please enter question #2 and its answer: ";
    cin >> expression2;
    question_parse(expression2, num1, num2, num3, op );
    input_check(expression2,num1,num2,num3);
    check_result(num1, num2, num3,result, op);
    if (input_check(expression2,num1,num2,num3) == false)
    {
        cout << "Wrong input format! You got -10 penalty points for this math expression."<< endl << endl;
        point = point-10;
    }
    else if ( input_check(expression2,num1,num2,num3) == true && check_result(num1,num2,num3,result,op) == true)
    {
        point= point + 25;
        cout << "Correct answer! You got 25 points for this math expression." << endl << endl;
    }
    else if ( input_check(expression2,num1,num2,num3) == true && check_result(num1, num2, num3,result, op) == false && joker_counter == 0)
    {
        cout << "Wrong!" << endl;
        cout << "Would you like to use your joker option to correct the answer? ";
        cin >> joker ;
        if ( LowerString(joker) == "no")
        {
            
            cout << "Sorry! The answer should have been: " << result << ". You got 0 points for this math expression." << endl << endl;
        }
        else if ( LowerString(joker) == "yes")
        {
            joker_counter = 1;
            cout << "Please enter the expression again: " ;
            cin >> expression2;
            question_parse(expression2, num1, num2, num3, op );
            if ( input_check(expression2,num1,num2,num3) == true && check_result(num1,num2,num3,result,op) == true)
            {
                cout << "Correct answer! You got 25 points for this joker option." << endl << endl;
                point = point + 25;
            }
            else if (input_check(expression2,num1,num2,num3) == false )
            {
                cout << "Wrong input format! You got -10 penalty points for this joker option." << endl << endl;
                point = point-10;
            }
            else if (input_check(expression2,num1,num2,num3) == true && check_result(num1, num2, num3,result, op) == false)
            {
                cout << "Sorry! The answer should have been: " << result << ". You got -10 penalty points for this joker option." << endl << endl;
                point = point-10;
            }
        }
        
        
    }
    else if  ( input_check(expression2,num1,num2,num3) == true && check_result(num1, num2, num3,result, op) == false && joker_counter == 1)
    {
        cout << "Sorry! The answer should have been: " << result << ". You got 0 points for this math expression." << endl << endl;
    }
    
    
    
    
// expression3
    cout << "Please enter question #3 and its answer: ";
    cin >> expression3;
    question_parse(expression3, num1, num2, num3, op );
    input_check(expression3,num1,num2,num3);
    check_result(num1, num2, num3,result, op);
    if (input_check(expression3,num1,num2,num3) == false)
    {
        cout << "Wrong input format! You got -10 penalty points for this math expression."<< endl << endl;
        point = point-10;
    }
    else if ( input_check(expression3,num1,num2,num3) == true && check_result(num1,num2,num3,result,op) == true)
    {
        point= point + 25;
        cout << "Correct answer! You got 25 points for this math expression." << endl << endl;
    }
    else if ( input_check(expression3,num1,num2,num3) == true && check_result(num1, num2, num3,result, op) == false && joker_counter == 0)
    {
        cout << "Wrong!" << endl;
        cout << "Would you like to use your joker option to correct the answer? ";
        cin >> joker ;
        if ( LowerString(joker) == "no")
        {
            
            cout << "Sorry! The answer should have been: " << result << ". You got 0 points for this math expression." << endl << endl;
        }
        else if ( LowerString(joker) == "yes")
        {
            joker_counter = 1;
            cout << "Please enter the expression again: " ;
            cin >> expression3;
            question_parse(expression3, num1, num2, num3, op );
            if ( input_check(expression3,num1,num2,num3) == true && check_result(num1,num2,num3,result,op) == true)
            {
                cout << "Correct answer! You got 25 points for this joker option." << endl << endl;
                point = point + 25;
            }
            else if (input_check(expression3,num1,num2,num3) == false )
            {
                cout << "Wrong input format! You got -10 penalty points for this joker option." << endl << endl;
                point = point-10;
            }
            else if (input_check(expression3,num1,num2,num3) == true && check_result(num1, num2, num3,result, op) == false)
            {
                cout << "Sorry! The answer should have been: " << result << ". You got -10 penalty points for this joker option." << endl << endl;
                point = point-10;
            }
        }
        
        
    }
    else if  ( input_check(expression3,num1,num2,num3) == true && check_result(num1, num2, num3,result, op) == false && joker_counter == 1)
    {
        cout << "Sorry! The answer should have been: " << result << ". You got 0 points for this math expression." << endl << endl;
    }
    
    
    
// expression4
    cout << "Please enter question #4 and its answer: ";
    cin >> expression4;
    question_parse(expression4, num1, num2, num3, op );
    input_check(expression4,num1,num2,num3);
    check_result(num1, num2, num3,result, op);
    if (input_check(expression4,num1,num2,num3) == false)
    {
        cout << "Wrong input format! You got -10 penalty points for this math expression."<< endl << endl;
        point = point-10;
    }
    else if ( input_check(expression4,num1,num2,num3) == true && check_result(num1,num2,num3,result,op) == true)
    {
        point= point + 25;
        cout << "Correct answer! You got 25 points for this math expression." << endl << endl;
    }
    else if ( input_check(expression4,num1,num2,num3) == true && check_result(num1, num2, num3,result, op) == false && joker_counter == 0)
    {
        cout << "Wrong!" << endl;
        cout << "Would you like to use your joker option to correct the answer? ";
        cin >> joker ;
        if ( LowerString(joker) == "no")
        {
            
            cout << "Sorry! The answer should have been: " << result << ". You got 0 points for this math expression." << endl << endl;
        }
        else if ( LowerString(joker) == "yes")
        {
            joker_counter = 1;
            cout << "Please enter the expression again: " ;
            cin >> expression4;
            question_parse(expression4, num1, num2, num3, op );
            if ( input_check(expression4,num1,num2,num3) == true && check_result(num1,num2,num3,result,op) == true)
            {
                cout << "Correct answer! You got 25 points for this joker option." << endl << endl;
                point = point + 25;
            }
            else if (input_check(expression4,num1,num2,num3) == false )
            {
                cout << "Wrong input format! You got -10 penalty points for this joker option." << endl << endl;
                point = point-10;
            }
            else if (input_check(expression4,num1,num2,num3) == true && check_result(num1, num2, num3,result, op) == false)
            {
                cout << "Sorry! The answer should have been: " << result << ". You got -10 penalty points for this joker option." << endl << endl;
            }
        }
        
        
    }
    else if  ( input_check(expression4,num1,num2,num3) == true && check_result(num1, num2, num3,result, op) == false && joker_counter == 1)
    {
        cout << "Sorry! The answer should have been: " << result << ". You got 0 points for this math expression." << endl << endl;
    }
    
    if (point <0)
    {
        point = 0;
    }
    cout << "End of the program. You got " << point << " points in total." << endl;
    
        
    return 0;
        
}
// OSMAN BERK AN CS201 HOMEWORK 2
