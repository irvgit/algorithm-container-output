#pragma once

#if __cplusplus < 202302L
    #error out of date c++ version, compile with -stdc++=2c
#elif defined(__clang__) && __clang_major__ < 19
    #error out of date clang, compile with latest version
#elif !defined(__clang__) && defined(__GNUC__) && __GNUC__ < 14
    #error out of date g++, compile with latest version
#elif defined(_MSC_VER) && _MSC_VER < 19
    #error out of date msvc, compile with latest version
#else

#include <concepts>
#include <iterator>
#include <ranges>
#include <utility>

namespace aco {
    namespace detail {
        template <
            typename tp_container_t,
            typename tp_value_t
        >
        concept non_adl_emplacable_container = requires (
            tp_container_t&& p_container,
            tp_value_t&&     p_value
        ) {
            std::forward<tp_container_t>(p_container).emplace(
                std::ranges::begin(p_container),
                std::forward<tp_value_t>(p_value)
            );
            std::forward<tp_container_t>(p_container).emplace(
                std::ranges::end(p_container),
                std::forward<tp_value_t>(p_value)
            );
        };

        template <
            typename tp_container_t,
            typename tp_value_t
        >
        concept adl_emplacable_container =
            std::ranges::range<tp_container_t> &&
            requires (
                tp_container_t&& p_container,
                tp_value_t&&     p_value
            ) {
                emplace(
                    std::forward<tp_container_t>(p_container),
                    std::ranges::begin(p_container),
                    std::forward<tp_value_t>(p_value)
                );
                emplace(
                    std::forward<tp_container_t>(p_container),
                    std::ranges::end(p_container),
                    std::forward<tp_value_t>(p_value)
                );
            };

        template <
            typename tp_container_t,
            typename tp_value_t
        >
        concept non_adl_emplace_afterable_container =
            std::ranges::range<tp_container_t> &&
            requires (
                tp_container_t&& p_container,
                tp_value_t&&     p_value
            ) {
                std::forward<tp_container_t>(p_container).emplace_after(
                    std::ranges::begin(p_container),
                    std::forward<tp_value_t>(p_value)
                );
                std::forward<tp_container_t>(p_container).emplace_after(
                    std::ranges::end(p_container),
                    std::forward<tp_value_t>(p_value)
                );
            };

        template <
            typename tp_container_t,
            typename tp_value_t
        >
        concept adl_emplace_afterable_container =
            std::ranges::range<tp_container_t> &&
            requires (
                tp_container_t&& p_container,
                tp_value_t&&     p_value
            ) {
                emplace_after(
                    std::forward<tp_container_t>(p_container),
                    std::ranges::begin(p_container),
                    std::forward<tp_value_t>(p_value)
                );
                emplace_after(
                    std::forward<tp_container_t>(p_container),
                    std::ranges::end(p_container),
                    std::forward<tp_value_t>(p_value)
                );
            };

        template <
            typename tp_container_t,
            typename tp_value_t
        >
        concept non_adl_emplace_frontable_container =
            std::ranges::range<tp_container_t> &&
            requires (
                tp_container_t&& p_container,
                tp_value_t&&     p_value
            ) {
                std::forward<tp_container_t>(p_container).emplace_front(std::forward<tp_value_t>(p_value));
            };

        template <
            typename tp_container_t,
            typename tp_value_t
        >
        concept adl_emplace_frontable_container =
            std::ranges::range<tp_container_t> &&
            requires (
                tp_container_t&& p_container,
                tp_value_t&&     p_value
            ) {
                emplace_front(
                    std::forward<tp_container_t>(p_container),
                    std::forward<tp_value_t>(p_value)
                );
            };

        template <
            typename tp_container_t,
            typename tp_value_t
        >
        concept non_adl_insertable_container =
            std::ranges::range<tp_container_t> &&
            requires (
                tp_container_t&& p_container,
                tp_value_t&&     p_value
            ) {
                std::forward<tp_container_t>(p_container).insert(
                    std::ranges::begin(p_container),
                    std::forward<tp_value_t>(p_value)
                );
                std::forward<tp_container_t>(p_container).insert(
                    std::ranges::end(p_container),
                    std::forward<tp_value_t>(p_value)
                );
            };

