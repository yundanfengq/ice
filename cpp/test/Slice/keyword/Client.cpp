// **********************************************************************
//
// Copyright (c) 2003-2016 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

#include <Ice/Ice.h>
#include <TestCommon.h>
#include <Key.h>

using namespace std;

class breakI : public _cpp_and::_cpp_break
{
public:

#ifdef ICE_CPP11_MAPPING
    virtual void caseAsync(::Ice::Int,
                           function<void(int)> response,
                           function<void(exception_ptr)>,
                           const ::Ice::Current&)
    {
        response(0);
    }
#else
    virtual void case_async(const ::_cpp_and::AMD_break_casePtr& cb, ::Ice::Int, const ::Ice::Current&)
    {
        cb->ice_response(0);
    }
#endif
};

class charI: public _cpp_and::_cpp_char
{
public:

#ifndef NDEBUG
    virtual void _cpp_explicit(const ::Ice::Current& current)
#else
    virtual void _cpp_explicit(const ::Ice::Current&)
#endif
    {
        assert(current.operation == "explicit");
    }
};

class switchI: public _cpp_and::_cpp_switch
{
public:
#ifdef ICE_CPP11_MAPPING
    virtual void foo(shared_ptr<_cpp_and::charPrx>, Ice::Int&, const ::Ice::Current&)
#else
    virtual void foo(const _cpp_and::charPrx&, Ice::Int&, const ::Ice::Current&)
#endif
    {
    }
};

class doI : public _cpp_and::_cpp_do
{
public:
#ifdef ICE_CPP11_MAPPING
    virtual void caseAsync(::Ice::Int,
                           function<void(int)>,
                           function<void(const exception_ptr&)>,
                           const ::Ice::Current&)
    {
    }
#else
    virtual void case_async(const ::_cpp_and::AMD_break_casePtr&, ::Ice::Int, const ::Ice::Current&)
    {
    }
#endif
    virtual void _cpp_explicit(const ::Ice::Current&)
    {
    }
    virtual void foo(const _cpp_and::charPrx&, Ice::Int&, const ::Ice::Current&)
    {
    }
};

class friendI : public _cpp_and::_cpp_friend
{
public:
    virtual _cpp_and::_cpp_auto
    _cpp_goto(_cpp_and::_cpp_continue,
              const _cpp_and::_cpp_auto&,
#ifdef ICE_CPP11_MAPPING
              const _cpp_and::_cpp_delete&,
#else
              const _cpp_and::deletePtr&,
#endif
              const _cpp_and::switchPtr&,
              const _cpp_and::doPtr&,
              const _cpp_and::breakPrxPtr&,
              const _cpp_and::charPrxPtr&,
              const _cpp_and::switchPrxPtr&,
              const _cpp_and::doPrxPtr&,
              ::Ice::Int, ::Ice::Int,
              ::Ice::Int, ::Ice::Int)
    {
        return _cpp_and::_cpp_auto();
    }
};

//
// This section of the test is present to ensure that the C++ types
// are named correctly. It is not expected to run.
//
void
testtypes()
{
#ifdef ICE_CPP11_MAPPING
    _cpp_and::_cpp_continue a = _cpp_and::_cpp_continue::_cpp_asm;
    test(a == _cpp_and::_cpp_continue::_cpp_asm);
#else
    _cpp_and::_cpp_continue a = _cpp_and::_cpp_asm;
    test(a);
#endif

    _cpp_and::_cpp_auto b, b2;
    b._cpp_default = 0;
    b2._cpp_default = b._cpp_default;
    b._cpp_default = b2._cpp_default;

#ifdef ICE_CPP11_MAPPING
    _cpp_and::_cpp_delete c;
    c._cpp_else = "";
#else
    _cpp_and::deletePtr c = new _cpp_and::_cpp_delete();
    c->_cpp_else = "";
#endif

    _cpp_and::breakPrxPtr d;
    int d2;
    d->_cpp_case(0, d2);
    _cpp_and::breakPtr d1 = ICE_MAKE_SHARED(breakI);

    _cpp_and::charPrxPtr e;
    e->_cpp_explicit();
    _cpp_and::charPtr e1 = ICE_MAKE_SHARED(charI);

    _cpp_and::switchPtr f1 = ICE_MAKE_SHARED(switchI);

    _cpp_and::doPrxPtr g;
    g->_cpp_case(0, d2);
    g->_cpp_explicit();
    _cpp_and::doPtr g1 = ICE_MAKE_SHARED(doI);

    _cpp_and::_cpp_extern h;
    _cpp_and::_cpp_for i;
    _cpp_and::_cpp_return j;
    j._cpp_signed = 0;
    _cpp_and::_cpp_sizeof k;
    k._cpp_static = 0;
    k._cpp_switch = 1;
    k._cpp_signed = 2;

    _cpp_and::friendPtr l = ICE_MAKE_SHARED(friendI);

    const int m  = _cpp_and::_cpp_template;
    test(m == _cpp_and::_cpp_template);

    test(_cpp_and::_cpp_xor_eq == 0);
}

int
run(const Ice::CommunicatorPtr& communicator)
{
    communicator->getProperties()->setProperty("TestAdapter.Endpoints", "default -p 12010:udp");
    Ice::ObjectAdapterPtr adapter = communicator->createObjectAdapter("TestAdapter");
    adapter->add(ICE_MAKE_SHARED(charI), Ice::stringToIdentity("test"));
    adapter->activate();

    cout << "Testing operation name... " << flush;
    _cpp_and::charPrxPtr p = ICE_UNCHECKED_CAST(_cpp_and::charPrx,
        adapter->createProxy(Ice::stringToIdentity("test")));
    p->_cpp_explicit();
    cout << "ok" << endl;

    return EXIT_SUCCESS;
}

int
main(int argc, char* argv[])
{
    try
    {
        Ice::CommunicatorHolder ich = Ice::initialize(argc, argv);
        return run(ich.communicator());
    }
    catch(const Ice::Exception& ex)
    {
        cerr << ex << endl;
        return  EXIT_FAILURE;
    }
}
