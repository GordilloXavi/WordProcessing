#include <algorithm>
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
    
    count how many words there are in tota, how many of each size, how many containing a given substring, etc

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

char ToUpper(char c){

    if(c >= 'a' and c <= 'z')c -= int('a'-'A');

    return c;

} 


bool isHex(char c){

    c = ToUpper(c);


    return (c == 'A' or c== 'B' or c == 'D' or c == 'E' or c == 'F');


} 


int main(){

    //std::cout << "How many characters?\n";

    //unsigned int n;

    //std::cin >> n;

    std::vector<std::string> v = loadWords("words_alpha.txt");

    std::vector<std::string> TopWords;

    //std::cout << "Size of word list: " << sizeof(v) << std::endl;


    //std::vector<char> Vchar = {'A','B','C','D','E','F'};

    for(std::string s : v){

        bool Hex = true;

        for(unsigned int i = 0; i<s.size()-1; ++i){
            
            //std::cout << s[i] << " "<< isHex(s[i]) <<  "\n";
            
            if(not isHex(s[i]))Hex = false;
           
            
        } 

     if(Hex)TopWords.push_back(s);   

    } 

    std::sort(TopWords.begin(), TopWords.end(), [](std::string a, std::string b){return (a.size() >= b.size());}); 

    std::cout << "Longest English word you can write in Hexadecimal:\n" << TopWords[0] << "\n";



} 


/*


    for(std::string s : v){

        bool Hex = true;

        for(int i = 0; i<int(s.size());++i){
            

            if(not isHex(s[i]))Hex = 0;
           
            
        } 

     if(Hex)std::cout << s << "\n";   

    } 
*/
