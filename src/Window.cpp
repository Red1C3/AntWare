#include <SDL2/SDL_video.h>
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
    if(SDL_Init(SDL_INIT_VIDEO)<0){
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
    internal.ctx=SDL_GL_CreateContext(internal.window);
    if (internal.ctx==nullptr){
        printf("Failed to create OpenGL context, err: %s",SDL_GetError());
        assert(0);
    }
}
void Window::terminate()
{
    SDL_DestroyWindow(internal.window);
    internal.window=nullptr;
    SDL_Quit();
}
