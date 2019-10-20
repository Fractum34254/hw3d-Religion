#pragma once
#include "Mesh.h"

class Object
{
public:
	Object(Graphics& gfx, const std::string& pathString, float scale = 1.0f, float dAsc = 0.0f, float dDec = 0.0f)
		:
		m(gfx, pathString, scale),
		deltaAsc(dAsc),
		deltaDec(dDec)
	{}
	void Set(float radius, float ascOrg, float decOrg, float dAsc, float dDec)
	{
		namespace dx = DirectX;
		r = radius;
		asc = ascOrg;
		dec = decOrg;
		deltaAsc = dAsc;
		deltaDec = dDec;

		xStart = r * cos(asc);
		zStart = r * sin(asc);
		const dx::XMMATRIX tf = dx::XMMatrixRotationY(PI / 2 - asc) * dx::XMMatrixTranslation(xStart, 0.0f, zStart) * dx::XMMatrixRotationAxis({ zStart, 0.0f, -xStart, 0.0f }, dec);
		m.SetRootTransform(tf);
	}
	void Update(float dt)
	{
		namespace dx = DirectX;
		asc += deltaAsc * dt;
		dec += deltaDec * dt;
		const float x = r * cos(asc);
		const float z = r * sin(asc);
		const dx::XMMATRIX tf = dx::XMMatrixRotationY(PI / 2 - asc) * dx::XMMatrixTranslation(x, 0.0f, z) * dx::XMMatrixRotationAxis({ zStart, 0.0f, -xStart, 0.0f }, dec);
		m.SetRootTransform(tf);
	}
public:
	Model m;
private:
	float xStart;
	float zStart;
	float r;
	float asc;
	float dec;
	float deltaAsc;
	float deltaDec;
};
