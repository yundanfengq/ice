// **********************************************************************
//
// Copyright (c) 2003-2016 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

package Ice;

/**
 * Manages an optional short parameter.
 **/
public class ShortOptional
{
    /**
     * The value defaults to unset.
     **/
    public ShortOptional()
    {
        _isSet = false;
    }

    /**
     * Sets the value to the given argument.
     *
     * @param v The initial value.
     **/
    public ShortOptional(short v)
    {
        _value = v;
        _isSet = true;
    }

    /**
     * Sets the value to a shallow copy of the given optional.
     *
     * @param opt The source value.
     **/
    public ShortOptional(ShortOptional opt)
    {
        _value = opt._value;
        _isSet = opt._isSet;
    }

    /**
     * Obtains the current value.
     *
     * @return The current value.
     * @throws IllegalStateException If the value is not set.
     **/
    public short get()
    {
        if(!_isSet)
        {
            throw new IllegalStateException("no value is set");
        }
        return _value;
    }

    /**
     * Sets the value to the given argument.
     *
     * @param v The new value.
     **/
    public void set(short v)
    {
        _value = v;
        _isSet = true;
    }

    /**
     * If the given argument is set, this optional is set to a shallow copy of the argument,
     * otherwise this optional is unset.
     *
     * @param opt The source value.
     **/
    public void set(ShortOptional opt)
    {
        _value = opt._value;
        _isSet = opt._isSet;
    }

    /**
     * Determines whether the value is set.
     *
     * @return True if the value is set, false otherwise.
     **/
    public boolean isSet()
    {
        return _isSet;
    }

    /**
     * Unsets this value.
     **/
    public void clear()
    {
        _isSet = false;
        _value = 0;
    }

    private short _value;
    private boolean _isSet;
}
