#pragma once

#include "SqlRepository.h"



SqlRepository::SqlRepository() {
	this->sql_host = "localhost";
	this->sql_user = "root";
	this->sql_password = "1234";
	this->sql_database = "oop_repository";
	this->fragments = std::vector<AnomalousFragment>{};

	this->connection = mysql_init(NULL);
	this->connection = mysql_real_connect(this->connection, this->sql_host.c_str(), this->sql_user.c_str(), this->sql_password.c_str(),
		this->sql_database.c_str(), 3306, NULL, NULL);
	if (connection == NULL) {
		throw ConnectionError{ "Could not connect to sql server" };
	}
}


SqlRepository::SqlRepository(const SqlRepository& repository_to_copy) {
	this->sql_host = repository_to_copy.sql_host;
	this->sql_user = repository_to_copy.sql_user;
	this->sql_password = repository_to_copy.sql_password;
	this->sql_database = repository_to_copy.sql_database;
	this->fragments = repository_to_copy.fragments;
	this->connection = mysql_init(NULL);
	this->connection = mysql_real_connect(this->connection, this->sql_host.c_str(), this->sql_user.c_str(), this->sql_password.c_str(),
		this->sql_database.c_str(), 3306, NULL, NULL);
	if (connection == NULL) {
		throw ConnectionError{ "Could not connect to sql server" };
	}
}


void SqlRepository::add(const AnomalousFragment& new_fragment) {
	std::string query = "INSERT INTO fragments VALUE ('" + new_fragment.getId() + "', '" + new_fragment.getSize() + "', " +
		std::to_string(new_fragment.getInfectionLevel()) + ", " + std::to_string(new_fragment.getMicrofragments()) + ", '" +
		new_fragment.getPhotograph() + "');";
	int query_state = mysql_query(this->connection, query.c_str());
	if (query_state) {
		throw ElementAlreadyExists{ "An object whit this id already exists" };
	}
}


void SqlRepository::update(const AnomalousFragment& new_fragment) {
	std::string query = "UPDATE fragments SET size = '" + new_fragment.getSize() + "', infection = " +
		std::to_string(new_fragment.getInfectionLevel()) + ", microfragments = " + std::to_string(new_fragment.getMicrofragments()) +
		", photograph = '" + new_fragment.getPhotograph() + "' WHERE id = '" + new_fragment.getId() + "';";
	int query_state = mysql_query(this->connection, query.c_str());
	if (query_state) {
		throw ElementNotFound{ "No object with this id was found" };
	}
}


void SqlRepository::remove(const std::string& id) {
	std::string query = "DELETE FROM fragments WHERE id = '" + id + "';";
	int query_state = mysql_query(this->connection, query.c_str());
	if (query_state) {
		throw ElementNotFound{ "No object with this id was found" };
	}
}


int SqlRepository::getSize() const {
	std::string query = "SELECT COUNT(id) FROM fragments;";
	int query_state = mysql_query(this->connection, query.c_str());
	MYSQL_RES* result = mysql_store_result(this->connection);
	MYSQL_ROW row = mysql_fetch_row(result);
	return std::stoi(row[0]);
}


AnomalousFragment SqlRepository::getElement(const int& position) const {
	std::string query = "SELECT * FROM fragments ORDER BY id LIMIT 1 OFFSET " + std::to_string(position) + ";";
	int query_state = mysql_query(this->connection, query.c_str());
	MYSQL_RES* result = mysql_store_result(this->connection);
	MYSQL_ROW row = mysql_fetch_row(result);
	return AnomalousFragment{ row[0], row[1], std::stod(row[2]), std::stoi(row[3]), row[4] };
}


std::vector<AnomalousFragment> SqlRepository::getAllElements() const {
	std::string query = "SELECT * FROM fragments;";
	int query_state = mysql_query(this->connection, query.c_str());
	MYSQL_RES* result = mysql_store_result(this->connection);
	std::vector<AnomalousFragment> list_of_fragments;
	MYSQL_ROW row;
	while (row = mysql_fetch_row(result)) {
		list_of_fragments.push_back(AnomalousFragment{ row[0], row[1], std::stod(row[2]), std::stoi(row[3]), row[4] });
	}
	return list_of_fragments;
}