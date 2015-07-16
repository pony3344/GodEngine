#include "GodDataTypes.h"

#define ReleaseClass(x) { if(x) { delete x; x=0;}}

namespace GodEngine
{
//	class DisplayAdapter;
//	class DisplayMode;
	class Image;
	class Mesh;
	class SubMesh;
	class Rectangle2D;
	class RenderWindow;
	class Texture;
	class WindowListener;
	class Window;
	class WindowManager;
namespace GodGeometry
{
	class GeometryManager;
	class Vertex; 
	class Triangle;
}
}