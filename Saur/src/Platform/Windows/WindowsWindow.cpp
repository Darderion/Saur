
#include "saurpch.h"
#include "WindowsWindow.h"

#include "Saur/Events/Event.h"
#include "Saur/Events/KeyEvent.h"
#include "Saur/Events/MouseEvent.h"
#include "Saur/Events/ApplicationEvent.h"

namespace Saur
{
	static bool is_GLFWInitialized = false;

	IWindow* IWindow::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	static void GLFWErrorCallback(int errorCode, const char* message)
	{
		SAUR_CORE_ERROR("GLFW ERROR({0}, {1})", errorCode, message);
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		SAUR_CORE_INFO("Create_Window({0}, {1}, {2})", props.Title, props.Width, props.Height);

		if (!is_GLFWInitialized)
		{
			int initialized = glfwInit();
			SAUR_CORE_ASSERT(initialized, "Could not initialize GLFW");

			glfwSetErrorCallback(GLFWErrorCallback);
			is_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow(
			(int)props.Width,
			(int)props.Height,
			m_Data.Title.c_str(),
			nullptr,
			nullptr
		);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		glfwSetWindowSizeCallback(m_Window,
			[](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;
			WindowResizeEvent event(width, height);
			data.EventCallback(event);
		});

		glfwSetWindowCloseCallback(m_Window,
			[](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.EventCallback(event);
		});

		glfwSetWindowCloseCallback(m_Window,
			[](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.EventCallback(event);
		});

		glfwSetKeyCallback(m_Window,
			[](GLFWwindow* window, int key, int scancode, int action, int modes)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent e(key, 0);
					data.EventCallback(e);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent e(key);
					data.EventCallback(e);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent e(key, 1);
					data.EventCallback(e);
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(m_Window,
			[](GLFWwindow* window, int button, int action, int modes)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent e(button);
					data.EventCallback(e);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent e(button);
					data.EventCallback(e);
					break;
				}
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent e((float)xOffset, (float)yOffset);
			data.EventCallback(e);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent e((float)xPos, (float)yPos);
			data.EventCallback(e);
		});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}
