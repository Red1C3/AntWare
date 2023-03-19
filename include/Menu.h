#pragma once
#ifndef NOSOUND
#include<SDL2/SDL_mixer.h>
#endif
#include<string>
#include <vector>
#include<MusicAdapter.h>
#include<SoundAdapter.h>
#include<SoundBufferAdapter.h>
#include <Window.h>
#include <HUD.h>
#include<glm/gtc/matrix_transform.hpp>
#define MENU Menu::instance()
namespace aw
{
    class Menu
    {
    private:
        Menu();
        MusicAdapter music;
        SoundBufferAdapter menuPickSoundBuffer, menuNavigateSoundBuffer;
        SoundAdapter menuPickSound, menuNavigateSound;
        std::vector<std::string> levels;
        std::vector<GLuint> labels;
        GLuint backgroundTex, gameLabelTex, creditsTex;
        glm::vec2 backgroundSize = {12, 12};
        glm::vec2 gameLabelSize = {5, 5};
        glm::vec2 gameLabelPos = {-5.5f, 1};
        glm::vec2 creditsSize = {5, 5};
        glm::vec2 creditsPos = {5.4f, -5.0f};
        glm::vec3 clearColor = {0, 0, 0};
        glm::vec3 dimColor = {0.5f, 0.5f, 0.5f};
        int selectedLvl = 0;
        glm::vec2 firstLevelPos = {-6, 0};
        glm::vec2 labelSize = {5, 5};
        float yMargain = -0.7f;

    public:
        static Menu &instance();
        void init(std::vector<std::string> levels, std::vector<std::string> labels);
        int loop();
    };
}