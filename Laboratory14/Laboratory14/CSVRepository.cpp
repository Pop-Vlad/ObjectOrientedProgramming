#include "CSVRepository.h"


CSVRepository::CSVRepository(const  std::string& file_location) {
	this->fragments = std::vector<AnomalousFragment>{};
	this->file_location = file_location;
	this->load();
}


void CSVRepository::load() {
	this->fragments.clear();
	std::ifstream csv_file;
	csv_file.open(this->file_location);

	AnomalousFragment current_fragment;
	std::string current_line;
	while (std::getline(csv_file, current_line, '\n')) {
		std::stringstream current_sstream = std::stringstream{ current_line };
		std::string parameters[5];
		for (int i = 0; i < 5; i++) {
			std::getline(current_sstream, parameters[i], ',');
		}
		this->fragments.push_back(AnomalousFragment{ parameters[0], parameters[1], std::stof(parameters[2]), std::stoi(parameters[3]),
			parameters[4] });
	}

	csv_file.close();
}

void CSVRepository::save() const {
	std::ofstream csv_file;
	csv_file.open(this->file_location);

	for (int i = 0; i < this->fragments.size(); i++) {
		csv_file << this->fragments[i].getId() << "," << this->fragments[i].getSize() << "," << this->fragments[i].getInfectionLevel()
			<< "," << this->fragments[i].getMicrofragments() << "," << this->fragments[i].getPhotograph() << "\n";
	}

	csv_file.close();
}