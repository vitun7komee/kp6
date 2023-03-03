#pragma once
#include "Publication.h"


class Magazine : public Publication 
{
private:
	size_t number, year; 
	std::string website; 
public:
	Magazine(std::string name = "", std::string publisher = "", size_t pageCount = 0, std::string website = "", size_t number = 0, size_t year = 0)
		: Publication(name, publisher, pageCount), website(website), number(number), year(year) {}

	
	size_t get_number() { return number; }
	size_t get_year() { return year; }

	std::string get_website() { return website; }
	void set_website(std::string value) { website = value; }

	
	std::string to_string() override {
		return "Magazine: " + Publication::to_string() + " #" + std::to_string(number) + ' ' + std::to_string(year) + "y | " + website;
	}
	
};