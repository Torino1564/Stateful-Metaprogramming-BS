#pragma once
#include <tuple>
#include <concepts>
#include <type_traits>


// E1
template<typename...>
struct type_list {};


// E2
template<class TypeList, typename T>
struct type_list_append;

template<typename... Ts, typename T>
struct type_list_append<type_list<Ts...>, T> {
    using type = type_list<Ts..., T>;
};


// E3
template<unsigned N, typename List>
struct state_t {
    static constexpr unsigned n = N;
    using list = List;
};


namespace {
    struct tu_tag {};           // E4
}


template<
    unsigned N,
    std::same_as<tu_tag> TUTag
>
struct reader {
    friend auto state_func(reader<N, TUTag>);
};


template<
    unsigned N,
    typename List,
    std::same_as<tu_tag> TUTag
>
struct setter {
    // E5
    friend auto state_func(reader<N, TUTag>) {
        return List{};
    }

    static constexpr state_t<N, List> state{};
};


template struct setter<0, type_list<>, tu_tag>;     // E6


// E7
template<
    std::same_as<tu_tag> TUTag,
    auto EvalTag,
    unsigned N = 0
>
[[nodiscard]]
consteval auto get_state() {
    constexpr bool counted_past_n = requires(reader<N, TUTag> r) {
        state_func(r);
    };

    if constexpr (counted_past_n) {
        return get_state<TUTag, EvalTag, N + 1>();
    }
    else {
        // E7.1
        constexpr reader<N - 1, TUTag> r;
        return state_t<N - 1, decltype(state_func(r))>{};
    }
}


// E8
template<
    std::same_as<tu_tag> TUTag = tu_tag,
    auto EvalTag = [] {},
    auto State = get_state<TUTag, EvalTag>()
>
using get_list = typename std::remove_cvref_t<decltype(State)>::list;
template<
    std::same_as<tu_tag> TUTag = tu_tag,
    auto EvalTag = [] {},
    auto State = get_state<TUTag, EvalTag>()
>
constexpr auto element_count()
{
    return State.n;
}


// E9
template<
    typename T,
    std::same_as<tu_tag> TUTag,
    auto EvalTag
>
[[nodiscard]]
consteval auto append_impl() {
    using cur_state = decltype(get_state<TUTag, EvalTag>());            // E9.1
    using cur_list = typename cur_state::list;
    using new_list = typename type_list_append<cur_list, T>::type;      // E9.2
    setter<cur_state::n + 1, new_list, TUTag> s;                        // E9.3
    return s.state;                                                     // E9.4
}


// E10
template<
    typename T,
    std::same_as<tu_tag> TUTag = tu_tag,
    auto EvalTag = [] {},
    auto State = append_impl<T, TUTag, EvalTag>()
>
constexpr auto append = [] { return State; };           // E10.1

template <typename T, typename Input_t>
using tuple_append_t = decltype(
	std::tuple_cat(std::declval<T>(), std::declval<std::tuple<Input_t>>())
);

template <unsigned N>
struct readerC {
	friend auto counted_flag(readerC<N>);
};

template <unsigned N>
struct setterC {
	friend auto	counted_flag(readerC<N>) {}

	static constexpr unsigned n = N;
};

template<auto Tag, typename T, unsigned NextVal = 0>
[[nodiscard]]
consteval auto counter_impl()
{
	constexpr bool counted_past_value = requires(readerC<NextVal> r) {
		counted_flag(r);
	};

	if constexpr (counted_past_value) {
		return counter_impl<Tag, T, NextVal + 1>();
	}
	else
	{
        append<T>;
		setterC<NextVal> s;
		return s.n;
	}
}

template <typename T, auto Tag = [] {}, auto Val = counter_impl<Tag, T>()>
constexpr auto counter = Val;

