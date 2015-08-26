#ifndef NEB_MOD_MAZE_HPP
#define NEB_MOD_MAZE_HPP

#include <neb/fnd0/game/map/base.hpp>

namespace neb { namespace mod { namespace maze {
	/** @brief Base
	 */
	class Base:
		virtual public gal::enable_shared_from_this<neb::mod::maze::Base>,
		virtual public neb::fnd0::game::map::Base
	{
		public:
			using gal::enable_shared_from_this<neb::mod::maze::Base>::shared_from_this;

			Base();
			virtual ~Base();
			virtual void		setup();
			virtual void		release();
			glm::ivec3		size_;
	};
}}}

#endif