        template <
            typename tp_container_t,
            typename tp_value_t
        >
        concept adl_insertable_container =
            std::ranges::range<tp_container_t> &&
            requires (
                tp_container_t&& p_container,
                tp_value_t&&     p_value
            ) {
                insert(
                    std::forward<tp_container_t>(p_container),
                    std::ranges::begin(p_container),
                    std::forward<tp_value_t>(p_value)
                );
                insert(
                    std::forward<tp_container_t>(p_container),
                    std::ranges::end(p_container),
                    std::forward<tp_value_t>(p_value)
                );
            };

        template <
            typename tp_container_t,
            typename tp_value_t
        >
        concept non_adl_insert_afterable_container =
            std::ranges::range<tp_container_t> &&
            requires (
                tp_container_t&& p_container,
                tp_value_t&&     p_value
            ) {
                std::forward<tp_container_t>(p_container).insert_after(
                    std::ranges::begin(p_container),
                    std::forward<tp_value_t>(p_value)
                );
                std::forward<tp_container_t>(p_container).insert_after(
                    std::ranges::end(p_container),
                    std::forward<tp_value_t>(p_value)
                );
            };

        template <
            typename tp_container_t,
            typename tp_value_t
        >
        concept adl_insert_afterable_container =
            std::ranges::range<tp_container_t> &&
            requires (
                tp_container_t&& p_container,
                tp_value_t&&     p_value
            ) {
                insert_after(
                    std::forward<tp_container_t>(p_container),
                    std::ranges::begin(p_container),
                    std::forward<tp_value_t>(p_value)
                );
                insert_after(
                    std::forward<tp_container_t>(p_container),
                    std::ranges::end(p_container),
                    std::forward<tp_value_t>(p_value)
                );
            };

        template <
            typename tp_container_t,
            typename tp_value_t
        >
        concept non_adl_insert_frontable_container =
            std::ranges::range<tp_container_t> &&
            requires (
                tp_container_t&& p_container,
                tp_value_t&&     p_value
            ) {
                std::forward<tp_container_t>(p_container).insert_front(std::forward<tp_value_t>(p_value));
            };

        template <
            typename tp_container_t,
            typename tp_value_t
        >
        concept adl_insert_frontable_container =
            std::ranges::range<tp_container_t> &&
            requires (
                tp_container_t&& p_container,
                tp_value_t&&     p_value
            ) {
                insert_front(
                    std::forward<tp_container_t>(p_container),
                    std::forward<tp_value_t>(p_value)
                );
            };

        template <typename tp_container_t>
        concept non_adl_erasable_container =
            std::ranges::range<tp_container_t> &&
            requires (tp_container_t&& p_container) {
                std::forward<tp_container_t>(p_container).erase(std::ranges::begin(p_container));
                std::forward<tp_container_t>(p_container).erase(std::ranges::end(p_container));
            };

        template <typename tp_container_t>
        concept adl_erasable_container =
            std::ranges::range<tp_container_t> &&
            requires (tp_container_t&& p_container) {
                erase(
                    std::forward<tp_container_t>(p_container),
                    std::ranges::begin(p_container)
                );
                erase(
                    std::forward<tp_container_t>(p_container),
                    std::ranges::end(p_container)
                );
            };

        template <
            typename tp_container_t,
            typename tp_range_t
        >
        concept non_adl_range_insertable_container =
            std::ranges::range<tp_container_t> &&
            requires (
                tp_container_t&& p_container,
                tp_range_t&&     p_range
            ) {
                std::forward<tp_container_t>(p_container).insert_range(
                    std::ranges::begin(p_container),
                    std::forward<tp_range_t>(p_range)
                );
            };
        
        template <
            typename tp_container_t,
            typename tp_range_t
        >
        concept adl_range_insertable_container =
            std::ranges::range<tp_container_t> &&
            requires (
                tp_container_t&& p_container,
                tp_range_t&&     p_range
            ) {
                insert_range(
                    std::forward<tp_container_t>(p_container),
                    std::ranges::end(p_container),
                    std::forward<tp_range_t>(p_range)
                );
            };

