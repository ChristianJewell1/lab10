/*
 *        File: lab10.cc
 *      Author: Christian Jewell
 *        Date: 3/28/2021
 * Description: Takes the prices from one file and names of the products from anotherfile. Then finds 
 * the least expensive and most expensive parts and displays them with their price.
 */

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[]){
    ifstream ins;
    ifstream ins2;
    string inputfile = "data1.txt";
    string inputfile2 = "data2.txt";
    double db;
    string str2;
    vector <double> data1;
    vector <string> data2;
    int lowestindex;
    int highestindex;
    double lowest = 1000000;
    double highest = 0;

// opens the two input files
    ins.open(inputfile);
    if(ins.fail()){
        cout << "The first input file has failed to open";
        exit (0);
    }
    ins2.open(inputfile2);
    if(ins2.fail()){
        cout << "The second input file has failed to open";
        exit (0);
    }
// takes the data from the first input file, stores it into an array, and also finds the highest and lowest values
    for (size_t i = 0; i < 6; i++)
    {
        ins >> db;
        data1.push_back(db);
        if(data1[i]<lowest){
            lowest = data1.at(i);
            lowestindex = i;
        }
        if(data1[i]>highest){
            highest = data1.at(i);
            highestindex = i;
        }
        cout << data1.at(i) << endl;
    }
// takes the data from the second input file and stores it into an array.
    for (size_t i = 0; i < 6; i++)
    {
        ins2 >> str2;
        data2.push_back(str2); 
        cout << data2.at(i) << endl;
    }
// Prints the most least/most expensive part and the price of those parts.
    cout << "The least expensive part is " << data2.at(lowestindex) << " ($" << lowest << ")" << endl;
    cout << "The most expensive part is " << data2.at(highestindex) << " ($" << highest << ")" << endl;
    ins.close();
    ins2.close();
}