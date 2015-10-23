#include <iostream> //cout cin
#include <fstream> //ifstream ofstream
#include <iomanip> //setw(int n)
#include <string> 
using namespace std;

int main()
{
    ifstream fin; //input stream
    char fileName[16]; //Obtain file name
    cout << "Enter the file name that you wish to open. File name can only be 16 characters long" << endl;
    cin >> fileName; //Obtain fileName

    fin.open(fileName); //Open fileName
    ofstream fout; //output to new stream
    fout.open("result.txt"); //open result.txt
    
    string firstName, lastName, studentHighScore; 
    double num1, num2, num3, num4, num5, num6, average, sum;
    double largestAverage = 0;
    
    while(fin >> firstName >> lastName >> num1 >> num2 >> num3 >> num4 >> num5 >> num6)
    {
        fout.setf(ios::fixed);
        fout.setf(ios::showpoint);
        fout.precision(2);
        fout.setf(ios::left);
        
        sum = num1 + num2 + num3 + num4 + num5 + num6;
        average = (sum / 6.0);
        
        if(average > largestAverage)
        {
            largestAverage = average;
            studentHighScore = firstName + " " + lastName;
        }
        fout << setw(10) << firstName << setw(10) << lastName << setw(10) << num1 << setw(10) << num2 << setw(10) << num3 << setw(10) << num4 << setw(10) << num5 << setw(10) << num6 << "Average: " << average << endl;    
    }
    fout << endl;
    fout << "Highest score: " << studentHighScore;
    
    fin.close();
    fout.close();   
}

