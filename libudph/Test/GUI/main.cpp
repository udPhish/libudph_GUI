#include "libudph/GUI/Application.h"
#include "libudph/GUI/Window.h"
#include "libudph/Math/Tensor.h"

class App : public UD::Application::Application
{
  void Startup()
  {
    auto& w = App::Create<UD::Application::GUI::Window>(
        "test",
        UD::Tensor::Vector<2, int>(50, 50),
        UD::Tensor::Vector<2, int>(500, 500));
    w.Show();
    auto& w2 = App::Create<UD::Application::GUI::Window>(
        "tesst",
        UD::Tensor::Vector<2, int>(500, 50),
        UD::Tensor::Vector<2, int>(500, 500));
    w2.Show();
  }
};

void udStartup()
{
  UD::Application::Set<App>();
}