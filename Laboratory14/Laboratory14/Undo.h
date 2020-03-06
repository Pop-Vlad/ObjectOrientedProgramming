#pragma once

#include "MemoryRepository.h"
#include "FileRepository.h"
#include "CSVRepository.h"
#include "HTMLRepository.h"


class AbstractUndo {

protected:

	Repository* repository;

	AnomalousFragment previous;

	AnomalousFragment after;


public:

	AbstractUndo() {};

	virtual void executeUndo() = 0;

	virtual void executeRedo() = 0;


};


class UndoAdd : public AbstractUndo {

public:

	UndoAdd(Repository* init_repository, AnomalousFragment init_fragment) {
		this->repository = init_repository;
		this->after = init_fragment;
	}

	void executeUndo() override {
		this->repository->remove(this->after.getId());
	}

	void executeRedo() override {
		this->repository->add(this->after);
	}


};


class UndoDelete : public AbstractUndo {

public:

	UndoDelete(Repository* init_repository, AnomalousFragment init_fragment) {
		this->repository = init_repository;
		this->previous = init_fragment;
	}

	void executeUndo() override {
		this->repository->add(this->previous);
	}

	void executeRedo() override {
		this->repository->remove(this->previous.getId());
	}


};


class UndoUpdate : public AbstractUndo {

public:

	UndoUpdate(Repository* init_repository, AnomalousFragment init_previous, AnomalousFragment init_after) {
		this->repository = init_repository;
		this->previous = init_previous;
		this->after = init_after;
	}

	void executeUndo() override {
		this->repository->update(this->previous);
	}

	void executeRedo() override {
		this->repository->update(this->after);
	}


};