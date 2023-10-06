/*
    Name: Bronson Nguyen
    Course: 2400-003
    Date:10/5/23
    Purpose: The purpose of part1.cpp is to take two integer arguments and calculate the Greatest
             Common Divisor using the Euclid Algorithm
*/
#include <iostream>
#include <string>
using namespace std;

/*
The Purpose of the EuclidAlgorithm Function to get the GCD of two number by using recursion, it does this by modulo dividing m and n and setting the result equal to r,
then calls the EuclidAlgorithm again replacing m with n and n with r until n is 0. Once n is 0 it will return m as GCD.

Args: 
    int m: first number
    int n: second number

Returns:
    string GCD: The Greatest Common Divsor of m and n
*/

int EuclidAlgorithm(int m, int n){
    if(n==0){ //base case if n is equal to 0 return m
        return m;
    }

    int r = m % n; //uses m modulo n to get the reminder 

    //use recursion to call EuclidAlgorithm where n is m and r is n
    //will continue to call this EuclidAlgorith until base case is reached
    return EuclidAlgorithm(n,r);
}

int main(int argc, char* argv[]){
    if(argc != 3){ //if statement will check if user passed two arguments
        cout << "Please provide two arguments" << endl;
        return 1; //end the code returning 1 to indicate an error
    }

    //gets the two arguments entered and set the first int one to m and second int to n
    //used the stoi function to convert the arguments(string) into int
    int m = stoi(argv[1]);
    int n = stoi(argv[2]);

    int v = EuclidAlgorithm(m,n); //will call the EuclidAlgorithm function and returning result to v
    
    if(v<0){ //if v is negative then turn v positive because v is still divisable between the two numbers and is greater than -v
        v= v*-1;
    }

    if(v==0){ //if gcd is 0 mean no gcd exist or undefined because you cant divide by zero
        cout << "gcd(" << m << ", "<< n<<") = undefined" << endl;
    }

    else{
        cout << "gcd(" << m << ", "<< n<<") = " << v << endl; //prints the gcd in format gcd(m, n) = v
    }
    return 0;
}