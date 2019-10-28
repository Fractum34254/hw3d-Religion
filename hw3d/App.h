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
	float former_speed_factor = speed_factor;
	Camera cam;
	PointLight light;
	static constexpr float pictureScale = 6.0f;
	Model atlas1{ wnd.Gfx(),   "Religion\\atlas\\untitled.obj", 1.0f / 20.0f };
	Model atlas2{ wnd.Gfx(),   "Religion\\atlas\\untitled.obj", 1.0f / 20.0f };
	Object picture0{ wnd.Gfx(), "Religion\\baby\\picture1.obj", pictureScale };
	Object picture1{ wnd.Gfx(), "Religion\\baby_afrika\\picture1.obj", pictureScale };
	Object picture2{ wnd.Gfx(), "Religion\\buddha\\picture1.obj", pictureScale };
	Object picture3{ wnd.Gfx(), "Religion\\earthrise\\picture1.obj", pictureScale };
	Object picture4{ wnd.Gfx(), "Religion\\einstein\\picture1.obj", pictureScale };
	Object picture5{ wnd.Gfx(), "Religion\\frau_fernost\\picture1.obj", pictureScale };
	Object picture6{ wnd.Gfx(), "Religion\\frau_indien\\picture1.obj", pictureScale };
	Object picture7{ wnd.Gfx(), "Religion\\girl_indien\\picture1.obj", pictureScale };
	Object picture8{ wnd.Gfx(), "Religion\\greta\\picture1.obj", pictureScale };
	Object picture9{ wnd.Gfx(), "Religion\\hongkong_mann\\picture1.obj", pictureScale };
	Object picture10{wnd.Gfx(), "Religion\\hongkong_proteste\\picture1.obj", pictureScale };
	Object picture11{wnd.Gfx(), "Religion\\kind_bemalt\\picture1.obj", pictureScale };
	Object picture12{wnd.Gfx(), "Religion\\kind_mit_fliege\\picture1.obj", pictureScale };
	Object picture13{wnd.Gfx(), "Religion\\kind_thailand\\picture1.obj", pictureScale };
	Object picture14{wnd.Gfx(), "Religion\\kinder_nepal\\picture1.obj", pictureScale };
	Object picture15{wnd.Gfx(), "Religion\\krim_1942\\picture1.obj", pictureScale };
	Object picture16{wnd.Gfx(), "Religion\\luther\\picture1.obj", pictureScale };
	Object picture17{wnd.Gfx(), "Religion\\mann_indien\\picture1.obj", pictureScale };
	Object picture18{wnd.Gfx(), "Religion\\mathe\\picture1.obj", pictureScale };
	Object picture19{wnd.Gfx(), "Religion\\obdachlose\\picture1.obj", pictureScale };
	Object picture20{wnd.Gfx(), "Religion\\professor\\picture1.obj", pictureScale };
	Object picture21{wnd.Gfx(), "Religion\\regenwald\\picture1.obj", pictureScale };
	Object picture22{wnd.Gfx(), "Religion\\reich_schwarz\\picture1.obj", pictureScale };
	Object picture23{wnd.Gfx(), "Religion\\religionen\\picture1.obj", pictureScale };
	Object picture24{wnd.Gfx(), "Religion\\ukraine_konflikt\\picture1.obj", pictureScale };
	Object picture25{wnd.Gfx(), "Religion\\umwelt\\picture1.obj", pictureScale };
	Object picture26{wnd.Gfx(), "Religion\\silas\\picture1.obj", pictureScale };
	Object picture27{wnd.Gfx(), "Religion\\credits\\picture1.obj", pictureScale };
	Object brownie{ wnd.Gfx(), "Religion\\brownie\\picture1.obj", pictureScale, true };
	std::vector<Object*> objects;
};