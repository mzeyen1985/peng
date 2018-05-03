#include <peng/version.hpp>




namespace maze
{
    namespace peng
    {


        version::version()
            : major_m(0),
            minor_m(0)
        {
        }


        version::version(std::uint64_t major)
            : major_m(major)
        {
        }


        version::version(std::uint64_t major, std::uint64_t minor)
            : major_m(major),
            minor_m(minor)
        {
        }


        version::version(std::initializer_list<std::uint64_t> list)
        {
            if(list.size() == 1)
            {
                this->major_m = *list.begin();
            }

            if(list.size() > 1)
            {
                this->major_m = *list.begin();
                this->minor_m = *(list.begin() + 1);
            }
        }


        std::uint64_t version::major() const
        {
            return this->major_m;
        }


        std::uint64_t version::minor() const
        {
            return this->minor_m;
        }


        bool version::operator==(const version &other) const
        {
            bool comp_major = this->major_m == other.major_m;
            bool comp_minor = this->minor_m == other.minor_m;
            return comp_major && comp_minor;
        }


        bool version::operator!=(const version &other) const
        {
            bool comp_major = this->major_m != other.major_m;
            bool comp_minor = this->minor_m != other.minor_m;
            return comp_major && comp_minor;
        }


        bool version::operator<(const version &other) const
        {
            if(this->major_m < other.major_m)
            {
                return true;
            }

            if(this->minor_m < other.minor_m)
            {
                return true;
            }

            return false;
        }


        bool version::operator>(const version &other) const
        {
            if(this->major_m > other.major_m)
            {
                return true;
            }

            if(this->minor_m > other.minor_m)
            {
                return true;
            }

            return false;
        }


        bool version::operator<=(const version &other) const
        {
            if(this->major_m <= other.major_m)
            {
                return true;
            }

            if(this->minor_m <= other.minor_m)
            {
                return true;
            }

            return false;
        }


        bool version::operator>=(const version &other) const
        {
            if(this->major_m >= other.major_m)
            {
                return true;
            }

            if(this->minor_m >= other.minor_m)
            {
                return true;
            }

            return false;
        }


    }
}