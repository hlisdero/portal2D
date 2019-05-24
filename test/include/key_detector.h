#ifndef KEY_DETECTOR_H
#define KEY_DETECTOR_H

#include "client/objects/drawable.h"
#include "client/view/sprite.h"
#include "client/event/keyboard_handler.h"

class KeyDetector : public Drawable, public KeyboardHandler {
public:
    KeyDetector(int x, int y, std::vector<Sprite*> sprites);

    virtual const Texture& getTexture() override;
    int getX() const override;
    int getY() const override;
    int getWidth() const override;
    int getHeight() const override;

    virtual void handle(const KeyboardEvent& event) override;

private:
    int x;
    int y;
    std::vector<Sprite*> sprites;
    size_t current = 0;

};

#endif  // KEY_DETECTOR
