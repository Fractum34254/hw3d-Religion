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
	Model atlas1{ wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\atlas\\untitled.obj", 1.0f / 20.0f };
	Model atlas2{ wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\atlas\\untitled.obj", 1.0f / 20.0f };
	Object bricks0{ wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\Religion\\baby\\picture1.obj", 6.0f };
	Object bricks1{ wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\Religion\\baby_afrika\\picture1.obj", 6.0f };
	Object bricks2{ wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\Religion\\buddha\\picture1.obj", 6.0f };
	Object bricks3{ wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\Religion\\earthrise\\picture1.obj", 6.0f };
	Object bricks4{ wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\Religion\\einstein\\picture1.obj", 6.0f };
	Object bricks5{ wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\Religion\\frau_fernost\\picture1.obj", 6.0f };
	Object bricks6{ wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\Religion\\frau_indien\\picture1.obj", 6.0f };
	Object bricks7{ wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\Religion\\girl_indien\\picture1.obj", 6.0f };
	Object bricks8{ wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\Religion\\greta\\picture1.obj", 6.0f };
	Object bricks9{ wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\Religion\\hongkong_mann\\picture1.obj", 6.0f };
	Object bricks10{wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\Religion\\hongkong_proteste\\picture1.obj", 6.0f };
	Object bricks11{wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\Religion\\kind_bemalt\\picture1.obj", 6.0f };
	Object bricks12{wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\Religion\\kind_mit_fliege\\picture1.obj", 6.0f };
	Object bricks13{wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\Religion\\kind_thailand\\picture1.obj", 6.0f };
	Object bricks14{wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\Religion\\kinder_nepal\\picture1.obj", 6.0f };
	Object bricks15{wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\Religion\\krim_1942\\picture1.obj", 6.0f };
	Object bricks16{wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\Religion\\luther\\picture1.obj", 6.0f };
	Object bricks17{wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\Religion\\mann_indien\\picture1.obj", 6.0f };
	Object bricks18{wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\Religion\\mathe\\picture1.obj", 6.0f };
	Object bricks19{wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\Religion\\obdachlose\\picture1.obj", 6.0f };
	Object bricks20{wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\Religion\\professor\\picture1.obj", 6.0f };
	Object bricks21{wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\Religion\\regenwald\\picture1.obj", 6.0f };
	Object bricks22{wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\Religion\\reich_schwarz\\picture1.obj", 6.0f };
	Object bricks23{wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\Religion\\religionen\\picture1.obj", 6.0f };
	Object bricks24{wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\Religion\\ukraine_konflikt\\picture1.obj", 6.0f };
	Object bricks25{wnd.Gfx(), "G:\\Microsoft Visual Studio Repos\\hw3d\\hw3d\\Models\\Religion\\umwelt\\picture1.obj", 6.0f };
	std::vector<Object*> objects;
};