#include "main_font.h"
#include "assets_manager.h"
#include "log_level.h"
#include "logger.h"

bool MainFont::init()
{
    texture = AssetsManager::getInstance()->getTexture(AssetsKey::FONT);
    if (texture == nullptr)
    {
        Logger::log(LogLevel::ERROR, "Failed to load font texture");
        return false;
    }
    setCharset(CHARSET);
    return true;
}

const std::string MainFont::CHARSET =
    " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789$￠€£¥¤+-*/"
    "÷=%‰\"'#@&_(),.;:¿?¡!\\|{}<>[]§¶µ`^~©®™";