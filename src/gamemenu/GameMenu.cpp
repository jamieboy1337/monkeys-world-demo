#include <gamemenu/GameMenu.hpp>
#include <critter/ui/UIGroup.hpp>
#include <gamemenu/ui/SlidingBlindsTransition.hpp>
#include <gamemenu/ui/MenuBG.hpp>
#include <gamemenu/ui/CourseSelectGroup.hpp>
#include <gamemenu/ui/StageBanner.hpp>
#include <gamemenu/ui/StageSelectTransition.hpp>

#include <critter/ui/layout/Margin.hpp>
#include <critter/ui/UIImage.hpp>

namespace gamemenu {

using ::monkeysworld::critter::ui::UIGroup;
using ui::SlidingBlindsTransition;
using ui::CourseSelectGroup;
using ui::StageBanner;
using namespace ::monkeysworld::critter::ui::layout;
using ::monkeysworld::critter::ui::UIImage;

GameMenu::GameMenu() {

}

void GameMenu::SetLastFrameTexture(GLuint color) {
}

std::string GameMenu::GetSceneIdentifier() {
  return "game_menu";
}

void GameMenu::Initialize(::monkeysworld::engine::Context* ctx) {
  auto transition_screen = std::make_shared<SlidingBlindsTransition>(ctx);
  auto bg = std::make_shared<ui::MenuBG>(ctx);
  auto picks = std::make_shared<CourseSelectGroup>(ctx);
  auto banner = std::make_shared<StageBanner>(ctx);
  auto transition_obj = std::make_shared<ui::StageSelectTransition>(ctx);

  bg->SetId(GRID_BG_ID);
  picks->SetId(SELECT_GROUP_ID);
  banner->SetId(BANNER_ID);
  transition_obj->SetId(TRANSITION_ID);

  transition_screen->z_index = -10000;
  bg->z_index = 10;
  picks->z_index = 0;
  banner->z_index = -100;

  auto margins = transition_screen->GetLayoutParams();
  auto win = GetWindow();

  margins.left.anchor_id = win->GetId();
  margins.left.anchor_face = Face::LEFT;
  margins.left.margin = 0;

  margins.right.anchor_id = win->GetId();
  margins.right.anchor_face = Face::RIGHT;
  margins.right.margin = 0;

  margins.top.anchor_id = banner->GetId();
  margins.top.anchor_face = Face::BOTTOM;
  margins.top.margin = 0;
  picks->SetLayoutParams(margins);

  margins.top.anchor_id = win->GetId();
  margins.top.anchor_face = Face::TOP;

  banner->SetLayoutParams(margins);

  margins.bottom.anchor_id = win->GetId();
  margins.bottom.anchor_face = Face::BOTTOM;
  margins.bottom.margin = 0;

  transition_screen->SetLayoutParams(margins);
  bg->SetLayoutParams(margins);


  win->AddChild(transition_screen);
  win->AddChild(bg);
  win->AddChild(picks);
  win->AddChild(banner);
  win->AddChild(transition_obj);
}


}