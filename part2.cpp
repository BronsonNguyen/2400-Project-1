/*
    Name: Bronson Nguyen
    Course: 2400-003
    Date:10/5/23
    Purpose: The purpose of part2.cpp is to take two integer arguments and calculate the Greatest
             Common Divisor using the Consecutive integer checking algorithm
*/
#include <iostream>
#include <string>
using namespace std;

/*
The Purpose of the ConsecutiveIntegerChecking Function to get the GCD of two number by modulo dividing the bigger number by the smaller one, if it returns a number higher than 0
then decrement the smaller number and modulo divide again until it returns a 0. Return the number that returned a 0 because that is the gcd

Args: 
    int m: first number
    int n: second number

Returns:
    string GCD: The Greatest Common Divsor of m and n
*/

string ConsecutiveIntegerChecking(int m, int n){
    //these two if statements will check and change m and n into there positive counter part if negative
    //because the gcd(-m,-n) is the same as gcd(m,n)
    if(m<0){
        m=m*-1;
    }
    if(n<0){
        n=n*-1;
    }
    
    if(n==0 && m==0){ //if both n and m is 0 then undefined
            return "undefined";
    }
    else if (n==0){ //If only n or m is 0 then return the other number, because the GCD of a number and 0 is the |number|
        return to_string(m);
    }
    else if (m==0){
        return to_string(n);
    }
    

    int min;
    int max;
    if(m<n){ //if statement to compare m and n and assign which one is min and max
        min=m;
        max=n;
    }
    else{
        min=n;
        max=m;
    }

    int t = min;
    while(t!=0){
        //the If statement will check if t can divide into both max and min and have a remainder of 0
        //if so then t is the GCD
        if (max%t==0)
        {
            if (min%t==0)
            {
                break; //break out of loop because gcd is found
            }
            
        }
        t--; //decrease t value by 1
    }

        return to_string(t); //converts t to string and returns it

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

    string v;
    v=ConsecutiveIntegerChecking(m,n); //calls ConsecutiveIntegerChecking function returning result to v

    cout << "gcd(" << m << ", "<< n<<") = " << v << endl; //prints the gcd in format gcd(m, n) = v

    return 0;
}