        template <
            typename tp_container_t,
            typename tp_input_iterator_t,
            typename tp_sentinel_iterator_t
        >
        concept non_adl_iterator_pair_insertable_container =
            std::ranges::range<tp_container_t> &&
            requires (
                tp_container_t&&         p_container,
                tp_input_iterator_t&&    p_first,
                tp_sentinel_iterator_t&& p_last
            ) {
                std::forward<tp_container_t>(p_container).insert_range(
                    std::ranges::begin(p_container),
                    std::forward<tp_input_iterator_t>(p_first),
                    std::forward<tp_sentinel_iterator_t>(p_last)
                );
                std::forward<tp_container_t>(p_container).insert_range(
                    std::ranges::end(p_container),
                    std::forward<tp_input_iterator_t>(p_first),
                    std::forward<tp_sentinel_iterator_t>(p_last)
                );
            };
        
        template <
            typename tp_container_t,
            typename tp_input_iterator_t,
            typename tp_sentinel_iterator_t
        >
        concept adl_iterator_pair_insertable_container =
            std::ranges::range<tp_container_t> &&
            requires (
                tp_container_t&&         p_container,
                tp_input_iterator_t&&    p_first,
                tp_sentinel_iterator_t&& p_last
            ) {
                insert(
                    std::forward<tp_container_t>(p_container),
                    std::ranges::begin(p_container),
                    std::forward<tp_input_iterator_t>(p_first),
                    std::forward<tp_sentinel_iterator_t>(p_last)
                );
                insert(
                    std::forward<tp_container_t>(p_container),
                    std::ranges::end(p_container),
                    std::forward<tp_input_iterator_t>(p_first),
                    std::forward<tp_sentinel_iterator_t>(p_last)
                );
            };
        
        template <typename tp_container_t>
        concept non_adl_reservable_container =
            std::ranges::range<tp_container_t> &&
            requires (
                tp_container_t&                           p_container,
                std::ranges::range_size_t<tp_container_t> p_size
            ) {
                std::forward<tp_container_t>(p_container).reserve(p_size);
            };

        template <typename tp_container_t>
        concept adl_reservable_container =
            std::ranges::range<tp_container_t> &&
            requires (
                tp_container_t&&                          p_container,
                std::ranges::range_size_t<tp_container_t> p_size
            ) {
                reserve(std::forward<tp_container_t>(p_container), p_size);
            };

        template <typename tp_container_t>
        concept non_adl_capacityable_container =
            std::ranges::range<tp_container_t> &&
            requires (tp_container_t&& p_container) {
                { std::forward<tp_container_t>(p_container).capacity() } -> std::same_as<std::ranges::range_size_t<tp_container_t>>;
            };

        template <typename tp_container_t>
        concept adl_capacityable_container =
            std::ranges::range<tp_container_t> &&
            requires (tp_container_t&& p_container) {
                { capacity(std::forward<tp_container_t>(p_container)) } -> std::same_as<std::ranges::range_size_t<tp_container_t>>;
            };

        template <typename tp_container_t>
        concept non_adl_max_sizeable_container =
            std::ranges::range<tp_container_t> &&
            requires (tp_container_t&& p_container) {
                { std::forward<tp_container_t>(p_container).maxsize() } -> std::same_as<std::ranges::range_size_t<tp_container_t>>;
            };

        template <typename tp_container_t>
        concept adl_max_sizeable_container =
            std::ranges::range<tp_container_t> &&
            requires (tp_container_t&& p_container) {
                { maxsize(std::forward<tp_container_t>(p_container)) } -> std::same_as<std::ranges::range_size_t<tp_container_t>>;
            };
    }
    template <typename tp_container_t>
    concept reservable_container =
        detail::non_adl_reservable_container<tp_container_t> ||
        detail::adl_reservable_container<tp_container_t>;
        
    namespace detail {
        struct reserve_fn {
            template <reservable_container tp_container_t>
            auto constexpr operator() (
                tp_container_t&&                          p_container,
                std::ranges::range_size_t<tp_container_t> p_size
            )
            const
            -> decltype(auto) {
                if constexpr (non_adl_reservable_container<tp_container_t>)
                    return std::forward<tp_container_t>(p_container).reserve(p_size);
                else return reserve(std::forward<tp_container_t>(p_container), p_size);
            }
        };
    }
    auto constexpr reserve = detail::reserve_fn{};

