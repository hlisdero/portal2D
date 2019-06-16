#include "client/view/view_object_creator.h"

ViewObjectCreator::ViewObjectCreator(std::map<size_t, DrawableBox2D*>& view_objects,
                                     const WorldViewSettings& settings) :
    view_objects(view_objects),
    settings(settings),
    textures(settings.getTextureLoader()) {}

const Player& ViewObjectCreator::createPlayer(size_t index, const Position& initial) const {
    Player* player = new Player(getSize(TYPE_PLAYER), initial, settings, textures["Player"]);
    view_objects[index] = player;
    return *player;
}

void ViewObjectCreator::createMetalBlock(size_t index, const Position& initial) const {
    MetalBlock* block = new MetalBlock(getSize(TYPE_METAL_BLOCK), initial, settings, textures["Entities"]);
    view_objects[index] = block;
}

void ViewObjectCreator::createDiagonalMetalBlock(size_t index, const Position& initial) const {
    DiagonalMetalBlock* block = new DiagonalMetalBlock(getSize(TYPE_METAL_DIAG_BLOCK), initial, settings, textures["Entities"]);
    view_objects[index] = block;
}

void ViewObjectCreator::createStoneBlock(size_t index, const Position& initial) const {
    StoneBlock* block = new StoneBlock(getSize(TYPE_STONE_BLOCK), initial, settings, textures["Entities"]);
    view_objects[index] = block;
}

void ViewObjectCreator::createAcid(size_t index, const Position& initial) const {
    Acid* acid = new Acid(getSize(TYPE_ACID), initial, settings, textures["Miscellaneous"]);
    view_objects[index] = acid;
}

void ViewObjectCreator::createGate(size_t index, const Position& initial) const {
    Gate* gate = new Gate(getSize(TYPE_GATE), initial, settings, textures["Entities"]);
    view_objects[index] = gate;
}

void ViewObjectCreator::createButton(size_t index, const Position& initial) const {
    Button* button = new Button(getSize(TYPE_BUTTON), initial, settings, textures["Miscellaneous"]);
    view_objects[index] = button;
}

void ViewObjectCreator::createEnergyBall(size_t index, const Position& initial) const {
    EnergyBall* energy_ball = new EnergyBall(getSize(TYPE_ENERGY_BALL), initial, settings, textures["FX"]);
    view_objects[index] = energy_ball;
}

void ViewObjectCreator::createEnergyBar(size_t index, const Position& initial) const {
    EnergyBar* energy_bar = new EnergyBar(getSize(TYPE_ENERGY_BAR), initial, settings, textures["Entities"]);
    view_objects[index] = energy_bar;
}

void ViewObjectCreator::createEndBarrier(size_t index, const Position& initial) const {
    EndBarrier* energy_bar = new EndBarrier(getSize(TYPE_END_BARRIER), initial, settings, textures["Entities"]);
    view_objects[index] = energy_bar;
}

void ViewObjectCreator::createEnergyEmitter(size_t index, const Position& initial) const {
    EnergyEmitter* energy_emitter = new EnergyEmitter(getSize(TYPE_ENERGY_EMITTER), initial, settings, textures["Entities"]);
    view_objects[index] = energy_emitter;
}

void ViewObjectCreator::createEnergyReceiver(size_t index, const Position& initial) const {
    EnergyReceiver* energy_receiver = new EnergyReceiver(getSize(TYPE_ENERGY_RECEIVER), initial, settings, textures["Entities"]);
    view_objects[index] = energy_receiver;
}

void ViewObjectCreator::createRock(size_t index, const Position& initial) const {
    Rock* rock = new Rock(getSize(TYPE_ROCK), initial, settings, textures["Entities"]);
    view_objects[index] = rock;
}

void ViewObjectCreator::createPortal(size_t index, const Position& initial, const State& state) const {
    Portal* portal = new Portal(getSize(TYPE_PORTAL), initial, settings, textures["Entities"], state);
    view_objects[index] = portal;
}

Size ViewObjectCreator::getSize(EntityType type) const {
    return Size(entitiesSettings[type][HALF_WIDTH]*2, entitiesSettings[type][HALF_HEIGHT]*2);
}
