#pragma once
#include "..\\MinhoEngine_SOURCE\minGameObject.h"


namespace min {
	class Player : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Rander(HDC hdc) override;
	private:
	};
}
