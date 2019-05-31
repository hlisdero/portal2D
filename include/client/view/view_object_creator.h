#ifndef VIEW_OBJECT_CREATOR_H
#define VIEW_OBJECT_CREATOR_H

#include <map>
#include "client/objects/drawable_box2D.h"
#include "client/objects/objects.h"
#include "client/view/world_view_settings.h"
#include "client/texture/texture_loader.h"
#include "common/entities/entities_settings.h"
#include "common/position.h"
#include "common/size.h"

class ViewObjectCreator {
public:
    ViewObjectCreator(std::map<size_t, DrawableBox2D*>& view_objects,
                      const WorldViewSettings& settings);

    ViewObjectCreator(const ViewObjectCreator&) = delete;
    ViewObjectCreator& operator=(const ViewObjectCreator&) = delete;
    ViewObjectCreator(ViewObjectCreator&& other) = delete;
    ViewObjectCreator& operator=(ViewObjectCreator&& other) = delete;

    const Player& createPlayer(size_t index, const Position& initial) const;
    void createMetalBlock(size_t index, const Position& initial) const;
    void createDiagonalMetalBlock(size_t index, const Position& initial, double rotation = 0.0) const;
    void createStoneBlock(size_t index, const Position& initial) const;
    void createAcid(size_t index, const Position& initial) const;
    void createGate(size_t index, const Position& initial) const;
    void createButton(size_t index, const Position& initial) const;
    void createEnergyBall(size_t index, const Position& initial) const;
    void createEnergyBar(size_t index, const Position& initial, double rotation = 0.0) const;
    void createEndBarrier(size_t index, const Position& initial, double rotation = 0.0) const;
    void createEnergyEmitter(size_t index, const Position& initial, double rotation = 0.0) const;
    void createEnergyReceiver(size_t index, const Position& initial, double rotation = 0.0) const;
    void createRock(size_t index, const Position& initial, double rotation = 0.0) const;
    void createPortal(size_t index, const Position& initial, double rotation = 0.0) const;

private:
    std::map<size_t, DrawableBox2D*>& view_objects;
    const Ratio& meter_to_pixel;
    const TextureLoader& textures;

    Size getSize(EntityType type) const;
};

#endif  // VIEW_OBJECT_CREATOR_H
