/*
 * Copyright (c) 2024, Shannon Booth <shannon@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibWeb/Bindings/Intrinsics.h>
#include <LibWeb/Bindings/ScreenOrientationPrototype.h>
#include <LibWeb/CSS/ScreenOrientation.h>
#include <LibWeb/HTML/EventNames.h>

namespace Web::CSS {

GC_DEFINE_ALLOCATOR(ScreenOrientation);

ScreenOrientation::ScreenOrientation(JS::Realm& realm)
    : DOM::EventTarget(realm)
{
}

void ScreenOrientation::initialize(JS::Realm& realm)
{
    WEB_SET_PROTOTYPE_FOR_INTERFACE(ScreenOrientation);
    Base::initialize(realm);
}

GC::Ref<ScreenOrientation> ScreenOrientation::create(JS::Realm& realm)
{
    return realm.create<ScreenOrientation>(realm);
}

// https://w3c.github.io/screen-orientation/#lock-method
WebIDL::ExceptionOr<GC::Ref<WebIDL::Promise>> ScreenOrientation::lock(Bindings::OrientationLockType)
{
    return WebIDL::NotSupportedError::create(realm(), "FIXME: ScreenOrientation::lock() is not implemented"_string);
}

// https://w3c.github.io/screen-orientation/#unlock-method
void ScreenOrientation::unlock()
{
    dbgln("FIXME: Stubbed ScreenOrientation::unlock()");
}

// https://w3c.github.io/screen-orientation/#type-attribute
Bindings::OrientationType ScreenOrientation::type() const
{
    dbgln("FIXME: Stubbed ScreenOrientation::type()");
    return Bindings::OrientationType::LandscapePrimary;
}

// https://w3c.github.io/screen-orientation/#angle-attribute
WebIDL::UnsignedShort ScreenOrientation::angle() const
{
    dbgln("FIXME: Stubbed ScreenOrientation::angle()");
    return 0;
}

// https://w3c.github.io/screen-orientation/#onchange-event-handler-attribute
void ScreenOrientation::set_onchange(GC::Ptr<WebIDL::CallbackType> event_handler)
{
    set_event_handler_attribute(HTML::EventNames::change, event_handler);
}

// https://w3c.github.io/screen-orientation/#onchange-event-handler-attribute
GC::Ptr<WebIDL::CallbackType> ScreenOrientation::onchange()
{
    return event_handler_attribute(HTML::EventNames::change);
}

}
