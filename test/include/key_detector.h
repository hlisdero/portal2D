#ifndef KEY_DETECTOR_H
#define KEY_DETECTOR_H

#include "entity.h"
#include "sprite.h"
#include "keyboard_handler.h"
#include "mouse_handler.h"

class KeyDetector : public Entity, public KeyboardHandler {
public:
    KeyDetector(int x, int y, std::vector<Sprite*> sprites);

    virtual Sprite& getSprite() override;
    int getWidth() const override;
    int getHeight() const override;

    virtual void handle(const KeyboardEvent& event) override;

private:
    std::vector<Sprite*> sprites;
    size_t current = 0;
};

#endif  // KEY_DETECTOR
