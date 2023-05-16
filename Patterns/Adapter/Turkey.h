#pragma once
#include <iostream>

namespace Adapter {

	class ADuck {
	public:
		virtual ~ADuck() = default;

		virtual void quack() = 0;
		virtual void fly() = 0;
	};

	class ATurkey {
	public:
		virtual ~ATurkey() = default;

		virtual void gobble() = 0;
		virtual void fly() = 0;

	};

	class AWildTurkey : public ATurkey
	{
	public:
		void gobble() override { std::cout << "A Gobble" << std::endl; }
		void fly() override { std::cout << "A Short Fly - 100m" << std::endl; }
	};


	class AMallardDuck : public ADuck {
	public:
		void quack() override { std::cout << "A Quack" << std::endl; }
		void fly() override { std::cout << "A Fly - 500m" << std::endl; }
	};

}
