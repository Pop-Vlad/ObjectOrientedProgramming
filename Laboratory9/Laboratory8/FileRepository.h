#pragma once

#include "GenericRepository.h"

#include <algorithm>
#include <fstream>



class FileRepository : public Repository {


protected:

	std::string file_location;


public:

	FileRepository(const  std::string& file_location = "\0");

	virtual void load();

	virtual void save() const;

	void add(const AnomalousFragment& new_fragment) override;

	void update(const AnomalousFragment& new_fragment) override;

	void remove(const std::string& id) override;

	int getSize() const override;

	AnomalousFragment getElement(const int& position) const override;

	virtual std::vector<AnomalousFragment> getAllElements() const override { return this->fragments; }


};


typedef GenericException FileOpenError;