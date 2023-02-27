#include "SDL_mixer.h"
#include <Menu.h>
using namespace aw;
using namespace std;
using namespace sf;
using namespace glm;
Menu::Menu() {}
Menu &Menu::instance()
{
    static Menu menu;
    return menu;
}
void Menu::init(vector<string> levels, vector<string> labels)
{
    music.openFromFile("Assets/Audio/music00.ogg");
    music.setVolume(40);
    music.setLoop(true);
    music.play();
    menuNavigateSoundBuffer.loadFromFile("Assets/Audio/menuNavigate.wav");
    menuPickSoundBuffer.loadFromFile("Assets/Audio/menuPick.wav");
    menuNavigateSound.setBuffer(menuNavigateSoundBuffer);
    menuPickSound.setBuffer(menuPickSoundBuffer);
    this->levels = levels;
    for (unsigned i = 0; i < labels.size(); ++i)
    {
        GLuint tex;
        Hud::loadTexture(labels[i].c_str(), tex);
        this->labels.push_back(tex);
    }
    Hud::loadTexture("Assets/Textures/Main Menu BG.png", backgroundTex);
    Hud::loadTexture("Assets/Textures/Game Label.png", gameLabelTex);
    Hud::loadTexture("Assets/Textures/Credits.png", creditsTex);
}
int Menu::loop()
{
    glClearColor(clearColor.r, clearColor.g, clearColor.b, 1.0f);
    glUseProgram(HUD.getShaderProgram());

    bool isSelecting = true;
    while (isSelecting)
    {
        Event event;
        /* while (WINDOW.internal.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                return -1;
            case Event::KeyReleased:
                if (event.key.code == Keyboard::Escape)
                {
                    return -1;
                }
                if (event.key.code == Keyboard::Enter)
                {
                    menuPickSound.play();
                    isSelecting = false;
                }
                else if (event.key.code == Keyboard::Down)
                {
                    menuNavigateSound.play();
                    selectedLvl++;
                    selectedLvl = selectedLvl % levels.size();
                }
                else if (event.key.code == Keyboard::Up)
                {
                    menuNavigateSound.play();
                    if (selectedLvl == 0)
                    {
                        selectedLvl = levels.size() - 1;
                    }
                    else
                    {
                        selectedLvl--;
                    }
                }
            default:
                break;
            }
        }*/ //FIXME
        vec2 labelPos = firstLevelPos;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        HUD.drawQuad(backgroundTex, {0, 0}, backgroundSize);
        HUD.drawQuad(gameLabelTex, gameLabelPos, gameLabelSize);
        HUD.drawQuad(creditsTex, creditsPos, creditsSize);
        for (unsigned i = 0; i < labels.size(); ++i)
        {
            if (i != selectedLvl)
            {
                HUD.drawQuad(labels[i], labelPos, labelSize, dimColor);
            }
            else
            {
                HUD.drawQuad(labels[i], {labelPos.x + 0.4f, labelPos.y}, labelSize);
            }
            labelPos.y += yMargain;
        }
//FIXME        WINDOW.internal.display();
    }
    glUseProgram(0);
    glBindTexture(GL_TEXTURE_2D, 0);
    glEnable(GL_DEPTH_TEST);
    glClearColor(0, 0, 0, 1.0f);

    //FIXME music.stop();
    return selectedLvl;
}
