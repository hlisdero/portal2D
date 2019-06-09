#include "server/events/game_event_creator.h"

GameEventCreator::GameEventCreator(SafeQueue<GameEvent>& queue) : queue(queue) {}