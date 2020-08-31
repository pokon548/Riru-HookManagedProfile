# Riru - HookManagedProfile

A module that hook isManagedProfile() in ``android.os.UserManagaer`` to throw restrictions in Android For Business (aka Android For Work) into void.

[中文版介绍](/README-zh.md)

![Travis CI](https://api.travis-ci.com/pokon548/Riru-HookManagedProfile.svg)

## Why this

When using [Island](https://play.google.com/store/apps/details?id=com.oasisfeng.island) (An multiboxing app based on AFB), I would like to make some programs access my notifications. Unfortunately, Android throw a toast notify me its impossible due to limits. And that's why this wheel is (maybe re)invented.

## Capability

Tested **ONLY** on AOSP like ROM (like OxygenOS). Other ROMs may also work but not permitted. 

**Always do backup before flashing this module, otherwise your phone may be trapped in bootloops.**

## Side effect

Not known for now. I will post some of them when it is discovered. :)

