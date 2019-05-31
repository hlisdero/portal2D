#include "client/view/view_object_creator.h"

ViewObjectCreator::ViewObjectCreator(std::map<size_t, DrawableBox2D*>& view_objects,
                                     const WorldViewSettings& settings) :
    view_objects(view_objects),
    meter_to_pixel(settings.getRatio()),
    textures(settings.getTextureLoader()) {}

const Player& ViewObjectCreator::createPlayer(size_t index, const Position& initial) const {
    Player* player = new Player(getSize(TYPE_PLAYER), initial, meter_to_pixel, textures["Player"]);
    view_objects[index] = player;
    return *player;
}

void ViewObjectCreator::createMetalBlock(size_t index, const Position& initial) const {
    MetalBlock* block = new MetalBlock(getSize(TYPE_METAL_BLOCK), initial, meter_to_pixel, textures["Block"]);
    view_objects[index] = block;
}

void ViewObjectCreator::createDiagonalMetalBlock(size_t index, const Position& initial, double rotation) const {
    DiagonalMetalBlock* block = new DiagonalMetalBlock(getSize(TYPE_METAL_DIAG_BLOCK), initial, meter_to_pixel, textures["Block"], rotation);
    view_objects[index] = block;
}

void ViewObjectCreator::createStoneBlock(size_t index, const Position& initial) const {
    StoneBlock* block = new StoneBlock(getSize(TYPE_STONE_BLOCK), initial, meter_to_pixel, textures["Block"]);
    view_objects[index] = block;
}

void ViewObjectCreator::createAcid(size_t index, const Position& initial) const {
    Acid* acid = new Acid(getSize(TYPE_ACID), initial, meter_to_pixel, textures["Miscellaneous"]);
    view_objects[index] = acid;
}

void ViewObjectCreator::createGate(size_t index, const Position& initial) const {
    Gate* gate = new Gate(getSize(TYPE_GATE), initial, meter_to_pixel, textures["Gate"]);
    view_objects[index] = gate;
}

void ViewObjectCreator::createButton(size_t index, const Position& initial) const {
    Button* button = new Button(getSize(TYPE_BUTTON), initial, meter_to_pixel, textures["Miscellaneous"]);
    view_objects[index] = button;
}

void ViewObjectCreator::createEnergyBall(size_t index, const Position& initial) const {
    EnergyBall* energy_ball = new EnergyBall(getSize(TYPE_ENERGY_BALL), initial, meter_to_pixel, textures["FX"]);
    view_objects[index] = energy_ball;
}

void ViewObjectCreator::createEnergyBar(size_t index, const Position& initial, double rotation) const {
    EnergyBar* energy_bar = new EnergyBar(getSize(TYPE_ENERGY_BAR), initial, meter_to_pixel, textures["FX"], rotation);
    view_objects[index] = energy_bar;
}

void ViewObjectCreator::createEnergyEmitter(size_t index, const Position& initial, double rotation) const {
    EnergyReceiver* energy_receiver = new EnergyReceiver(getSize(TYPE_ENERGY_EMITTER), initial, meter_to_pixel, textures["Block"], rotation);
    view_objects[index] = energy_receiver;
}

void ViewObjectCreator::createEnergyReceiver(size_t index, const Position& initial, double rotation) const {
    EnergyReceiver* energy_receiver = new EnergyReceiver(getSize(TYPE_ENERGY_RECEIVER), initial, meter_to_pixel, textures["Block"], rotation);
    view_objects[index] = energy_receiver;
}

void ViewObjectCreator::createRock(size_t index, const Position& initial, double rotation) const {
    Rock* rock = new Rock(getSize(TYPE_ROCK), initial, meter_to_pixel, textures["Block"], rotation);
    view_objects[index] = rock;
}

void ViewObjectCreator::createPortal(size_t index, const Position& initial, double rotation) const {
    Portal* portal = new Portal(getSize(TYPE_PORTAL), initial, meter_to_pixel, textures["FX"], rotation);
    view_objects[index] = portal;
}

Size ViewObjectCreator::getSize(EntityType type) const {
    return Size(entitiesSettings[type][HALF_WIDTH]*2, entitiesSettings[type][HALF_HEIGHT]*2);
}
