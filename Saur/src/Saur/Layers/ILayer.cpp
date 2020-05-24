
#include "saurpch.h"
#include "ILayer.h"

namespace Saur
{
	ILayer::ILayer(const std::string& name)
#ifdef SAUR_DEBUG
		: m_name(name)
#endif
	{
	}

	ILayer::~ILayer() {}
}
