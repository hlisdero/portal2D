#ifndef DRAWABLE_BOX2D_H
#define DRAWABLE_BOX2D_H

#include "client/objects/drawable.h"
#include "client/view/world_view_settings.h"
#include "common/objects/position.h"
#include "common/objects/size.h"

class DrawableBox2D : public Drawable {
public:
    explicit DrawableBox2D(const Size& size, const Position& initial,
                           const WorldViewSettings& settings);

    virtual const Texture& getTexture() = 0;

    virtual int getX() const override;
    virtual int getY() const override;
    virtual int getWidth() const override;
    virtual int getHeight() const override;

    virtual double getRotation() const override;

    double currentX() const;
    double currentY() const;

    virtual void updatePosition(const Position& new_position);

    virtual ~DrawableBox2D() = default;

private:
    const Size size;
    Position position;
    const double& pixel_per_meter;
    const size_t& window_height;
};

#endif  // DRAWABLE_BOX2D_H
