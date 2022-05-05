//#include <SDL.h>
#include <iostream>

#include <stdio.h>
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

//#include "libudph/GUI/Application.h"
//#include "libudph/GUI/Window.h"
//#include "libudph/Math/Tensor.h"

//void t(int s)
//{
//  std::cout << s << std::endl;
//}
//struct s
//{
//  void operator()(char s, int)
//  {
//    std::cout << s << std::endl;
//  }
//};

// struct s
//{
//   s()
//   {
//     UD::Event::Handler Main(&t);
//   }
// };
//  struct App : public UD::Application::Application<App>
//{
//    App()
//    {
//      this->Add<UD::Application::GUI::Button>();
//    }
//    void Main() override
//    {
//      if (this->CurrentTime() - this->StartTime() > 3000)
//      {
//        this->Quit();
//      }
//    }
//    void Shutdown() override {}
//  };
int main(int argc, char** argv)
{
  //UD::Event::Event<char, int> e;

  //UD::Event::Handler<char,int> h;
  //auto               d = [&h,&e](char c, int i)
  //{
  // static int count = 0;
  // count++;
  //  h(e,-1);
  // 
  //  std::cout << c << count << ": " << i << std::endl;
  //};
  //h.Reset(d);
  //h(e,-1);
  //e('c', 2);
  //e('c', 2);
  //e('c', 2);
  //   return App(argc, argv).Run();
  //
  //   SDL_Window*  window        = nullptr;
  //   SDL_Surface* screenSurface = nullptr;
  //   if (SDL_Init(SDL_INIT_VIDEO) < 0)
  //   {
  //     printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
  //   }
  //   else
  //   {
  //     // Create window
  //     window = SDL_CreateWindow("SDL Tutorial",
  //                               SDL_WINDOWPOS_UNDEFINED,
  //                               SDL_WINDOWPOS_UNDEFINED,
  //                               SCREEN_WIDTH,
  //                               SCREEN_HEIGHT,
  //                               SDL_WINDOW_SHOWN);
  //     if (window == NULL)
  //     {
  //       printf("Window could not be created! SDL_Error: %s\n",
  //       SDL_GetError());
  //     }
  //     else
  //     {
  //       // Get window surface
  //       screenSurface = SDL_GetWindowSurface(window);
  //       // Fill the surface white
  //       SDL_FillRect(screenSurface,
  //                    NULL,
  //                    SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
  //       // Update the surface
  //       SDL_UpdateWindowSurface(window);
  //       // Wait two seconds
  //       SDL_Delay(2000);
  //     }
  //   }
  //   // Destroy window
  //   SDL_DestroyWindow(window);
  //   // Quit SDL subsystems
  //   SDL_Quit();
  //
  return 0;
}