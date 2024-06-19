#pragma once //make sure reffered to once

#include "GlobalNamespace/LevelBar.hpp" //game stuff
#include "GlobalNamespace/StandardLevelDetailView.hpp"
#include "GlobalNamespace/IReadonlyBeatmapData.hpp"
#include "HMUI/ViewController.hpp"
#include "HMUI/ModalView.hpp"
#include "HMUI/SimpleTextDropdown.hpp"
#include "TMPro/TextMeshProUGUI.hpp"
#include "UnityEngine/UI/Button.hpp" //game stuff

#include "questui/shared/CustomTypes/Components/Settings/IncrementSetting.hpp"

#include "custom-types/shared/macros.hpp"

struct ReplayInfo; //declare struct

namespace Menu { //new menu namespace
    void EnsureSetup(GlobalNamespace::StandardLevelDetailView* view); //declare func

    void SetButtonEnabled(bool enabled); //declare func
    void SetButtonUninteractable(std::string_view reason); //declare func

    void CheckMultiplayer(); //declare func

    void SetReplays(std::vector<std::pair<std::string, ReplayInfo*>> replays, bool external = false); //declare func

    void PresentMenu(); //declare func
    void DismissMenu(); //declare func

    bool AreReplaysLocal(); //declare func
}

DECLARE_CLASS_CODEGEN(Menu, ReplayViewController, HMUI::ViewController,

    DECLARE_OVERRIDE_METHOD(void, DidActivate,
        il2cpp_utils::il2cpp_type_check::MetadataGetter<&HMUI::ViewController::DidActivate>::get(),
        bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling); //overide smthing with menu namespace?

    DECLARE_INSTANCE_METHOD(void, UpdateUI);
    DECLARE_INSTANCE_METHOD(void, OnEnable);

    public:
        void SetReplays(std::vector<std::pair<std::string, ReplayInfo*>> replays);
        void SelectReplay(int index);
        std::string& GetReplay();
    private:
        GlobalNamespace::LevelBar* levelBar;
        TMPro::TextMeshProUGUI* sourceText;
        TMPro::TextMeshProUGUI* dateText;
        TMPro::TextMeshProUGUI* modifiersText;
        TMPro::TextMeshProUGUI* scoreText;
        TMPro::TextMeshProUGUI* failText;
        UnityEngine::UI::Button* watchButton;
        UnityEngine::UI::Button* renderButton;
        UnityEngine::UI::Button* queueButton;
        UnityEngine::UI::Button* deleteButton;
        HMUI::SimpleTextDropdown* cameraDropdown;
        QuestUI::IncrementSetting* increment;
        HMUI::ModalView* confirmModal;

        std::vector<std::pair<std::string, ReplayInfo*>> replays;
        GlobalNamespace::IDifficultyBeatmap* beatmap;
        GlobalNamespace::IReadonlyBeatmapData* beatmapData;
)
