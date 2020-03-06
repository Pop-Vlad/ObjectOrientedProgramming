#pragma once

#include "GenericRepository.h"

#include <mysql.h>



class SqlRepository : public Repository {


private:

	std::string sql_host;

	std::string sql_user;

	std::string sql_password;

	std::string sql_database;

	MYSQL* connection;


public:

	SqlRepository();

	SqlRepository(const SqlRepository& repository_to_copy);

	~SqlRepository() { mysql_close(connection); }

	SqlRepository operator= (const SqlRepository& rhs_repository) { return SqlRepository(rhs_repository); }

	void add(const AnomalousFragment& new_fragment) override;

	void update(const AnomalousFragment& new_fragment) override;

	void remove(const std::string& id) override;

	int getSize() const override;

	AnomalousFragment getElement(const int& position) const override;

	std::vector<AnomalousFragment> getAllElements() const override;


};


typedef GenericException ConnectionError;