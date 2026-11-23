#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(CleanMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        if (auto menu = this->getChildByID("bottom-menu")) {
            if (auto btn = menu->getChildByID("geode.loader/geode-button")) {
                btn->removeFromParent();
                menu->updateLayout();
            }
        }

        return true;
    }
};
