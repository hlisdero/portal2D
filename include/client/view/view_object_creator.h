#ifndef VIEW_OBJECT_CREATOR_H
#define VIEW_OBJECT_CREATOR_H

#include <map>
#include "client/objects/drawable_box2D.h"
#include "client/objects/objects.h"
#include "client/view/world_view_settings.h"
#include "client/sound/sound_manager.h"
#include "client/texture/texture_loader.h"
#include "common/entities/entities_settings.h"
#include "common/objects/position.h"
#include "common/objects/size.h"
#include "common/objects/state.h"

class ViewObjectCreator {
public:
    ViewObjectCreator(std::map<size_t, DrawableBox2D*>& view_objects,
                      std::vector<DrawableBox2D*>& pending_destroy_view_objects,
                      const WorldViewSettings& settings,
                      SoundManager& sound_manager);

    ViewObjectCreator(const ViewObjectCreator&) = delete;
    ViewObjectCreator& operator=(const ViewObjectCreator&) = delete;
    ViewObjectCreator(ViewObjectCreator&& other) = delete;
    ViewObjectCreator& operator=(ViewObjectCreator&& other) = delete;

    const Player& createPlayer(size_t index, const Position& initial) const;
    void createMetalBlock(size_t index, const Position& initial) const;
    void createDiagonalMetalBlock(size_t index, const Position& initial) const;
    void createStoneBlock(size_t index, const Position& initial) const;
    void createAcid(size_t index, const Position& initial) const;
    void createGate(size_t index, const Position& initial) const;
    void createButton(size_t index, const Position& initial) const;
    void createEnergyBall(size_t index, const Position& initial) const;
    void createEnergyBar(size_t index, const Position& initial) const;
    void createEndBarrier(size_t index, const Position& initial) const;
    void createEnergyEmitter(size_t index, const Position& initial) const;
    void createEnergyReceiver(size_t index, const Position& initial) const;
    void createRock(size_t index, const Position& initial) const;
    void createPortal(size_t index, const Position& initial, const State& state) const;
    void createPinTool(const Position& initial) const;

private:
    std::map<size_t, DrawableBox2D*>& view_objects;
    std::vector<DrawableBox2D*>& pending_destroy_view_objects;
    const WorldViewSettings& settings;
    SoundManager& sound_manager;
    const TextureLoader& textures;

    Size getSize(EntityType type) const;
};

#endif  // VIEW_OBJECT_CREATOR_H
