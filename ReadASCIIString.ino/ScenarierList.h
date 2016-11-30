#pragma once
#include "Scenarier.h"
#include <vector>
#include <string>
class ScenarierList
{
public:
	ScenarierList();
	~ScenarierList();
	void addScenarie(char* a);
	void addScenarie(std::vector<char> a);
  void addScenarie(std::string a);
	void AntalaktionerIScenarie(int , char ) const;
	void tilCharArray(char* a,int b);
	std::vector<char> etScenarie(int);
private:
	std::vector<Scenarier> scenarielist;
};

