#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>

using namespace std;

/*
    Kipling Gillespie
    10/20/2017
    I wrote this program to generate the answer to a class assignment.
    We were supposed to perform exponential modulation on a set of numbers.
    I decided to instead write a program to perform and display those steps instead.
    ....
    Writing this program definately took longer than actually performing the operations
    by hand... BUT AS LONG AS I REMEMBER I HAVE THIS PROGRAM I NEVER HAVE TO DO IT
    BY HAND AGAIN!!!!! HAHAHAHAH!!!

    The program takes in 3 arguments from the command line. The first is an integer
    representing X, the second is the y value and the third is the N value for the
    formula (X^Y)Mod N
*/

int main(int argc, char* argv[])
{

    // Ensure I have the correct number of inputs
    if(argc != 4){
        cout << "Incorrect number of input" << endl;
        return 1;
    }

    // Open a text file to write my results to.
    ofstream myfile("Output.txt");

    if(!myfile.is_open()){
        cout << "Error: Program could not open file." << endl;
        return 1;
    }

    // Get inputs from the argument vector
    int y = atoi(argv[2]);
    int N = atoi(argv[3]);
    int z = 1;

    // w will be our x value
    int w = aotoi(argv[1]);
    int b = 0;

    myfile << "Z=1" << endl << "W=" << w << endl;

    // Perform the modulus exponentiation by successive doubling of X
    // X^2 Mod N where the exponents times the number of loops will be less than
    // or equal to Y and will be a power of 2. If y is not a power of two, then by
    // checking the ith bit on each loop our z value will pick up the difference in the exponent.
    for(int i = 0; i < floor(log2(y))+1; i++)
    {
        // b is equal to the ith Bit in y
        b = ((1<<i)&y)>>i;
        myfile << "b" << i << "=" << b << endl;

        // If the ith Bit in y is 1 I set z equal to (z*w)Mod N
        // Grabe
        if((1<<i)&y){
            myfile << "\tZ=(" << z << '*' << w << ")mod" << N << '=';
            z = (z*w)%N;
            myfile << z << endl;
        }
        else
            myfile << "\tZ=" << z << endl;

        myfile << "W=(" << w  << '*' << w << ")mod" << N << '=';

        // Double x and take Mod N
        w = (w*w)%N;
        myfile << w << endl << endl;
    }

    myfile << z << endl;

    // close my file
    myfile.close();

    return 0;
}
