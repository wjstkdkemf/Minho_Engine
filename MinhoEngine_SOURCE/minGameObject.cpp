#include "minGameObject.h"
#include "mininput.h"
#include "MinTime.h"

namespace min {
	bool GameObject::shot = false;

	GameObject::GameObject()
		:mX(0.0f)
		,mY(0.0f)
		,speed(100.0f)
	{
	}
	GameObject::~GameObject()
	{

	}

	void GameObject::Update()
	{
		if (input::GetKey(eKeyCode::A)) {
			mX -= speed * Time::DeltaTime();
		}
		if (input::GetKey(eKeyCode::D)) {
			mX += speed * Time::DeltaTime();
		}
		if (input::GetKey(eKeyCode::W)) {
			mY -= speed * Time::DeltaTime();
		}
		if (input::GetKey(eKeyCode::S)) {
			mY += speed * Time::DeltaTime();
		}
		if (input::GetKey(eKeyCode::Space)) {
			shot = true;
		}
		if (GetShot()) {
			GameObject* gameobj = new GameObject();
			gameobj->mX = mX;
			gameobj->mY = mY;
			Bullet.push_back(gameobj);
			SetShot(false);
		}
	}
	void GameObject::LateUpdate()
	{
	}
	void GameObject::Rander(HDC mHdc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));// 파랑배경 브러쉬 생성
		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, brush); // 파랑 브러쉬 DC에 선택 후 기존 흰색 브러쉬 반환

		/*HPEN redpen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldpen = (HPEN)SelectObject(mHdc, redpen);

		SelectObject(mHdc, oldpen);*/

		Rectangle(mHdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		SelectObject(mHdc, oldBrush);
		DeleteObject(brush);
		for (size_t i = 0; i < Bullet.size(); i++) {
			Bullet[i]->ShotRander(mHdc);
		}
	}
	void GameObject::ShotRander(HDC mHdc)
	{
		mY -= speed * Time::DeltaTime();
		Ellipse(mHdc, 145 + mX, 90 + mY, 155 + mX, 100 + mY);

	}


	void GameObject::SetShot(bool button)
	{
		shot = button;
	}

	void GameObject::Update_2()
	{
		if (input::GetKey(eKeyCode::Left)) {
			mX -= speed * Time::DeltaTime();
		}
		if (input::GetKey(eKeyCode::Right)) {
			mX += speed * Time::DeltaTime();
		}
		if (input::GetKey(eKeyCode::Up)) {
			mY -= speed * Time::DeltaTime();
		}
		if (input::GetKey(eKeyCode::Down)) {
			mY += speed * Time::DeltaTime();
		}
	}
	void GameObject::LateUpdate_2()
	{
	}
	void GameObject::Rander_2(HDC mHdc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, brush); // 파랑 브러쉬 DC에 선택 후 기존 흰색 브러쉬 반환

		/*HPEN redpen_2 = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldpen = (HPEN)SelectObject(mHdc, redpen_2);*/

		Ellipse(mHdc, 1500 + mX, 800 + mY, 1600 + mX, 900 + mY);

		SelectObject(mHdc, oldBrush);
		DeleteObject(brush);
	}
}