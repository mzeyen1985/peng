#include <peng/factory_base.hpp>




namespace maze
{
    namespace peng
    {


        bool factory_base::is_compatible(const factory_base *factory) const
        {
            // compare plugin types
            if(this->plugin_type() != factory->plugin_type())
            {
                return false;
            }

            // check this plugin factory's version requirements against the given factory
            bool lower_version_bound = this->minimum_version() <= factory->current_version();
            bool upper_version_bound = factory->current_version() <= this->current_version();
            return lower_version_bound && upper_version_bound;
        }


    }
}