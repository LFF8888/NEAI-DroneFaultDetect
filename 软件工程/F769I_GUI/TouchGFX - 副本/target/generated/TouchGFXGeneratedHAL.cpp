/**
  ******************************************************************************
  * File Name          : TouchGFXGeneratedHAL.cpp
  ******************************************************************************
  * This file is generated by TouchGFX Generator 4.21.4. Please, do not edit!
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#include <TouchGFXGeneratedHAL.hpp>
#include <touchgfx/hal/OSWrappers.hpp>
#include <gui/common/FrontendHeap.hpp>

#include <touchgfx/widgets/canvas/CWRVectorRenderer.hpp>

#include <HardwareMJPEGDecoder.hpp>
#include <DedicatedBufferVideoController.hpp>
#include <jpeg_utils.h>
#include <stm32f7xx_hal.h>

HardwareMJPEGDecoder mjpegdecoder1;
LOCATION_PRAGMA_NOLOAD("Video_RGB_Buffer")
uint32_t videoRGBBuffer[192000] LOCATION_ATTRIBUTE_NOLOAD("Video_RGB_Buffer");
DedicatedBufferController<1, 800, 480, 800*2U, Bitmap::RGB565> videoController;

//Singleton Factory
VideoController& VideoController::getInstance()
{
    return videoController;
}

namespace touchgfx
{
VectorRenderer* VectorRenderer::getInstance()
{
    static CWRVectorRendererRGB565 renderer;

    return &renderer;
}
} // namespace touchgfx

#include "stm32f7xx.h"

using namespace touchgfx;

namespace
{
    // Use the section "TouchGFX_Framebuffer" in the linker script to specify the placement of the buffer
    LOCATION_PRAGMA_NOLOAD("TouchGFX_Framebuffer")
    uint32_t frameBuf[(800 * 480 * 2 + 3) / 4] LOCATION_ATTRIBUTE_NOLOAD("TouchGFX_Framebuffer");
}

void TouchGFXGeneratedHAL::initialize()
{
    HAL::initialize();
    registerEventListener(*(Application::getInstance()));
    setFrameBufferStartAddresses((void*)frameBuf, (void*)0, (void*)0);
    /*
     * Add hardware decoder to video controller
     */
    videoController.addDecoder(mjpegdecoder1, 0);
    videoController.setRGBBuffer((uint8_t*)videoRGBBuffer, sizeof(videoRGBBuffer));
}

void TouchGFXGeneratedHAL::configureInterrupts()
{
    NVIC_SetPriority(DMA2D_IRQn, 9);
}

void TouchGFXGeneratedHAL::enableInterrupts()
{
    NVIC_EnableIRQ(DMA2D_IRQn);
}

void TouchGFXGeneratedHAL::disableInterrupts()
{
    NVIC_DisableIRQ(DMA2D_IRQn);
}

void TouchGFXGeneratedHAL::enableLCDControllerInterrupt()
{
}

bool TouchGFXGeneratedHAL::beginFrame()
{
    return HAL::beginFrame();
}

void TouchGFXGeneratedHAL::endFrame()
{
    HAL::endFrame();
    videoController.endFrame();
}

inline uint8_t* TouchGFXGeneratedHAL::advanceFrameBufferToRect(uint8_t* fbPtr, const touchgfx::Rect& rect) const
{
    //       Advance vertically                   Advance horizontally
    fbPtr += rect.y * lcd().framebufferStride() + rect.x * 2;
    return fbPtr;
}

uint16_t* TouchGFXGeneratedHAL::getTFTFrameBuffer() const
{
    return (uint16_t*)frameBuf;
}

void TouchGFXGeneratedHAL::setTFTFrameBuffer(uint16_t* adr)
{
    //setTFTFrameBuffer() not used for selected display interface
}

void TouchGFXGeneratedHAL::flushFrameBuffer(const touchgfx::Rect& rect)
{
    HAL::flushFrameBuffer(rect);
}

bool TouchGFXGeneratedHAL::blockCopy(void* RESTRICT dest, const void* RESTRICT src, uint32_t numBytes)
{
    return HAL::blockCopy(dest, src, numBytes);
}

void TouchGFXGeneratedHAL::InvalidateCache()
{
    // If the framebuffer is placed in Write Through cached memory (e.g. SRAM) then
    // the DCache must be flushed prior to DMA2D accessing it. That's done
    // using the function SCB_CleanInvalidateDCache(). Remember to enable "CPU Cache" in the
    // "System Core" settings for "Cortex M7" in CubeMX in order for this function call to work.
    if (SCB->CCR & SCB_CCR_DC_Msk)
    {
        SCB_CleanInvalidateDCache();
    }
}

void TouchGFXGeneratedHAL::FlushCache()
{
    // If the framebuffer is placed in Write Through cached memory (e.g. SRAM) then
    // the DCache must be flushed prior to DMA2D accessing it. That's done
    // using the function SCB_CleanInvalidateDCache(). Remember to enable "CPU Cache" in the
    // "System Core" settings for "Cortex M7" in CubeMX in order for this function call to work.
    if (SCB->CCR & SCB_CCR_DC_Msk)
    {
        SCB_CleanInvalidateDCache();
    }
}

extern "C" void videoTaskFunc(void *argument)
{
    videoController.decoderTaskEntry();
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
