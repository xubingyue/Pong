#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "systems/CollisionSystem.h"
#include "systems/MovementSystem.h"

#include "artemiscpp/World.h"
#include "artemiscpp/SystemManager.h"
#include "artemiscpp/EntityManager.h"
#include "artemiscpp/Entity.h"

int main()
{
    artemis::World world;

    // Get video mode
    const std::vector<sf::VideoMode>& availableVideoModes = sf::VideoMode::getFullscreenModes();
    if (availableVideoModes.empty()) {
        return EXIT_FAILURE;
    }
    sf::VideoMode videoMode = availableVideoModes[0];
    std::cout << "Using VideoMode = " << videoMode.width << "x" << videoMode.height << std::endl;

    // Initialize systems
    artemis::SystemManager* systemManager = world.getSystemManager();
    MovementSystem& movementSystem = (MovementSystem&)systemManager->setSystem(new MovementSystem());
    CollisionSystem& collisionSystem = (CollisionSystem&)systemManager->setSystem(new CollisionSystem(videoMode));
    systemManager->initializeAll();
    std::cout << "Systems initialized" << std::endl;

    // Create ball
    artemis::EntityManager* entityManager = world.getEntityManager();
    artemis::Entity& ball = entityManager->create();
    ball.addComponent(new MovementComponent(400, 300));
    ball.addComponent(new PositionComponent(videoMode.width / 2, videoMode.height / 2));
    ball.refresh();

    // Create a shape for the ball
    sf::CircleShape ballShape(100.0f);
    ballShape.setFillColor(sf::Color::White);

    // Create window
    sf::RenderWindow window(videoMode, "SFML works!", sf::Style::Fullscreen);
    window.setVerticalSyncEnabled(true);

    while (window.isOpen()) {
        // Process input
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        world.loopStart();
        // TODO: Need to obtain actual time delta
        world.setDelta(0.016f);

        // Process game logic
//        std::cout << "About to process game logic" << std::endl;
        collisionSystem.process();
//        std::cout << "CollisionSystem processed" << std::endl;
        movementSystem.process();
//        std::cout << "Systems processed" << std::endl;

        PositionComponent* ballPosition = (PositionComponent*)ball.getComponent<PositionComponent>();
        ballShape.setPosition(ballPosition->posX - 50, ballPosition->posY - 50);

        // TODO: Need to properly fix timestep
        sf::sleep(sf::seconds(0.016f));

        // Render
        // TODO: Make a RenderSystem
        window.clear();
        window.draw(ballShape);
        window.display();
//        std::cout << "Rendering complete" << std::endl;
    }

    return EXIT_SUCCESS;
}
