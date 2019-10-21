#pragma once
#include "Window.h"
#include "ChiliMath.h"
#include "ChiliTimer.h"
#include "ImguiManager.h"
#include "Camera.h"
#include "PointLight.h"
#include "TestPlane.h"
#include "Mesh.h"
#include "Object.h"
#include <set>

class App
{
public:
	App( const std::string& commandLine = "" );
	// master frame / message loop
	int Go();
	~App();
private:
	void DoFrame();
	void ShowImguiDemoWindow();
private:
	//randoms for picture generating
	std::random_device rd{};
	std::mt19937 rng{ rd() };
	static constexpr float minR = 40.0f;
	static constexpr float maxR = 50.0f;
	static constexpr float minAsc = -PI;
	static constexpr float maxAsc = PI;
	static constexpr float minDec = -PI/2;
	static constexpr float maxDec = PI;
	static constexpr float meanV = 0.1f;
	static constexpr float stddevV = 0.01f;
	static constexpr float minV = 0.00001f;
	static constexpr float maxV = 1.0f;
	static constexpr float minRadians = -PI;
	static constexpr float maxRadians = PI;
	//command line
	std::string commandLine;
	//imgui
	bool showDemoWindow = false;
	ImguiManager imgui;
	//window
	Window wnd;
	//scene
	ChiliTimer timer;
	float speed_factor = 1.0f;
	Camera cam;
	PointLight light;
	static constexpr float pictureScale = 6.0f;
	Model atlas1{ wnd.Gfx(),   "Religion\\atlas\\untitled.obj", 1.0f / 20.0f };
	Model atlas2{ wnd.Gfx(),   "Religion\\atlas\\untitled.obj", 1.0f / 20.0f };
	Object bricks0{ wnd.Gfx(), "Religion\\baby\\picture1.obj", pictureScale };
	Object bricks1{ wnd.Gfx(), "Religion\\baby_afrika\\picture1.obj", pictureScale };
	Object bricks2{ wnd.Gfx(), "Religion\\buddha\\picture1.obj", pictureScale };
	Object bricks3{ wnd.Gfx(), "Religion\\earthrise\\picture1.obj", pictureScale };
	Object bricks4{ wnd.Gfx(), "Religion\\einstein\\picture1.obj", pictureScale };
	Object bricks5{ wnd.Gfx(), "Religion\\frau_fernost\\picture1.obj", pictureScale };
	Object bricks6{ wnd.Gfx(), "Religion\\frau_indien\\picture1.obj", pictureScale };
	Object bricks7{ wnd.Gfx(), "Religion\\girl_indien\\picture1.obj", pictureScale };
	Object bricks8{ wnd.Gfx(), "Religion\\greta\\picture1.obj", pictureScale };
	Object bricks9{ wnd.Gfx(), "Religion\\hongkong_mann\\picture1.obj", pictureScale };
	Object bricks10{wnd.Gfx(), "Religion\\hongkong_proteste\\picture1.obj", pictureScale };
	Object bricks11{wnd.Gfx(), "Religion\\kind_bemalt\\picture1.obj", pictureScale };
	Object bricks12{wnd.Gfx(), "Religion\\kind_mit_fliege\\picture1.obj", pictureScale };
	Object bricks13{wnd.Gfx(), "Religion\\kind_thailand\\picture1.obj", pictureScale };
	Object bricks14{wnd.Gfx(), "Religion\\kinder_nepal\\picture1.obj", pictureScale };
	Object bricks15{wnd.Gfx(), "Religion\\krim_1942\\picture1.obj", pictureScale };
	Object bricks16{wnd.Gfx(), "Religion\\luther\\picture1.obj", pictureScale };
	Object bricks17{wnd.Gfx(), "Religion\\mann_indien\\picture1.obj", pictureScale };
	Object bricks18{wnd.Gfx(), "Religion\\mathe\\picture1.obj", pictureScale };
	Object bricks19{wnd.Gfx(), "Religion\\obdachlose\\picture1.obj", pictureScale };
	Object bricks20{wnd.Gfx(), "Religion\\professor\\picture1.obj", pictureScale };
	Object bricks21{wnd.Gfx(), "Religion\\regenwald\\picture1.obj", pictureScale };
	Object bricks22{wnd.Gfx(), "Religion\\reich_schwarz\\picture1.obj", pictureScale };
	Object bricks23{wnd.Gfx(), "Religion\\religionen\\picture1.obj", pictureScale };
	Object bricks24{wnd.Gfx(), "Religion\\ukraine_konflikt\\picture1.obj", pictureScale };
	Object bricks25{wnd.Gfx(), "Religion\\umwelt\\picture1.obj", pictureScale };
	Object bricks26{wnd.Gfx(), "Religion\\silas\\picture1.obj", pictureScale };
	std::vector<Object*> objects;
};