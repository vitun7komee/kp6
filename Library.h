#pragma once
#include <iostream> 
#include <fstream>
#include <functional>
#include <memory>
#include <vector>
#include <algorithm>

#include "Publication.h"


using TInfo = std::shared_ptr<Publication>;

class Library
{
private:
	std::vector<TInfo> publicationVector; 
	std::string name;
public:
	Library(std::string name="") : name(name) {}

	
	void add_publication_to_back(TInfo shptr);

	
	void sort();

	
	std::vector<TInfo>::iterator begin();
	std::vector<TInfo>::iterator end();

	
	friend std::ostream& operator<<(std::ostream& out, const Library& obj);
};

