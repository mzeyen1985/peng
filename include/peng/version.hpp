#pragma once

#include <cstdint>
#include <initializer_list>

#include <peng/config.hpp>




namespace maze
{
    namespace peng
    {


        class PENG_EXPORT version
        {
        public:
            version();
            explicit version(std::uint64_t major);
            version(std::uint64_t major, std::uint64_t minor);
            version(std::initializer_list<std::uint64_t> list);

            std::uint64_t major() const;
            std::uint64_t minor() const;

            bool operator==(const version &other) const;
            bool operator!=(const version &other) const;
            bool operator<(const version &other) const;
            bool operator>(const version &other) const;
            bool operator<=(const version &other) const;
            bool operator>=(const version &other) const;
        private:
            std::uint64_t major_m;
            std::uint64_t minor_m;
        };


    }
}