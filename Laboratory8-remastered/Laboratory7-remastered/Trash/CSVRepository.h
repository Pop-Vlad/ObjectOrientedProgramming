#pragma once

#include "FileRepository.h"

#include <sstream>



class CSVRepository : public FileRepository {


private:

	void load() override;

	void save() const override;


public:

	CSVRepository();


};