#include "client/view/world_view.h"

WorldView::WorldView(float32 width, float32 height) :
    meter_to_pixel(1024/width, 768/height),
    screen(1024, 768),
    view_object_creator(meter_to_pixel, view_objects, screen.getTextureCreator(), 1024, 768) {}

WorldView::~WorldView() {
    for (const auto& object : view_objects) {
        delete object;
    }
}

void WorldView::createEntities(const std::vector<Entity*>& entities) {
    for (const auto& entity : entities) {
        Position position(entity->getX(), entity->getY());
        size_t id(entity->getId());
        reserveSize(id);
        view_objects.reserve(id);
        createEntity(entity->getType(), id, position);
    }
}

void WorldView::updatePosition(size_t index, const Position& position) {
    checkValidIndex(index);
    view_objects[index]->updatePosition(position);
}

void WorldView::updatePosition(const std::vector<Entity*>& entities) {
    for (const auto& entity : entities) {
        Position position(entity->getX(), entity->getY());
        size_t id(entity->getId());
        updatePosition(id, position);
    }
}

void WorldView::update() {
    screen.setRenderDrawColor("white");
    screen.clear();
    screen.render(view_object_creator.background);
    renderObjects();

    screen.update();
}

void WorldView::renderObjects() {
    for (const auto& object : view_objects) {
        screen.render(*object);
    }
}

void WorldView::checkValidIndex(size_t index) {
    if (index >= view_objects.size() || view_objects[index] == nullptr) {
        throw std::runtime_error("Error: Índice de objeto en la vista inválido");
    }
}

void WorldView::reserveSize(size_t index) {
    if (index + 1 > view_objects.size()) {
        view_objects.resize(index + 1, nullptr);
    }
}

void WorldView::createEntity(EntityType type, size_t id, const Position& position) {
    switch (type) {
        case TYPE_STONE_BLOCK:
            view_object_creator.createStoneBlock(id, position);
            break;
        case TYPE_METAL_BLOCK:
            view_object_creator.createMetalBlock(id, position);
            break;
        case TYPE_METAL_DIAG_BLOCK:
            view_object_creator.createDiagonalMetalBlock(id, position);
            break;
        case TYPE_ACID:
            view_object_creator.createAcid(id, position);
            break;
        case TYPE_GATE:
            view_object_creator.createGate(id, position);
            break;
        case TYPE_ENERGY_BAR:
            view_object_creator.createEnergyBar(id, position);
            break;
        case TYPE_ENERGY_EMITTER:
            view_object_creator.createEnergyEmitter(id, position);
            break;
        case TYPE_ENERGY_RECEIVER:
            view_object_creator.createEnergyReceiver(id, position);
            break;
        case TYPE_BUTTON:
            view_object_creator.createButton(id, position);
            break;
        case TYPE_PORTAL:
            view_object_creator.createPortal(id, position);
            break;
        case TYPE_ROCK:
            view_object_creator.createRock(id, position);
            break;
        case TYPE_PLAYER:
            view_object_creator.createPlayer(id, position);
            break;
        case TYPE_ENERGY_BALL:
            view_object_creator.createEnergyBall(id, position);
            break;
        default:
            throw std::runtime_error("Error: EntityType inválido");
    }
}
