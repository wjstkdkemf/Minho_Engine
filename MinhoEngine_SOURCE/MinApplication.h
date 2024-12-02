#pragma once
#include "minGameObject.h"

namespace min{
	class Application
	{
	public:
		Application();
		~Application();
		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();
		void Rander();

	private:
		void clearRenderTarget();
		void copyRenderTarget(HDC source, HDC dest);
		void adjustWindowRect(HWND hwnd, UINT width, UINT height);
		void createBuffer(UINT width, UINT height);
		void initializeEtc();

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;

		GameObject mPlayer[2];
		//std::vector<GameObject*> Bullet;
		//std::vector<Scene*> mScenes;
	};
}

