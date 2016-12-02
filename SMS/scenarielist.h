#pragma once
#include "Scenarier.h"
#include <vector>
class ScenarierList
{
public:
    ScenarierList();
    ~ScenarierList();
    void addScenarie(char* a);
   void addScenarie(std::vector<char> a, std::string b);
    int AntalElementer() const;
    void AntalaktionerIScenarie(int , char ) const;
    void opretScenarie();
    void tilCharArray(char* a,int b);
    std::vector<char> etScenarie(int);
private:
    std::vector<Scenarier> scenarielist;
};
