#include <string>



class AnomalousFragment {


private:

	std::string id;

	std::string size;

	double infection;

	int microfragments;

	std::string photograph;


public:

	//Create a new empty fragment
	AnomalousFragment() :id(""), size(""), infection(0), microfragments(0), photograph("") {};

	//Create a new frament with given attributes
	AnomalousFragment(const std::string& new_id, const std::string& new_size, const double& new_infection, const int& new_microfragments,
		const std::string new_photograph) :id(new_id), size(new_size), infection(new_infection), microfragments(new_microfragments),
		photograph(new_photograph) {};

	//Get the id of a fragment
	std::string getId() const { return this->id; }

	//Get the size of a fragment
	std::string getSize() const { return this->size; }

	//Get the infection level of a fragment
	double getInfectionLevel() const { return this->infection; }

	//Get the number of microfragments of a fragment
	int getMicrofragments() const { return this->microfragments; }

	//Get the phtograph of a fragment
	std::string getPhotograph() const { return this->photograph; }

	//Convert the data of a fragment to a string
	std::string toString() const;

	//Read a fragment from stream
	friend std::istream& operator>>(std::istream& stream, AnomalousFragment& fragment);

	//Write a fragment to stream
	friend std::ostream& operator<<(std::ostream& stream, const AnomalousFragment& fragment);


};