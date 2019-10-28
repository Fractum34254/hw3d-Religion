#include "App.h"
#include <memory>
#include <algorithm>
#include "ChiliMath.h"
#include "Surface.h"
#include "GDIPlusManager.h"
#include "imgui/imgui.h"
#include "VertexBuffer.h"
#include "TexturePreprocessor.h"
#include <shellapi.h>

namespace dx = DirectX;

GDIPlusManager gdipm;

App::App( const std::string& commandLine )
	:
	commandLine( commandLine ),
	wnd( 1280,720,"Engine" ),
	light( wnd.Gfx() )
{
	// makeshift cli for doing some preprocessing bullshit (so many hacks here)
	if( this->commandLine != "" )
	{
		int nArgs;
		const auto pLineW = GetCommandLineW();
		const auto pArgs = CommandLineToArgvW( pLineW,&nArgs );
		if( nArgs >= 3 && std::wstring(pArgs[1]) == L"--twerk-objnorm" )
		{
			const std::wstring pathInWide = pArgs[2];
			TexturePreprocessor::FlipYAllNormalMapsInObj(
				std::string( pathInWide.begin(),pathInWide.end() )
			);
			throw std::runtime_error( "Normal maps all processed successfully. Just kidding about that whole runtime error thing." );
		}
		else if( nArgs >= 3 && std::wstring( pArgs[1] ) == L"--twerk-flipy" )
		{
			const std::wstring pathInWide = pArgs[2];
			const std::wstring pathOutWide = pArgs[3];
			TexturePreprocessor::FlipYNormalMap(
				std::string( pathInWide.begin(),pathInWide.end() ),
				std::string( pathOutWide.begin(),pathOutWide.end() )
			);
			throw std::runtime_error( "Normal map processed successfully. Just kidding about that whole runtime error thing." );
		}
		else if( nArgs >= 4 && std::wstring( pArgs[1] ) == L"--twerk-validate" )
		{
			const std::wstring minWide = pArgs[2];
			const std::wstring maxWide = pArgs[3];
			const std::wstring pathWide = pArgs[4];
			TexturePreprocessor::ValidateNormalMap(
				std::string( pathWide.begin(),pathWide.end() ),std::stof( minWide ),std::stof( maxWide )
			);
			throw std::runtime_error( "Normal map validated successfully. Just kidding about that whole runtime error thing." );
		}
	}

	//push back all object models in container
	objects.push_back(&picture0);
	objects.push_back(&picture1);
	objects.push_back(&picture2);
	objects.push_back(&picture3);
	objects.push_back(&picture4);
	objects.push_back(&picture5);
	objects.push_back(&picture6);
	objects.push_back(&picture7);
	objects.push_back(&picture8);
	objects.push_back(&picture9);
	objects.push_back(&picture10);
	objects.push_back(&picture11);
	objects.push_back(&picture12);
	objects.push_back(&picture13);
	objects.push_back(&picture14);
	objects.push_back(&picture15);
	objects.push_back(&picture16);
	objects.push_back(&picture17);
	objects.push_back(&picture18);
	objects.push_back(&picture19);
	objects.push_back(&picture20);
	objects.push_back(&picture21);
	objects.push_back(&picture22);
	objects.push_back(&picture23);
	objects.push_back(&picture24);
	objects.push_back(&picture25);
	objects.push_back(&picture26);
	objects.push_back(&picture27);


	//translate both atlas models and rotate the second one
	const float yaw = PI;
	const float delta_z = 5.0f;
	const float delta_y = -5.0f;

	atlas1.SetRootTransform(dx::XMMatrixTranslation(0.0f, delta_y, delta_z));
	atlas2.SetRootTransform(dx::XMMatrixTranslation(0.0f, delta_y, delta_z) * dx::XMMatrixRotationRollPitchYaw(0.0f, yaw, 0.0f));

	//get random translations for the pictures
	///positions
	std::uniform_real_distribution<float> rDist(minR, maxR);
	std::uniform_real_distribution<float> ascDist(minAsc, maxAsc);
	std::uniform_real_distribution<float> decDist(minDec, maxDec);
	std::uniform_real_distribution<float> radiansDist(minRadians, maxRadians);
	///velocities
	std::normal_distribution<float> vel(meanV,stddevV);

	for (size_t i = 0; i < objects.size(); i++)
	{
		///position & orientation
		const float r = rDist(rng);
		const float asc = ascDist(rng);
		const float dec = decDist(rng);

		///velocity
		const float v = std::clamp(vel(rng), minV, maxV);
		const float deltaAngle = radiansDist(rng);
		const float vAsc = v * cos(deltaAngle);
		const float vDec = v * sin(deltaAngle);

		objects.at(i)->Set(r, asc, dec, vAsc, vDec);
	}

	wnd.Gfx().SetProjection(dx::XMMatrixPerspectiveLH(1.0f, 9.0f / 16.0f, 0.5f, 400.0f));

	//brownie
	objects.push_back(&brownie);
	std::uniform_real_distribution<float> rBrownieDist(100.0f, 110.0f); 
	const float v = std::clamp(vel(rng), minV, maxV);
	const float deltaAngle = radiansDist(rng);
	objects.at(objects.size()-1)->Set(rBrownieDist(rng), ascDist(rng), decDist(rng), v * cos(deltaAngle), v * sin(deltaAngle));

	//set standard to locked mouse
	wnd.DisableCursor();
	wnd.mouse.EnableRaw();
}

