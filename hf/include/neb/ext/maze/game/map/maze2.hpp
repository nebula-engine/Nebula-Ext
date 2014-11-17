#ifndef NEBULA_EXT_MAZE_GAME_MAP_MAZE2_HPP
#define NEBULA_EXT_MAZE_GAME_MAP_MAZE2_HPP

#include <neb/core/game/map/base.hpp>

#include <neb/fin/core/scene/base.hpp>

namespace neb { namespace ext { namespace maze { namespace game { namespace map {
	/** @brief maze
	 *
	 */
	class base:
		virtual public nc::game::map::base,
		virtual public neb::fin::core::scene::base
	{
		public:
			base();
			virtual ~base() {}
			virtual void		init(parent_t * const & p);
			virtual void		release();
			virtual void		step(gal::etc::timestep const &);
		private:
			bool			init_hf_;
	};
}}}}}

#endif

