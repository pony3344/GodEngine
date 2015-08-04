#pragma once

#include <QtWidgets/QTextEdit>
#include <QtGui/QPaintEvent>

class GodShaderTextEdit : public QTextEdit
{
public:
	GodShaderTextEdit(QWidget* parent = 0); 

	~GodShaderTextEdit();

	//void paintEvent(QPaintEvent *e);
	
	void checkKeyword();
};