#include <chrono>
#include <thread>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

/*

    Versatile program that uses a list of (all) words in the English alphabet.

    TODO: upload words to a database.

*/



std::vector<std::string> loadWords(std::string fileName){

    std::vector<std::string> vect;
    
    std::ifstream FF(fileName);

    std::string readText = "";

    //FF.open(fileName, std::fstream::in);

    if(FF.is_open()){

        while(FF.good()){

            getline(FF, readText);
       
            vect.push_back(readText); 
            
            
        } 
            
    
    } 

    FF.close();


    return vect;

} 

template<typename T>

void display(std::vector<T>& v){

    for(int i = 0; i<v.size()-1; ++i){


      std::cout << v[i] << "\n"; 


    } 

    std::cout << v[v.size()] << "\n";

} 



int main(){

    std::cout << "How many characters?\n";

    unsigned int n;

    std::cin >> n;



    std::vector<std::string> v = loadWords("words_alpha.txt");

    for(std::string s : v){

        if(s.size() >= n)std::cout << s << "\n";

        //std::this_thread::sleep_for(std::chrono::milliseconds(100));


    } 



} 
