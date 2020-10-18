#include "pch.h"
#include "../HTMLDecode/Decode.h"
#include "../HTMLDecode/Decode.cpp"



TEST(GetCharacter)
{
	EXPECT_EQ(GetCharacter(QUOTES.code), QUOTES.symbol);
	EXPECT_EQ(GetCharacter(APOSTROPHE.code), APOSTROPHE.symbol);
	EXPECT_EQ(GetCharacter(LESS_TOKEN.code), LESS_TOKEN.symbol);
	EXPECT_EQ(GetCharacter(GREATER_TOKEN.code), GREATER_TOKEN.symbol);
	EXPECT_EQ(GetCharacter(AMPERSAND.code), AMPERSAND.symbol);
	EXPECT_EQ(GetCharacter("Hello"), "");
}

TEST(HtmlDecode_test_cat)
{
	std::string strIn = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
	std::string strOut = "Cat <says> \"Meow\". M&M's";
	EXPECT_EQ(HtmlDecode(strIn), strOut);
}

TEST(HtmlDecode_test_double_ampersand)
{
	std::string strIn = "&&amp;";
	std::string strOut = "&&";
	EXPECT_EQ(HtmlDecode(strIn), strOut);
}

TEST(HtmlDecode_test_multi_ampersand)
{
	std::string strIn = "&&&&&amp; &&lt;hello&&&gt; &&&&&apos;&&hello&c";
	std::string strOut = "&&&&& &<hello&&> &&&&'&&hello&c";
	EXPECT_EQ(HtmlDecode(strIn), strOut);
}

TEST(HtmlDecode_test_html)
{
	std::string strIn = "&lt;!DOCTYPE html&gt;";
	std::string strOut = "<!DOCTYPE html>";
	EXPECT_EQ(HtmlDecode(strIn), strOut);
}

TEST(HtmlDecode_test_html2)
{
	std::string strIn = "&lt;meta http-equiv = &quot;Content-Type&quot; content = &quot;text/html&quot;&gt;";
	std::string strOut = "<meta http-equiv = \"Content-Type\" content = \"text/html\">";
	EXPECT_EQ(HtmlDecode(strIn), strOut);
}