#include "client/view/world_view.h"

WorldView::WorldView(float32 width, float32 height,
                     size_t level_width, size_t level_height) :
    meter_to_pixel(screen_width/width, screen_height/height),
    level_width(level_width), level_height(level_height),
    screen(screen_width, screen_height),
    view_object_creator(meter_to_pixel, view_objects, screen.getTextureCreator(), 1024, 768) {
    if (level_width < screen_width || level_height < screen_height) {
        throw std::runtime_error("Error: el tamaño del mundo en pixeles es demasiado pequeño");
    }
}

WorldView::~WorldView() {
    for (const auto& object : view_objects) {
        delete object;
    }
}

void WorldView::createEntities(const std::vector<Entity*>& entities) {
    for (const auto& entity : entities) {
        Position position(entity->getX(), entity->getY());
        size_t id(entity->getId());
        double angle(entity->getRotationDeg());
        view_objects.reserve(id);
        createEntity(entity->getType(), id, position, angle);
    }
}

void WorldView::updatePosition(size_t index, const Position& position, double angle) {
    checkValidIndex(index);
    view_objects[index]->updatePosition(position, angle);
}

void WorldView::updatePosition(const std::vector<Entity*>& entities) {
    for (const auto& entity : entities) {
        Position position(entity->getX(), entity->getY());
        size_t id(entity->getId());
        double angle(entity->getRotationDeg());
        updatePosition(id, position, angle);
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

void WorldView::createEntity(EntityType type, size_t id,
                const Position& position, double rotation) {
    switch (type) {
        case TYPE_STONE_BLOCK:
            view_object_creator.createStoneBlock(id, position);
            break;
        case TYPE_METAL_BLOCK:
            view_object_creator.createMetalBlock(id, position);
            break;
        case TYPE_METAL_DIAG_BLOCK:
            view_object_creator.createDiagonalMetalBlock(id, position, rotation);
            break;
        case TYPE_ACID:
            view_object_creator.createAcid(id, position);
            break;
        case TYPE_GATE:
            view_object_creator.createGate(id, position);
            break;
        case TYPE_ENERGY_BAR:
            view_object_creator.createEnergyBar(id, position, rotation);
            break;
        case TYPE_ENERGY_EMITTER:
            view_object_creator.createEnergyEmitter(id, position, rotation);
            break;
        case TYPE_ENERGY_RECEIVER:
            view_object_creator.createEnergyReceiver(id, position, rotation);
            break;
        case TYPE_BUTTON:
            view_object_creator.createButton(id, position);
            break;
        case TYPE_PORTAL:
            view_object_creator.createPortal(id, position, rotation);
            break;
        case TYPE_ROCK:
            view_object_creator.createRock(id, position, rotation);
            break;
        case TYPE_PLAYER:
            createPlayerWithCamera(id, position);
            break;
        case TYPE_ENERGY_BALL:
            view_object_creator.createEnergyBall(id, position);
            break;
        default:
            throw std::runtime_error("Error: EntityType inválido");
    }
}

void WorldView::createPlayerWithCamera(size_t id, const Position& position) {
    const Player& player = view_object_creator.createPlayer(id, position);
    screen.createCamera(level_width, level_height, player);
    meter_to_pixel.x = meter_to_pixel.x*level_width/screen_width;
    meter_to_pixel.y = meter_to_pixel.x*level_height/screen_height;
}
