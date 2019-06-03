#ifndef DRAWABLE_BOX2D_H
#define DRAWABLE_BOX2D_H

#include "client/objects/drawable.h"
#include "common/position.h"
#include "common/size.h"

class DrawableBox2D : public Drawable {
public:
    explicit DrawableBox2D(const Size& size, const Position& initial,
                           const double& ratio, double angle = 0.0);

    virtual const Texture& getTexture() = 0;

    virtual int getX() const override;
    virtual int getY() const override;
    virtual int getWidth() const override;
    virtual int getHeight() const override;

    virtual double getRotation() const override;

    float32 currentX() const;
    float32 currentY() const;

    virtual void updatePosition(const Position& new_position, double angle);

    virtual ~DrawableBox2D() = default;

private:
    const Size size;
    Position position;
    const double& pixel_per_meter;
    double angle = 0.0;
};

#endif  // DRAWABLE_BOX2D_H
