#include "gtest/gtest.h"

#include "common/convert2string.h"

TEST(string, convertTo)
{
    int val = 11;
    const std::string stext = "11";
    const std::string convText = common::convertToString(val);
    ASSERT_EQ(stext, convText);

    long lval = 11;
    const std::string ltext = "11";
    const std::string lconvText = common::convertToString(lval);
    ASSERT_EQ(ltext, lconvText);
}

#ifdef OS_WIN
TEST(string16, convertTo)
{
    const common::char16* text = L"text";
    const std::string stext = "text";
    const common::string16 convText = common::convertToString16(stext);
    ASSERT_EQ(text, convText);
    const std::string fstext = common::convertFromString16<std::string>(convText);
    ASSERT_EQ(stext, fstext);

    const common::char16* text2 = L"Привет";
    const std::string stext2 = "Привет";
    const common::string16 convText2 = common::convertToString16(stext2);
    ASSERT_EQ(text2, convText2);
    const std::string fstext2 = common::convertFromString16<std::string>(convText2);
    ASSERT_EQ(stext2, fstext2);
}
#endif
