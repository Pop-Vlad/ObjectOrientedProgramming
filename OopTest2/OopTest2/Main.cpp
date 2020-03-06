#include "UI.h"


int main() {
	Repository repoAll = Repository{};
	Repository repoSpecialStorage = Repository{};
	Painting painting1 = Painting{ "title1", "artist1", 1990 };
	Painting painting2 = Painting{ "title2", "artist2", 1650 };
	Painting painting3 = Painting{ "title3", "artist3", 1857 };
	repoAll.addPainting(painting1);
	repoAll.addPainting(painting2);
	repoAll.addPainting(painting3);
	repoSpecialStorage.addPainting(painting2);
	repoSpecialStorage.addPainting(painting3);
	Controller* controller = new Controller{ repoAll, repoSpecialStorage };
	UI ui = UI{ controller };
	ui.run();
	return 0;
}