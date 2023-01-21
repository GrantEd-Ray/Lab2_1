#include <string>
#include <AnimatedText.h>

namespace mt
{
	AnimatedText::AnimatedText(const std::string& text, int duration)
	{
		m_text = text;
		m_duration = duration;
		SecToLetter = duration / text.length();
	}

	void AnimatedText::update(double time)
	{
		int num = time / SecToLetter;
		if (num <= m_text.length())
		{
			TextToShow = m_text.substr(0, num);
		}
		else
		{
			TextToShow = m_text.substr(0, m_text.length());
		}
	}

	std::string AnimatedText::text() const
	{
		return TextToShow;
	}
}