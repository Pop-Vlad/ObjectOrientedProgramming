#include "IssueRepository.h"



IssueRepository::IssueRepository(std::string init_u, std::string init_i) : users_file(init_u), issues_file(init_i) {
	this->loadFiles();
}


IssueRepository::~IssueRepository() {
	this->saveFile();
}


void IssueRepository::loadFiles() {
	std::ifstream usersFile{ this->users_file };
	std::string line;
	while (std::getline(usersFile, line)) {
		std::stringstream line_stream{ line };
		std::string current_name;
		std::string current_type;
		std::getline(line_stream, current_name, ' ');
		std::getline(line_stream, current_type, ' ');
		User new_user{ current_name, current_type };
		this->users.push_back(new_user);
	}
	usersFile.close();

	std::ifstream issuesFile{ this->issues_file };
	while (std::getline(issuesFile, line)) {
		std::stringstream line_stream{ line };
		std::string descr;
		std::string status;
		std::string reporter;
		std::string solver;
		std::getline(line_stream, descr, ' ');
		std::getline(line_stream, status, ' ');
		std::getline(line_stream, reporter, ' ');
		std::getline(line_stream, solver, ' ');
		Issue new_issue{ descr, status, reporter, solver };
		this->issues.push_back(new_issue);
	}
	issuesFile.close();
}


void IssueRepository::saveFile() {
	std::ofstream issuesFile{ this->issues_file };
	for (Issue current : this->issues) {
		issuesFile << current.toString() << "\n";
	}
	issuesFile.close();
}

void IssueRepository::add(std::string description, std::string reporter) {
	if(description.length() == 0)
		throw std::exception{ "No description" };
	bool found = false;
	for (User current : this->users) {
		if (current.getName() == reporter) {
			if (current.getType() != "tester")
				throw std::exception{ "Not a tester" };
			found = true;
			break;
		}
	}
	if (!found)
		throw std::exception{ "Reporter not found" };
	found = false;
	for (Issue current : this->issues) {
		if (current.getDescription() == description) {
			found = true;
			break;
		}
	}
	if (found)
		throw std::exception{ "Description already exists" };
	Issue new_issue = Issue{ description, "open", reporter, "" };
	this->issues.push_back(new_issue);
	this->notify();
}

void IssueRepository::remove(std::string description) {
	for (Issue& current : this->issues)
		if (current.getDescription() == description) {
			if (current.getStatus() == "closed") {
				current = this->issues.back();
				this->issues.pop_back();
				this->notify();
				return;
			}
			else
				throw std::exception{ "Issue not closed" };
		}
	throw std::exception{ "Description not found" };
}

void IssueRepository::resolve(std::string description, std::string solver) {
	bool found = false;
	for (User current : this->users) {
		if (current.getName() == solver) {
			if (current.getType() != "programmer")
				throw std::exception{ "Not a programmer" };
			found = true;
			break;
		}
	}
	if (!found)
		throw std::exception{ "Solver not found" };
	for (Issue& current : this->issues)
		if (current.getDescription() == description) {
			if (current.getStatus() == "open") {
				current.setStatus("closed");
				current.setSolver(solver);
				this->notify();
				return;
			}
			else
				throw std::exception{ "Issue not open" };
		}
	throw std::exception{ "Description not found" };
}