#include "HTMLRepository.h"



HTMLRepository::HTMLRepository(const  std::string& file_location) {
	this->fragments = std::vector<AnomalousFragment>{};
	this->file_location = file_location;
	this->load();
}


void HTMLRepository::load() {
	this->fragments.clear();
	std::ifstream html_file;
	html_file.open(this->file_location);

	std::string file_content;
	file_content.assign(std::istreambuf_iterator<char>(html_file), std::istreambuf_iterator<char>());

	int current_position = file_content.find("<tr>", 0);
	current_position = file_content.find("<tr>", current_position + 1);
	while (current_position != std::string::npos) {
		int row_start = current_position;
		int row_end = file_content.find("</tr>", current_position);
		int cell_start = file_content.find("<td>", row_start) + 4;
		int cell_end = file_content.find("</td>", cell_start);
		std::string id = file_content.substr(cell_start, cell_end - cell_start);
		cell_start = file_content.find("<td>", cell_end) + 4;
		cell_end = file_content.find("</td>", cell_start);
		std::string size = file_content.substr(cell_start, cell_end - cell_start);
		cell_start = file_content.find("<td>", cell_end) + 4;
		cell_end = file_content.find("</td>", cell_start);
		std::string infection = file_content.substr(cell_start, cell_end - cell_start);
		cell_start = file_content.find("<td>", cell_end) + 4;
		cell_end = file_content.find("</td>", cell_start);
		std::string microfragments = file_content.substr(cell_start, cell_end - cell_start);
		cell_start = file_content.find("<td>", cell_end) + 4;
		cell_end = file_content.find("</td>", cell_start);
		std::string photo = file_content.substr(cell_start, cell_end - cell_start);
		AnomalousFragment new_fragment{ id, size, stod(infection), stoi(microfragments), photo };
		this->fragments.push_back(new_fragment);
		current_position = file_content.find("<tr>", current_position + 1);
	}

	html_file.close();
}


void HTMLRepository::save() const {
	std::ofstream html_file;
	html_file.open(this->file_location);

	html_file << "<!DOCTYPE html>\n";
	html_file << "<html>\n";
	html_file << "	<head>\n";
	html_file << "		<title>MyList</title>\n";
	html_file << "	</head>\n";
	html_file << "	<body>\n";
	html_file << "		<table border = \"1\">\n";

	html_file << "			<tr>\n";
	html_file << "				<td>Id</td>\n";
	html_file << "				<td>Size</td>\n";
	html_file << "				<td>Infection level</td>\n";
	html_file << "				<td>Nr. of microfragments</td>\n";
	html_file << "				<td>Photo</td>\n";
	html_file << "			</tr>\n";
	for (auto iterator = this->fragments.begin(); iterator != this->fragments.end(); iterator++) {
		AnomalousFragment current = *iterator;
	html_file << "			<tr>\n";
	html_file << "				<td>" + current.getId() + "</td>\n";
	html_file << "				<td>" + current.getSize() + "</td>\n";
	html_file << "				<td>" + std::to_string(current.getInfectionLevel()) + "</td>\n";
	html_file << "				<td>" + std::to_string(current.getMicrofragments()) + "</td>\n";
	html_file << "				<td>" + current.getPhotograph() + "</td>\n";
	html_file << "			</tr>\n";
	}

	html_file << "		</table>\n";
	html_file << "	</body>\n";
	html_file << "</html>\n";

	html_file.close();
}


std::vector<AnomalousFragment> HTMLRepository::getAllElements() const {
	ShellExecuteA(0, 0, "chrome.exe", this->file_location.c_str(), 0, SW_SHOWMAXIMIZED);
	return std::vector<AnomalousFragment> {};
}