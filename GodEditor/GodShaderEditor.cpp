#include "GodShaderEditor.h"

GodShaderEditor::GodShaderEditor(QWidget* parent /* = 0 */)
	: QWidget(parent)
{
	m_shaderText = new GodShaderTextEdit(parent);
	m_shaderText->setGeometry(this->x(),
		this->y(),
		this->width(),
		this->height());
	m_shaderText->resize(this->width(), this->height());
}

GodShaderEditor::~GodShaderEditor()
{

}