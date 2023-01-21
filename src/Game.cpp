#include <SFML/Graphics.hpp>
#include <Game.h>
#include <AnimatedText.h>
#include <string>
#include <iostream>

namespace mt
{
	Game::~Game()
	{
		if (m_window != nullptr)
			delete m_window;
	}

	void Game::set_name(const std::string name)
	{
		m_name = name;
	}

	void Game::set_resolution(int width, int height)
	{
		m_width = width;
		m_height = height;
	}

	void Game::setup()
	{
		m_window = new sf::RenderWindow(sf::VideoMode(m_width, m_height), m_name);
	}

	void Game::Run()
	{
		std::string str = "Hello, world!";
		int dur = 13;

		//std::cout << "Enter the text: ";
		//std::cin >> str;

		//std::cout << "Enter the duration: ";
		//std::cin >> dur;

		mt::AnimatedText at(str, dur);

		sf::Text text;

		sf::Font font;
		font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");

		text.setFont(font);
		text.setCharacterSize(24);
		text.setFillColor(sf::Color::White);

		sf::Clock timer;

		double t = 0;

		while (m_window->isOpen())
		{
			sf::Event event;
			while (m_window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					m_window->close();
			}

			sf::Time dt = timer.restart();
			t += dt.asMicroseconds() / 1e6;

			at.update(t);
			text.setString(at.text());

			m_window->clear();
			m_window->draw(text);
			m_window->display();

		}
	}
}