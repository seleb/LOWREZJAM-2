#pragma once

#include <MY_Scene_Base.h>

class RenderSurface;
class StandardFrameBuffer;
class ShaderComponentUvOffset;
class ShaderComponentHsv;
class Peep;
class TextLabelControlled;

class MY_Scene_Main : public MY_Scene_Base{
public:
	Shader * screenSurfaceShader;
	RenderSurface * screenSurface;
	StandardFrameBuffer * screenFBO;
	Timeout * peepTimeout;

	TextLabelControlled * scoreLabel;
	NodeUI * poser;
	NodeUI * fg;
	NodeUI * bg;
	std::vector<Peep * > peeps;

	float confidence;
	bool posing;
	float score;

	virtual void update(Step * _step) override;
	virtual void render(sweet::MatrixStack * _matrixStack, RenderOptions * _renderOptions) override;

	virtual void unload() override;
	virtual void load() override;

	MY_Scene_Main(Game * _game);
	~MY_Scene_Main();

	void addPeep();
};