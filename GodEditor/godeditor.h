#ifndef GODEDITOR_H
#define GODEDITOR_H

#include <QtWidgets/QMainWindow>
#include "ui_godeditor.h"
#include "GodShaderEditor.h"

class GodEditor : public QMainWindow
{
	Q_OBJECT

public:
	GodEditor(QWidget *parent = 0);
	~GodEditor();

private:
	GodShaderEditor* m_sedit;
	GodShaderTextEdit* m_shaderTE;
	Ui::GodEditorClass ui;
};

#endif // GODEDITOR_H
