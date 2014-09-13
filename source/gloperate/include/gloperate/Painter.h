/******************************************************************************\
 * gloperate
 *
 * Copyright (C) 2014 Computer Graphics Systems Group at the 
 * Hasso-Plattner-Institut (HPI), Potsdam, Germany.
\******************************************************************************/
#pragma once


#include <vector>
#include <globjects/base/Referenced.h>
#include <gloperate/gloperate_api.h>
#include <gloperate/capabilities/AbstractCapability.h>


namespace gloperate
{


/**
*  @brief
*    Represents the main class for defining a rendering process
*
*    A painter describes an entire rendering process. It is the main class for
*    rendering in gloperate and has to be specialized for specific rendering
*    tasks. Painters can be inserted into a viewer for rendering on the screen,
*    or used inside tools, such as a screenshot tool for saving images to disk.
*    Also, some painters can include other (nested) painters and include them
*    into their rendering process by means of render-to-texture.
*
*    A rendering is defined by an initialization method, in which necessary
*    resources and, e.g., OpenGL states, are set up, and a paint method that
*    performs the rendering of a frame. In addition to that, a painter can
*    use capabilities to describe what kind of functionality and interfaces
*    it supports. See AbstractCapability for more information on capabilities.
*/
class GLOPERATE_API Painter : public globjects::Referenced
{


public:
    /**
    *  @brief
    *    Constructor
    */
    Painter();

    /**
    *  @brief
    *    Destructor
    */
    virtual ~Painter();

    /**
    *  @brief
    *    Initialize painter
    */
    void initialize();

    /**
    *  @brief
    *    Render a frame
    */
    void paint();

    /**
    *  @brief
    *    Check if a specific capability is supported by the painter
    *
    *  @return
    *    'true' if capability is supported, else 'false'
    */
    template <typename Capability>
    bool supports() const;

    /**
    *  @brief
    *    Get a specific capability
    *
    *  @return
    *    Pointer to the capability, nullptr if the capability is not supported
    */
    template <typename Capability>
    Capability * getCapability() const;


protected:
    /**
    *  @brief
    *    Called on initialization
    */
    virtual void onInitialize() = 0;

    /**
    *  @brief
    *    Called on rendering
    */
    virtual void onPaint() = 0;


protected:
    /**
    *  @brief
    *    Add capability to the painter
    *
    *  @param[in] capability
    *    Capability
    *
    *  @remarks
    *    The painter takes ownership of the capability.
    */
    void addCapability(AbstractCapability * capability);


protected:
    std::vector<AbstractCapability*> m_capabilities;    /**< List of supported capabilities */


};


} // namespace gloperate


#include <gloperate/Painter.hpp>
