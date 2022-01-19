#pragma once

#include "Event.h"
#include <sstream>

namespace Infectious
{
	class INFECTIOUS_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y) {}

		inline float getX() const { return m_MouseX; }
		inline float getY() const { return m_MouseY; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: (" << getX() << ", " << getY() << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_MouseX;
		float m_MouseY;

	};


	class INFECTIOUS_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float x, float y)
			: m_OffsetX(x), m_OffsetY(y) {}

		inline float getX() const { return m_OffsetX; }
		inline float getY() const { return m_OffsetY; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: (" << getX() << ", " << getY() << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_OffsetX;
		float m_OffsetY;

	};

	class INFECTIOUS_API MouseButtonEvent : public Event
	{

	public:
		inline int getMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	protected:
		MouseButtonEvent(int button)
			:m_Button(button) {}

		int m_Button;

	};

	class INFECTIOUS_API MouseButtonPressedEvent : public MouseButtonEvent
	{

	public:
		MouseButtonPressedEvent(int button)
			:MouseButtonEvent(button) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent:" << getMouseButton();
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonPressed)

	};

	class INFECTIOUS_API MouseButtonReleasedEvent : public MouseButtonEvent
	{

	public:
		MouseButtonReleasedEvent(int button)
			:MouseButtonEvent(button) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent:" << getMouseButton();
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonReleased)

	};

}
