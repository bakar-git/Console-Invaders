#pragma once
class ALevel
{
protected:
	virtual void Start() = 0;
	virtual void Renderer() = 0;
	virtual void End() = 0;
public:
	virtual void Initialize() final { // because of "final" keyword, any derived class wont be able to redefine it
		Start();
		Renderer();
		End();
	}
};

