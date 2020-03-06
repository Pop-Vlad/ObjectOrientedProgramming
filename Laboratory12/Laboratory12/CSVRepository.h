#pragma once

#include "FileRepository.h"

#include <sstream>



class CSVRepository : public FileRepository {


public:

	CSVRepository(const  std::string& file_location);

	void load() override;

	void save() const override;


};