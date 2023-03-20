#pragma once

#include "HMUI/FlowCoordinator.hpp"
#include "HMUI/ViewController.hpp"

#include "UnityEngine/UI/Button.hpp"

#include "custom-types/shared/macros.hpp"

#define METHOD(...) il2cpp_utils::il2cpp_type_check::MetadataGetter<&HMUI::__VA_ARGS__>::get()

DECLARE_CLASS_CODEGEN(ReplaySettings, MainSettings, HMUI::ViewController,
    DECLARE_OVERRIDE_METHOD(void, DidActivate, METHOD(ViewController::DidActivate), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
)

DECLARE_CLASS_CODEGEN(ReplaySettings, RenderSettings, HMUI::ViewController,
    DECLARE_OVERRIDE_METHOD(void, DidActivate, METHOD(ViewController::DidActivate), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
    DECLARE_DEFAULT_CTOR();
    DECLARE_DTOR(dtor);

    public:
    static inline UnityEngine::UI::Button *beginQueueButton, *clearQueueButton;
    static inline bool addedEvent = false;
)

DECLARE_CLASS_CODEGEN(ReplaySettings, InputSettings, HMUI::ViewController,
    DECLARE_OVERRIDE_METHOD(void, DidActivate, METHOD(ViewController::DidActivate), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
)

DECLARE_CLASS_CODEGEN(ReplaySettings, ModSettings, HMUI::FlowCoordinator,
    DECLARE_OVERRIDE_METHOD(void, DidActivate, METHOD(FlowCoordinator::DidActivate), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
    DECLARE_OVERRIDE_METHOD(void, BackButtonWasPressed, METHOD(FlowCoordinator::BackButtonWasPressed), HMUI::ViewController* topViewController);
)

#undef METHOD

// defined in Config.cpp
