#include "godeditor.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GodEditor w;
	w.show();
	return a.exec();
}
