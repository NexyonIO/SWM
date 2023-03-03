#include <SDE/SDE.h>

std::weak_ptr<Nexyon::SDE> __sde;

namespace Nexyon {
    std::shared_ptr<SDE> SDE::Get() {
        return __sde.lock();
    }
};


int main(int argc, char** argv)
{
    __sde = std::make_shared<Nexyon::SDE>();
    Nexyon::SDE::Get()->main(argc, argv);
}