void App::DoFrame()
{
	const auto rt = timer.Mark();
	const auto dt = rt * speed_factor;
	wnd.Gfx().BeginFrame( 0.07f,0.0f,0.12f );
	wnd.Gfx().SetCamera( cam.GetMatrix() );
	light.Bind( wnd.Gfx(),cam.GetMatrix() );
	for (size_t i = 0; i < objects.size(); i++)
	{
		objects.at(i)->Update(dt);
	}

	light.Draw( wnd.Gfx() );
	atlas1.Draw(wnd.Gfx());
	atlas2.Draw(wnd.Gfx());
	for (int i = 0; i < (int)objects.size(); i++)
	{
		objects.at(i)->m.Draw(wnd.Gfx());
	}

	while( const auto e = wnd.kbd.ReadKey() )
	{
		if( !e->IsPress() )
		{
			continue;
		}

		switch( e->GetCode() )
		{
		case VK_ESCAPE:
			if( wnd.CursorEnabled() )
			{
				wnd.DisableCursor();
				wnd.mouse.EnableRaw();
			}
			else
			{
				wnd.EnableCursor();
				wnd.mouse.DisableRaw();
			}
			break;
		case VK_F1:
			showDemoWindow = true;
			break;
		case VK_RETURN:
			if (speed_factor == 0.0f)
			{
				speed_factor = former_speed_factor;
			}
			else
			{
				former_speed_factor = speed_factor;
				speed_factor = 0.0f;
			}
		}
	}

	if( !wnd.CursorEnabled() )
	{
		const auto et = dt > 0.0f ? dt : rt * former_speed_factor;
		if( wnd.kbd.KeyIsPressed( 'W' ) )
		{
			cam.Translate( { 0.0f,0.0f,et } );
		}
		if( wnd.kbd.KeyIsPressed( 'A' ) )
		{
			cam.Translate( { -et,0.0f,0.0f } );
		}
		if( wnd.kbd.KeyIsPressed( 'S' ) )
		{
			cam.Translate( { 0.0f,0.0f,-et } );
		}
		if( wnd.kbd.KeyIsPressed( 'D' ) )
		{
			cam.Translate( { et,0.0f,0.0f } );
		}
		if( wnd.kbd.KeyIsPressed( VK_SPACE ) )
		{
			cam.TranslateInWorldSpace( { 0.0f,et,0.0f } );
		}
		if( wnd.kbd.KeyIsPressed( VK_CONTROL ) )
		{
			cam.TranslateInWorldSpace( { 0.0f,-et,0.0f } );
		}
	}

	while( const auto delta = wnd.mouse.ReadRawDelta() )
	{
		if( !wnd.CursorEnabled() )
		{
			cam.Rotate( (float)delta->x,(float)delta->y );
		}
	}
		
	if (wnd.CursorEnabled())
	{
		// imgui windows
		cam.SpawnControlWindow();
		light.SpawnControlWindow();
		ShowImguiDemoWindow();
	}

	// present
	wnd.Gfx().EndFrame();
}

void App::ShowImguiDemoWindow()
{
	if( showDemoWindow )
	{
		ImGui::ShowDemoWindow( &showDemoWindow );
	}
}

App::~App()
{}


int App::Go()
{
	while( true )
	{
		// process all messages pending, but to not block for new messages
		if( const auto ecode = Window::ProcessMessages() )
		{
			// if return optional has value, means we're quitting so return exit code
			return *ecode;
		}
		DoFrame();
	}
}