#include <algorithm>
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

    std::vector<std::string> v = loadWords("words_alpha.txt");

    std::vector<std::string> TopWords;

    for(std::string s : v){
                
        bool Hex = true;

        for(unsigned int i = 0; i<s.size()-1; ++i){
            
            if(not isHex(s[i]))Hex = false;
            
        } 

     if(Hex)TopWords.push_back(s);   

    } 

    std::sort(TopWords.begin(), TopWords.end(), [](std::string a, std::string b){return (a.size() >= b.size());}); 

    std::cout << "\n###############################\n\n";

    std::cout << "Total words in the English language: " << v.size() << ".\n\n";

    std::cout << "Total Hexadecimal words in the English language: " << TopWords.size() << ".\n\n";

    std::cout << "Top 10 longest words you can write in hexadecimal:\n" << "\n";

    for(int i =0; i<10; ++i){

        std::cout << TopWords[i] << "\n";

    } 


    std::cout << "\n###############################\n\n";


} 