    template <typename tp_container_t>
    concept capacityable_container =
        detail::non_adl_capacityable_container<tp_container_t> ||
        detail::adl_capacityable_container<tp_container_t>;

    namespace detail {
        struct capacity_fn {
            template <capacityable_container tp_container_t>
            auto constexpr operator() (tp_container_t&& p_container)
            const
            -> decltype(auto) {
                if constexpr (non_adl_capacityable_container<tp_container_t>)
                    return std::forward<tp_container_t>(p_container).capacity();
                else return capacity(std::forward<tp_container_t>(p_container));
            }
        };
    }
    auto constexpr capacity = detail::capacity_fn{};

    template <typename tp_container_t>
    concept max_sizeable_container =
        detail::non_adl_max_sizeable_container<tp_container_t> ||
        detail::adl_max_sizeable_container<tp_container_t>;

    namespace detail {
        struct max_size_fn {
            template <max_sizeable_container tp_container_t>
            auto constexpr operator() (tp_container_t&& p_container)
            const
            -> decltype(auto) {
                if constexpr (non_adl_max_sizeable_container<tp_container_t>)
                    return std::forward<tp_container_t>(p_container).max_size();
                else return max_size(std::forward<tp_container_t>(p_container));
            }
        };
    }
    auto constexpr max_size = detail::max_size_fn{};


    template <
        typename tp_container_t,
        typename tp_value_t
    >
    concept emplacable_container =
        detail::non_adl_emplacable_container<
            tp_container_t,
            tp_value_t
        > ||
        detail::adl_emplacable_container<
            tp_container_t,
            tp_value_t
        >;

    namespace detail {
        struct emplace_fn {
            template <
                typename                         tp_value_t,
                emplacable_container<tp_value_t> tp_container_t
            >
            auto constexpr operator() (
                tp_container_t&&                              p_container,
                std::ranges::const_iterator_t<tp_container_t> p_position,
                tp_value_t&&                                  p_value
            )
            const
            -> decltype(auto) {
                if constexpr (non_adl_emplacable_container<
                    tp_container_t,
                    tp_value_t
                >) {
                    return std::forward<tp_container_t>(p_container).emplace(
                        p_position,
                        std::forward<tp_value_t>(p_value)
                    );
                }
                else {
                    return emplace(
                        std::forward<tp_container_t>(p_container),
                        p_position,
                        std::forward<tp_value_t>(p_value)
                    );    
                }
            }
        };
    }
    auto constexpr emplace = detail::emplace_fn{};

    template <
        typename tp_container_t,
        typename tp_value_t
    >
    concept emplace_afterable_container =
        detail::non_adl_emplace_afterable_container<
            tp_container_t,
            tp_value_t
        > ||
        detail::adl_emplace_afterable_container<
            tp_container_t,
            tp_value_t
        >;
    
    namespace detail {
        struct emplace_after_fn {
            template <
                typename                                tp_value_t,
                emplace_afterable_container<tp_value_t> tp_container_t
            >
            auto constexpr operator() (
                tp_container_t&&                              p_container,
                std::ranges::const_iterator_t<tp_container_t> p_position,
                tp_value_t&&                                  p_value
            )
            const
            -> decltype(auto) {
                if constexpr (non_adl_emplace_afterable_container<
                    tp_container_t,
                    tp_value_t
                >) {
                    return std::forward<tp_container_t>(p_container).emplace_after(
                        p_position,
                        std::forward<tp_value_t>(p_value)
                    );
                }
                else {
                    return emplace_after(
                        std::forward<tp_container_t>(p_container),
                        p_position,
                        std::forward<tp_value_t>(p_value)
                    );    
                }
            }
        };
    }
    auto constexpr emplace_after = detail::emplace_after_fn{};

    template <
        typename tp_container_t,
        typename tp_value_t
    >
    concept emplace_frontable_container =
        detail::non_adl_emplace_frontable_container<
            tp_container_t,
            tp_value_t
        > ||
        detail::adl_emplace_frontable_container<
            tp_container_t,
            tp_value_t
        >;
    
