#pragma once
#include "Publication.h"


class Book : public Publication 
{
private:
	std::string author, genre; 
	bool binding; 
public:
	Book(std::string name = "", std::string publisher = "", size_t pageCount = 0, std::string author = "", std::string genre = "", bool binding = 0)
		: Publication(name, publisher, pageCount), author(author), genre(genre), binding(binding) {}

	

	std::string get_author() { return author; }

	std::string get_genre() { return genre; }
	void set_genre(std::string value) { genre = value; }

	
	bool get_binding() { return binding; }

	
	std::string to_string() override {
		return "Book: " + Publication::to_string() + ' ' + author + ' ' + genre + (binding ? " Hard" : " Soft");
	}
};