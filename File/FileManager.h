#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

struct file_map{
	std::string key;
	int value;
	int active;
};

typedef file_map PropertyMap;

class FileManager {
public:
	static FileManager* getInstance();

    virtual ~FileManager();

    void openFile(const char* );
    void openPropertiesFile(const char* );
    int getProperty(const char*);

private:
	FileManager();
	static FileManager* instance;

	PropertyMap propertiesMap[100];
	int centinel;
};

#endif