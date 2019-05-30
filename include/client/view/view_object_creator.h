#ifndef VIEW_OBJECT_CREATOR_H
#define VIEW_OBJECT_CREATOR_H

#include <vector>
#include "client/objects/drawable_box2D.h"
#include "client/objects/objects.h"
#include "client/texture/texture_loader.h"
#include "common/entities/entities_settings.h"
#include "common/position.h"
#include "common/size.h"

class ViewObjectCreator {
public:
    ViewObjectCreator(Ratio& ratio, std::vector<DrawableBox2D*>& view_objects,
                      const TextureCreator& texture_creator,
                      size_t width, size_t height);

    ViewObjectCreator(const ViewObjectCreator&) = delete;
    ViewObjectCreator& operator=(const ViewObjectCreator&) = delete;
    ViewObjectCreator(ViewObjectCreator&& other) = delete;
    ViewObjectCreator& operator=(ViewObjectCreator&& other) = delete;

    void createPlayer(size_t index, const Position& initial);
    void createMetalBlock(size_t index, const Position& initial);
    void createDiagonalMetalBlock(size_t index, const Position& initial, double rotation = 0.0);
    void createStoneBlock(size_t index, const Position& initial);
    void createAcid(size_t index, const Position& initial);
    void createGate(size_t index, const Position& initial);
    void createButton(size_t index, const Position& initial);
    void createEnergyBall(size_t index, const Position& initial);
    void createEnergyBar(size_t index, const Position& initial, double rotation = 0.0);
    void createEnergyEmitter(size_t index, const Position& initial, double rotation = 0.0);
    void createEnergyReceiver(size_t index, const Position& initial, double rotation = 0.0);
    void createRock(size_t index, const Position& initial, double rotation = 0.0);
    void createPortal(size_t index, const Position& initial, double rotation = 0.0);

private:
    Ratio& meter_to_pixel;
    std::vector<DrawableBox2D*>& view_objects;
    TextureLoader textures;

public:
    Background background;
};

#endif  // VIEW_OBJECT_CREATOR_H
