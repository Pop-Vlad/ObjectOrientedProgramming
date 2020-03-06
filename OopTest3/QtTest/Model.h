#pragma once

#include <vector>
#include <string>


class Document {

public:

	std::string name;
	std::vector<std::string> keywords;
	std::string content;

	Document() {}

	Document(std::string init_name, std::vector<std::string> init_keywords, std::string init_content) : name(init_name),
		keywords(init_keywords), content(init_content) {}

	std::string toString() const {
		std::string str = this->name;
		for (int i = 0; i < this->keywords.size(); i++) {
			str += " " + this->keywords[i];
		}
		return str;
	}
};