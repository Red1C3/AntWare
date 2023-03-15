#pragma once
#include<ClockAdapter.h>
#include<MusicAdapter.h>
#include<SoundAdapter.h>
#include<SoundBufferAdapter.h>
#include <assert.h>
#include <fstream>
#include <vector>
#include <exception>
#include <random>
#include <rapidjson/document.h>
#include<GLES2/gl2.h>
#include <Window.h>
#include <Renderer.h>
#include <Menu.h>
#include <Mesh.h>
#include <Transform.h>
#include <Physics.h>
#include <Scene.h>
#include <Player.h>
#include <Ant.h>
#define APP aw::App::instance()
namespace aw
{
    class App
    {
    private:
        struct Settings
        {
            int resHeight, resWidth;
            std::vector<std::string> levels;
            std::vector<std::string> levelsLabels;
            std::vector<std::string> levelsMusic;
        } settings;

        App();
        void start();
        void update();
        void readSettingsFile();

        ClockAdapter timeSinceStart;
        Scene *currentScene;
        float deltaTime = 0.0f;
        Status gameStatus;
        MusicAdapter music;
        SoundBufferAdapter easterEggSoundBuffer;
        SoundAdapter easterEggSound;

    public:
        static App &instance();
        bool init(int argc, char **argv);
        void loop();
        void terminate();
        float getTime();
    };
}
