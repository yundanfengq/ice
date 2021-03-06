// **********************************************************************
//
// Copyright (c) 2003-2016 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

[["cpp:dll-export:TEST_API"]]

module Test
{

module Common
{

exception ServerFailedException
{
    string reason;
};

interface Server
{
    void waitTestSuccess();
    void waitForServer() throws ServerFailedException;
    void terminate();
};

sequence<string> StringSeq;

interface Controller
{
    Server* runServer(string lang, string name, string protocol, string host, bool winrt, string configName,
                      StringSeq options);
};

};

};
