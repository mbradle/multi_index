/* Copyright Joaqu�n M L�pez Mu�oz 2003-2004. Use, modification, and
 * distribution are subject to the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org/libs/multi_index for library home page.
 */

#ifndef BOOST_MULTI_INDEX_DETAIL_ACCESS_SPECIFIER_HPP
#define BOOST_MULTI_INDEX_DETAIL_ACCESS_SPECIFIER_HPP

#include <boost/config.hpp>
#include <boost/detail/workaround.hpp>

/* In those compilers that do not accept the member template friend syntax,
 * some protected and private sections might need to be specified as
 * public.
 */

#if !defined(BOOST_NO_MEMBER_TEMPLATE_FRIENDS)
#define BOOST_MULTI_INDEX_PROTECTED_IF_MEMBER_TEMPLATE_FRIENDS protected
#define BOOST_MULTI_INDEX_PRIVATE_IF_MEMBER_TEMPLATE_FRIENDS private
#else
#define BOOST_MULTI_INDEX_PROTECTED_IF_MEMBER_TEMPLATE_FRIENDS public
#define BOOST_MULTI_INDEX_PRIVATE_IF_MEMBER_TEMPLATE_FRIENDS public
#endif

/* GCC does not correctly support in-class using declarations for template
 * functions. See http://gcc.gnu.org/bugzilla/show_bug.cgi?id=9810
 * MSVC 7.1 seems to have a similar problem, though the conditions in which
 * the error happens are not that simple. I have yet to isolate this
 * into a snippet suitable for bug reporting.
 */

#if BOOST_WORKAROUND(__GNUC__, <3)||\
    BOOST_WORKAROUND(__GNUC__,==3)&&(__GNUC_MINOR__<4)||\
    BOOST_WORKAROUND(BOOST_MSVC,==1310)
#define BOOST_MULTI_INDEX_PRIVATE_IF_USING_DECL_FOR_TEMPL_FUNCTIONS public
#else
#define BOOST_MULTI_INDEX_PRIVATE_IF_USING_DECL_FOR_TEMPL_FUNCTIONS private
#endif

#endif
