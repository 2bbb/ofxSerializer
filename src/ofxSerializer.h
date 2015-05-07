//
//  ofxSerializer.h
//
//  Created by ISHII 2bit on 2015/04/28.
//
//

#pragma once

#include "ofMain.h"

#define USE_DIRTY_OFFENSIVE_IMPLEMENTATION 0

#define BEGIN_NAMESPACE(name) namespace name {
#define END_NAMESPACE(name) };

#include "details/utils.h"
#include "details/type_filter.h"

#include "details/serialize.h"
#include "details/deserialize.h"
#include "details/jsonize.h"

#pragma mark main

namespace ofxSerializer = ofx::Serializer;

#include "details/implementation_macros.h"
#include "ofType/includes.h"

#undef BEGIN_NAMESPACE
#undef END_NAMESPACE
