#pragma once
#include "MinGraphicDevice_DX11.h"

namespace min::graphics
{
	class IndexBuffer : public GpuBuffer
	{
	public:
		IndexBuffer();
		~IndexBuffer();

		bool Create(const std::vector<UINT>& indices);
		void Bind() const;

	private:
	};
}

