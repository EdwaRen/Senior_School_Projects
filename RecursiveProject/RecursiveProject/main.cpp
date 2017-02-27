//
//  main.cpp
//  RecursiveProject
//
//  Created by - on 2016/11/21.
//  Copyright © 2016 Eddie of The Ren. All rights reserved.
//

#include <iostream>
using namespace std;

long factorial (  long n) {
    //A simple recursive function that multiplies the starting n value by n-1, n-2 ... until n = 1.
    long total = 1;
    
    if (n == 1) {
        total = 1;
    } else {
        total = n* factorial(n-1);
    }
    
    return total;
    
}

int tSequence(int n) {
    
    //Subtracts two for each recursion of the function. Sets the initial t value to 3.
    int termN = 3;
    
    if (n==1) {
        termN = 3;
    } else {
        termN = tSequence(n-1) -2;
    }
    
    cout << "T" << n << " = " << termN << ", ";
    
    return termN;
    
}

int getN(string a) {
    //Displays text asking the user for a number and gets it via cin.
    cout << "   " << a << endl;
    int n;
    cin >> n;
    return n;
}

long long tSequence2(int n) {
    //Simple recursive function to multiple a function by 2 with initial term at t = -1 for n times.
    
    long long termN = -1;
    
    if (n==1) {
        termN = -1;
    } else {
        termN = tSequence2(n-1)*2;
    }
    
    cout << "T" << n << " = " << termN << ", ";
    
    return termN;
    
}

long long fibonacci(int n) {
    //Sets the value of the fibonacci sequence for n = 0 and n = 1
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;

    }
    //Simply makes the nth value the addition of the n-1th and n-2th value.
    return fibonacci(n-1) + fibonacci(n-2);
    
}

int gcd(int x, int y){
    //If y is equal to 0, then gcd(x, y) is x; otherwise gcd(x, y) is gcd(y, x%y), where % is the modulus operator.
    
    int result = 0;
    if (y == 0) {
        //When y = 0, that means x divides by y without a remainder.
        result = x;
        return result;
    } else {
        result = gcd(y, x%y);
    }
    return result;
}

int leastCommonM (int x) {
    //This is also known as fractorials because they are the least common multiple of x numbers
    int total = 1;
    
    if (x == 1) {
        return total;
    } else {
        total = leastCommonM(x-1);
    }
    //When this function 'unwinds', the value of the function is multiplied by the x value. Then we divide it by the greatest common divisor of the previous total and the current x value. This effectively finds the new least common multiple (LCM) between the old LCM and the new x value.
    int totalO  = total;
    
    total = total * x;
    total = (total / gcd(totalO, x));
    
    return total;
    
    
}

void towerOfHanoi(int numDisks, int posInitial, int posTemp, int posFinal)
{
    
    if (numDisks == 0) {
        
    } else if( numDisks != 0 ) {
        //the function is called twice because the tower has to be deconstructed and then constructed again after the final peg is moved.
        towerOfHanoi( numDisks-1, posInitial, posFinal, posTemp);
        cout <<"("<< posInitial << " to " << posFinal << "), " << endl;
        towerOfHanoi( numDisks-1, posTemp, posInitial, posFinal);
   
    }
}


int main(int argc, const char * argv[]) {
    int n = 2;
    
    cout << "\nRecursive Question 1) Function to find factorial of n"<< endl;
    n = getN("Please enter an integer.");
    long finalFactorial = factorial(n);
    cout << "Factorial of "<< n << ": " << finalFactorial << endl;
    
    
    
    cout << "\n\nRecursive Question 2) T-series recursive sequence" << endl;
    n = getN("Please enter the number of terms in these two series'.");
    cout << "     First sequence: For " << n << " terms, the terms are:  ";
    tSequence(n);
    cout << "The final term is T" << n << "."<< endl;
    
    cout << "\n     Second sequence: For " << n << " terms, the terms are:  ";
    tSequence2(n);
    cout << "The final term is T" << n << "."<< endl;
    
    cout << "\n\nRecursive Question 3) Fibonacci Sequence" << endl;
    n = getN("Please enter the number of terms to be calculated in the fibonacci sequence.");
    int count = 1;
    while (count <= n) {
        cout << fibonacci(count) << " ";
        count++;
    }
    
    
    cout << "\n\nRecursive Question 4) Greatest Common Divisor" << endl;
    int x = getN("Please enter the first number.");
    int y = getN("Please enter the second number.");
    int result = gcd(x, y);
    cout << "The greatest common divisor is: " << result << "."<< endl;
    
    
    cout << "\n\nRecursive Question 5) Fractorials (Least common multiple)" << endl;
    n = getN("Please enter the number to be fractorial-ed.");
    result = leastCommonM(n);
    cout << "The fractorial for this number is: " << result << "."<< endl;

    
    cout << "\n\nRecursive Question 6) Towers of Hanoi" << endl;
    n = getN("Please enter the number of towers.");
    int o = getN("Please enter the starting peg for the tower.");
    int p = getN("Please enter the temporary peg for the tower");
    int q = getN("Please enter the final peg for the tower");
    towerOfHanoi(n, o, p, q);
    cout << endl;
    
    return 0;
}
