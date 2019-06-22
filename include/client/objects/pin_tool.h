#ifndef PIN_TOOL_H
#define PIN_TOOL_H

#include "client/objects/drawable_box2D.h"
#include "client/texture/sprite.h"
#include "client/texture/finite_animation.h"

class PinTool : public DrawableBox2D {
public:
    PinTool(const Size& size, const Position& initial,
         const WorldViewSettings& settings, const Texture& texture);

	virtual const Texture& getTexture() override;
	virtual SDL_Rect* getClip() override;

    virtual bool isFinished() override;

private:
	FiniteAnimation animation;
};

#endif  // PIN_TOOL_H