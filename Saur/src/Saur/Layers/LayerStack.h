
#pragma once

#include "ILayer.h"

namespace Saur
{
	class SAUR_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(ILayer* layer);
		void PushOverlay(ILayer* overlay);
		void PopLayer(ILayer* layer);
		void PopOverlay(ILayer* overlay);

		std::vector<ILayer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<ILayer*>::iterator end() { return m_Layers.end(); }
	private:
		std::vector<ILayer*> m_Layers;
		std::vector<ILayer*>::iterator m_LayerInsert;
	};
}
