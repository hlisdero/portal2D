#ifndef KEYBOARD_TEST_H
#define KEYBOARD_TEST_H

#include "entity.h"
#include "sprite.h"
#include "keyboard_handler.h"
#include "mouse_handler.h"

class KeyboardTest : public Entity, public KeyboardHandler {
public:
    KeyboardTest(int x, int y, std::vector<Sprite*> sprites);

    virtual Sprite& getSprite() override;
    int getWidth() const override;
    int getHeight() const override;

    virtual void handle(const KeyboardEvent& event) override;

private:
    std::vector<Sprite*> sprites;
    size_t current = 0;
};

#endif  // KEYBOARD_TEST
