//Title:        amortization-scheduler.cpp
//Author:       Emmanuela Fleurant
//Description:  This program will accepts user's prince, interest 
//              and payment on a loan and return a formatted tabular 
//              schedule for the loan



// 8/8/2025     Create the program from a past assignment


//Input:         Principle
//               Yearly Interest
//               Monthly Payment
//Output:        A nicely formated tabular output

#include <iostream>
#include <iomanip> //used for tabular format


void amortizationScheduler (){

    //Assign all user's data
    double principal, yearlyInterest, monthlyPayment; 
    int month = 1; 


    //Accepts user's initial loan amount
    std::cout <<"Principle $: "; 
    std::cin >> principal; 

    //Accepts the yearly interest
    std::cout <<"Yearly Interest (%): ";
    std::cin >> yearlyInterest;

    //Accepts the monthly payment
    std::cout <<"Monthly Payment $: ";
    std::cin >> monthlyPayment; 

    //Calculate the monthly interest amount and 
    float monthlyInterest = yearlyInterest / 12.0/100.0; 

    //Headers for tabular format
    std::cout << "\nMonth\tPrincipal\tInterest Paid\tPrincipal Paid\tEnding Payment\t\tPayment Balance\n";
    std::cout << "-------------------------------------------------------------------------------------\n";

    std::cout << std::fixed << std::setprecision(2);


    //Algorithm provided by Professor
    while (principal >0){
        double startingBalance = principal;
        double interestPaid = principal* monthlyInterest;
        double principalPaid = monthlyPayment - interestPaid;

        if (principalPaid > principal) {
            principalPaid = principal;
            monthlyPayment= interestPaid + principalPaid;
             
        }

        principal -= principalPaid;

        std::cout << std::setw(5)<< month
                <<"\t" << std::setw(13) <<startingBalance
                 << "\t" << std::setw(13)<< interestPaid
                 << "\t" << std::setw(13)<< principalPaid
                 <<"\t" << std::setw(13) <<monthlyPayment
                 << "\t" << std::setw(17) << principal <<"\n"; 

        month++; 
        
    }
}

int main (){
    amortizationScheduler (); 
    return 0;
}

