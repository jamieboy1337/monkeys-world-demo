#ifndef GAME_MENU_H_
#define GAME_MENU_H_

#include <engine/Scene.hpp>


namespace gamemenu {

class GameMenu : public ::monkeysworld::engine::Scene {

 public:
  GameMenu();

  /**
   *  Pass a texture to this scene representing the last frame generated by the previous scene.
   *  @param color - the GLuint which contains the desired frame.
   * 
   *  Does nothing if the scene has not yet completed initializing.
   */ 
  void SetLastFrameTexture(GLuint color);
  void Initialize(::monkeysworld::engine::Context* ctx) override;
  std::string GetSceneIdentifier() override;

  static const uint64_t BANNER_ID = 44100;
  static const uint64_t SELECT_GROUP_ID = 44101;
  static const uint64_t GRID_BG_ID = 44102;
  static const uint64_t TRANSITION_ID = 44103;
  
  static const uint64_t CAMERA_ID = 48000;
};

}

#endif