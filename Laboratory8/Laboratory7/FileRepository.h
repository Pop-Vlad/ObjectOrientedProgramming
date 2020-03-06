#include "MemoryRepository.h"



class FileRepository : public Repository {


private:

	char file_path[100];

	void load();

	void save();


public:

	FileRepository();

	~FileRepository();

	void setPath(char new_file_path[]);

};