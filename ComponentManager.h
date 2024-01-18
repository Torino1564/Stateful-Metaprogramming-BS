#pragma once
#include "CTC.h"

class ComponentManager
{
public:
	static ComponentManager& Get()
	{
		static ComponentManager singleton;
		return singleton;
	}
	template <auto Tag = [] {} >
	static constexpr auto GetElementCount()
	{
		return element_count<>();
	}
	template <auto Tag = [] {} >
	using list = get_list<>;
	
	template <unsigned N, auto Tag = []{}>
	using type_by_index_t = typename std::remove_reference_t<decltype(std::get<N>(std::declval<ComponentManager::list<>>()))>;
private:
	ComponentManager() = default;
};

template <typename T>
class ComponentBase
{
public:
	static constexpr auto ID = counter<T>;
};