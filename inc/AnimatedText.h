#pragma once
#include <string>

namespace mt
{
	class AnimatedText
	{
	private:
		std::string m_text;
		int m_duration;
		double SecToLetter;
		std::string TextToShow;

	public:
		AnimatedText(const std::string& text, int duration);

		void update(double time);

		std::string text() const;
	};
}