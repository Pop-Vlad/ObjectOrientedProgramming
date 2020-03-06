#include <string>



class AnomalousFragment {


public:

	char* id;
	char* size;
	double infection_level;
	int microfragments;
	char* photograph;

	AnomalousFragment();

	AnomalousFragment(char* id, char* size, double infection_leve, int microfragments, char* photograph);

	~AnomalousFragment();

	void toString(char* buffer);

	friend std::istream& operator>>(std::istream& stream, AnomalousFragment* &fragment);

	friend std::ostream& operator<<(std::ostream& stream, AnomalousFragment* fragment);


};