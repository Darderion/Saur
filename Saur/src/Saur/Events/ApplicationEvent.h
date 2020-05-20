
#pragma once

#include "Event.h"

namespace Saur
{
	class SAUR_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {}

		inline float GetWidth() const { return m_Width; }
		inline float GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent(" << m_Width << "," << m_Height << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResized)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		float m_Width, m_Height;
	};

	class SAUR_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClosed)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}
