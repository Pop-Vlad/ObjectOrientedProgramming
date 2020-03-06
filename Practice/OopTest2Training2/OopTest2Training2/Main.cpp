#include "UI.h"


int main() {
	Controller controller{};
	ElectricEngine* engine1 = new ElectricEngine{ "turroline", 2000 };
	TurboEngine* engine2 = new TurboEngine{ "turroline" };
	Pod pod1{ std::string{"Monosphere"}, engine1 };
	Pod pod2{ std::string{"Railcar"} , engine2 };
	UI ui{ controller };
	ui.run();
	return 0;
}