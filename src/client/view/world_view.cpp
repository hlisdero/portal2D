#include "client/view/world_view.h"

WorldView::WorldView(float32 width, float32 height) :
    meter_to_pixel(1024/width, 768/height),
    screen(1024, 768),
    background(screen.getTextureCreator()("../data/sprites/background.png")) {}

WorldView::~WorldView() {
    for (const auto& object : view_objects) {
        delete object;
    }
}

size_t WorldView::createPlayer(const Position& initial) {
    Player* player = new Player(initial, meter_to_pixel, screen.getTextureCreator());
    view_objects.push_back(player);
    return view_objects.size() - 1;
}

size_t WorldView::createBlock(const Position& initial) {
    Block* block = new Block(initial, meter_to_pixel, screen.getTextureCreator());
    view_objects.push_back(block);
    return view_objects.size() - 1;
}

void WorldView::updatePosition(size_t index, const Position& position) {
    checkValidIndex(index);
    view_objects[index]->updatePosition(position);
}

void WorldView::update() {
    clearScreen();
    renderBackground();
    renderObjects();

    screen.update();
}

void WorldView::clearScreen() {
    screen.setRenderDrawColor("white");
    screen.clear();
}

void WorldView::renderBackground() {
    SDL_Rect srcrect = {0, 415, 252, 750 - 415};
    screen.render(background, &srcrect, nullptr);
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
