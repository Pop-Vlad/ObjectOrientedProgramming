#include "UI.h"



int main() {
	Person person{ "Joe" };
	BMI* analysis1 = new BMI{ "2018.07.12", 20 };
	BP* analysis2 = new BP{ "2018.08.20", 125, 80 };
	person.addAnalysis(analysis1);
	person.addAnalysis(analysis2);
	UI ui{ person };
	ui.run();
}