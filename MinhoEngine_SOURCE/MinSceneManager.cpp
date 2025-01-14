#include "MinSceneManager.h"
#include "Mininput.h"
#include "MinDontDestroyOnLoad.h"

namespace min {
	std::map<std::wstring, Scene*> SceneManager::mScene = {{}};
	Scene* SceneManager::mActiveScene = nullptr;
	Scene* SceneManager::mDontDestroyOnLoad = nullptr;

	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		if (mActiveScene) {
			mActiveScene->OnExit();
		}

		std::map<std::wstring, Scene*>::iterator iter = mScene.find(name);

		if (iter == mScene.end()) {
			return nullptr;
		}
		mActiveScene = iter->second;
		mActiveScene->OnEnter();

		return iter->second;
	}

	void SceneManager::Initialize()
	{
		mDontDestroyOnLoad = CreateScene<DontDestroyOnLoad>(L"DontDestroyOnLoad");
	}

	void SceneManager::Update()
	{
		if (input::GetKey(eKeyCode::N)) {
			SceneManager::LoadScene(L"TitleScene");
		}
		if (input::GetKey(eKeyCode::M)) {
			SceneManager::LoadScene(L"PlayScene");
		}
		mActiveScene->Update();
		mDontDestroyOnLoad->Update();
	}
	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
		mDontDestroyOnLoad->LateUpdate();
	}
	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Rander(hdc);
		mDontDestroyOnLoad->Rander(hdc);
	}
	void SceneManager::Destory()
	{
		mActiveScene->Destory();
		mDontDestroyOnLoad->Destory();
	}
	void SceneManager::Release()
	{
		for (auto& iter : mScene)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
}