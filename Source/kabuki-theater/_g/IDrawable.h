////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2016 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#pragma once

#include <SFML/Graphics/Export.hpp>
#include <SFML/Graphics/RenderStates.hpp>


namespace _G {

class RenderTarget;

class SFML_GRAPHICS_API IDrawable
/*< Abstract base class for objects that can be drawn
           to a render target
    @ingroup graphics
   
    _G::Drawable is a very simple base class that allows objects
    of derived classes to be drawn to a _G::RenderTarget.
   
    All you have to do in your derived class is to override the
    draw virtual function.
   
    Note that inheriting from _G::Drawable is not mandatory,
    but it allows this nice syntax "window.draw(object)" rather
    than "object.draw(window)", which is more consistent with other
    SFML classes.
   
    Example:
    @code
    class MyDrawable : public _G::Drawable
    {
    public:
   
       ...
   
    private:
   
        virtual void draw(_G::RenderTarget& target, _G::RenderStates states) const
        {
            // You can draw other high-level objects
            target.draw(m_sprite, states);
   
            // ... or use the low-level API
            states.texture = &m_texture;
            target.draw(m_vertices, states);
   
            // ... or draw with OpenGL directly
            glBegin(GL_QUADS);
            ...
            glEnd();
        }
   
        _G::Sprite m_sprite;
        _G::Texture m_texture;
        _G::VertexArray m_vertices;
    };
    @endcode
   
    @see _G::RenderTarget
*/
{
    public:

    virtual ~Drawable() {}
    /*< Virtual destructor. */

    protected:

    friend class RenderTarget;
    
    virtual void draw(RenderTarget& target, RenderStates states) const = 0;
    /*< Draw the object to a render target
        This is a pure virtual function that has to be implemented
        by the derived class to define how the drawable should be
        drawn.
        @param target Render target to draw to
        @param states Current render states. */
};

} // namespace _G