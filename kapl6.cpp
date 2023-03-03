﻿#include <iostream>
#include <Windows.h>
#include <fstream>
#include "Library.h"
#include "Magazine.h"
#include "Book.h"

void task(Library& lib, std::string publisher)
{
	std::vector<TInfo>::iterator it = std::find_if(lib.begin(), lib.end(), [&publisher](TInfo shptr) { return shptr->get_publisher() == publisher; });

	if (it != lib.end()) {
		size_t softDetectiveBooks = 0, hardDetectiveBooks = 0; 
		Book* tmp;
		bool tmpBinding;
		while (it != lib.end() && (*it)->get_publisher() == publisher) {
			tmp = dynamic_cast<Book*>(it->get()); 
			if (tmp && tmp->get_genre() == "Detective") { 
				tmpBinding = tmp->get_binding(); 
				if (tmpBinding)
					++hardDetectiveBooks;
				else
					++softDetectiveBooks;
			}
			++it;
		}

		std::cout << "У издательства " << publisher << " ";
		if (hardDetectiveBooks == 0 && softDetectiveBooks == 0)
			std::cout << "нет книг в жанре детектив\n";
		else if (hardDetectiveBooks == softDetectiveBooks)
			std::cout << "одинаковое количество книг в жанре детектив\n";
		else if (hardDetectiveBooks > softDetectiveBooks)
			std::cout << "книг в твердом переплете в жанре детектив больше чем в мягком\n";
		else
			std::cout << "книг в мягком переплете в жанре детектив больше чем в твердом\n";
	}
	else std::cout << "В библиотеке нет публикаций издательства " << publisher << '\n';
}

void create_library(Library& lib, std::string path);

int main()
{
	SetConsoleOutputCP(1251);

	Library lib;
	create_library(lib, "data.txt");
	lib.sort();

	std::cout << lib << '\n';

	task(lib, "Thomas & Mercer");

	
	std::cin.ignore(SHRT_MAX, '\n');
	std::cin.get();
	return 0;
}

void create_library(Library& lib, std::string path)
{
	std::ifstream file(path);
	if (file) {
		char type;
		std::string name, publisher, author, genre, website;
		size_t pageC, number, year;
		bool binding;
		std::string delim_line;

		
		while (file >> type)
		{
			
			file.ignore();
			std::getline(file, name);
			std::getline(file, publisher);
			file >> pageC;
			if (type == 'M') {
				file >> number >> year;
				file.ignore();
				std::getline(file, website);
				lib.add_publication_to_back(std::move(std::make_shared<Magazine>(Magazine(name, publisher, pageC, website, number, year))));
			}
			else {
				file.ignore();
				std::getline(file, author);
				std::getline(file, genre);
				file >> binding;
				lib.add_publication_to_back(std::move(std::make_shared<Book>(Book(name, publisher, pageC, author, genre, binding))));
			}
			file.ignore();
			std::getline(file, delim_line);
		}
	}
}