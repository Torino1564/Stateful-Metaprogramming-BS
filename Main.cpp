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
public:
	int pepe;
};

class TC2 : public Base_impl<TC2>
{
public:
	float pepone;
};

class TC3 : public Base_impl<TC3>
{
public:
	double pepununs;
};

class TC4 : public Base_impl<TC4>
{
public:
	long double pepopotamus;
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

	using T1 = typename std::remove_reference_t<decltype(std::get<0>(cm.GetList()))>;
	T1 component0;

	component0.pepe = 69;

	std::tuple<int> tt1;
	tuple_append_t<decltype(tt1), float> test3;
}