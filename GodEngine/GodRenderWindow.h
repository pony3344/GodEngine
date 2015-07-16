#pragma once

#include "GodPrerequisites.h"
#include "GodWindow.h"

namespace GodEngine
{
	class RenderWindow : public Window
	{
	protected:
		bool m_bFullScreen;
		bool m_bUseStencil;
		bool m_bUseVSync;
		uint32 m_ui32VSyncLvls;
		uint32 m_ui32BitsPerPixel; 
		uint32 m_ui32NumSamples;
		uint32 m_ui32Quality;
	public:
		RenderWindow();

		RenderWindow(String winName, String title, uint32 width, uint32 height,
			bool fullscreen,
			bool stencil,
			bool vSync,
			uint32 vSynclvls,
			uint32 birsPerPixel,
			uint32 numSamples,
			uint32 quality);

		virtual ~RenderWindow();

		virtual bool createRenderWindow(String winName,
			String winTitle,
			uint32 width,
			uint32 height,
			bool fullscreen,
			bool Stencil,
			bool vSync,
			uint32 vSynclvl,
			uint32 bitsPerPixel,
			uint32 numSamples,
			uint32 quality) = 0;

		virtual void beginRender() = 0;

		virtual void endRender() = 0;

		virtual void presentScene() = 0;

		virtual void clearScene(uint32 bufferType, Real a, Real r, Real g, Real b) = 0;



	};
}