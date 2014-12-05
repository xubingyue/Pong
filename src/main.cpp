#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "systems/MovementSystem.h"

#include "artemiscpp/World.h"
#include "artemiscpp/SystemManager.h"
#include "artemiscpp/EntityManager.h"
#include "artemiscpp/Entity.h"

int main()
{
    artemis::World world;
    artemis::SystemManager* sm = world.getSystemManager();
    MovementSystem& movementsys = (MovementSystem&)sm->setSystem(new MovementSystem());
    artemis::EntityManager* em = world.getEntityManager();

    sm->initializeAll();

    artemis::Entity& player = em->create();

    player.addComponent(new MovementComponent(2,4));
    player.addComponent(new PositionComponent(0,0));
    player.refresh();

    PositionComponent* comp = (PositionComponent*)player.getComponent<PositionComponent>();

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        world.loopStart();
        world.setDelta(0.016f);
        movementsys.process();

        std::cout << "X:"<< comp->posX << std::endl;
        std::cout << "Y:"<< comp->posY << std::endl;
        sf::sleep(sf::seconds(0.016f));

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
