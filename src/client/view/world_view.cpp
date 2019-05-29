#include "client/view/world_view.h"

WorldView::WorldView(float32 width, float32 height) :
    meter_to_pixel(1024/width, 768/height),
    screen(1024, 768),
    textures(screen.getTextureCreator()),
    background(screen.getWidth(), screen.getHeight(), textures["Background"]) {}

WorldView::~WorldView() {
    for (const auto& object : view_objects) {
        delete object;
    }
}

size_t WorldView::createPlayer(const Position& initial) {
    Size size(entitiesSettings[TYPE_PLAYER][HALF_WIDTH]*2, entitiesSettings[TYPE_PLAYER][HALF_HEIGHT]*2);
    Player* player = new Player(size, initial, meter_to_pixel, textures["Player"]);
    view_objects.push_back(player);
    return view_objects.size() - 1;
}

size_t WorldView::createMetalBlock(const Position& initial) {
    Size size(entitiesSettings[TYPE_METAL_BLOCK][HALF_WIDTH]*2, entitiesSettings[TYPE_METAL_BLOCK][HALF_HEIGHT]*2);
    Block* block = new MetalBlock(size, initial, meter_to_pixel, textures["Block"]);
    view_objects.push_back(block);
    return view_objects.size() - 1;
}

size_t WorldView::createStoneBlock(const Position& initial) {
    Size size(entitiesSettings[TYPE_STONE_BLOCK][HALF_WIDTH]*2, entitiesSettings[TYPE_STONE_BLOCK][HALF_HEIGHT]*2);
    Block* block = new MetalBlock(size, initial, meter_to_pixel, textures["Block"]);
    view_objects.push_back(block);
    return view_objects.size() - 1;
}

size_t WorldView::createAcid(const Position& initial) {
    Size size(entitiesSettings[TYPE_ACID][HALF_WIDTH]*2, entitiesSettings[TYPE_ACID][HALF_HEIGHT]*2);
    Acid* acid = new Acid(size, initial, meter_to_pixel, textures["Miscellaneous"]);
    view_objects.push_back(acid);
    return view_objects.size() - 1;
}

size_t WorldView::createButton(const Position& initial) {
    Size size(entitiesSettings[TYPE_BUTTON][HALF_WIDTH]*2, entitiesSettings[TYPE_BUTTON][HALF_HEIGHT]*2);
    Button* button = new Button(size, initial, meter_to_pixel, textures["Miscellaneous"]);
    view_objects.push_back(button);
    return view_objects.size() - 1;
}

size_t WorldView::createEnergyBall(const Position& initial) {
    Size size(entitiesSettings[TYPE_ENERGY_BALL][HALF_WIDTH]*2, entitiesSettings[TYPE_ENERGY_BALL][HALF_HEIGHT]*2);
    EnergyBall* energy_ball = new EnergyBall(size, initial, meter_to_pixel, textures["FX"]);
    view_objects.push_back(energy_ball);
    return view_objects.size() - 1;
}

size_t WorldView::createEnergyReceiver(const Position& initial, double rotation) {
    Size size(entitiesSettings[TYPE_ENERGY_RECEIVER][HALF_WIDTH]*2, entitiesSettings[TYPE_ENERGY_RECEIVER][HALF_HEIGHT]*2);
    EnergyReceiver* energy_receiver = new EnergyReceiver(size, initial, meter_to_pixel, textures["Block"], rotation);
    view_objects.push_back(energy_receiver);
    return view_objects.size() - 1;
}

size_t WorldView::createRock(const Position& initial, double rotation) {
    Size size(entitiesSettings[TYPE_ROCK][HALF_WIDTH]*2, entitiesSettings[TYPE_ROCK][HALF_HEIGHT]*2);
    Rock* rock = new Rock(size, initial, meter_to_pixel, textures["Block"], rotation);
    view_objects.push_back(rock);
    return view_objects.size() - 1;
}

void WorldView::updatePosition(size_t index, const Position& position) {
    checkValidIndex(index);
    view_objects[index]->updatePosition(position);
}

void WorldView::update() {
    screen.setRenderDrawColor("white");
    screen.clear();
    screen.render(background);
    renderObjects();

    screen.update();
}

void WorldView::renderObjects() {
    for (const auto& object : view_objects) {
        screen.render(*object);
    }
}

void WorldView::checkValidIndex(size_t index) {
    if (index >= view_objects.size()) {
        throw std::runtime_error("Error: Índice de objeto en la vista inválido");
    }
}
