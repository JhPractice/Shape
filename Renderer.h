#pragma once

#ifndef _RENDERER_
#define _RENDERER_

const int kRow = 20;
const int kCullum = 50;

class Renderer
{
private:
	char buffer[kRow][kCullum];
public:
	Renderer();
	~Renderer();

	void Initialize();

	void Render();
};

#endif
