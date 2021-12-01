//#pragma once
//#include <concepts>
//#include <memory>
#include <string>
//#include <unordered_map>
#include <vector>
//
#include <libudph/Class/Event.h>
#include <libudph/Class/Interface.h>
//#include <libudph/GUI/ApplicationTypes.h>
//#include <libudph/GUI/Window.h>
#include <libudph/Math/udMath.h>
//
//#include "wx/app.h"
//
//extern void udStartup();
namespace UD::Application
{
class Application
    : public UD::Interface::Interface<Application,
                                      UD::Interface::SimpleModifiers>
{
  using Arguments = std::vector<std::string>;
  using ID = UD::Math::Type::ULong;

  Arguments _arguments = {};
  //std::unordered_map<ID, std::unique_ptr<UD::Application::GUI::Window>> _windows
  //    = {};

  ID _next_id = 1;

  auto arguments() -> Arguments&;
  void InternalStartup(int argc, char** argv);
  void InternalSetup();
  void InternalMain();
  void InternalTeardown();
  void InternalShutdown();

 protected:
  virtual void Startup();
  virtual void Main();
  virtual void Shutdown();

 public:
  void Run(int argc, char** argv);
  //template<std::derived_from<UD::Application::GUI::Window> T, class... Args>
  //auto Create(Args... args) -> T&
  //{
  //  auto window            = std::make_unique<T>(args...);
  //  auto& window_ref = *window;
  //  _windows[window->id()] = std::move(window);
  //  return window_ref;
  //}
  auto GetNextID() -> ID;
};
}  // namespace UD::Application