// #include "..//GodEngine/GodWindow.h"
// #include "..//GodEngine/GodWindowManager.h"
// #include "..//GodRenderSystemD3D9/GodAdapterManager.h"
// #include "..//GodRenderSystemD3D9/GodDeviceD3D9.h"
// #include "..//GodRenderSystemD3D9/GodDepthStencilBufferD3D9.h"
// #include "..//GodRenderSystemD3D9/GodImageD3D9.h"
// #include "..//GodEngine/GodImage.h"
// 
// #pragma comment(lib,"..//GodEngine/Lib/Debug/godEngine_d.lib")
// #pragma comment(lib,"..//GodEngine/Lib/Debug/GodRenderSystemD3D9_d.lib")
// using namespace std;
// 
// 
// using namespace GodEngine;
// 
// int main()
// {
// 	WindowManager* mgr = new WindowManager();
// 	Window* win = new Window();
// 	mgr->addWindow(win);
// 	win->createWindow("Window", "God Engine", 800, 600, 0, 0);
// 	win->show();
// 
// 	AdapterManager* adap = new AdapterManager();
// 	adap->createD3D9();
// 
// 	DeviceD3D9* device = new DeviceD3D9(adap->getD3D9());
// 
// 	device->createDevice(win->getHandle(), 0, 1, 800, 600, false, true, false, 0, 1, 0);
// 
// 	DepthStencilBufferD3D9* depth = new DepthStencilBufferD3D9(device->getDeviceD3D9());
// 	depth->createDepthStencil(512, 512, 0, 0);
// 	IDirect3DDevice9* dev = device->getDeviceD3D9();
// 	D3DVIEWPORT9 mainView;
// 	dev->GetViewport(&mainView);
// 
// 	D3DVIEWPORT9 secondView;
// 	secondView.X = 10;
// 	secondView.Y = 10;
// 	secondView.Width = 410;
// 	secondView.Height = 410;
// 	secondView.MinZ = 0.0f;
// 	secondView.MaxZ = 1.0f;
// 	
// 	int width = (secondView.Width - secondView.X);
// 	int height = (secondView.Height - secondView.Y);
// 
// 	Image* img = new ImageD3D9(dev);
// 	img->setColorKey(D3DCOLOR_ARGB(255, 255, 255, 255));
// 	img->setSourceRect(Rectangle2D(0, 0, 100, 100));
// 	img->setDestinationRect(Rectangle2D(0, 0, 100, 100));
// 	img->loadImage("Sonic", "Celestia.jpg");
// 
// 	while (mgr->isRunning())
// 	{
// 		mgr->messagePump();
// 		dev->SetViewport(&mainView);
// 		
// 		device->clear(0, 1.0f, 1.0f, 0.0f, 0.0f);
// 		device->begin();
// 		img->draw();
// 		device->end();
// 		dev->SetViewport(&secondView);
// 		device->clear(0, 1.0f, 0.0f, 0.0f, 0.2f);
// 		device->begin();
// 		device->end();
// 		device->present();
// 	}
// 	ReleaseClass(depth);
// 	ReleaseClass(img);
// 	ReleaseClass(adap);
// 	ReleaseClass(device);
// 	system("PAUSE");
// 	return 0;
// }

#include "..//GodEngine/GodWindow.h"
#include "..//GodEngine/GodWindowManager.h"
#include "..//GodRenderSystemD3D9/GodAdapterManager.h"
#include "..//GodRenderSystemD3D9/GodDeviceD3D9.h"
#include "..//GodRenderSystemD3D9/GodDepthStencilBufferD3D9.h"
#include "..//GodRenderSystemD3D9/GodImageD3D9.h"
#include "..//GodEngine/GodImage.h"
#include "..//GodEngine/GodRenderWindow.h"
#include "..//GodRenderSystemD3D9/GodRenderWindowD3D9.h"

#pragma comment(lib,"..//GodEngine/Lib/Debug/godEngine_d.lib")
#pragma comment(lib,"..//GodEngine/Lib/Debug/GodRenderSystemD3D9_d.lib")
using namespace std;


using namespace GodEngine;

int main()
{
	WindowManager* winMgr = new WindowManager();
	RenderWindow* renWindow = new RenderWindowD3D9();
	winMgr->addWindow(renWindow);
	renWindow->createRenderWindow("RenderWindow", "God Engine", 800, 600, false, false, false, 0, 32, 0, 0);
	renWindow->show();


	while (winMgr->isRunning())
	{
		winMgr->messagePump();

		renWindow->clearScene(0, 1.0f, 0.0f, 0.0f, 1.0f);
		renWindow->beginRender();
		renWindow->endRender();
		renWindow->presentScene();
	}
	ReleaseClass(renWindow);
}