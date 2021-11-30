//#pragma once
//#include <concepts>
//#include <memory>
//#include <string>
//#include <unordered_map>
//#include <vector>
//
//#include <libudph/Class/Event.h>
//#include <libudph/Class/Interface.h>
//#include <libudph/GUI/ApplicationTypes.h>
//#include <libudph/GUI/Window.h>
//#include <libudph/Math/udMath.h>
//
//#include "wx/app.h"
//
////extern void udStartup();
//namespace UD::Application
//{
//class Application
//    : public UD::Interface::Interface<Application,
//                                      UD::Interface::SimpleModifiers>
//{
//  friend class Application_wxWrapper;
//
//  Arguments _arguments = {};
//  std::unordered_map<ID, std::unique_ptr<UD::Application::GUI::Window>> _windows
//      = {};
//
//  ID _next_id = 1;
//
//  auto arguments() -> Arguments&;
//  void InternalStartup(int argc, char** argv);
//  void InternalSetup();
//  void InternalMain();
//  void InternalTeardown();
//  void InternalShutdown();
//
// protected:
//  virtual void Startup();
//  virtual void Setup();
//  virtual void Main();
//  virtual void Teardown();
//  virtual void Shutdown();
//
// public:
//  void Run(int argc, char** argv);
//  template<std::derived_from<UD::Application::GUI::Window> T, class... Args>
//  auto Create(Args... args) -> T&
//  {
//    auto window            = std::make_unique<T>(args...);
//    auto& window_ref = *window;
//    _windows[window->id()] = std::move(window);
//    return window_ref;
//  }
//  auto GetNextID() -> ID;
//};
//class Application_wxWrapper
//    : public UD::Interface::Interface<Application_wxWrapper,
//                                      UD::Pack::Pack<wxApp>,
//                                      UD::Interface::SimpleModifiers>
//{
//  std::unique_ptr<Application> _application;
//
//  auto OnInit() -> bool override;
//
// public:
//  Application_wxWrapper();
//  auto application() -> Application&;
//  template<std::derived_from<Application> T>
//  void InitApplication()
//  {
//    _application = std::make_unique<T>();
//  }
//};
//}  // namespace UD::Application
//
//wxDECLARE_APP(UD::Application::Application_wxWrapper);
//
//namespace UD::Application
//{
//template<std::derived_from<Application> T>
//void Set()
//{
//  wxGetApp().InitApplication<T>();
//}
//template<std::derived_from<Application> T = Application>
//auto Get() -> T&
//{
//  return dynamic_cast<T&>(wxGetApp().application());
//}
//}  // namespace UD::Application