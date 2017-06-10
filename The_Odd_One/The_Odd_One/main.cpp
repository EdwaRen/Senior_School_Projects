//
//  main.cpp
//  The_Odd_One
//
//  Created by - on 2017/06/06.
//  Copyright © 2017 Recycle Canada. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include <iterator>

using namespace std;
int main(int argc, const char * argv[]) {
    
    
    
    map<int, int> mapOfWords;
    // Inserting data in std::map
    
    mapOfWords.insert(std::make_pair("earth", 1));
    mapOfWords.insert(std::make_pair("moon", 2));
    mapOfWords["sun"] = 3;
    // Will replace the value of already added key i.e. earth
    mapOfWords["earth"] = 4;
    // Iterate through all elements in std::map
    std::map<std::string, int>::iterator it = mapOfWords.begin();
    while(it != mapOfWords.end())
    {
        mapOfWords.find
        std::cout<<it->first<<" :: "<<it->second<<std::endl;
        it++;
    }
    // Check if insertion is successful or not
    if(mapOfWords.insert(std::make_pair("earth", 1)).second == false)
    {
        std::cout<<"Element with key 'earth' not inserted because already existed"<<std::endl;
    }
    // Searching element in std::map by key.
    if(mapOfWords.find("sun") != mapOfWords.end())
        std::cout<<"word 'sun' found"<<std::endl;
    if(mapOfWords.find("mars") == mapOfWords.end())
        std::cout<<"word 'mars' not found"<<std::endl;
    return 0;
}
