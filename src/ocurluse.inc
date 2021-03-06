(***  Copyright (c) 2002-2005, Jeffrey Pohlmeyer, <yetanothergeek@yahoo.com>  ***)
(* Licensed per the file COPYING, which should be included in all distributions *)

// Uses clause and global ifdef's ...

{$IFDEF FPC}
  {$MODE OBJFPC}
{$ENDIF}
{$H+}


{$IFDEF FPC}
  {$IFDEF LAZARUS}
    {$DEFINE CURL_COMPONENT}
    {$IFDEF MSWINDOWS}
      {$R *.res}
    {$ENDIF MSWINDOWS}
  {$ENDIF LAZARUS}
{$ELSE FPC}
  {$DEFINE CURL_COMPONENT}
  {$R *.res}
{$ENDIF FPC}


{$IFDEF FPC}
  {$IFDEF MSWINDOWS}
    {$IFDEF CURL_COMPONENT}
      uses sysutils, winsock, classes, LResources, windows;
    {$ELSE CURL_COMPONENT}
      uses sysutils, windows, winsock;
    {$ENDIF CURL_COMPONENT}
  {$ELSE MSWINDOWS}
    {$IFDEF CURL_COMPONENT}
      uses sysutils, classes, LResources, libc;
    {$ELSE CURL_COMPONENT}
      uses strings, libc;
    {$ENDIF CURL_COMPONENT}
  {$ENDIF MSWINDOWS}
{$ELSE FPC}
  uses Classes, sysutils, {$IFDEF LINUX} Libc {$ELSE} Windows, winsock {$ENDIF};
{$ENDIF FPC}

{$DEFINE CURL_H_INCLUDE}
  {$INCLUDE curl_h.pas} // <- Core library
{$UNDEF CURL_H_INCLUDE}
