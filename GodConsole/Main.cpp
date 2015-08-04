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
#include "..//GodRenderSystemD3D9/GodVertexDeclarationD3D9.h"
#include "..//GodEngine/GodVertexDeclaration.h"
#include "..//GodEngine/GodTexture.h"
#include "..//GodRenderSystemD3D9/GodTextureD3D9.h"

#pragma comment(lib,"..//GodEngine/Lib/Debug/godEngine_d.lib")
#pragma comment(lib,"..//GodEngine/Lib/Debug/GodRenderSystemD3D9_d.lib")
using namespace std;


using namespace GodEngine;

int main()
{
	WindowManager* winMgr = new WindowManager();
	RenderWindow* renWindow = new RenderWindowD3D9();
	winMgr->addWindow(renWindow);
	renWindow->createRenderWindow("RenderWindow", "God Engine", 800, 600, false,true, false, 0, 32, 0, 0);
	renWindow->show();

	IDirect3DDevice9* dev = 0;
	RenderWindowD3D9* d3dWin = (RenderWindowD3D9*)renWindow;
	dev = d3dWin->getDevice()->getDeviceD3D9();
	VertexDeclaration* vertDecl = new VertexDeclarationD3D9(dev);
	vertDecl->createVertexDeclaration("Triangle");
	vertDecl->addElement(0, 0, GVDT_FLOAT3, GVM_DEFAULT, GVUT_POSITION, 0);
	vertDecl->update();

	Texture* texture = new TextureD3D9(dev);
	texture->createDynamicTexture("Dynamic", 512, 512, "A8R8G8B8");

	TextureD3D9* d3dTex = (TextureD3D9*)texture;
	IDirect3DTexture9* iTex = d3dTex->getTexture();

	HRESULT hr = D3DXSaveTextureToFile("checkered.jpg", D3DXIMAGE_FILEFORMAT::D3DXIFF_JPG, iTex, NULL);

	if (FAILED(hr))
	{
		const char* err = DXGetErrorDescription(hr);

		MessageBox(nullptr, err, err, MB_OK);
	}

	ID3DXMesh* Sphere = NULL;	// sphere mesh.
	ID3DXMesh* Box = NULL;		// box mesh.
	D3DXCreateSphere(dev, 10.0f, 20, 20, &Sphere, nullptr);
	D3DXCreateBox(dev, 10.0f, 50.0f, 10.0f, &Box, NULL);	 

	D3DXMATRIX pView;
	D3DXMATRIX pProj;
	D3DXMATRIX pWorld;

	
	while (winMgr->isRunning())
	{
		winMgr->messagePump();

		renWindow->clearScene(1, 1.0f, 0.0f, 0.0f, 1.0f);
		renWindow->beginRender();
		D3DXMatrixLookAtLH(&pView,
			&D3DXVECTOR3(0, 0, -100.0f),
			&D3DXVECTOR3(0, 0, 0),
			&D3DXVECTOR3(0, 1, 0));
		dev->SetTransform(D3DTS_VIEW, &pView);
		D3DXMatrixPerspectiveFovLH(&pProj, 45.0f, 1.3333f, 1.0f, 2000.0f);
		dev->SetTransform(D3DTS_PROJECTION, &pProj);

		D3DXMatrixTranslation(&pWorld, 0.0f, 0.0f, 0.0f);

		dev->SetTransform(D3DTS_WORLD, &pWorld);

		Sphere->DrawSubset(0);
		Box->DrawSubset(0);
		renWindow->endRender();
		renWindow->presentScene();
	}
	ReleaseCOM(Sphere);
	ReleaseCOM(Box);
	ReleaseClass(texture);
	ReleaseClass(vertDecl);
	ReleaseClass(renWindow);
}