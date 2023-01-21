#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace mt
{
	class Game
	{
	private:
		int m_width, m_height;
		std::string m_name;
		sf::RenderWindow* m_window = nullptr;
	
	public:
		Game(){}

		~Game();

		void set_name(const std::string name);

		void set_resolution(int width, int height);

		void setup();

		void Run();
	};
}