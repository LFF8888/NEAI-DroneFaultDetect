#ifndef ERRORCONTAINER_HPP
#define ERRORCONTAINER_HPP

#include <gui_generated/containers/errorContainerBase.hpp>

class errorContainer : public errorContainerBase
{
public:
    errorContainer();
    virtual ~errorContainer() {}

    virtual void initialize();
protected:
};

#endif // ERRORCONTAINER_HPP
