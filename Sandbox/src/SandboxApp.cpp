
#include <Infectious.h>

class Sandbox : public Infectious::Application
{
public:
	Sandbox() {

	};
	~Sandbox() {

	};



};


Infectious::Application* Infectious::CreateApplication() {
	return new Sandbox();
}
