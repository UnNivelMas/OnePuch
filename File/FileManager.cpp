#include "FileManager.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

FileManager::FileManager(){
	centinel = 0;
}

FileManager::~FileManager(){

}

FileManager* FileManager::instance = 0;

FileManager* FileManager::getInstance()
{
	if(!instance)
		instance = new FileManager();
	return instance;
}

void FileManager::openFile(const char* fileName){

}

int FileManager::getProperty(const char* key){
	std::string searchedKey(key);
	for(int i = 0; i < 100; i++){
		if(propertiesMap[i].active == 0)
			return 0;
		if(!searchedKey.compare(propertiesMap[i].key)){
			return propertiesMap[i].value;
        }
	}
	return 0;
}
    
void FileManager::openPropertiesFile(const char* fileName){
	std::ifstream infile(fileName);

	std::string line;
	while (std::getline(infile, line))
	{
		std::vector<std::string> property;
		std::stringstream ss(line);
		std::string word;
		while(std::getline(ss, word, '=')){
			property.push_back(word);
		}
		propertiesMap[centinel].key = property[0];
		std::istringstream numberWithStringFormat(property[1]);
		numberWithStringFormat >> propertiesMap[centinel].value;
		propertiesMap[centinel].active = 1;
		centinel++;
	}
}