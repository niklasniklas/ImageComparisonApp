#ifndef GLASGOWTEST_H
#define GLASGOWTEST_H
#include <vector>
#include <qstring.h>

struct GlasgowItem
{
	QString filepath;
	bool	same;
	bool	correct;
};

class GlasgowTest
{
public:
	GlasgowTest(int no);
	~GlasgowTest();

	void nextItem(void);


private:
	int _no_of_comparisons;
	std::vector<GlasgowItem> testVector;

	bool isCorrect(bool answer);
};

#endif