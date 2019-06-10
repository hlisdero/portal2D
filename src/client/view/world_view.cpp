#include "client/view/world_view.h"

WorldView::WorldView(float world_width, float world_height, BlockingQueue<ViewEvent>& queue) :
    event_manager(queue),
    screen(1024, 768),
    settings(screen.getWidth(), screen.getHeight(), world_width, world_height, screen.getTextureCreator()),
    background(settings.getScreenWidth(), settings.getScreenHeight(), settings.getTextureLoader()["Background"]),
    object_creator(view_objects, settings) {
    event_manager.addHandler((KeyboardHandler*) &sound_manager);
    event_manager.addHandler((MouseHandler*) &sound_manager);
    event_manager.addHandler((WindowEventHandler*) &screen);
    event_manager.addHandler((KeyboardHandler*) &screen);
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

void WorldView::createEntity(size_t index, EntityType type, const Position& position) {
    switch (type) {
        case TYPE_STONE_BLOCK:
            object_creator.createStoneBlock(index, position);
            break;
        case TYPE_METAL_BLOCK:
            object_creator.createMetalBlock(index, position);
            break;
        case TYPE_METAL_DIAG_BLOCK:
            object_creator.createDiagonalMetalBlock(index, position);
            break;
        case TYPE_ACID:
            object_creator.createAcid(index, position);
            break;
        case TYPE_GATE:
            object_creator.createGate(index, position);
            break;
        case TYPE_ENERGY_BAR:
            object_creator.createEnergyBar(index, position);
            break;
        case TYPE_ENERGY_EMITTER:
            object_creator.createEnergyEmitter(index, position);
            break;
        case TYPE_ENERGY_RECEIVER:
            object_creator.createEnergyReceiver(index, position);
            break;
        case TYPE_BUTTON:
            object_creator.createButton(index, position);
            break;
        case TYPE_PORTAL:
            object_creator.createPortal(index, position);
            break;
        case TYPE_END_BARRIER:
            object_creator.createEndBarrier(index, position);
            break;
        case TYPE_ROCK:
            object_creator.createRock(index, position);
            break;
        case TYPE_PLAYER:
            object_creator.createPlayer(index, position);
            break;
        case TYPE_ENERGY_BALL:
            object_creator.createEnergyBall(index, position);
            break;
        default:
            throw std::runtime_error("Error: EntityType inválido");
    }
}

void WorldView::destroyEntity(size_t index) {
    delete view_objects.at(index);
    view_objects.erase(index);

    // TODO Main player delete => camera delete
}

void WorldView::updatePosition(size_t index, const Position& position) {
    view_objects.at(index)->updatePosition(position);
}

void WorldView::updateState(size_t index, const State& state) {
    view_objects.at(index)->updateState(state);
}

void WorldView::selectPlayer(size_t index) {
    Player* player = static_cast<Player*>(view_objects.at(index));
    screen.createCamera(settings.getLevelWidth(), settings.getLevelHeight(), *player);
    main_player = new MainPlayer(index, *player, screen.getCamera(), event_manager.getQueue());
    event_manager.addHandler((KeyboardHandler*) main_player);
    event_manager.addHandler((MouseHandler*) main_player);
    settings.changeRatioCameraMode();
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
