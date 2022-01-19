#pragma once
#include "Event.h"
#include <sstream>

namespace Infectious
{
	class INFECTIOUS_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(int width, int height)
			:m_Width(width), m_Height(height) {}

		inline unsigned int getWidth() const { return m_Width; }
		inline unsigned int getHeight() const { return  m_Height; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << getWidth() << " , " << getHeight();
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		unsigned int m_Width;
		unsigned int m_Height;
	};

	class INFECTIOUS_API WindowCloseEvent :public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class INFECTIOUS_API AppTickEvent :public Event
	{
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class INFECTIOUS_API AppUpdateEvent :public Event
	{
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


	class INFECTIOUS_API AppRenderEvent :public Event
	{
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


}
