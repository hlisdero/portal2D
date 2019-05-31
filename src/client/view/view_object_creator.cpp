#include "client/view/view_object_creator.h"

ViewObjectCreator::ViewObjectCreator(Ratio& ratio, std::vector<DrawableBox2D*>& view_objects,
    const TextureCreator& texture_creator, size_t width, size_t height) :
    meter_to_pixel(ratio), view_objects(view_objects), textures(texture_creator),
    background(width, height, textures["Background"]) {}

const Player& ViewObjectCreator::createPlayer(size_t index, const Position& initial) {
    Size size(entitiesSettings[TYPE_PLAYER][HALF_WIDTH]*2, entitiesSettings[TYPE_PLAYER][HALF_HEIGHT]*2);
    Player* player = new Player(size, initial, meter_to_pixel, textures["Player"]);
    reserveSize(index);
    view_objects.at(index) = player;
    return *player;
}

void ViewObjectCreator::createMetalBlock(size_t index, const Position& initial) {
    Size size(entitiesSettings[TYPE_METAL_BLOCK][HALF_WIDTH]*2, entitiesSettings[TYPE_METAL_BLOCK][HALF_HEIGHT]*2);
    MetalBlock* block = new MetalBlock(size, initial, meter_to_pixel, textures["Block"]);
    reserveSize(index);
    view_objects.at(index) = block;
}

void ViewObjectCreator::createDiagonalMetalBlock(size_t index, const Position& initial, double rotation) {
    Size size(entitiesSettings[TYPE_METAL_DIAG_BLOCK][HALF_WIDTH]*2, entitiesSettings[TYPE_METAL_DIAG_BLOCK][HALF_HEIGHT]*2);
    DiagonalMetalBlock* block = new DiagonalMetalBlock(size, initial, meter_to_pixel, textures["Block"], rotation);
    reserveSize(index);
    view_objects.at(index) = block;
}

void ViewObjectCreator::createStoneBlock(size_t index, const Position& initial) {
    Size size(entitiesSettings[TYPE_STONE_BLOCK][HALF_WIDTH]*2, entitiesSettings[TYPE_STONE_BLOCK][HALF_HEIGHT]*2);
    StoneBlock* block = new StoneBlock(size, initial, meter_to_pixel, textures["Block"]);
    reserveSize(index);
    view_objects.at(index) = block;
}

void ViewObjectCreator::createAcid(size_t index, const Position& initial) {
    Size size(entitiesSettings[TYPE_ACID][HALF_WIDTH]*2, entitiesSettings[TYPE_ACID][HALF_HEIGHT]*2);
    Acid* acid = new Acid(size, initial, meter_to_pixel, textures["Miscellaneous"]);
    reserveSize(index);
    view_objects.at(index) = acid;
}

void ViewObjectCreator::createGate(size_t index, const Position& initial) {
    Size size(entitiesSettings[TYPE_GATE][HALF_WIDTH]*2, entitiesSettings[TYPE_GATE][HALF_HEIGHT]*2);
    Gate* gate = new Gate(size, initial, meter_to_pixel, textures["Gate"]);
    reserveSize(index);
    view_objects.at(index) = gate;
}

void ViewObjectCreator::createButton(size_t index, const Position& initial) {
    Size size(entitiesSettings[TYPE_BUTTON][HALF_WIDTH]*2, entitiesSettings[TYPE_BUTTON][HALF_HEIGHT]*2);
    Button* button = new Button(size, initial, meter_to_pixel, textures["Miscellaneous"]);
    reserveSize(index);
    view_objects.at(index) = button;
}

void ViewObjectCreator::createEnergyBall(size_t index, const Position& initial) {
    Size size(entitiesSettings[TYPE_ENERGY_BALL][HALF_WIDTH]*2, entitiesSettings[TYPE_ENERGY_BALL][HALF_HEIGHT]*2);
    EnergyBall* energy_ball = new EnergyBall(size, initial, meter_to_pixel, textures["FX"]);
    reserveSize(index);
    view_objects.at(index) = energy_ball;
}

void ViewObjectCreator::createEnergyBar(size_t index, const Position& initial, double rotation) {
    Size size(entitiesSettings[TYPE_ENERGY_BAR][HALF_WIDTH]*2, entitiesSettings[TYPE_ENERGY_BAR][HALF_HEIGHT]*2);
    EnergyBar* energy_bar = new EnergyBar(size, initial, meter_to_pixel, textures["FX"], rotation);
    reserveSize(index);
    view_objects.at(index) = energy_bar;
}

void ViewObjectCreator::createEnergyEmitter(size_t index, const Position& initial, double rotation) {
    Size size(entitiesSettings[TYPE_ENERGY_EMITTER][HALF_WIDTH]*2, entitiesSettings[TYPE_ENERGY_EMITTER][HALF_HEIGHT]*2);
    EnergyReceiver* energy_receiver = new EnergyReceiver(size, initial, meter_to_pixel, textures["Block"], rotation);
    reserveSize(index);
    view_objects.at(index) = energy_receiver;
}

void ViewObjectCreator::createEnergyReceiver(size_t index, const Position& initial, double rotation) {
    Size size(entitiesSettings[TYPE_ENERGY_RECEIVER][HALF_WIDTH]*2, entitiesSettings[TYPE_ENERGY_RECEIVER][HALF_HEIGHT]*2);
    EnergyReceiver* energy_receiver = new EnergyReceiver(size, initial, meter_to_pixel, textures["Block"], rotation);
    reserveSize(index);
    view_objects.at(index) = energy_receiver;
}

void ViewObjectCreator::createRock(size_t index, const Position& initial, double rotation) {
    Size size(entitiesSettings[TYPE_ROCK][HALF_WIDTH]*2, entitiesSettings[TYPE_ROCK][HALF_HEIGHT]*2);
    Rock* rock = new Rock(size, initial, meter_to_pixel, textures["Block"], rotation);
    reserveSize(index);
    view_objects.at(index) = rock;
}

void ViewObjectCreator::createPortal(size_t index, const Position& initial, double rotation) {
    Size size(entitiesSettings[TYPE_PORTAL][HALF_WIDTH]*2, entitiesSettings[TYPE_PORTAL][HALF_HEIGHT]*2);
    Portal* portal = new Portal(size, initial, meter_to_pixel, textures["FX"], rotation);
    reserveSize(index);
    view_objects.at(index) = portal;
}

void ViewObjectCreator::reserveSize(size_t index) {
    if (index + 1 > view_objects.size()) {
        view_objects.resize(index + 1, nullptr);
    }
}
