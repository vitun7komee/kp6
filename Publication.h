#pragma once
#include <string>



class Publication
{
protected:
	std::string name, publisher; 
	size_t pageCount;
public:
	Publication(std::string name = "", std::string publisher = "", size_t pageCount = 0) : name(name), publisher(publisher), pageCount(pageCount) {}

	

	std::string get_name() { return name; }
	void set_name(std::string value) { name = value; }

	std::string get_publisher() { return publisher; }
	void set_publisher(std::string value) { publisher = value; }

	size_t get_page_count() { return pageCount; }


	int compare(const Publication& obj) {
		int result = 1;
		if (publisher < obj.publisher)
			result = -1;
		else if (name == obj.name && publisher == obj.publisher)
			result = 0;
		return result;
	}

	
	virtual std::string to_string() {
		return name + " : " + publisher + " " + std::to_string(pageCount) + "p";
	}
};

