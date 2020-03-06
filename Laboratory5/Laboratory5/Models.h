#include <string>

using namespace std;



typedef struct {
	int length;
	int width;
	int height;
} triple;


class AnomalousFragment {


public:

	char* id;
	triple size;
	double infection_level;
	int microfragments;
	char* photograph;

	AnomalousFragment(char* id, triple size, double infection_leve, int microfragments, char* photograph);

	~AnomalousFragment();

	void toString(char* buffer);


};
