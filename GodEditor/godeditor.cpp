#include "godeditor.h"

GodEditor::GodEditor(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_shaderTE = new GodShaderTextEdit(ui.centralWidget);
	m_shaderTE->setGeometry(0, 0, 150, 300);
	m_shaderTE->show();
}

GodEditor::~GodEditor()
{

}
