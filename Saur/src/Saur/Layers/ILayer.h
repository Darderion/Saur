
#pragma once

#include "Saur/Core.h"
#include "Saur/Events/Event.h"

namespace Saur
{
	class SAUR_API ILayer
	{
	public:
		ILayer(const std::string& name = "Layer");
		virtual ~ILayer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}
#ifdef SAUR_DEBUG
		inline const std::string& getName() const { return m_name; }
	protected:
		std::string m_name;
	};
#endif
}
