/**
 * Copyright (c) 2017 Zefiros Software.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include "testClasses.h"

#define SERIALISATION_TREE_SKIPPING_TEST( type )                                                    \
SERIALISATION_TEST2( Skipping, ObjectTree, SERIALISATION_PP_TEMPLATE2( TestClassTree, type, 5 ),    \
                     SERIALISATION_PP_TEMPLATE2( TestClassTreeSkipping, type, 5 ), type,            \
                     MakeSeed<type>( 4242 ), 4241 );

SERIALISATION_ALL_TYPES( SERIALISATION_TREE_SKIPPING_TEST );

#define SERIALISATION_OBJECT_VECTOR_SKIPPING_TEST( type )                                                       \
SERIALISATION_TEST2( Skipping, ObjectVector, SkippedObjectVector< type >, SinglePrimitive< uint8_t >, type,     \
                     MakeSeed<type>( 414242 ), 34 );

SERIALISATION_ALL_TYPES( SERIALISATION_OBJECT_VECTOR_SKIPPING_TEST );

#define SERIALISATION_OBJECT_VECTORNON_EXISTINGG_TEST( type )                                                   \
SERIALISATION_TEST2( NonExisting, ObjectVector, SinglePrimitive< uint8_t >, SkippedObjectVector< type >, type,  \
                     SERIALISATION_PP_TEMPLATE2(MakeSeed, type, uint8_t)( 414242 ), 414242 );

SERIALISATION_ALL_TYPES( SERIALISATION_OBJECT_VECTORNON_EXISTINGG_TEST );

#define SERIALISATION_OBJECT_VECTOR_REORDERED_TEST( type )                                                    \
SERIALISATION_TEST2( Object, VectorReordered, ObjectVector< type >, ObjectVectorReordered< type >, type, MakeSeed<type>( 414241 ), 424242 );

SERIALISATION_ALL_TYPES( SERIALISATION_OBJECT_VECTOR_REORDERED_TEST );

#define SERIALISATION_OBJECT_VECTOR_REORDERED_REVERSE_TEST( type )                                                    \
SERIALISATION_TEST2( Object, VectorReorderedReverse, ObjectVectorReordered< type >, ObjectVector< type >, type, MakeSeed<type>( 414241 ), 424242 );

SERIALISATION_ALL_TYPES( SERIALISATION_OBJECT_VECTOR_REORDERED_REVERSE_TEST );