#pragma once
#include "minScene.h"

namespace min {
	class SceneManager
	{
	public:
		template <typename T>
		static Scene* CreateScene(const std::wstring& name) {
			T* scene = new T();
			scene->SetName(name);
			mActiveScene = scene;

			scene->Initialize();

			mScene.insert(std::make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name);
		static std::wstring GetSceneName() { return mActiveScene->GetName(); }
		static Scene* GetActiveScene() { return mActiveScene; }

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Rander(HDC hdc);
		static void Release();

	//	static SceneManager& GetInst()
	//	{
	//		static SceneManager sceneManager;
	//		return sceneManager;
	//	}

	//private:
	//	SceneManager();
	//	~SceneManager();

	private:
		//static std::vector<Scene*> mScene;
		static std::map<std::wstring, Scene*> mScene;
		static Scene* mActiveScene;
	};
}

