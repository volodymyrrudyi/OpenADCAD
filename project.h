#ifndef PROJECT_H
#define PROJECT_H


#include <string>
#include <list>

using namespace std;

/**

**/
class Project
{
    // Pointer to the principle scheme of the project


    // File name of the main
    string baseName;
public:
    Project();
    Project(const string& baseName);
    ~Project();
    // Returns principle scheme of the current project

};

#endif // PROJECT_H
