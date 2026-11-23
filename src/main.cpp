#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;
        Ref<MenuLayer> self = this;
        queueInMainThread([self]() {
            if (auto menu = self->getChildByID("bottom-menu")) {
                if (auto btn = menu->getChildByID("geode.loader/geode-button")) {
                    btn->removeFromParent();
                    menu->updateLayout();
                }
            }
        });
        return true;
    }
};
