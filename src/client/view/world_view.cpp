#include "client/view/world_view.h"

WorldView::WorldView(float world_width, float world_height, BlockingQueue<ViewEvent>& queue) :
    event_manager(queue),
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

bool WorldView::quit() const {
    return event_manager.quit();
}

const ViewObjectCreator& WorldView::getObjectCreator() const {
    return object_creator;
}

void WorldView::createEntity(size_t id, EntityType type, const Position& position) {
    switch (type) {
        case TYPE_STONE_BLOCK:
            object_creator.createStoneBlock(id, position);
            break;
        case TYPE_METAL_BLOCK:
            object_creator.createMetalBlock(id, position);
            break;
        case TYPE_METAL_DIAG_BLOCK:
            object_creator.createDiagonalMetalBlock(id, position);
            break;
        case TYPE_ACID:
            object_creator.createAcid(id, position);
            break;
        case TYPE_GATE:
            object_creator.createGate(id, position);
            break;
        case TYPE_ENERGY_BAR:
            object_creator.createEnergyBar(id, position);
            break;
        case TYPE_ENERGY_EMITTER:
            object_creator.createEnergyEmitter(id, position);
            break;
        case TYPE_ENERGY_RECEIVER:
            object_creator.createEnergyReceiver(id, position);
            break;
        case TYPE_BUTTON:
            object_creator.createButton(id, position);
            break;
        case TYPE_PORTAL:
            object_creator.createPortal(id, position);
            break;
        case TYPE_END_BARRIER:
            object_creator.createEndBarrier(id, position);
            break;
        case TYPE_ROCK:
            object_creator.createRock(id, position);
            break;
        case TYPE_PLAYER:
            createPlayerWithCamera(id, position);
            break;
        case TYPE_ENERGY_BALL:
            object_creator.createEnergyBall(id, position);
            break;
        default:
            throw std::runtime_error("Error: EntityType inválido");
    }
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
        screen.render(*object.second);
    }
}

void WorldView::checkValidIndex(size_t index) {
    if (view_objects[index] == nullptr) {
        throw std::runtime_error("Error: Índice de objeto en la vista inválido");
    }
}

void WorldView::createPlayerWithCamera(size_t id, const Position& position) {
    const Player& player = object_creator.createPlayer(id, position);
    screen.createCamera(settings.getLevelWidth(), settings.getLevelHeight(), player);
    main_player = new MainPlayer(player, screen.getCamera(), event_manager.getQueue());
    event_manager.addHandler((KeyboardHandler*) main_player);
    event_manager.addHandler((MouseHandler*) main_player);
    settings.changeRatioCameraMode();
}
