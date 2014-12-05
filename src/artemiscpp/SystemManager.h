#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include <unordered_map>
#include "ImmutableBag.h"
#include <iostream>
#include <typeinfo>

namespace artemis {

	class EntitySystem;
	class Entity;
	class World;

	class SystemManager {
		public:
			SystemManager(World &world);
			~SystemManager();
			void initializeAll();
			Bag<EntitySystem*> & getSystems();
			EntitySystem& setSystem(EntitySystem * stm);

			template<typename eSystem>
			EntitySystem& getSystem() {
				return *(eSystem*)(systems[typeid(eSystem).hash_code()]);
			}

		private:
			World * world;
			std::unordered_map<size_t, EntitySystem*> systems;
			Bag<EntitySystem*> bagged;
	};
};
#endif // $(Guard token)