    namespace detail {
        struct emplace_front_fn {
            template <
                typename                                tp_value_t,
                emplace_frontable_container<tp_value_t> tp_container_t
            >
            requires (
                non_adl_emplace_frontable_container<
                    tp_container_t,
                    tp_value_t
                >
            )
            auto constexpr operator() (
                tp_container_t&& p_container,
                tp_value_t&&     p_value
            )
            const
            -> decltype(auto) {
                if constexpr (non_adl_emplace_frontable_container<
                    tp_container_t,
                    tp_value_t
                >) {
                    return std::forward<tp_container_t>(p_container).emplace_front(std::forward<tp_value_t>(p_value));
                }
                else {
                    return emplace_front(
                        std::forward<tp_container_t>(p_container),
                        std::forward<tp_value_t>(p_value)
                    );    
                }
            }
        };
    }
    auto constexpr emplace_front = detail::emplace_front_fn{};

    template <
        typename tp_container_t,
        typename tp_value_t
    >
    concept insertable_container =
        detail::non_adl_insertable_container<
            tp_container_t,
            tp_value_t
        > ||
        detail::adl_insertable_container<
            tp_container_t,
            tp_value_t
        >;

    template <
        typename tp_container_t,
        typename tp_iterator_t,
        typename tp_sentinel_t
    >
    concept iterator_pair_insertable_container = 
        detail::non_adl_iterator_pair_insertable_container<
            tp_container_t,
            tp_iterator_t,
            tp_sentinel_t
        > ||
        detail::adl_iterator_pair_insertable_container<
            tp_container_t,
            tp_iterator_t,
            tp_sentinel_t
        >;

    namespace detail {
        struct insert_fn {
            template <
                typename                         tp_value_t,
                insertable_container<tp_value_t> tp_container_t
            >
            auto constexpr operator() (
                tp_container_t&&                              p_container,
                std::ranges::const_iterator_t<tp_container_t> p_position,
                tp_value_t&&                                  p_value
            )
            const
            -> decltype(auto) {
                if constexpr (non_adl_insertable_container<
                    tp_container_t,
                    tp_value_t
                >) {
                    return std::forward<tp_container_t>(p_container).insert(
                        p_position,
                        std::forward<tp_value_t>(p_value)
                    );
                }
                else {
                    return insert(
                        std::forward<tp_container_t>(p_container),
                        p_position,
                        std::forward<tp_value_t>(p_value)
                    );    
                }
            }
            template <
                std::input_iterator                     tp_input_iterator_t,
                std::sentinel_for<tp_input_iterator_t>  tp_sentinel_iterator_t,
                iterator_pair_insertable_container<
                    tp_input_iterator_t,
                    tp_sentinel_iterator_t
                >                                       tp_container_t
            >
            auto constexpr operator() (
                tp_container_t&&                              p_container,
                std::ranges::const_iterator_t<tp_container_t> p_position,
                tp_input_iterator_t                           p_first,
                tp_sentinel_iterator_t                        p_last
            )
            const
            -> void {
                if constexpr (non_adl_iterator_pair_insertable_container<
                    tp_container_t,
                    tp_input_iterator_t,
                    tp_sentinel_iterator_t
                >) {
                    std::forward<tp_container_t>(p_container).insert(
                        p_position,
                        p_first,
                        p_last
                    );
                }
                else {
                    insert(
                        std::forward<tp_container_t>(p_container),
                        p_position,
                        p_first,
                        p_last
                    );    
                }
            }
        };
    }
    auto constexpr insert = detail::insert_fn{};

    template <
        typename tp_container_t,
        typename tp_value_t
    >
    concept insert_afterable_container =
        detail::non_adl_insert_afterable_container<
            tp_container_t,
            tp_value_t
        > ||
        detail::adl_insert_afterable_container<
            tp_container_t,
            tp_value_t
        >;

