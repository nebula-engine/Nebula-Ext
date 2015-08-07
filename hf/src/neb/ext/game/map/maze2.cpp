
//#include <neb/fnd/shape/Box.hh>
//#include <neb/fnd/actor/RigidStatic/local.hpp>

#include <neb/fnd/game/map/util/Parent.hpp>
#include <neb/fnd/core/actor/Base.hpp>
#include <neb/fnd/core/shape/HeightField/desc.hpp>

#include <neb/ext/maze/game/map/maze2.hpp>

#define D 3

typedef neb::fnd::game::map::Base		T0;
typedef neb::mod::hf::Base			T1;

extern "C" T0*	scene_create()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	return new T1;
}
extern "C" void	scene_destroy(T0* t)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	delete t;
}
T1::Base():
	init_hf_(false)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}
void		T1::setup()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	
	auto self = shared_from_this();

	auto scene = get_scene();

	// insert a spawn point at origin
	// ?

	// create heightfield

	if(!init_hf_)
	{
		auto actor = scene->createActorRigidStaticUninitialized().lock();
		actor->pose_.pos_ = glm::vec3(0,0,0);
		actor->init(scene.get());

		neb::fnd::core::shape::HeightField::desc d;
		d.w = 50.0;
		d.h = 50.0;
		d.r = 128;
		d.c = 128;
		d.hs = 10.0;
		d.fc.push_back(0.2);
		d.fc.push_back(0.2);
		
		actor->createShapeHeightField(d);

		// light
		scene->createActorLightPoint(glm::vec3(
					0.0 * d.w / 2.0,
					0.0,
					0.0 * d.h / 2.0));
/*		createActorLightPoint(glm::vec3(
					d.w / 2.0,
					8.0,
					d.h / 2.0));*/
/*		createActorLightPoint(glm::vec3(
					d.w / 2.0,
					-50.0,
					d.h / 2.0));
*/
		init_hf_ = true;
	}
}
void		T1::Base::release()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	neb::fnd::game::map::Base::release();
}
void		T1::Base::step(gal::etc::timestep const & ts)
{
	//std::cout << __PRETTY_FUNCTION__ << std::endl;

	//neb::game::map::base::step(ts);
}



