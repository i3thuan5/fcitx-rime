/*
* Copyright (C) 2017~2017 by CSSlayer
* wengxt@gmail.com
*
* This library is free software; you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as
* published by the Free Software Foundation; either version 2.1 of the
* License, or (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this library; see the file COPYING. If not,
* see <http://www.gnu.org/licenses/>.
*/
#ifndef _FCITX_RIME_H_RIME_H_
#define _FCITX_RIME_H_RIME_H_

#include <fcitx-config/configuration.h>
#include <fcitx/addonfactory.h>
#include <fcitx/addonmanager.h>
#include <fcitx/inputcontextproperty.h>
#include <fcitx/inputmethodengine.h>
#include <fcitx/instance.h>
#include <memory>
#include <rime_api.h>

namespace fcitx {

class RimeState;

class RimeEngine final : public InputMethodEngine {
public:
    RimeEngine(Instance *instance);
    ~RimeEngine();
    Instance *instance() { return instance_; }
    void activate(const InputMethodEntry &entry,
                  InputContextEvent &event) override;
    void keyEvent(const InputMethodEntry &entry, KeyEvent &keyEvent) override;
    void reloadConfig() override;
    void reset(const InputMethodEntry &entry,
               InputContextEvent &event) override;
    void save() override;
    auto &factory() { return factory_; }

    void updateUI(InputContext *inputContext);

    std::string subMode(const InputMethodEntry &, InputContext &) override;

    rime_api_t *api() { return api_; }

    void rimeStart(bool fullcheck);

    RimeState *state(InputContext *ic);

private:
    static void rimeNotificationHandler(void *context_object,
                                        RimeSessionId session_id,
                                        const char *message_type,
                                        const char *message_value);

    Instance *instance_;
    rime_api_t *api_;
    bool firstRun_ = true;
    KeyList selectionKeys_;
    FactoryFor<RimeState> factory_;

    FCITX_ADDON_DEPENDENCY_LOADER(notifications, instance_->addonManager());
};

class RimeEngineFactory : public AddonFactory {
public:
    AddonInstance *create(AddonManager *manager) override {
        return new RimeEngine(manager->instance());
    }
};
}

#endif // _FCITX_RIME_H_RIME_H_