    namespace detail {
        struct insert_after_fn {
            template <
                typename                               tp_value_t,
                insert_afterable_container<tp_value_t> tp_container_t
            >
            auto constexpr operator() (
                tp_container_t&&                              p_container,
                std::ranges::const_iterator_t<tp_container_t> p_position,
                tp_value_t&&                                  p_value
            )
            const
            -> decltype(auto) {
                if constexpr (non_adl_insert_afterable_container<
                    tp_container_t,
                    tp_value_t
                >) {
                    return std::forward<tp_container_t>(p_container).insert_after(
                        p_position,
                        std::forward<tp_value_t>(p_value)
                    );
                }
                else {
                    return insert_after(
                        std::forward<tp_container_t>(p_container),
                        p_position,
                        std::forward<tp_value_t>(p_value)
                    );
                }
            }
        };
    }
    auto constexpr insert_after = detail::insert_after_fn{};

    template <
        typename tp_container_t,
        typename tp_value_t
    >
    concept insert_frontable_container =
        detail::non_adl_insert_frontable_container<
            tp_container_t,
            tp_value_t
        > || 
        detail::adl_insert_frontable_container<
            tp_container_t,
            tp_value_t
        >;

    namespace detail {
        struct insert_front_fn {
            template <
                typename                               tp_value_t,
                insert_frontable_container<tp_value_t> tp_container_t
            >
            auto constexpr operator() (
                tp_container_t&& p_container,
                tp_value_t&&     p_value
            )
            const
            -> decltype(auto) {
                if constexpr (non_adl_insert_frontable_container<
                    tp_container_t,
                    tp_value_t
                >)
                    return std::forward<tp_container_t>(p_container).insert_front(std::forward<tp_value_t>(p_value));
                else {
                    return insert_front(
                        std::forward<tp_container_t>(p_container),
                        std::forward<tp_value_t>(p_value)
                    );    
                }
            }
        };
    }
    auto constexpr insert_front = detail::insert_front_fn{};

    template <
        typename tp_container_t,
        typename tp_value_t
    >
    concept emplacable_or_insertable_container = requires (
        tp_container_t&& p_container,
        tp_value_t&&     p_value
    ) {
        requires (
            requires {
                emplace(
                    std::forward<tp_container_t>(p_container),
                    std::ranges::begin(p_container),
                    std::forward<tp_value_t>(p_value)
                );
            } ||
            requires {
                insert(
                    std::forward<tp_container_t>(p_container),
                    std::ranges::begin(p_container),
                    std::forward<tp_value_t>(p_value)
                );
            }
        );
    };

    namespace detail {
        struct emplace_or_insert_fn {
            template <
                typename                                       tp_value_t,
                emplacable_or_insertable_container<tp_value_t> tp_container_t
            >
            auto constexpr operator() (
                tp_container_t&&                              p_container,
                std::ranges::const_iterator_t<tp_container_t> p_position,
                tp_value_t&&                                  p_value
            )
            const
            -> decltype(auto) {
                if constexpr (emplacable_container<
                    tp_container_t,
                    tp_value_t
                >)
                    return emplace(
                        std::forward<tp_container_t>(p_container),
                        p_position,
                        std::forward<tp_value_t>(p_value)
                    );
                else return insert(
                    std::forward<tp_container_t>(p_container),
                    p_position,
                    std::forward<tp_value_t>(p_value)
                );
            }
        };
    }
    auto constexpr emplace_or_insert = detail::emplace_or_insert_fn{};

    template <
        typename tp_container_t,
        typename tp_value_t
    >
    concept emplace_afterable_or_insert_afterable_container = requires (
        tp_container_t&& p_container,
        tp_value_t&&     p_value
    ) {
        requires (
            requires {
                emplace_after(
                    std::forward<tp_container_t>(p_container),
                    std::ranges::begin(p_container),
                    std::forward<tp_value_t>(p_value)
                );
            } ||
            requires {
                insert_after(
                    std::forward<tp_container_t>(p_container),
                    std::ranges::begin(p_container),
                    std::forward<tp_value_t>(p_value)
                );
            }
        );
    };

