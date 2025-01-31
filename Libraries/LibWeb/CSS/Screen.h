/*
 * Copyright (c) 2021, Linus Groh <linusg@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibGfx/Rect.h>
#include <LibWeb/Bindings/PlatformObject.h>
#include <LibWeb/DOM/EventTarget.h>
#include <LibWeb/Forward.h>
#include <LibWeb/HTML/Window.h>

namespace Web::CSS {

class Screen final : public DOM::EventTarget {
    WEB_PLATFORM_OBJECT(Screen, DOM::EventTarget);
    GC_DECLARE_ALLOCATOR(Screen);

public:
    [[nodiscard]] static GC::Ref<Screen> create(HTML::Window&);

    i32 width() const { return screen_rect().width(); }
    i32 height() const { return screen_rect().height(); }
    i32 avail_width() const { return screen_rect().width(); }
    i32 avail_height() const { return screen_rect().height(); }
    u32 color_depth() const { return 24; }
    u32 pixel_depth() const { return 24; }
    GC::Ref<ScreenOrientation> orientation();

    bool is_extended() const;

    void set_onchange(GC::Ptr<WebIDL::CallbackType> event_handler);
    GC::Ptr<WebIDL::CallbackType> onchange();

private:
    explicit Screen(HTML::Window&);

    virtual void initialize(JS::Realm&) override;
    virtual void visit_edges(Cell::Visitor&) override;

    HTML::Window const& window() const { return *m_window; }

    Gfx::IntRect screen_rect() const;

    GC::Ref<HTML::Window> m_window;
    GC::Ptr<ScreenOrientation> m_orientation;
};

}
