#pragma once

#include "FileRepository.h"

#include <sstream>
#include <windows.h>
#include <ShellApi.h>



class HTMLRepository : public FileRepository {


public:

	HTMLRepository(const  std::string& file_location);

	void load() override;

	void save() const override;

	std::vector<AnomalousFragment> getAllElements() const override;


};