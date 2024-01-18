#include "Test.h"
#include "CTC.h"
#include <tuple>

class Base
{

};

template <typename T>
class Base_impl
{
public:
	static constexpr auto ID = counter<T>;
};

class TC1 : public Base_impl<TC1>
{

};

class TC2 : public Base_impl<TC2>
{

};

class TC3 : public Base_impl<TC3>
{

};

class TC4 : public Base_impl<TC4>
{

};

template<typename ... input_t>
using tuple_cat_t =
decltype(std::tuple_cat(
	std::declval<input_t>()...
));


class ComponentManager
{
public:
	static ComponentManager& Get()
	{
		static ComponentManager singleton;
		return singleton;
	}
	auto& GetList()
	{
		return list;
	}
	auto GetElementCount()
	{
		return element_count<>();
	}
private:
	ComponentManager() = default;
	get_list<> list;
};


int main(int argc, char** argv)
{
	TC1 tc1;
	constexpr auto t1 = tc1.ID;

	TC2 tc2;
	constexpr auto t2 = tc2.ID;

	TC3 tc3;
	constexpr auto t3 = tc3.ID;

	auto& cm = ComponentManager::Get();

	cm.GetList();
	cm.GetElementCount();



	std::tuple<int> tt1;
	tuple_append_t<decltype(tt1), float> test3;
}