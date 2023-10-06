/*
    Name: Bronson Nguyen
    Course: 2400-003
    Date:10/5/23
    Purpose: The purpose of part3.cpp is to take two integer arguments and calculate the Greatest
             Common Divisor using the middle school procedure method
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
The Purpose of the isPrime function is to determine if the number provided is a prime number 

Args: 
    int num: number
Returns:
    bool prime: returns true or false if the number is a prime number
*/
bool isPrime(int num){ 
    bool prime = false;
    int counter=0;

    if (num > 1) //checks to see if num is > 1 because any number less than 2 is not a prime number
    {
        for(int i=2; i <=num; i++) //the two loops will multiply each number of i by j until i is greater than num
        {
            for(int j=1; j<num; j++ )
            {
                if ((i*j)==num) //if there is a case where i*j is equal to num add one to counter
                    counter++;
            }
        }
        if(counter == 1) //if counter is equal to 1, that mean there is only one case where i*j is equal to num (1*num) meaning it's a prime number
            prime=true;
    }

    return prime;
}

/*
The Purpose getPrimes function is to get all the prime numbers that lead up to number provided

Args: 
    int max: The biggest number between the two

Returns:
    vector<int> primes: returns the list int vectors that contains all prime numbers
*/
vector<int> getPrimes(int max){//Function purpose is to get all prime number from 1 to max and insert into a list
    vector<int> primes;

    for(int i=1; i<=max; i++){ //for loop iterate from 1 to max
        if(isPrime(i)){ //call isPrime() to check if i is a prime
            primes.push_back(i); //if isPrime() returns true add i to vector primes
        }
    }
    return primes;
}



/*
The Purpose getPrimeFactors gets all the prime numbers that would create the number provided.
Args: 
    int num: number to evaluate
    vector<int> primeNums: list of prime numbers

Returns:
    vector<int> factors: the vector list that contain all prime factors to make up number
*/
vector<int> getPrimeFactors(int num, vector<int> primeNums){
    vector<int> factors;

    for(int i = 0; i != primeNums.size()-1 ; i++ ){ //for loop will iterate through primeNums elements
        while(num % primeNums[i] == 0){ //if num % primeNums[i] returns 0 that means its a prime factor of num
            factors.push_back(primeNums[i]); //adds the primeNums to factors vector
            num=num/primeNums[i]; //divides prime number to change num. if num is equal to 1 it will end the loop
        }

    }
    return factors;
}

/*
The Purpose of the MiddleSchoolProcedure function is to calculate the GCD of two numbers by getting their prime numbers, 
then multiplying the common prime numbers between the two to get the GCD

Args: 
    int m: first number
    int n: second number

Returns:
    string GCD: The Greatest Common Divsor of m and n
*/
string MiddleSchoolProcedure(int m, int n){
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
    

    //gets the max between m and n
    int max;
    if (m>n){
        max=m;
    }
    else{
        max=n;
    }

    vector<int> primeNums = getPrimes(max);//will get all prime numbers from max number and put into vector

    vector<int> mFactors = getPrimeFactors(m, primeNums); // calls getPrimeFactors to get all prime factors of m in a vector
    vector<int> nFactors = getPrimeFactors(n, primeNums); // calls getPrimeFactors to get all prime factors of n in a vector


    vector<int> commonElements ={1};

    while(mFactors.size() >= 1 && nFactors.size() >= 1){  //while loop will run until one of the vectors are empty
        for(int i=0; i<=nFactors.size()-1;i++){ //for loop will all use to compare the first element of mfactor to each element of n factor
            if(mFactors[0]==nFactors[i]){
                commonElements.push_back(nFactors[i]); //if a match is made add element to commonElements vector
                nFactors.erase(nFactors.begin()-i); //then remove element from nFactors vector
                break; //break for loop to keep us from comparing mFactors[0] with any other elements in nFactor once a match is made
            }
        }
        
        mFactors.erase(mFactors.begin()); //removes first element in mfactors once it has been compared to each element in nfactors or a match was found


    }

    int gcd=1;
     for(int j=0; j<=commonElements.size()-1;j++){ //For loop multiplies each element in commonElements and sets the results to gcd
        gcd=gcd*commonElements[j];
    }
    return to_string(gcd);
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
    v=MiddleSchoolProcedure(m,n); //calls MiddleSchoolProcedure function returning result to v      
    cout << "gcd(" << m << ", "<< n<<") = " << v << endl; //prints the gcd in format gcd(m, n) = v

    return 0;
}