#pragma once

#include "GenericRepository.h"

#include <algorithm>



class MemoryRepository : public Repository {


public:

	MemoryRepository();

	void add(const AnomalousFragment& new_fragment) override;

	void update(const AnomalousFragment& new_fragment) override;

	void remove(const std::string& id) override;

	int getSize() const override;

	AnomalousFragment getElement(const int& position) const override;

	std::vector<AnomalousFragment> getAllElements() const override { return this->fragments; }


};