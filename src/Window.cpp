#include<SDL2/SDL_events.h>
#include<SDL2/SDL_mixer.h>
#include<SDL2/SDL_mouse.h>
#include <SDL2/SDL_video.h>
#include<SDL2/SDL_image.h>
#include<assert.h>
#include <Window.h>
using namespace aw;
Window::Window() {}
Window &Window::instance()
{
    static Window window;
    return window;
}
void Window::init(int height, int width)
{
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)<0){
        printf("Failed to init SDL_Video, err: %s",SDL_GetError());
        assert(0);   
    }
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,0);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,24);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_ES);
    internal.window=SDL_CreateWindow("AntWare",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_OPENGL|SDL_WINDOW_SHOWN);
    if (internal.window==nullptr){
        printf("Failed to create SDL window, err: %s",SDL_GetError());
        assert(0);
    }
    SDL_ShowCursor(SDL_DISABLE);
    internal.ctx=SDL_GL_CreateContext(internal.window);
    if (internal.ctx==nullptr){
        printf("Failed to create OpenGL context, err: %s",SDL_GetError());
        assert(0);
    }
    initAudio();
}
void Window::initAudio(){
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048)<0){
        printf("Failed to open MIX, err:%s",Mix_GetError());
        assert(0);
    }
}
void Window::initImageLoading(){
    int imgFlags=IMG_INIT_PNG|IMG_INIT_JPG;
    if(!(IMG_Init(imgFlags)&imgFlags)){
        printf("Failed to init images loading, err:%s",IMG_GetError());
        assert(0);
    }
}
void Window::terminate()
{
    SDL_DestroyWindow(internal.window);
    internal.window=nullptr;
    Mix_CloseAudio();
    Mix_Quit();
    SDL_Quit();
}
SDL_Window* Window::WindowAdapter::getHandle(){
    return window;
}
int Window::WindowAdapter::pollEvent(SDL_Event& event){
    return SDL_PollEvent(&event);
}
void Window::WindowAdapter::display(){
    SDL_GL_SwapWindow(window);
}
Window::WindowAdapter::SizeAdapter Window::WindowAdapter::getSize(){
    int width,height;
    SDL_GetWindowSize(window,&width,&height);
    return Window::WindowAdapter::SizeAdapter(width,height);
}
Window::WindowAdapter::SizeAdapter::SizeAdapter(int x,int y){
    this->x=x;
    this->y=y;
}