    namespace detail {
        struct emplace_after_or_insert_after_fn {
            template <
                typename                                                    tp_value_t,
                emplace_afterable_or_insert_afterable_container<tp_value_t> tp_container_t
            >
            auto constexpr operator() (
                tp_container_t&&                              p_container,
                std::ranges::const_iterator_t<tp_container_t> p_position,
                tp_value_t&&                                  p_value
            )
            const
            -> decltype(auto) {
                if constexpr (emplace_afterable_container<
                    tp_container_t,
                    tp_value_t
                >)
                    return emplace_after(
                        std::forward<tp_container_t>(p_container),
                        p_position,
                        std::forward<tp_value_t>(p_value)
                    );
                else return insert_after(
                    std::forward<tp_container_t>(p_container),
                    p_position,
                    std::forward<tp_value_t>(p_value)
                );
            }
        };
    }
    auto constexpr emplace_after_or_insert_after = detail::emplace_after_or_insert_after_fn{};

    template <
        typename tp_container_t,
        typename tp_value_t
    >
    concept emplace_frontable_or_insert_frontable_container = requires (
        tp_container_t&& p_container,
        tp_value_t&&     p_value
    ) {
        requires (
            requires {
                emplace_front(
                    std::forward<tp_container_t>(p_container),
                    std::forward<tp_value_t>(p_value)
                );
            } ||
            requires {
                insert_front(
                    std::forward<tp_container_t>(p_container),
                    std::forward<tp_value_t>(p_value)
                );
            }
        );
    };

    namespace detail {
        struct emplace_front_or_insert_front_fn {
            template <
                typename                                                    tp_value_t,
                emplace_frontable_or_insert_frontable_container<tp_value_t> tp_container_t
            >
            auto constexpr operator() (
                tp_container_t&& p_container,
                tp_value_t&&     p_value
            )
            const
            -> decltype(auto) {
                if constexpr (emplace_frontable_container<
                    tp_container_t,
                    tp_value_t
                >) {
                    return emplace_front(
                        std::forward<tp_container_t>(p_container),
                        std::forward<tp_value_t>(p_value)
                    );
                }
                else return insert_front(
                    std::forward<tp_container_t>(p_container),
                    std::forward<tp_value_t>(p_value)
                );
            }
        };
    }
    auto constexpr emplace_front_or_insert_front = detail::emplace_front_or_insert_front_fn{};

    template <typename tp_container_t>
    concept erasable_container =
        detail::non_adl_erasable_container<tp_container_t> ||
        detail::adl_erasable_container<tp_container_t>;

    namespace detail {
        struct erase_fn {
            template <erasable_container tp_container_t>
            auto constexpr operator() (
                tp_container_t&&                              p_container,
                std::ranges::const_iterator_t<tp_container_t> p_position
            )
            const
            -> decltype(auto) {
                if constexpr (non_adl_erasable_container<tp_container_t>)
                    return std::forward<tp_container_t>(p_container).erase(p_position);
                else return erase(
                    std::forward<tp_container_t>(p_container),
                    p_position
                );
            }
        };
    }
    auto constexpr erase = detail::erase_fn{};
    
    template <
        typename tp_container_t,
        typename tp_range_t
    >
    concept range_insertable_container =
        detail::non_adl_range_insertable_container<tp_container_t, tp_range_t> ||
        detail::adl_range_insertable_container<tp_container_t, tp_range_t>;

    namespace detail {
        struct insert_range_fn {
            template <
                std::ranges::input_range tp_input_range_t,
                range_insertable_container<tp_input_range_t> tp_container_t
            >
            auto constexpr operator() (
                tp_container_t&&                              p_container,
                std::ranges::const_iterator_t<tp_container_t> p_position,
                tp_input_range_t&&                            p_range
            )
            const
            -> decltype(auto) {
                if constexpr (non_adl_range_insertable_container<
                    tp_container_t,
                    tp_input_range_t
                >) {
                    return std::forward<tp_container_t>(p_container).insert_range(
                        p_position,
                        std::forward<tp_input_range_t>(p_range)
                    );
                }
                else {
                    return insert_range(
                        std::forward<tp_container_t>(p_container),
                        p_position,
                        std::forward<tp_input_range_t>(p_range)
                    );
                }
            }
        };
    }
    auto constexpr insert_range = detail::insert_range_fn{};
}

#endif
