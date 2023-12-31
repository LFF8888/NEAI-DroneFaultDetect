/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <fonts/ApplicationFontProvider.hpp>
#include <fonts/GeneratedFont.hpp>
#include <texts/TypedTextDatabase.hpp>

touchgfx::Font* ApplicationFontProvider::getFont(touchgfx::FontId typography)
{
    switch (typography)
    {
    case Typography::SY16:
        // SourceHanSansSC_Bold_16_2bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[0]);
    case Typography::SY18:
        // SourceHanSansSC_Bold_18_2bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[1]);
    case Typography::SY20:
        // SourceHanSansSC_Bold_20_2bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[2]);
    case Typography::SY24:
        // SourceHanSansSC_Bold_24_2bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[3]);
    case Typography::SY28:
        // SourceHanSansSC_Bold_28_2bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[4]);
    case Typography::SY32:
        // SourceHanSansSC_Bold_32_2bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[5]);
    case Typography::SY36:
        // SourceHanSansSC_Bold_36_2bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[6]);
    case Typography::SY40:
        // SourceHanSansSC_Bold_40_2bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[7]);
    default:
        return 0;
    }
}
