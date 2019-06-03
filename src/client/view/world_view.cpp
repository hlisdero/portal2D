#include "client/view/world_view.h"

WorldView::WorldView(float32 world_width, float32 world_height) :
    screen(screen_width, screen_height),
    settings(screen.getWidth(), screen.getHeight(), world_width, world_height, screen.getTextureCreator()),
    background(screen_width, screen_height, settings.getTextureLoader()["Background"]),
    object_creator(view_objects, settings) {
    event_manager.addHandler(&sound_manager);
}

WorldView::~WorldView() {
    for (const auto& object : view_objects) {
        delete object.second;
    }
    if (main_player) {
        delete main_player;
    }
}

void WorldView::pollEvents() {
    event_manager.pollEvents();
}

BlockingQueue& WorldView::getQueue() {
    return event_manager.getQueue();
}

bool WorldView::quit() const {
    return event_manager.quit();
}

const ViewObjectCreator& WorldView::getObjectCreator() const {
    return object_creator;
}

void WorldView::createEntities(const std::vector<Entity*>& entities) {
    for (const auto& entity : entities) {
        Position position(entity->getX(), entity->getY());
        size_t id(entity->getId());
        double angle(entity->getRotationDeg());
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
    screen.render(background);
    renderObjects();

    screen.update();
}

void WorldView::renderObjects() {
    for (const auto& object : view_objects) {
        screen.render(*object.second);
    }
}

void WorldView::checkValidIndex(size_t index) {
    if (view_objects[index] == nullptr) {
        throw std::runtime_error("Error: Índice de objeto en la vista inválido");
    }
}

void WorldView::createEntity(EntityType type, size_t id,
                const Position& position, double rotation) {
    switch (type) {
        case TYPE_STONE_BLOCK:
            object_creator.createStoneBlock(id, position);
            break;
        case TYPE_METAL_BLOCK:
            object_creator.createMetalBlock(id, position);
            break;
        case TYPE_METAL_DIAG_BLOCK:
            object_creator.createDiagonalMetalBlock(id, position, rotation);
            break;
        case TYPE_ACID:
            object_creator.createAcid(id, position);
            break;
        case TYPE_GATE:
            object_creator.createGate(id, position, rotation);
            break;
        case TYPE_ENERGY_BAR:
            object_creator.createEnergyBar(id, position, rotation);
            break;
        case TYPE_ENERGY_EMITTER:
            object_creator.createEnergyEmitter(id, position, rotation);
            break;
        case TYPE_ENERGY_RECEIVER:
            object_creator.createEnergyReceiver(id, position, rotation);
            break;
        case TYPE_BUTTON:
            object_creator.createButton(id, position);
            break;
        case TYPE_PORTAL:
            object_creator.createPortal(id, position, rotation);
            break;
        case TYPE_END_BARRIER:
            object_creator.createEndBarrier(id, position, rotation);
            break;
        case TYPE_ROCK:
            object_creator.createRock(id, position, rotation);
            break;
        case TYPE_PLAYER:
            createPlayerWithCamera(id, position);
            break;
        case TYPE_ENERGY_BALL:
            object_creator.createEnergyBall(id, position, rotation);
            break;
        default:
            throw std::runtime_error("Error: EntityType inválido");
    }
}

void WorldView::createPlayerWithCamera(size_t id, const Position& position) {
    const Player& player = object_creator.createPlayer(id, position);
    screen.createCamera(settings.getLevelWidth(), settings.getLevelHeight(), player);
    main_player = new MainPlayer(player, screen.getCamera(), event_manager.getQueue(), screen.getHeight());
    event_manager.addHandler((KeyboardHandler*) main_player);
    event_manager.addHandler((MouseHandler*) main_player);
    settings.changeRatioCameraMode();
}
