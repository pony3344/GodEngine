#pragma once

#include <QtWidgets/qwidget>
#include "GodShaderTextEdit.h"

class GodShaderEditor : public QWidget
{
protected:
	GodShaderTextEdit* m_shaderText;
public:
	GodShaderEditor(QWidget* parent = 0);

	~GodShaderEditor();


};
