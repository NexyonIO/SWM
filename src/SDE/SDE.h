#pragma once


#include <memory>

namespace Nexyon {

    class SDE
    {
    public:
        void main(int argc, char** argv);

        static std::shared_ptr<SDE> Get();
    };

}

