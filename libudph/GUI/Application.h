#pragma once
#include <concepts>
#include <memory>
#include <string>
#include <vector>

#include <libudph/Class/Event.h>
#include <libudph/Class/Interface.h>
#include <libudph/GUI/Window.h>

#include "wx/app.h"
#include "wx/wx.h"

extern void udStartup();
namespace UD::Application
{
using Arguments = std::vector<std::string>;
class Application
    : public UD::Interface::Interface<Application,
                                      UD::Interface::SimpleModifiers>
{
  friend class Application_wxWrapper;

  Arguments                                                  _arguments = {};
  std::vector<std::unique_ptr<UD::Application::GUI::Window>> _windows   = {};

  auto arguments() -> Arguments&
  {
    return _arguments;
  }
  void InternalStartup(int argc, char** argv)
  {
    if (argc > 1)
    {
      _arguments.assign(argv + 1, argv + argc);
    }
    Startup();
  }
  void InternalSetup()
  {
    Setup();
  }
  void InternalMain()
  {
    Main();
  }
  void InternalTeardown()
  {
    Teardown();
  }
  void InternalShutdown()
  {
    Shutdown();
  }

 protected:
  virtual void Startup() {}
  virtual void Setup() {}
  virtual void Main() {}
  virtual void Teardown() {}
  virtual void Shutdown() {}

 public:
  template<std::derived_from<UD::Application::GUI::Window> T, class... Args>
  auto Create(Args... args) -> T&
  {
    _windows.push_back(std::make_unique<T>(args...));
    return **_windows.rbegin();
  }
};
class Application_wxWrapper
    : public UD::Interface::Interface<Application,
                                      UD::Pack::Pack<wxApp>,
                                      UD::Interface::SimpleModifiers>
{
  std::unique_ptr<Application> _application;

  auto OnInit() -> bool override
  {
    udStartup();
    if (!_application)
    {
      return false;
    }
    _application->InternalStartup(this->argc, this->argv);
    return true;
  }

 public:
  Application_wxWrapper() : _application{nullptr} {}
  auto application() -> Application&
  {
    return *_application;
  }
  template<std::derived_from<Application> T>
  void InitApplication()
  {
    _application = std::make_unique<T>();
  }
};
}  // namespace UD::Application

wxIMPLEMENT_APP(UD::Application::Application_wxWrapper);

namespace UD::Application
{
template<std::derived_from<Application> T>
void Set()
{
  wxGetApp().InitApplication<T>();
}
template<std::derived_from<Application> T>
void Get()
{
  dynamic_cast<T&>(wxGetApp().application());
}
}  // namespace UD::Application