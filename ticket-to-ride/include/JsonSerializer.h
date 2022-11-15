#ifndef JsonSerializer_H
#define JsonSerializer_H

#include "./nlohmann/json.hpp"

namespace nlohmann
{
template <typename T>
struct adl_serializer<std::shared_ptr<T>>
{
    static void to_json(json& j, const std::shared_ptr<T>& opt)
    {
        if (opt)
        {
            j = *opt;
        }
        else
        {
            j = nullptr;
        }
    }

    static void from_json(const json& j, std::shared_ptr<T>& opt)
    {
        if (j.is_null())
        {
            opt = nullptr;
        }
        else
        {
            opt.reset(new T(j.get<T>()));
        }
    }
};
}

#endif