#include "Repository.h"



void Repository::load() {
	std::fstream f;
	std::string line;
	f.open(this->file);
	while (std::getline(f, line)) {
		std::stringstream line_stream{ line };
		std::string attr1;
		std::string aux;
		std::vector<std::string> keywords;
		std::string attr3;
		std::getline(line_stream, attr1, '|');
		std::getline(line_stream, aux, '|');
		std::stringstream current_stream{ aux };
		std::string keyword;
		while (std::getline(current_stream, keyword, ',')) {
			keywords.push_back(keyword);
		}
		std::getline(line_stream, attr3, '|');
		Document new_documet{ attr1, keywords, attr3 };
		this->elements.push_back(new_documet);
	}
}


std::vector<Document> Repository::search(std::string text) const {
	std::vector<Document> results;
	for (Document current : this->elements) {
		std::string current_str = current.toString();
		int position = current_str.find(text);
		if (position < current_str.length())
			results.push_back(current);
	}
	return results;
}


Document Repository::bestMatch(std::string text) const {
	Document best_match;
	double best_match_nr = 10000;
	int text_length = text.length();
	for (Document current : this->elements) {
		std::string current_name = current.name;
		int position = current_name.find(text);
		if (position < current_name.length()){
			int current_length = current_name.length();
			if ((current_length / text_length) < best_match_nr) {
				best_match_nr = current_length / text_length;
				best_match = current;
			}
		}
	}
	return best_match;
}