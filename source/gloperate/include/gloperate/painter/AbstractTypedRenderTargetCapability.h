
#pragma once


#include <gloperate/gloperate_api.h>
#include <gloperate/painter/AbstractCapability.h>
#include <gloperate/base/RenderTarget.h>


namespace gloperate {


/**
*  @brief
*    Type of data provided by the render target
*/
enum class RenderTargetType {
    Color,
    Depth,
    Normal,
    Geometry,
    ObjectID
};


/**
*  @brief
*    
*/
class GLOPERATE_API AbstractTypedRenderTargetCapability : public AbstractCapability
{
public:
    /**
    *  @brief
    *    Constructor
    */
    AbstractTypedRenderTargetCapability();

    /**
    *  @brief
    *    Destructor
    */
    virtual ~AbstractTypedRenderTargetCapability();

    /**
    *  @brief
    *    Check if a render target of the specified type is available
    *
    *  @param[in] type
    *    Requested data type
    *
    *  @return
    *    'true' if render target is available, else 'false'
    */
    virtual bool hasRenderTarget(RenderTargetType type) = 0;

    /**
    *  @brief
    *    Get render target of the specified type
    *
    *  @param[in] type
    *    Requested data type
    *
    *  @return
    *    Render target
    */
    virtual const RenderTarget & renderTarget(RenderTargetType type) = 0;
};


} // namespace gloperate
