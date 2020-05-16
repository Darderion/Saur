
#include <Saur.h>

class SandBox : public Saur::Application
{
public:
	SandBox() {}
	~SandBox() {}
};

Saur::Application* Saur::CreateApplication()
{
	return new SandBox();
}
